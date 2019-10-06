#include "cellular_automaton.h"

Tape::Tape(){
    tape_head=0;
    tape.clear();
}

std::vector<bool> Tape::read(){
    std::vector<bool> a;
    if(tape_head == 0){//the tape it's like a torid 
        a.push_back(tape[tape.size()-1]);
        a.push_back(tape[0]);
        a.push_back(tape[1]);
    }
    else if(tape_head==tape.size()-1){
        a.push_back(tape[tape.size()-2]);
        a.push_back(tape[tape.size()-1]);
        a.push_back(tape[0]);
    }
    else{
        a.push_back(tape[tape_head-1]);
        a.push_back(tape[tape_head]);
        a.push_back(tape[tape_head+1]);
    }
    return a;
}

void Tape::update(bool new_element){
    tape[tape_head]=new_element;
}

void Tape::move(){
    if(tape_head == tape.size()-1)
        tape_head =0;
    else
        tape_head++;
}

void Tape::fill(int size){
    tape.clear();
    do{
        if(size < 3){
            std::cout << "Must be a value greater than 3" <<std::endl;
            std::cout << "try again:" <<std::endl;
            std::cin >> size;
        }
        else
            break;
    }while(true);
    double p = 0.5;
    std::random_device rd;
    std::mt19937 gen( rd());
    std::bernoulli_distribution d(p);
    tape.reserve(size-1);
    for(unsigned i=0; i<size; ++i)
            tape.push_back( d(gen));
}

std::string Tape::print(){
    std::string string;
    for(std::vector<bool>::iterator iter = tape.begin(); iter != tape.end(); ++iter){
        if(*iter)
            string += '#';
        else
            string += ' ';
    }
    return string;
}


void writeDoc(std::string s, std::fstream &myfile){
    myfile << s << std::endl;
}
