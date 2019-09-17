#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
struct transition{
  std::string actual_state,event,next_state;
};

std::ostream& operator<<(std::ostream& stream, const transition& transition){
  stream << transition.actual_state << ","<< transition.event << "," << transition.next_state;
  return stream;
}

//DECLARATIONS
std::vector<std::string> StringToVector(std::string str);
std::vector<std::string> GetLines(std::string file);//Save all the lines of the document in an arrangement to have better handling on these
std::vector<transition> ReadTransitions(const std::vector<std::string> &lines);

int main(){
  std::vector<std::string> lines, states, alphabet, start, accept;
  std::vector<transition> transitions;
  lines = GetLines("input");
  states = StringToVector(lines[0]);
  alphabet = StringToVector(lines[1]);
  start = StringToVector(lines[2]);
  accept = StringToVector(lines[3]);
  transitions = ReadTransitions(lines);
  for (transition& T : transitions)
  {
    std::cout << T << std::endl;
  }
  

}


//DEFINITIONS 
std::vector<std::string> GetLines(std::string name_file){
  std::vector<std::string> Lines;
  std::string line;
  std::fstream file;
  file.open(name_file);
  while (getline(file, line)){
    Lines.push_back(line);
  }
  return Lines;
}

std::vector<std::string> StringToVector(std::string str){
  std::vector<std::string> vect;
  std::string aux;
  for(int i=0; i < str.length(); i++){
    if(str[i]==44){
      vect.push_back(aux);
      aux.clear();
    }
    else
      aux += str[i];
  }
  vect.push_back(aux);
  aux.clear();

  return vect;
}

std::vector<transition> ReadTransitions(const std::vector<std::string> &lines){
  std::vector<transition> transitions;//array to save the transitions 
  std::string A,B,C,aux;
  std::stringstream ss;

  for(int i= 4; i < lines.size(); i++){
    aux = lines[i];
    std::stringstream ss(aux);
    getline(ss,aux, ',');
    A=aux;
    getline(ss,aux, ',');
    B=aux;
    getline(ss,aux, ',');
    C=aux;  
    transitions.push_back({A, B, C});
  }
  return transitions;
}

