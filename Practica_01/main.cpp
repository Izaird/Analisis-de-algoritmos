#include "cellular_automaton.h"

int main(){
    int rule, size_of_l;
    std::fstream myfile; 
    myfile.open("output.txt", std::ofstream::out | std::ofstream::trunc);//I clear the document
    Tape tape;
    TruthTable table;
    myfile.close();

    do{
        std::cout << "Enter the rule you want, example: 244"<<std::endl;
        std::cin>>rule;
        table.fill(rule);
        std::cout << "Enter the size of the bit array(L)"<<std::endl;
        std::cin>>size_of_l;
        tape.fill(size_of_l);
    }while(true);

    return 0;
}