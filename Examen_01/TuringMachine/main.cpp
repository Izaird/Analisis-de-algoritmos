#include "turing.h"
#include "color.h"

int main(){
    std::vector<State> states;
    // std::vector<char> test= {'_','a','a','a','b','b','b','_'};
    char event, tape_actual_char;
    int actual_state, next_state;

    states= createStates();
    std::cout << FGRN("Insert the tape: ") << std::endl;
    Tape tape(getString());

    actual_state = getInitialState(states);

    // travel_r(actual_state,next_state,tape_actual_char,tape,states);
    travel(actual_state,next_state,tape_actual_char,tape,states);


    return 0;
}


void travel(int actual_state, int next_state, char tape_actual_char, Tape &tape, std::vector<State> &states){
    std::string path;
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
}


void travel_r(int actual_state, int next_state, char tape_actual_char, Tape &tape, std::vector<State> &states){
    if(states[actual_state].getAcceptance()){
        std::cout << "string accepted" << std::endl;
    }
    else if(actual_state == -1){
        std::cout << "string rejected" << std::endl;
    }
    else{
    tape_actual_char = tape.read();
    next_state = states[actual_state].getNextState(tape_actual_char);
    tape.update(states[actual_state].getNewEvent(tape_actual_char));
    tape.move(states[actual_state].getDirection(tape_actual_char));
    actual_state = next_state;
    travel_r(actual_state,next_state,tape_actual_char,tape,states);
    }
}