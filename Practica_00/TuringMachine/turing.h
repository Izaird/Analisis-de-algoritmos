#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

struct Transition{
    char event;
    char new_event;
    bool direction;//0=Left and 1=Rigth
    int next_state;
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
    std::string getTape();
    char read();
    void update(char new_event);
    void move(bool direction);
};

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
//write a string into the document
void writeDoc(std::string s, std::fstream &myfile);
void travel(int actual_state, int next_state, char tape_actual_char, Tape &tape, std::vector<State> &states);
void travel_r(int actual_state, int next_state, char tape_actual_char, Tape &tape, std::vector<State> &states);
