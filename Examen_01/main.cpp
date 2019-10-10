#include "cellular_turing.h"

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


int main(int argc, char const *argv[]){
    int rule,size_of_L,repetitions;
    std::fstream myfile; 
    std::string cellular_answer;
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
    myfile.close();

    return 0;
}

