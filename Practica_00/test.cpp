#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>


class Animal{
private:
    std::string name;
    double height;
    double weight;
    static int numOfAnimals;//its gonna be the same for all the objects 


public:
    std::string GetName(){
        return name;
    }
    void SetName(std::string name){
        this->name = name;
    }


};

int main(){
    return 0;
}