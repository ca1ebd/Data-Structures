#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab 10 - queue2        

    author: 

    last modified: 3/15/2018
*/

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
	    _data = new char[_capacity];
	}

    // enqueue: add a char to the end of the queue if room and return true;
    // if not enough room, return false
	bool enqueue(char c) {
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
	char front()    { return _data[_front]; }

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _size == 0; }

	int get_capacity() { return _capacity; }

	void set_capacity(int capacity) { _capacity = capacity; }

private:
	char* _data;
    int  _size;
	int  _front;
	int  _back;
	int _capacity;
    void _resize(){

        //int new_front = 0;
        char* new_arr = new char[_capacity*2];
        for (int i = _front; i < _front + _size; ++i) {
            new_arr[i] = _data[(_front+i)%_capacity];
        }
        delete[] _data;
        _capacity *= 2;
        _data = new_arr;
        _front = 0;
        _back = _front + _size;
    }
	
};

#endif
