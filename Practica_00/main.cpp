#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct transition{
  int actual_state;
  std::string event;  
  int next_state;
};


std::ostream& operator<<(std::ostream& stream, const transition& transition){
  stream << transition.actual_state << ","<< transition.event << "," << transition.next_state;
  return stream;
}

//CLASSES
class State{
private:
  bool initial, accepted;
  int number;
  std::vector<transition> transitions;
public:
  void setState(int a, bool b, bool c);
  int getNumber();
  bool getInitial();
  bool getAccepted();
};

void State::setState(int a, bool b, bool c){
  number = a;
  initial = b;
  accepted = c;
}



//DECLARATIONS
std::vector<std::string> StrToVectStr(std::string str);
std::vector<int> StrToVectInt(std::string str);
std::vector<std::string> GetLines(std::string file);//Save all the lines of the document in an arrangement to have better handling on these

int main(){
  std::vector<int> states, initial_state, acceptance_states;
  std::vector<std::string> lines, alphabet;
  std::vector<transition> all_transitions;
  std::vector<State> obj_states;
  std::vector<transition> aux;
  lines = GetLines("input");
  states = StrToVectInt(lines[0]);
  states.push_back(-1);
  alphabet = StrToVectStr(lines[1]);
  initial_state = StrToVectInt(lines[2]);
  acceptance_states = StrToVectInt(lines[3]);


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
  State state;
  state.setState(states[i],initial,final);
  obj_states.push_back(state);
  }

  obj_states.size();
   


  return 1;
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

