#include "turing.h"
#include "color.h"

int main(){
    std::vector<State> states;
    std::string path;
    // std::vector<char> test= {'_','a','a','a','b','b','b','_'};
    char event, tape_actual_char;
    int actual_state, next_state;

    states= createStates();
    std::cout << FGRN("Insert the tape: ") << std::endl;
    Tape tape(getString());

    actual_state = getInitialState(states);

    do{
        tape_actual_char = tape.read();
        next_state = states[actual_state].getNextState(tape_actual_char);
        tape.update(states[actual_state].getNewEvent(tape_actual_char));
        tape.move(states[actual_state].getDirection(tape_actual_char));
        path += std::to_string(actual_state ) + '(' + tape_actual_char + ')' ;
        actual_state = next_state;
        if(states[actual_state].getAcceptance()){
            std::cout << "String accepted" << std::endl;
            std::cout << path << std::endl;
            break;
        }
        else if(actual_state == -1){
            std::cout << "String rejected" << std::endl;
            std::cout << path << std::endl;
            break;
        }
        else
            path += "\u2192";
    }while(true);

    return 0;
}