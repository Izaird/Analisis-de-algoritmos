#include "cellular_automaton.h"

int main(){
    std::string turing_answer;
    Tape tape;
    TruthTable table;
    int rule =110, size_of_l=30,repetitions;
    // std::cout << "Enter the rule you want, example: 244"<<std::endl;
    // std::cin>>rule;
    table.fill(rule);
    // std::cout << "Enter the size of the bit array(L)"<<std::endl;
    // std::cin>>size_of_l;
    repetitions = 5;
    

    // SERVER
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0};

       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    }
    do{
    runAutomata(table,tape,rule,size_of_l,repetitions);
    std::string str = tape.print(); 
    const char *hello = str.c_str();
    valread = read( new_socket , buffer, 1024);
    turing_answer = buffer;
    tape.fillStr(turing_answer);
    printf("%s\n",buffer ); 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("message sent\n"); 
    }while(true);

    return 0;
}

void runAutomata(TruthTable &table, Tape &tape, int rule, int size_of_l, int repetitions){
    std::fstream myfile; 
    myfile.open("output.txt", std::ofstream::out | std::ofstream::trunc);//I clear the document
    std::vector<bool> aux_tape;
    tape.fill(size_of_l);
    for(int i=0; i<repetitions;i++){
        for(int j=0; j<tape.size(); j++){
            aux_tape.push_back(table.getCase(tape.read()));
            tape.move();
        }
        writeDoc(tape.print(), myfile);
        tape.update(aux_tape);
        aux_tape.clear();
    }
    myfile.close();
}