#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>


struct transition{
  std::string event;  
  int next_state;

  transition(std::string a, int b){
  event = a;
  next_state = b;
  }
};

std::ostream& operator<<(std::ostream& stream, const transition& transition){
  stream << transition.event << "," << transition.next_state;
  return stream;
}

/*
CLASSES
*/
class State{
private:
  bool initial, accepted;
  int number;
  std::vector<transition> transitions;
public:
  void setState(int a, bool b, bool c);
  void setTransition(transition transition);
  int getNumber();
  bool getInitial();
  bool getAccepted();
  std::vector<std::string> getEventsOfTransitions();
  int numberOfTransitions();
};

/*
METHODS
*/
void State::setState(int a, bool b, bool c){
  number = a;
  initial = b;
  accepted = c;
}

int State::numberOfTransitions(){
    return transitions.size();
}

void State::setTransition(transition transition){
    transitions.push_back(transition);
}

int State::getNumber(){
    return number;
}

bool State::getInitial(){
    return initial;
}

bool State::getAccepted(){
    return accepted;
}

std::vector<std::string> State::getEventsOfTransitions(){
    std::vector<std::string> events;
    for(int i = 0; i < transitions.size(); i++){
      events.push_back(transitions[i].event);
    }
    return events;
}
/*
DECLARETIONS
*/
void uniqueElements(std::vector<std::string>& vec);
transition stringToTransition(int i, const std::vector<std::string>& lines);
int getFirstElement(std::string line);
void fillStates(std::vector<State> &obj_states, const std::vector<std::string>& alphabet);
std::vector<std::string> StrToVectStr(std::string str);
std::vector<int> StrToVectInt(std::string str);
std::vector<std::string> GetLines(std::string file);//Save all the lines of the document in an arrangement to have better handling on these
std::vector<std::string> subVectorfromVector(std::vector<std::string> &vector1, const std::vector<std::string> &vector2);


int main(){
  std::vector<int> states, initial_state, acceptance_states;
  std::vector<std::string> lines, alphabet;
  std::vector<transition> all_transitions;
  std::vector<State> obj_states;
  std::vector<transition> aux;
  lines = GetLines("inputs/input");
  states = StrToVectInt(lines[0]);
  states.push_back(-1);
  alphabet = StrToVectStr(lines[1]);
  initial_state = StrToVectInt(lines[2]);
  acceptance_states = StrToVectInt(lines[3]);


  for(int i=0; i<states.size(); i++){
    bool initial, final;
    if(std::find(initial_state.begin(), initial_state.end(), states[i]) != initial_state.end())
      initial = true;
    else
      initial = false;   

    if(std::find(acceptance_states.begin(), acceptance_states.end(), states[i]) != acceptance_states.end())
      final = true;
    else
      final = false;
  State state;
  state.setState(states[i],initial,final);
  obj_states.push_back(state);
  }

  for(int i=4; i < lines.size(); i++){
    bool found = true;
    std::string event;
    int j=0, next_state=0;
      while(found){
        if(getFirstElement(lines[i]) == obj_states[j].getNumber()){
          obj_states[j].setTransition(stringToTransition(i,lines));
          j=0;
          found =false;
        }
        else
          j++;
      }
  }
  
  fillStates(obj_states,alphabet);
  return 0;
}




/*
DEFINITIONS
*/ 
std::vector<std::string> GetLines(std::string name_file){
  std::vector<std::string> Lines;
  std::string line;
  std::fstream file;
  file.open(name_file);
  while (getline(file, line)){
    if(!line.empty())
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

int getFirstElement(std::string line){
  std::string aux;
  int x;
  for(int i=0; i < line.length(); i++){
    if(line[i]==44){
      std::stringstream ss(aux);
      ss >> x;
      return x;
    }
    else
      aux += line[i];
  }
  return x;
}

transition stringToTransition(int i, const std::vector<std::string>& lines){
  std::string B,aux;
  aux = lines[i];
  int C;
  
  std::stringstream ss(aux);
  getline(ss,aux, ',');
  getline(ss,aux, ',');
  B=aux;
  getline(ss,aux, ',');
  C=std::stoi(aux); 
  transition transition_line(B,C);
  return transition_line;
}

void fillStates(std::vector<State> &obj_states, const std::vector<std::string>& alphabet){
  std::vector<std::string> events, missing_events;
  for (int i = 0; i < obj_states.size(); i++){
    events = obj_states[i].getEventsOfTransitions();
    uniqueElements(events);
    missing_events = subVectorfromVector(events,alphabet);
    for (int j = 0; j < missing_events.size(); j++){
      transition transition_1(missing_events[j],-1);
      obj_states[i].setTransition(transition_1);
    }
    
  }
  
}

void uniqueElements(std::vector<std::string>& vec){
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
vec.erase(std::remove(vec.begin(), vec.end(), "E"), vec.end());
}


std::vector<std::string> subVectorfromVector(std::vector<std::string> &vector1, const std::vector<std::string> &vector2){
  std::vector<std::string> vec = vector2;
  for (int i = 0; i < vector1.size(); i++){
   vec.erase(std::remove(vec.begin(), vec.end(), vector1[i]), vec.end()); 
  }
  return vec;
}