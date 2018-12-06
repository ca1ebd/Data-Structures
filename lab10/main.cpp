/*
    tests.cpp

    Tests for the Queue class. 

    Code for CSCI 262 lab 6 - Queues

    Author: C. Painter-Wakefield
*/

#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

int NUM_PASSED = 0;

void test_true(bool expr, string desc);

/* 
   NOTE: Make sure your ARRAY_SZ constant in Queue.h is set such that your
   Queue has a capacity of exactly 5 elements.
*/

int main() {
    Queue<char> q;
    int number_of_queue = 3;

    for(int i=int('a'); i<'a' + number_of_queue; i++){
        cout << "Adding element " << char(i) << " to the q" << endl;
        q.enqueue(char(i));
    }

    cout << endl;
    while(!q.is_empty()){
        cout << "Dequeueing: " << q.front() << endl;
        q.dequeue();
    }

    cout << endl << "testing enqueing more objects to cause wraparound" << endl;
    char new_start = 'a'; // + number_of_queue;
    cout << "new start: " << new_start << endl;
    for(int i=new_start; i< new_start + number_of_queue*2; i++){
        cout << "Adding element " << char(i) << " to the q" << endl;
        q.enqueue(i);
    }

    cout << "Testing dequeuing after wraparound" << endl;
    while (!q.is_empty()){
        cout << "Dequeueing: " << q.front() << endl;
        q.dequeue();
    }

    cout << "Testing copy constructor" << endl;
    Queue<char> qu = q;
    cout << "old front: " << q.get_front() << " new front: " << qu.get_front() << endl;
    cout << "old back: " << q.get_back() << " new back: " << qu.get_back() << endl;
    cout << "old size: " << q.get_size() << " new size: " << qu.get_size() << endl;
    cout << "old capacity: " << q.get_capacity() << " new capacity: " << qu.get_capacity() << endl;
    cout << "old _data ptr: " << q.get_data() << " new _data ptr: " << qu.get_data() << endl;

    Queue<char> b;
    cout << endl << "Testing assignment operator" << endl;
    q = b;
    cout << "old front: " << qu.get_front() << " new front: " << q.get_front() << endl;
    cout << "old back: " << qu.get_back() << " new back: " << q.get_back() << endl;
    cout << "old size: " << qu.get_size() << " new size: " << q.get_size() << endl;
    cout << "old capacity: " << qu.get_capacity() << " new capacity: " << q.get_capacity() << endl;
    cout << "old _data ptr: " << qu.get_data() << " new _data ptr: " << q.get_data() << endl;
    //
    //
    //
    cout << endl << "Now trying with integers" << endl;

    Queue<int> q2;
    for(int i=int('a'); i<'a' + number_of_queue; i++){
        cout << "Adding element " << i << " to the q" << endl;
        q2.enqueue(i);
    }

    cout << endl;
    while(!q2.is_empty()){
        cout << "Dequeueing: " << q2.front() << endl;
        q2.dequeue();
    }

    cout << endl << "testing enqueing more objects to cause wraparound" << endl;
    cout << "new start: " << new_start << endl;
    for(int i=new_start; i< new_start + number_of_queue*2; i++){
        cout << "Adding element " << i << " to the q" << endl;
        q2.enqueue(i);
    }

    cout << "Testing dequeuing after wraparound" << endl;
    while (!q2.is_empty()){
        cout << "Dequeueing: " << q2.front() << endl;
        q2.dequeue();
    }

    cout << "Testing copy constructor" << endl;
    Queue<int> qu2 = q2;
    cout << "old front: " << q2.get_front() << " new front: " << qu2.get_front() << endl;
    cout << "old back: " << q2.get_back() << " new back: " << qu2.get_back() << endl;
    cout << "old size: " << q2.get_size() << " new size: " << qu2.get_size() << endl;
    cout << "old capacity: " << q2.get_capacity() << " new capacity: " << qu2.get_capacity() << endl;
    cout << "old _data ptr: " << q2.get_data() << " new _data ptr: " << qu2.get_data() << endl;

    Queue<int> b2;
    cout << endl << "Testing assignment operator" << endl;
    q2 = b2;
    cout << "old front: " << qu2.get_front() << " new front: " << q2.get_front() << endl;
    cout << "old back: " << qu2.get_back() << " new back: " << q2.get_back() << endl;
    cout << "old size: " << qu2.get_size() << " new size: " << q2.get_size() << endl;
    cout << "old capacity: " << qu2.get_capacity() << " new capacity: " << q2.get_capacity() << endl;
    cout << "old _data ptr: " << qu2.get_data() << " new _data ptr: " << q2.get_data() << endl;


    // constructor test
//    test_true(q.is_empty(), "Queue is initially empty.");
//
//    // single element tests
//    test_true(q.enqueue('x'), "Queue reports true on successful enqueueing.");
//    test_true(!q.is_empty(), "Queue is not empty after enqueueing.");
//    test_true(q.front() == 'x', "Queue front element is the element enqueued.");
//    test_true(q.dequeue(), "Queue reports true on successful dequeuing.");
//    test_true(q.is_empty(), "Queue is empty after dequeuing single element.");
//
//    test_true(q.enqueue('x'), "Queue reports true on successful enqueueing.");
//    test_true(!q.is_empty(), "Queue is not empty after enqueueing.");
//    test_true(q.front() == 'x', "Queue front element is the element enqueued.");
//    test_true(q.dequeue(), "Queue reports true on successful dequeuing.");
//    test_true(q.is_empty(), "Queue is empty after dequeuing single element.");
//
//    // empty queue test
//    test_true(!q.dequeue(), "Queue reports false on dequeue of empty queue.");
//
//    // enqueue, then dequeue 4 elements
//    test_true(q.enqueue('a'), "Queue reports true enqueueing 'a'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//    test_true(q.enqueue('b'), "Queue reports true enqueueing 'b'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//    test_true(q.enqueue('c'), "Queue reports true enqueueing 'c'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//    test_true(q.enqueue('d'), "Queue reports true enqueueing 'd'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//
//    test_true(q.front() == 'a', "Queue front element is 'a'.");
//    test_true(q.dequeue(), "Successful dequeue of 'a'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//    test_true(q.front() == 'b', "Queue front element is 'b'.");
//    test_true(q.dequeue(), "Successful dequeue of 'b'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//    test_true(q.front() == 'c', "Queue front element is 'c'.");
//    test_true(q.dequeue(), "Successful dequeue of 'c'.");
//    test_true(!q.is_empty(), "Queue reports false is_empty.");
//    test_true(q.front() == 'd', "Queue front element is 'd'.");
//    test_true(q.dequeue(), "Successful dequeue of 'd'.");
//    test_true(q.is_empty(), "Queue is empty after dequeuing many elements.");
//
//    // enqueue to full, then dequeue
//    test_true(q.enqueue('a'), "Queue reports true enqueueing 'a'.");
//    test_true(q.enqueue('b'), "Queue reports true enqueueing 'b'.");
//    test_true(q.enqueue('c'), "Queue reports true enqueueing 'c'.");
//    test_true(q.enqueue('d'), "Queue reports true enqueueing 'd'.");
//    test_true(q.enqueue('e'), "Queue reports true enqueueing 'e'.");
//
//    test_true(!q.enqueue('y'), "Queue reports false on enqueue to full queue.");
//    test_true(!q.enqueue('z'), "Queue reports false on enqueue to full queue.");
//
//    test_true(!q.is_empty(), "Queue reports false on is_empty on full queue.");
//
//    test_true(q.front() == 'a', "Queue front element is 'a'.");
//    test_true(q.dequeue(), "Successful dequeue of 'a'.");
//    test_true(q.front() == 'b', "Queue front element is 'b'.");
//    test_true(q.dequeue(), "Successful dequeue of 'b'.");
//    test_true(q.front() == 'c', "Queue front element is 'c'.");
//    test_true(q.dequeue(), "Successful dequeue of 'c'.");
//    test_true(q.front() == 'd', "Queue front element is 'd'.");
//    test_true(q.dequeue(), "Successful dequeue of 'd'.");
//    test_true(q.front() == 'e', "Queue front element is 'e'.");
//    test_true(q.dequeue(), "Successful dequeue of 'a'.");
//    test_true(q.is_empty(), "Queue is empty after dequeuing many elements.");
//
//    cout << endl << NUM_PASSED << "/51 tests passed" << endl;



    return 0;
}

void test_true(bool expr, string desc) {
    if (!expr) {
        cout << "FAILED test: ";
    } else {
        cout << "Passed test: ";
        NUM_PASSED++;
    }
    cout << '"' << desc << '"' << endl;
}

