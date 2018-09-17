/*
 * lab3.cpp
 *
 * Implementations of binary search, Fisher-Yates shuffling, and insertion
 * sort (with added timing code) for analysis practice.  There are also some 
 * convenience methods to provide vectors of integers to use in testing.
 *
 * Author: C. Painter-Wakefield
 * 
 * Last modified: 9/6/2018
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Function prototypes */
/* Algorithms */
int binary_search(const vector<int> &vec, int search_val);
int binary_search_helper(const vector<int> &vec, int search_val, int left, int right);
void insertion_sort(vector<int> &vec);
void shuffle(vector<int> &vec);

/* Utility */
vector<int> range_vector(unsigned int size);
vector<int> random_vector(unsigned int size);

/* timing */
/* 
 * time_it returns the number of seconds executing a function call takes 
 * This uses fancy template programming - we won't cover the techniques
 * used here in this class, alas. You can read up on "variadic templates"
 * for more info.
 */
template<class Function, class... Args>
double time_it(Function&& f, Args&&... args) {
	clock_t start = clock();

	f(args...);

	clock_t stop = clock();
	return (stop - start) / double(CLOCKS_PER_SEC);
}

/* main() */
int main() {
	// Vary the SIZE input to get measures of how the time taken by
	// the function grows with the size of input.  Recommended:
	// start with size 1000 and either increase in increments of 1000,
	// or double each time
	unsigned int SIZE = 0;
	while (SIZE == 0) {
		cout << "How big a vector would you like to test? ";
		cin >> SIZE;
	}

	// Better timing data can be obtained by averaging many trial runs
	// of the same algorithm.  This can even out differences due to 
	// various types of interference, or differences in the data input.
    unsigned int TRIALS = 0;    // how many trials to perform
	while (TRIALS == 0) {
		cout << "How many trials would you like to run? ";
		cin >> TRIALS;
	}

	cout << "Using vectors of size " << SIZE << ", running " << TRIALS << " trials." << endl;

	// Approach:
	// 1. Initialize a double time total to zero
	// 2. Loop TRIALS time:
	//    a. Create an appropriate vector for the algorithm to work on
	//    b. Use time_it() to time running the algorithm on the vector
	//    c. Add the return from time_it() to the time total
	// 3. Divide the time total by TRIALS to get the average run time

	vector<int> vec;

	// INSERTION SORT
	double t1 = 0.0;
    for (int i = 0; i < TRIALS; i++) {
        vec = random_vector(SIZE);  // unsorted integer vector
        t1 += time_it(insertion_sort, vec);
    }
	cout << "Sorted " << SIZE << " elements in " << t1 / TRIALS << " seconds (average)." << endl;


	// FISHER-YATES SHUFFLE

//	vec = range_vector(SIZE);       // any vector works for shuffling
//	double t2 = 0.0;
//	for (int i = 0; i < TRIALS; i++) {
//		t2 += time_it(shuffle, vec);
//	}
//	cout << "Shuffled " << SIZE << " elements in " << t2 / TRIALS << " seconds (average)." << endl;



	// BINARY SEARCH

//	double t3 = 0.0;
//	vec = range_vector(SIZE);       // input to binary search *must* be ordered
//	for (int i = 0; i < TRIALS; i++) {
//        // pick a random number in the vector to search for
//        int search_val = rand() % SIZE;
//		t3 += time_it(binary_search, vec, search_val);
//	}
//	cout << "Searched " << SIZE << "  elements in " << t3 / TRIALS << " seconds (average)." << endl;

}

/*
  double binary_search(const vector<int> &vec, int search_val)
  Takes in an *already sorted* vector of integers, and searches the vector for
  the search value.  When the value is found, or is determined not to be in
  the vector, the function returns. Returns the index of the found value,
  or -1 if not found.
*/
int binary_search(const vector<int> &vec, int search_val) {
	return binary_search_helper(vec, search_val, 0, vec.size() - 1);
}

/*
 * int binary_search_helper(const vector<int> &vec, int search_val, int left, int right) 
 * The actual recursive implementation of the binary search algorithm.  In
 * addition to the vector and the search value, this function takes in the 
 * left hand and right hand indices bounding the part of the vector being
 * searched.  The function returns the index of the found value, or -1 if not
 * found.
 */
int binary_search_helper(const vector<int> &vec, int search_val, int left, int right) {
	if (left > right) return -1;
	int pivot = left + (right - left) / 2;
	if (vec[pivot] == search_val) {
		return pivot;
	} else if (search_val < vec[pivot]) {
		return binary_search_helper(vec, search_val, left, pivot - 1);
	} else {
		return binary_search_helper(vec, search_val, pivot + 1, right);
	}
}

/*
 * double insertion_sort(vector<int> &vec)
 * Sorts a vector of integers in place.
 */
void insertion_sort(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++) {
		int j;
		int el = vec[i];
		for (j = i - 1; j >= 0 && vec[j] > el; j--) {
			vec[j + 1] = vec[j];
		}
		vec[j + 1] = el;
	}
}

/*
 * double shuffle(vector<int> &vec)
 * Shuffles a vector of integers in place.  The algorithm used is 
 * the Fisher-Yates algorithm.
 */
void shuffle(vector<int> &vec) {
	for (int i = vec.size() - 1; i >= 1; i--) {
		int idx = rand() % (i + 1);
		swap(vec[idx], vec[i]);
	}
}

/*
 * vector<int> range_vector(int size)
 * Return a vector<int> containing all the integers from 0 to size - 1, in 
 * order.
 */
vector<int> range_vector(unsigned int size) {
	vector<int> answer(size);
	for (unsigned int i = 0; i < size; i++) answer[i] = i;
	return answer;
}

/*
 * vector<int> random_vector(int size)
 * Return a vector<int> containing random integers, in no particular order.
 */
vector<int> random_vector(unsigned int size) {
	vector<int> answer(size);
	for (unsigned int i = 0; i < size; i++) answer[i] = rand();
	return answer;
}

