#include "cellular_automaton.h"

int main(){
    std::fstream myfile; 
    myfile.open("output.txt", std::ofstream::out | std::ofstream::trunc);//I clear the document
    Tape tape;
    tape.fill(10);
    for(int i =0; i < 4; i++)
    writeDoc(tape.print(),myfile);

    myfile.close();

    return 0;
}