#ifndef _Queue_h
#define _Queue_h

#include <iostream>
using namespace std;
/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab 10 - queue2        

    author: 

    last modified: 3/15/2018
*/
template <class T>
class Queue {
public:
	// max elements in queue
	//static const size_t ARRAY_SZ = 5;

    // constructor
	Queue() {
	    _front = 0;
	    _back = 0;
	    _size = 0;
	    _capacity = 1;
	    _data = new T[_capacity];
	}

	Queue(const Queue& q) {
	    _front = q._front;
	    _back = q._back;
	    _size = q._size;
	    _capacity = q._capacity;
	    _data = new T[_capacity];
	    for(int i=0; i<_size; i++){
	        _data[i] = q._data[i];
	    }
	}

	~Queue() { delete _data; }

	Queue& operator=(const Queue& q){
        if(this == &q) { return *this; }
        delete _data;
        _capacity = q._capacity;
        _size = q._size;
        _front = q._front;
        _back = q._back;
        _data = new T[_capacity];
        for(int i=0; i<_size; i++){
            _data[i] = q._data[i];
        }
        return *this;
	}

    // enqueue: add a char to the end of the queue if room and return true;
    // if not enough room, return false
	bool enqueue(T c) {
        if (_size == _capacity) {
            _resize();
        }
		_data[_back] = c;
		_back = (_back + 1) % _capacity;
        _size++;
		return true;
	}
		
    // dequeue: if queue is not empty, remove the front element from the queue;
    // if queue is empty, return false and do nothing.
	bool dequeue()  { 
		if (is_empty()) return false;
		_front = (_front + 1) % _capacity;
        _size--;
		return true;
	}
	
    // front: return the front element in the queue
	T front()    { return _data[_front]; }

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _size == 0; }

	int get_capacity() { return _capacity; }

	int get_size() { return _size; }

	void set_capacity(int capacity) { _capacity = capacity; }
	int get_back() { return _back; }

	T* get_data() { return _data; }

	int get_front() { return _front; }

private:
	T* _data;
    int  _size;
	int  _front;
	int  _back;
	int _capacity;
    void _resize(){
        cout << "Resizing" << endl;
        //int new_front = 0;
        T* new_arr = new T[_capacity*2];

        for (int i = _front; i < _front + _size; ++i) {
            new_arr[i] = _data[(_front+i)%_capacity];
        }
        //delete[] _data;
        T* prev_data = _data;
        _capacity *= 2;
        _data = new_arr;
        _front = 0;
        _back = _front + _size;
    }
	
};

#endif
