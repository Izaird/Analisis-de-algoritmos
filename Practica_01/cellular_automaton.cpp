#include "cellular_automaton.h"

Tape::Tape(){
    tape_head=0;
    tape.clear();
}

int Tape::read(){
    std::vector<bool> a;
    int aux;
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

    aux = a[0]*4 + a[1]*2 + a[2];
    return aux;
}

void Tape::update(std::vector<bool> &new_tape){
    tape=new_tape;
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

void Tape::fillOneBit(int size){
    tape.clear();
    for (int i = 0; i < size; i++)
        tape.push_back(0);
    int aux = size/2;
    tape.at(aux) = 1;
}

void Tape::fillStr(std::string string){
    tape.clear();
    for (int i = 0; i < string.size(); i++){
        if(string[i]=='1')
            tape.push_back(1);
        else
            tape.push_back(0);
    }
    
}

std::string Tape::print(){
    std::string string;
    for(std::vector<bool>::iterator iter = tape.begin(); iter != tape.end(); ++iter){
        if(*iter)
            string += "\u25A0";
        else
            string += ' ';
    }
    return string;
}

int Tape::size(){
    return tape.size();
}

TruthTable::TruthTable(){}

void TruthTable::fill(int rule){
    do{
        if(rule>255 || rule<0){
            std::cout << "Only 0 to 255" <<std::endl;
            std::cout << "try again:" <<std::endl;
            std::cin >> rule;
        }
        else
            break;
    }while(true);
    std::string binary = std::bitset<8>(rule).to_string(); //to binary
    for(int i=0; i<8; i++){
        if (binary[7-i] == '1')
            cases[i] = 1;
        else
            cases[i] = 0;
    }
}

bool TruthTable::getCase(int a){
    return cases[a];
}

void writeDoc(std::string s, std::fstream &myfile){
    myfile << s << std::endl;
}
