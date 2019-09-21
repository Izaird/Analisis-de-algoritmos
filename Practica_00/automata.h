#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

struct transition{
  char event;  
  int next_state;
};


/*
CLASSES
*/
class State{
private:
  bool initial, accepted;
  int number;
  std::vector<transition> transitions;
public:
  void setState(int a, bool b, bool c);
  void setTransition(transition transition);
  int getNumber();
  bool getInitial();
  bool getAccepted();
  std::vector<char> getEventsOfTransitions();
  std::vector<transition> getTransitions();
  std::string getNextState(char symbol);
  int numberOfTransitions();
  char getEventOfTransition(int transition);
  int getNextStateOfTransition(int num_transition);
};


/*
DECLARETIONS
*/
std::vector<std::string> GetLines(std::string name_file);
std::vector<char> StrToVectChar(std::string str);
std::vector<int> StrToVectInt(std::string str);
int getFirstElement(std::string line);
transition stringToTransition(int i, const std::vector<std::string>& lines);
void fillStates(std::vector<State> &obj_states, const std::vector<char>& alphabet);
void uniqueElements(std::vector<char>& vec);
std::vector<char> subVectorfromVector(std::vector<char> &vector1, const std::vector<char> &vector2);
void printTable(const std::vector<char> &alphabet,std::vector<State>& states);
void travel(std::vector<State>& states, std::vector<char>& alphabet,int actual_state, std::string string, std::vector<int> path, std::string original_str, std::vector<int> valid);
void showPath(std::vector<int> path);
int getNumberOfInitialState(std::vector<State> &states);//return the array number in which initial state is stored
int getNumberOfState(std::vector<State> &states, int state);//return the number of the arrangement in which the status is stored