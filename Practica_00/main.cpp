#include <iostream>
#include <fstream>
using namespace std;


class Estado{
    private:
        int numero;
        int inicial;
        int final;
}

int main(){
  string line;
  ifstream myfile ("archivo.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}