#include <iostream>
#include <vector>
#include <random>
#include <fstream> 
#include <bitset>


class Tape{//Class to store the bit string
private:
    std::vector<bool> tape;
    int tape_head;
public:
    Tape();
    std::vector<bool> read();//return an array with the tape_head element, the previous and the next element
    void update(bool new_element);
    void move();//move the tape_head one spot
    void fill(int size);//It's gonna fill the vector with random numbers 
    std::string print();
};

class TruthTable{
private:
    bool cases[8];
public:
    TruthTable();
    void fill(int rule);
};

void writeDoc(std::string s, std::fstream &myfile);