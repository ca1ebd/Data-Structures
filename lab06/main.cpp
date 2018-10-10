/*
    tests.cpp

    Tests for the Queue class. 

    Code for CSCI 262 lab 3 - Queues

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
    Queue q;

    // constructor test
    test_true(q.is_empty(), "Queue is initially empty.");
    
    // single element tests
    test_true(q.enqueue('x'), "Queue reports true on successful enqueueing.");
    test_true(!q.is_empty(), "Queue is not empty after enqueueing.");
    test_true(q.front() == 'x', "Queue front element is the element enqueued.");
    test_true(q.dequeue(), "Queue reports true on successful dequeuing.");
    test_true(q.is_empty(), "Queue is empty after dequeuing single element.");

    test_true(q.enqueue('x'), "Queue reports true on successful enqueueing.");
    test_true(!q.is_empty(), "Queue is not empty after enqueueing.");
    test_true(q.front() == 'x', "Queue front element is the element enqueued.");
    test_true(q.dequeue(), "Queue reports true on successful dequeuing.");
    test_true(q.is_empty(), "Queue is empty after dequeuing single element.");

    // empty queue test
    test_true(!q.dequeue(), "Queue reports false on dequeue of empty queue.");

    // enqueue, then dequeue 4 elements
    test_true(q.enqueue('a'), "Queue reports true enqueueing 'a'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");
    test_true(q.enqueue('b'), "Queue reports true enqueueing 'b'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");
    test_true(q.enqueue('c'), "Queue reports true enqueueing 'c'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");
    test_true(q.enqueue('d'), "Queue reports true enqueueing 'd'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");

    test_true(q.front() == 'a', "Queue front element is 'a'.");
    test_true(q.dequeue(), "Successful dequeue of 'a'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");
    test_true(q.front() == 'b', "Queue front element is 'b'.");
    test_true(q.dequeue(), "Successful dequeue of 'b'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");
    test_true(q.front() == 'c', "Queue front element is 'c'.");
    test_true(q.dequeue(), "Successful dequeue of 'c'.");
    test_true(!q.is_empty(), "Queue reports false is_empty.");
    test_true(q.front() == 'd', "Queue front element is 'd'.");
    test_true(q.dequeue(), "Successful dequeue of 'd'.");
    test_true(q.is_empty(), "Queue is empty after dequeuing many elements.");

    // enqueue to full, then dequeue
    test_true(q.enqueue('a'), "Queue reports true enqueueing 'a'.");
    test_true(q.enqueue('b'), "Queue reports true enqueueing 'b'.");
    test_true(q.enqueue('c'), "Queue reports true enqueueing 'c'.");
    test_true(q.enqueue('d'), "Queue reports true enqueueing 'd'.");
    test_true(q.enqueue('e'), "Queue reports true enqueueing 'e'.");

    test_true(!q.enqueue('y'), "Queue reports false on enqueue to full queue.");
    test_true(!q.enqueue('z'), "Queue reports false on enqueue to full queue.");

    test_true(!q.is_empty(), "Queue reports false on is_empty on full queue.");

    test_true(q.front() == 'a', "Queue front element is 'a'.");
    test_true(q.dequeue(), "Successful dequeue of 'a'.");
    test_true(q.front() == 'b', "Queue front element is 'b'.");
    test_true(q.dequeue(), "Successful dequeue of 'b'.");
    test_true(q.front() == 'c', "Queue front element is 'c'.");
    test_true(q.dequeue(), "Successful dequeue of 'c'.");
    test_true(q.front() == 'd', "Queue front element is 'd'.");
    test_true(q.dequeue(), "Successful dequeue of 'd'.");
    test_true(q.front() == 'e', "Queue front element is 'e'.");
    test_true(q.dequeue(), "Successful dequeue of 'a'.");
    test_true(q.is_empty(), "Queue is empty after dequeuing many elements.");

    cout << endl << NUM_PASSED << "/51 tests passed" << endl;

    return 0;
}

void test_true(bool expr, string desc) {
    if (!expr) {
        cerr << "FAILED test: ";
    } else {
        cerr << "Passed test: ";
        NUM_PASSED++;
    }
    cerr << '"' << desc << '"' << endl;
}

