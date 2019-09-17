#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct transition{
  std::string actual_state,event,next_state;
};

std::ostream& operator<<(std::ostream& stream, const transition& transition){
  stream << transition.actual_state << ","<< transition.event << "," << transition.next_state;
  return stream;
}
//CLASSES
class State{
public:
  bool initial, final;
  int number;
  std::vector<std::string> transitions;
  State(int a, bool b, bool c);
};

State::State(int a, bool b, bool c){
  number = a;
  initial = b;
  final = c;
}

//DECLARATIONS
std::vector<std::string> StrToVectStr(std::string str);
std::vector<int> StrToVectInt(std::string str);
std::vector<std::string> GetLines(std::string file);//Save all the lines of the document in an arrangement to have better handling on these
std::vector<transition> ReadTransitions(const std::vector<std::string> &lines);

int main(){

  std::vector<int> states, initial_state, acceptance_states;
  std::vector<std::string> lines, alphabet;
  std::vector<transition> all_transitions;
  std::vector<State> obj_states;
  lines = GetLines("input");
  states = StrToVectInt(lines[0]);
  states.push_back(-1);
  alphabet = StrToVectStr(lines[1]);
  initial_state = StrToVectInt(lines[2]);
  acceptance_states = StrToVectInt(lines[3]);
  all_transitions = ReadTransitions(lines);
  for(int i=0; i<states.size(); i++){
    bool initial, final;
    if(std::find(initial_state.begin(), initial_state.end(), states[i]) != initial_state.end()) {
      initial = true;
    } 
    else{
      initial = false;   
    }

    if(std::find(acceptance_states.begin(), acceptance_states.end(), states[i]) != acceptance_states.end()){
      final = true;
    } 
    else{
      final = false;
    }
  obj_states.push_back(State(states[i],initial,final));
  }
}


//DEFINITIONS 
std::vector<std::string> GetLines(std::string name_file){
  std::vector<std::string> Lines;
  std::string line;
  std::fstream file;
  file.open(name_file);
  while (getline(file, line)){
    Lines.push_back(line);
  }
  return Lines;
}

std::vector<std::string> StrToVectStr(std::string str){
  std::vector<std::string> vect;
  std::string aux;
  for(int i=0; i < str.length(); i++){
    if(str[i]==44){
      vect.push_back(aux);
      aux.clear();
    }
    else
      aux += str[i];
  }
  vect.push_back(aux);
  aux.clear();

  return vect;
}

std::vector<int> StrToVectInt(std::string str){
  std::vector<int> vect;
  std::string aux;
  int x;
  for(int i=0; i < str.length(); i++){
    if(str[i]==44){
      std::stringstream ss(aux);
      ss >> x;
      vect.push_back(x);
      aux.clear();
    }
    else
      aux += str[i];
  }
  std::stringstream ss(aux);
  ss >> x;
  vect.push_back(x);
  aux.clear();

  return vect;
}

std::vector<transition> ReadTransitions(const std::vector<std::string> &lines){
  std::vector<transition> transitions;//array to save the transitions 
  std::string A,B,C,aux;
  std::stringstream ss;

  for(int i= 4; i < lines.size(); i++){
    aux = lines[i];
    std::stringstream ss(aux);
    getline(ss,aux, ',');
    A=aux;
    getline(ss,aux, ',');
    B=aux;
    getline(ss,aux, ',');
    C=aux;  
    transitions.push_back({A, B, C});
  }
  return transitions;
}
