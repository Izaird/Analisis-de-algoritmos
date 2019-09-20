#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

struct transition{
  std::string event;  
  int next_state;

  transition(std::string a, int b){
  event = a;
  next_state = b;
  }
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
  std::vector<std::string> getEventsOfTransitions();
  std::vector<transition> getTransitions();
  int numberOfTransitions();
};


/*
DECLARETIONS
*/
void uniqueElements(std::vector<std::string>& vec);
transition stringToTransition(int i, const std::vector<std::string>& lines);
int getFirstElement(std::string line);
void fillStates(std::vector<State> &obj_states, const std::vector<std::string>& alphabet);
std::vector<std::string> StrToVectStr(std::string str);
std::vector<int> StrToVectInt(std::string str);
std::vector<std::string> GetLines(std::string file);//Save all the lines of the document in an arrangement to have better handling on these
std::vector<std::string> subVectorfromVector(std::vector<std::string> &vector1, const std::vector<std::string> &vector2);
void printTable(const std::vector<std::string>& alphabet,std::vector<State>& states);