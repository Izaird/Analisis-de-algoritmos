#include "automata.h"


int main(){
  std::vector<int> states, initial_state, acceptance_states;
  std::vector<std::string> lines, alphabet;
  std::vector<transition> all_transitions;
  std::vector<State> obj_states;
  std::vector<transition> aux;
  lines = GetLines("inputs/input3");
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
  printTable(alphabet,obj_states);
  return 0;
}




