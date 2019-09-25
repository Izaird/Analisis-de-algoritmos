#include "turing.h"
#include "color.h"

int main(){
    std::vector<State> states;
    char event;
    std::vector<char> prueba = {'_','a','b','_'};
    states= createStates();
    std::cout << FGRN("Insert the tape: ") << std::endl;
    Tape tape(prueba);
    tape.move(true);
    tape.move(true);
    tape.move(true);
    tape.move(true);
    tape.move(true);
    tape.move(true);
    tape.move(true);
    event = tape.read();
    tape.update('a');
    tape.move(true);
    tape.move(false);
    tape.move(false);
    tape.move(true);
    event = tape.read();
    tape.update('a');

    return 0;
}