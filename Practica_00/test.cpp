 
#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{
    int count = 0;
    string line;
 
    /* Creating input filestream */ 
    ifstream file("input.txt");
    while (getline(file, line))
        count++;
 
    cout << "Numbers of lines in the file : " << count << endl;
    return 0;
}