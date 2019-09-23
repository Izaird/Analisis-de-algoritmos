#include "turing.h"
#include "color.h"

State::State(int a, bool b, bool c){
    number = a;
    initial = b;
    acceptance = c;
}

void State::addTransition(Transition transition){
    transitions.push_back(transition);
}

int State::getNumber(){
    return number;
}

bool State::getInitial(){
    return initial;
}

bool State::getAcceptance(){
    return acceptance;
}

std::vector<Transition> State::getTransitions(){
    return transitions;
}

int State::getNextState(char event){
    bool run = true;
    int i=0, aux;
    do{
        if(transitions[i].event ==event){
            run = false;
            aux = transitions[i].next_state;
        }
        i++;
    }while(run);
    return aux;
}

std::vector<std::string> GetLines(std::string name_file){
  std::vector<std::string> Lines;
  std::string line;
  std::fstream file;
  file.open(name_file);
  while (getline(file, line)){
    if(!line.empty() && line[0]!='#')
    Lines.push_back(line);
  }
  return Lines;
}

std::vector<int> strToVecInt(std::string str){
    std::vector<int> vec;
    std::string aux;
    int x;
    for(int i=0; i < str.length(); i++){
        if(str[i]!=44)
            aux += str[i];
        else{
            x = stoi(aux);
            vec.push_back(x);
            aux.clear();
        }
    }
    x = stoi(aux); 
    vec.push_back(x);
    return vec;
}

std::vector<char> strToVecChar(std::string str){
  std::vector<char> vec(str.begin(), str.end());
  for (int i = 0; i < vec.size(); i++){
    if(vec[i] == 44){
      vec.erase(vec.begin() + i);
    }
  }
  return vec;
}

std::vector<State> createStates(){
    std::vector<std::string> lines;
    std::vector<int> states_doc, aux;
    std::vector<char> alphabet;
    std::vector<Transition> transitions_doc;
    std::vector<State> states;
    int initial_state, acceptance_state;
    lines = GetLines("inputs/input");
    states_doc = strToVecInt(lines[0]);
    states_doc.push_back(-1);
    alphabet = strToVecChar(lines[1]);
    aux = strToVecInt(lines[2]);
    if(aux.size()==1)
        initial_state = aux[0];
    else{
    std::cout << FRED("There can only be one initial state.") << std::endl;
    exit;    
    }
    aux.clear();
    aux = strToVecInt(lines[3]);
    if(aux.size()==1)
        acceptance_state = aux[0];
    else{
    std::cout << FRED("There can only be one acceptance state.") << std::endl;
    exit;
    }


    for(int i=0; i<states_doc.size(); i++){
        bool initial, final;
        if(initial_state == states_doc[i])
            initial = true;
        else
            initial = false;   

        if(acceptance_state == states_doc[i])
            final = true;
        else
            final = false;
        State state(states_doc[i],initial,final);
        states.push_back(state);
    }
    return states;
}