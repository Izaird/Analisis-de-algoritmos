#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct Transition{
    char event;
    char new_event;
    char direction;
    int next_state;
};

class State{
private:
    bool initial, acceptance;
    int number;
    std::vector<Transition> transitions;
public:
    State(int a, bool b, bool c);
    void addTransition(Transition transition);
    int getNumber();
    bool getInitial();
    bool getAcceptance();
    std::vector<Transition> getTransitions();
    int getNextState(char event);
};

std::vector<State> createStates();
std::vector<std::string> GetLines(std::string name_file);
std::vector<int> strToVecInt(std::string str);
std::vector<char> strToVecChar(std::string str);

