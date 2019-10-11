#include "cellular_turing.h"
#include "color.h"

CellularTape::CellularTape(){
    tape_head=0;
    tape.clear();
}


int CellularTape::read(){
    std::vector<bool> a;
    int aux;
    if(tape_head == 0){//the tape it's like a torid 
        a.push_back(tape[tape.size()-1]);
        a.push_back(tape[0]);
        a.push_back(tape[1]);
    }
    else if(tape_head==tape.size()-1){
        a.push_back(tape[tape.size()-2]);
        a.push_back(tape[tape.size()-1]);
        a.push_back(tape[0]);
    }
    else{
        a.push_back(tape[tape_head-1]);
        a.push_back(tape[tape_head]);
        a.push_back(tape[tape_head+1]);
    }

    aux = a[0]*4 + a[1]*2 + a[2];
    return aux;
}

void CellularTape::update(std::vector<bool> &new_tape){
    tape=new_tape;
}

void CellularTape::move(){
    if(tape_head == tape.size()-1)
        tape_head =0;
    else
        tape_head++;
}

void CellularTape::fill(int size){
    tape.clear();
    do{
        if(size < 3){
            std::cout << "Must be a value greater than 3" <<std::endl;
            std::cout << "try again:" <<std::endl;
            std::cin >> size;
        }
        else
            break;
    }while(true);
    double p = 0.5;
    std::random_device rd;
    std::mt19937 gen( rd());
    std::bernoulli_distribution d(p);
    tape.reserve(size-1);
    for(unsigned i=0; i<size; ++i)
            tape.push_back( d(gen));
}

void CellularTape::fillOneBit(int size){
    tape.clear();
    for (int i = 0; i < size; i++)
        tape.push_back(0);
    int aux = size/2;
    tape.at(aux) = 1;
}

void CellularTape::fillStr(std::string string){
    tape.clear();
    for (int i = 0; i < string.size(); i++){
        if(string[i]=='1')
            tape.push_back(1);
        else
            tape.push_back(0);
    }
    
}
std::string CellularTape::print(){
    std::string string;
    for(std::vector<bool>::iterator iter = tape.begin(); iter != tape.end(); ++iter){
        if(*iter)
            string += '1';
        else
            string += '0';
    }
    return string;
}

int CellularTape::size(){
    return tape.size();
}

TruthTable::TruthTable(){}

void TruthTable::fill(int rule){
    do{
        if(rule>255 || rule<0){
            std::cout << "Only 0 to 255" <<std::endl;
            std::cout << "try again:" <<std::endl;
            std::cin >> rule;
        }
        else
            break;
    }while(true);
    std::string binary = std::bitset<8>(rule).to_string(); //to binary
    for(int i=0; i<8; i++){
        if (binary[7-i] == '1')
            cases[i] = 1;
        else
            cases[i] = 0;
    }
}


bool TruthTable::getCase(int a){
    return cases[a];
}

State::State(int a, bool b, bool c){
    number = a;
    initial = b;
    acceptance = c;
}

void State::pushTransition(Transition transition){
    transitions.push_back(transition);
}

int State::getNumber(){
    return number;
}

bool State::getInitial(){
    return initial;
}

bool State::getAcceptance(){
    return acceptance;
}

std::vector<Transition> State::getTransitions(){
    return transitions;
}

Transition State::getTransition(char event){
    Transition transition;
    for (int i = 0; i < transitions.size(); i++){
        if(transitions[i].event == event){
            transition = transitions[i];
            break; //End the loop
        }
    }
    return transition;
}

char State::getNewEvent(char event){
    Transition transition;
    transition = getTransition(event);
    return transition.new_event;
}

bool State::getDirection(char event){
    Transition transition;
    transition = getTransition(event);
    return transition.direction;
}

int State::getNextState(char event){
    Transition transition;
    transition = getTransition(event);
    return transition.next_state;
}

TuringTape::TuringTape(std::vector<char> a){
    tape = a;
    tape_head = 1;
}

std::string TuringTape::getTape(){
    std::vector<char> copy = tape;
    copy.erase(std::remove(copy.begin(), copy.end(), '_'), copy.end());
    std::string string(copy.begin(), copy.end());
    return string;
}

char TuringTape::read(){
    char event;
    event = tape[tape_head];
    return event;
}

void TuringTape::update(char new_event){
    tape[tape_head] = new_event;
}

void TuringTape::move(bool direction){
    if(direction){//True, move the tape_head one step RIGHT 
        if((tape.size()-1)==tape_head){//It means that we are at the end of the tape and we need to add a blank space
            tape.push_back('_');// and then move the tape_head
            tape_head++;
        }
        else
            tape_head++;
    }
    else{//False, move the tape_head one step LEFT
        if(tape_head == 0){
            tape.insert(tape.begin(), '_');//It means that we are at the begining of the tape and we need to add a blank space
            tape_head++;// and then move the tape_head
        }
        else
            tape_head--;

    }
}

std::vector<char> State::getEventsOfTransitions(){
    std::vector<char> events;
    for(int i = 0; i < transitions.size(); i++){
      events.push_back(transitions[i].event);
    }
    return events;
}

std::vector<std::string> GetLines(std::string name_file){
  std::vector<std::string> Lines;
  std::string line;
  std::fstream file;
  file.open(name_file);
  while (getline(file, line)){
    if(!line.empty() && line[0]!='#')
    Lines.push_back(line);
  }
  return Lines;
}

