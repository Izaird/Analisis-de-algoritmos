#include "automata.h"

std::ostream& operator<<(std::ostream& stream, const transition& transition){
  stream << transition.event << "," << transition.next_state;
  return stream;
}
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

std::vector<char> State::getEventsOfTransitions(){
    std::vector<char> events;
    for(int i = 0; i < transitions.size(); i++){
      events.push_back(transitions[i].event);
    }
    return events;
}

std::vector<transition> State::getTransitions(){
    return transitions;
}

std::string State::getNextState(char symbol){
  std::string next_state;
  for (int i = 0; i < transitions.size(); i++){
    if (transitions[i].event ==symbol){
      if(next_state.empty()){
        next_state += std::to_string(transitions[i].next_state);
      }
      else{
        next_state += ", " ;
        next_state += std::to_string(transitions[i].next_state);
      } 
    } 
  }
  return next_state;
}

char State::getEventOfTransition(int num_transition){
  return transitions[num_transition].event;
}

int State::getNextStateOfTransition(int num_transition){
  return transitions[num_transition].next_state;
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

std::vector<char> StrToVectChar(std::string str){
  std::vector<char> vec(str.begin(), str.end());
  for (int i = 0; i < vec.size(); i++){
    if(vec[i] == 44){
      vec.erase(vec.begin() + i);
    }
  }
  return vec;
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
  std::string aux;
  aux = lines[i];
  char B;
  int C;
  std::stringstream ss(aux);
  getline(ss,aux, ',');
  getline(ss,aux, ',');
  B=aux[0];
  getline(ss,aux, ',');
  C=std::stoi(aux);
  transition transition_line(B,C);
  return transition_line;
}

void fillStates(std::vector<State> &obj_states, const std::vector<char>& alphabet){
  std::vector<char> events, missing_events;
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

void uniqueElements(std::vector<char>& vec){
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
vec.erase(std::remove(vec.begin(), vec.end(), 'E'), vec.end());
}


std::vector<char> subVectorfromVector(std::vector<char> &vector1, const std::vector<char> &vector2){
  std::vector<char> vec = vector2;
  for (int i = 0; i < vector1.size(); i++){
   vec.erase(std::remove(vec.begin(), vec.end(), vector1[i]), vec.end()); 
  }
  return vec;
}

void printTable(const std::vector<char> &alphabet,std::vector<State>& states){
  std::string line ="|\t|";
  for(int i=0; i < alphabet.size(); i++){
    line+= "\t";
    line+= alphabet[i];
    line+= "\t|";
  }
  line += "\tε\t|";
  std::cout << line << std::endl;

  for(int i=0; i < states.size(); i++){
    line = "|   ";
    if(states[i].getInitial())
      line += "→";
    line += std::to_string(states[i].getNumber());
    if(states[i].getAccepted())
      line += "*";
    line += "\t|";
    for (int j = 0; j < alphabet.size(); j++){
      line += "\t" + states[i].getNextState(alphabet[j]) + "\t|";
    }
    line += "\t" + states[i].getNextState('E') + "\t|";
    std::cout << line << std::endl;
  }

}


int getNumberOfInitialState(std::vector<State> &states){
  int aux =1, i =0, number;
  do{
    if(states[i].getInitial()){
      number = i;
      aux = false;
    }
  } while (aux);
  return number;
}

int getNumberOfState(std::vector<State> &states, int state){
  int aux =1, i =0, number;
  do{
    if(states[i].getNumber() == state){
      number = i;
      aux = false;
    }
  } while (aux);
  return number;
}