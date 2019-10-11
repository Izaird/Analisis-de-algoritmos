#include <iostream>
#include <vector>
#include <random>
#include <fstream> 
#include <bitset>
#include <algorithm>
#include <sstream>
//Structure to store a single transition
struct Transition{
    char event;
    char new_event;
    //0=Left and 1=Rigth
    bool direction;
    int next_state;
};

//Class to store the bit string
class CellularTape{
private:
    std::vector<bool> tape;
    int tape_head;
public:
    CellularTape();
    //return an array with the tape_head element, the previous and the next element
    int read();
    //Changes the symbol of the current tape head
    void update(std::vector<bool> &new_tape);
    //move the tape_head one spot
    void move();
    //Fill the vector with random numbers
    void fill(int size);
    //Fill the vector only with 1 bit at the center of the vector
    void fillOneBit(int size);
    //Fill the vector with a string 
    void fillStr(std::string string);
    //Return the tape as a string
    std::string print();
    //return the size of the tape
    int size();
};

//Class Truth table
class TruthTable{
private:
    bool cases[8];
public:
    //Constructor of the class
    TruthTable();
    //Fill the truth table with the respective rule
    void fill(int rule);
    //Return the case of the truth table
    bool getCase(int a);
};

//Class to store all the states of the turing machine
class State{
private:
    bool initial, acceptance;
    int number;
    std::vector<Transition> transitions;
public:
    State(int a, bool b, bool c);
    void pushTransition(Transition transition);
    int getNumber();
    bool getInitial();
    bool getAcceptance();
    std::vector<Transition> getTransitions();
    std::vector<char> getEventsOfTransitions();
    Transition getTransition(char event);
    char getNewEvent(char event);
    bool getDirection(char event);
    int getNextState(char event);


};

//Class to store the turing tape 
class TuringTape{
private:
    std::vector<char> tape;
    int tape_head;
public:
    TuringTape(std::vector<char> a);
    std::string getTape();
    char read();
    void update(char new_event);
    void move(bool direction);
};


void writeDoc(std::string s, std::fstream &myfile);
std::vector<State> createStates();
std::vector<std::string> GetLines(std::string name_file);
std::vector<int> strToVecInt(std::string str);
std::vector<char> strToVecChar(std::string str);
Transition strToTransition(std::string string);
std::vector<char> vecMinusVec(std::vector<char> &vector1, const std::vector<char> &vector2);
int getNumberOfState(std::vector<State> &states, int state);
void fillStates(std::vector<State> &states, const std::vector<char>& alphabet);
int getFirstElement(std::string line);
std::vector<char> getString(std::string string);
int getInitialState(std::vector<State> &states);//Return the 
std::string travel(int actual_state, int next_state, char tape_actual_char, TuringTape &tape, std::vector<State> &states);
std::string runCellular(CellularTape &tape, TruthTable &table, int rule, int repetitions, std::fstream &myfile);
