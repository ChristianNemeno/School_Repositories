#ifndef NODE_H   // Start of the header guard
#define NODE_H
#include <iostream>
using namespace std;
struct Person{
    string firstName;
    string lastName;
    int age;
    int requests[4] = {0};

    void print(){
        cout << firstName << " " << lastName << "(" << age << ") - req ";
        char req[4] = {'B', 'M', 'C', 'D'};

        for(int i=0; i<4; i++){
            if(requests[i] == 1){
                cout << req[i] << " ";
            }
        }
        cout << endl;
    }

    int req_count(){
        int ctr=0;
        for(int i=0; i<4; i++){
            ctr += requests[i];
        }
        return ctr;
    }
};
struct node {
    Person* person;
    node* next;
    node* prev;
};


#endif  