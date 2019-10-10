#include "cellular_automaton.h"

int main(){
    int rule, size_of_l,repetitions;
    std::fstream myfile; 
    std::vector<bool> aux_tape;
    myfile.open("output.txt", std::ofstream::out | std::ofstream::trunc);//I clear the document
    Tape tape;
    TruthTable table;

    // do{
        std::cout << "Enter the rule you want, example: 244"<<std::endl;
        std::cin>>rule;
        table.fill(rule);
        std::cout << "Enter the size of the bit array(L)"<<std::endl;
        std::cin>>size_of_l;
        std::cout << "Enter the number of repetitions"<<std::endl;
        std::cin>>repetitions;
        tape.fill(size_of_l);
        for(int i=0; i<repetitions;i++){
            for(int j=0; j<tape.size(); j++){
                aux_tape.push_back(table.getCase(tape.read()));
                tape.move();
            }
            writeDoc(tape.print(), myfile);
            tape.update(aux_tape);
            aux_tape.clear();
        }
    // }while(true);
    myfile.close();

    return 0;
}