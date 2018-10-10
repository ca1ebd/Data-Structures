#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab 3 - Queues        

    author: 

    last modified: 9/7/2017
*/

#include <cstdlib>
#include <iostream>
#include "Queue.cpp"
using namespace std;

class Queue {
    public:
        // max elements in queue
        static const size_t ARRAY_SZ = 5;

        Queue() { ; }

        bool enqueue(char c) {
            if(_size == ARRAY_SZ){
                //printArray();
                return false;
            }
            else{
                _data[_back] = c;
                _back++;
                _back%=ARRAY_SZ+1;
                _size++;
                //printArray();
                return true;
            }
        }

        bool dequeue(){
            if(_size==0){
                return false;
            }
            else{
                _front++;
                _front%=ARRAY_SZ+1;
                _size--;
                return true;
            }
        }
        char front(){return _data[_front];}
        bool is_empty() { return _size == 0; }
        void printArray() {
            for(int i=0; i<ARRAY_SZ; i++){
                cout << _data[i] << " ";
            }
            cout << endl;
        }

    private:
        char _data[ARRAY_SZ];
        int _front = 0;
        int _back = 0;
        int _size = 0;
};

#endif
