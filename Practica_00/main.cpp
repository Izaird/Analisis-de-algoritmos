#include "automata.h"



int main(){
  std::vector<int> states_str, initial_state, acceptance_states;
  std::vector<std::string> lines;
  std::vector<char> alphabet;
  std::vector<transition> all_transitions;
  std::vector<State> states;
  std::vector<transition> aux;
  lines = GetLines("inputs/input");
  states_str = StrToVectInt(lines[0]);
  states_str.push_back(-1);
  alphabet = StrToVectChar(lines[1]);
  initial_state = StrToVectInt(lines[2]);
  acceptance_states = StrToVectInt(lines[3]);


  for(int i=0; i<states_str.size(); i++){
    bool initial, final;
    if(std::find(initial_state.begin(), initial_state.end(), states_str[i]) != initial_state.end())
      initial = true;
    else
      initial = false;   

    if(std::find(acceptance_states.begin(), acceptance_states.end(), states_str[i]) != acceptance_states.end())
      final = true;
    else
      final = false;
  State state;
  state.setState(states_str[i],initial,final);
  states.push_back(state);
  }

  for(int i=4; i < lines.size(); i++){
    bool found = true;
    std::string event;
    transition aux();
    int j=0, next_state=0;
      while(found){
        if(getFirstElement(lines[i]) == states[j].getNumber()){
          states[j].setTransition(stringToTransition(i,lines));
          j=0;
          found =false;
        }
        else
          j++;
      }
  }
  
  fillStates(states,alphabet);
  printTable(alphabet,states);



  std::string string = "bba";
  std::vector<int> path,valid;
  int initial = getNumberOfInitialState(states);
  path.clear();
  valid.clear();
  travel(states, alphabet, initial ,string, path, string, valid);
  return 0;
}




void travel(std::vector<State>& states, std::vector<char>& alphabet,int actual_state, std::string string, std::vector<int> path, std::string original_str, std::vector<int> valid){
  std::vector<int> temp_path = path;
  if (states[actual_state].getNumber()!= -1){
    if(string.empty()){
      if(states[actual_state].getAccepted() == true){
        valid.push_back(1);
        temp_path = path;
        temp_path.push_back(states[actual_state].getNumber());
        showPath(temp_path);
      }
    }
    else{
      if(std::find(alphabet.begin(), alphabet.end(), string[0])!=alphabet.end() == false){
        temp_path = path;
        temp_path.push_back(-2);
        travel(states, alphabet, actual_state, string.substr(1),temp_path, original_str, valid);
      }
      else{
        std::string temp_string = string;
        for(int i = 0; i < states[actual_state].numberOfTransitions(); i++){
          if(states[actual_state].getEventOfTransition(i) == string[0]){
            temp_path = path;
            temp_path.push_back(actual_state);  
            travel(states, alphabet,states[actual_state].getNextStateOfTransition(i), temp_string.substr(1),temp_path, original_str, valid);
          }
        }
      }
    }
  }
}


void showPath(std::vector<int> path){
  for (int i = 0; i < path.size(); i++){
    std::cout << path[i];
  }
  
}