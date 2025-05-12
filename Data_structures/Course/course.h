#include <iostream>
#include "student.h"
#include <cmath>
class Course{
    student** students;
    int size;
    int capacity;

    public: 
    Course(){
        size=0;
        capacity = 5;

        students = (student**)malloc(capacity * sizeof(student*));

    }


    void addstudent(student* s){
        if(size == capacity){
            capacity = ceil(capacity * 1.5);

            students = (student**)realloc(students, capacity * sizeof(student*));

        }
        // if(size != 0){
        //     for(int i=0; i<size;i++){
        //         if(students[i]->grade < s->grade ){
        //             for(int j=size; j>i; j--){
        //                 students[j] = students[j-1];
        //             }
        //             students[i] = s;
        //             size++;
        //             return;        
        //         }
        //     }
        // }

        cout << "Adding" << endl;
        students[size++] = s; 

    }


    void addAt(int index, student* rawr){

        if(size >= capacity){
            capacity = ceil(capacity * 1.5);
            students = (student**)realloc(students, sizeof(student*) * capacity);

        }

        for(int i=size-1; i>=index; i--){
            students[i+1] = students[i];
        }

        students[index] = rawr;
        size++;

    }


    void print() {
    cout << size << "/" << capacity << endl;

    for (int i = 0; i < size; i++) {
        if (students[i] != nullptr) { // Check if the pointer is valid
            cout << i + 1 << ". " << students[i]->name << " " << students[i]->grade << endl;
        } else {
            cout << i + 1 << ". Invalid student entry (null)" << endl;
        }
    }
}

    int removestudent(student* s){

        for(int i=0;i<size;i++){

            if(s->name == students[i]->name){
                for(int j=i;j<size-1;j++){
                    students[j] = students[j+1];
                }
                size--;
                if(size <= capacity * (2.0/3.0)){
                    capacity = floor(capacity * 0.75);
                    if(capacity > 5){
                      students = (student**)realloc(students,sizeof(student*) * capacity);
                    }else{
                        capacity = 5; 
                    }
                }
            }
        }
    }

    student* removeAt(int index){
        
        student* helo = new student;
        helo = students[index];  
        //free(students[index]); dont uncomment it will lead to segfault!
        for(int i=index; i<size; i++){
            students[i] = students[i+1];
        }
        size--; 
        if(size <= capacity * (2.0/3.0)){
            if(capacity > 5){
                capacity = capacity * 0.75;
                students = (student**)realloc(students, capacity * sizeof(student*)); 
            }
        }

        return helo;
    }

    void topStudents(int n){
        if(n > size){ 
            cout <<"Out of bounds!";
            return; 
            }
        for(int i=0; i<n;i++){
            cout << i+1 <<". "<<students[i]->name << " " << students[i]->grade << endl; 
        }
        
    }


    void sort(){

        for(int i=0;i<size-1;i++){
            for(int j=0; j<size-i-1;j++){
                if(students[j]->grade < students[j+1]->grade){
                    student* temp = students[j];
                    students[j] = students[j+1];
                    students[j+1]= temp;
                }
            }
        }
    }

};