#include "cellular_turing.h"
#include "color.h"


int main(int argc, char const *argv[]){
    std::vector<State> states;
    // std::vector<char> test= {'_','a','a','a','b','b','b','_'};
    char event, tape_actual_char;
    int actual_state, next_state,rule,size_of_L,repetitions;
    std::fstream myfile; 
    std::string cellular_answer, turing_answer;

    states= createStates();
    std::cout << FGRN("Insert the tape: ") << std::endl;

    actual_state = getInitialState(states);
    myfile.open("output", std::ofstream::out | std::ofstream::trunc);//I clear the document
    CellularTape tape_c;
    TruthTable table;
    std::cout << "Enter the rule you want, example: 244"<<std::endl;
    std::cin>>rule;
    table.fill(rule);
    std::cout << "Enter the size of the bit array(L)"<<std::endl;
    std::cin>>size_of_L;
    std::cout << "Enter the number of repetitions"<<std::endl;
    std::cin>>repetitions;
    tape_c.fillOneBit(size_of_L);
    cellular_answer = runCellular(tape_c,table,rule,repetitions,myfile);
    std::cout << cellular_answer << std::endl;

    
    do{
        TuringTape tape_t(getString(cellular_answer));
        turing_answer = travel(actual_state,next_state,tape_actual_char,tape_t,states);
        tape_c.fillStr(turing_answer);
        cellular_answer = runCellular(tape_c,table,rule,repetitions,myfile);
    }while(true);
    
    
    myfile.close();

    return 0;
}



std::string travel(int actual_state, int next_state, char tape_actual_char, TuringTape &tape, std::vector<State> &states){
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
    return tape.getTape();

}

std::string runCellular(CellularTape &tape, TruthTable &table, int rule, int repetitions, std::fstream &myfile){
    std::vector<bool> aux_tape;
    std::string string;
    for(int i=0; i<repetitions;i++){
        for(int j=0; j<tape.size(); j++){
            aux_tape.push_back(table.getCase(tape.read()));
            tape.move();
        }
        writeDoc(tape.print(), myfile);
        string = tape.print();
        tape.update(aux_tape);
        aux_tape.clear();
    }
    
    return string;
}