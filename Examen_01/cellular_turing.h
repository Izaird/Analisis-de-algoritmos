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
    int read();//return an array with the tape_head element, the previous and the next element
    void update(std::vector<bool> &new_tape);
    void move();//move the tape_head one spot
    void fill(int size);//It's gonna fill the vector with random numbers 
    std::string print();
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

class Tape{
private:
    std::vector<char> tape;
    int tape_head;
public:
    Tape(std::vector<char> a);
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
std::vector<char> getString();
int getInitialState(std::vector<State> &states);//Return the 