std::vector<int> strToVecInt(std::string str){
    std::vector<int> vec;
    std::string aux;
    int x;
    for(int i=0; i < str.length(); i++){
        if(str[i]!=44)
            aux += str[i];
        else{
            x = stoi(aux);
            vec.push_back(x);
            aux.clear();
        }
    }
    x = stoi(aux); 
    vec.push_back(x);
    return vec;
}

std::vector<char> strToVecChar(std::string str){
  std::vector<char> vec(str.begin(), str.end());
  for (int i = 0; i < vec.size(); i++){
    if(vec[i] == 44){
      vec.erase(vec.begin() + i);
    }
  }
  return vec;
}

Transition strToTransition(std::string string){
    int next_state;
    bool direction;
    char event, new_event;
    std::stringstream ss(string);
    getline(ss,string, ',');
    getline(ss,string, ',');
    event=string[0];
    getline(ss,string, ',');
    new_event=string[0];
    getline(ss,string, ',');
    if(string[0]=='l'||string[0]=='L')
        direction = false;
    else if(string[0]=='r'||string[0]=='R')
        direction = true;
    getline(ss,string, ',');
    next_state = std::stoi(string);    
    Transition transition({event,new_event,direction,next_state});
    return transition;
}

std::vector<State> createStates(){
    std::vector<std::string> lines;
    std::vector<int> states_doc, aux;
    std::vector<char> alphabet, alphabet_input, full_alphabet;
    std::vector<Transition> transitions_doc;
    std::vector<State> states;
    int initial_state, acceptance_state;
    lines = GetLines("input");
    states_doc = strToVecInt(lines[0]);
    states_doc.push_back(-1);
    alphabet = strToVecChar(lines[1]);
    alphabet_input = strToVecChar(lines[2]);
    full_alphabet = alphabet;
    full_alphabet.insert( full_alphabet.end(), alphabet_input.begin(), alphabet_input.end() );
    full_alphabet.push_back('_');
    aux = strToVecInt(lines[3]);
    if(aux.size()==1)
        initial_state = aux[0];
    else{
    std::cout << FRED("There can only be one initial state.") << std::endl;
    exit;    
    }
    aux.clear();
    aux = strToVecInt(lines[4]);
    if(aux.size()==1)
        acceptance_state = aux[0];
    else{
    std::cout << FRED("There can only be one acceptance state.") << std::endl;
    exit;
    }
    for(int i=0; i<states_doc.size(); i++){
        bool initial, final;
        if(initial_state == states_doc[i])
            initial = true;
        else
            initial = false;   

        if(acceptance_state == states_doc[i])
            final = true;
        else
            final = false;
        State state(states_doc[i],initial,final);
        states.push_back(state);
    }

    for(int i=5; i < lines.size(); i++){
    bool found = true;
    std::string event;
    Transition aux;
    int aux2;
    int j=0, next_state=0;
      while(found){
        if(getFirstElement(lines[i]) == states[j].getNumber()){
          aux = strToTransition(lines[i]);
          aux2 = getNumberOfState(states, aux.next_state);
          aux.next_state = aux2;
          states[j].pushTransition(aux);
          j=0;
          found =false;
        }
        else
          j++;
      }
  }
    fillStates(states,full_alphabet);

    return states;
}


int getNumberOfState(std::vector<State> &states, int state){
  bool aux = true;
  int i =0, number;
  do{
    if(states[i].getNumber() == state){
      number = i;
      aux = false;
    }
    i++;
  } while (aux);
  return number;
}

void fillStates(std::vector<State> &states, const std::vector<char>& alphabet){
    std::vector<char> events, missing_events;
    for (int i = 0; i < states.size(); i++){
    events = states[i].getEventsOfTransitions();
    missing_events = vecMinusVec(events,alphabet);
    for (int j = 0; j < missing_events.size(); j++){
        Transition transition_1({missing_events[j],'*',false,-1});
        states[i].pushTransition(transition_1);
    }
    }
}

std::vector<char> vecMinusVec(std::vector<char> &vector1, const std::vector<char> &vector2){
    std::vector<char> vec = vector2;
    for (int i = 0; i < vector1.size(); i++){
    vec.erase(std::remove(vec.begin(), vec.end(), vector1[i]), vec.end()); 
    }
    return vec;
}

int getFirstElement(std::string line){
    int x;
    std::stringstream ss(line);
    getline(ss,line, ',');
    x = std::stoi(line);
    return x;
}

std::vector<char> getString(std::string string){
    bool run = true;
    int count=0;
    std::vector<char> tape, alphabet;
    std::vector<std::string> lines;
    lines = GetLines("input");
    alphabet = strToVecChar(lines[1]);


    do{
        if(string.size()==1 && string[0]=='_'){
            tape.insert(tape.begin(),3,'_');
            break;
        }

        for (int i = 0; i < alphabet.size(); i++){
            size_t n = std::count(string.begin(), string.end(), alphabet[i]);
            count += n;
        }

        if(count == string.size()){//We need to verify if the string is composed of valid characters
            std::copy(string.begin(),string.end(), std::back_inserter(tape));
            tape.push_back('_');
            tape.insert(tape.begin(),'_');
            break;
        }

        else{
            std::cin >> string;
            std::cout<< FRED("String not accepted, try again") << std::endl;          
            count = 0;
        }


    }while(run);
    return tape;
}

int getInitialState(std::vector<State> &states){
    int i;
    for (i = 0; i < states.size(); i++)
        if(states[i].getInitial())
            break;
    return i;
}

void writeDoc(std::string s, std::fstream &myfile){
    myfile << s << std::endl;
}
