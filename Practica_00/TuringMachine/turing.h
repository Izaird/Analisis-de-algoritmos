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
    int getNextState(char event);
    std::vector<char> getEventsOfTransitions();

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