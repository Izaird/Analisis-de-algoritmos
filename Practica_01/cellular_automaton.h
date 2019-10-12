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
    int read();//return an array with the tape_head element, the previous and the next element
    void update(std::vector<bool> &new_tape);
    void move();//move the tape_head one spot
    //Fill the vector with random numbers
    void fill(int size);
    //Fill the vector only with 1 bit at the center of the vector
    void fillOneBit(int size);
    //Fill the vector with a string 
    void fillStr(std::string string);    std::string print();
    int size();
};

class TruthTable{
private:
    bool cases[8];
public:
    TruthTable();
    void fill(int rule);
    bool getCase(int a);

};

void writeDoc(std::string s, std::fstream &myfile);