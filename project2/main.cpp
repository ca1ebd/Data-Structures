/*
    CSCI 262 Data Structures, Fall 2018, Assignment 2 - mazes

    main.cpp

    Provides the user interface for launching the maze solver.

    C. Painter-Wakefield
*/

#include <iostream>
#include <fstream>
#include <string>

#include "maze_solver.h"

using namespace std;


// You should not modify any of this code.  Changing it may cause
// difficulty for the grader.  Touch at your own risk!


/*
 file_exists()

 open/close the file to test for existence.  This is lame, but
 the best we can do until the experimental filesystem library
 is standardized.
*/

bool file_exists(string filename) {
    ifstream test(filename);
    if (test) {
        test.close();
        return true;
    }
    return false;
}


/*
 main()

 Gets user inputs, creates and runs maze_solver object.
*/
int main(int argc, char* argv[]) {
	string infile;
	string s_or_q;
	bool do_pause = false;
	bool use_stack = true;

	// Check for command line arguments for maze filename and stack/queue
	// selection.  An optional third argument lets the grader circumvent
	// the pause between UI refreshes for automated testing purposes.
	if (argc >= 3) {
		infile = argv[1];
		s_or_q = argv[2];
		if (s_or_q != "Q" && s_or_q != "S") {
		    cerr << "Unrecognized argument: please specify stack (S) or queue (Q).  Exiting." << endl;
		}
		if (argc == 4 && string(argv[3]) == "false") do_pause = false;
		if (!file_exists(infile)) {
		    cerr << "Error opening file \"" << infile << "\" for reading, exiting." << endl;
		    return -1;
		}
	}
	else {
		cout << "Please enter a maze filename: ";
		getline(cin, infile);
		while (!file_exists(infile)) {
		    cout << "Error opening file \"" << infile << "\" for reading." << endl;
            cout << "Please enter a maze filename: ";
            getline(cin, infile);
        }
		cout << "Please enter (S) to use a stack, or (Q) to use a queue: ";
		getline(cin, s_or_q);
		while (s_or_q != "Q" && s_or_q != "S") {
            cout << "Input error: please specify stack (S) or queue (Q): ";
            getline(cin, s_or_q);
		}
	}

	use_stack = (s_or_q == "S");

	// create the maze_solver object and run it with the user inputs

	//Personal modifications so I don't waste my life typing these filenames
//	vector<string> filenames = {"0-simple.txt", "1-empty.txt", "2-no_walls.txt", "3-no_path.txt", "4-general.txt", "5-complex.txt", "6-loop.txt", "7-center.txt", "8-perc1.txt", "9-perc2.txt", "10-good-for-queue.txt"};
//	for(int i=0; i<filenames.size(); i++){
//	    try{
//            maze_solver solver(filenames[i], use_stack, do_pause);
//            solver.run();
//            maze_solver queuesolver(filenames[i], false, do_pause);
//            queuesolver.run();
//	    }
//		catch (runtime_error){
//            cout << "runtime error on file " << filenames[i] << endl;
//		}
//	}

    maze_solver solver(infile, use_stack, do_pause);
    solver.run();



	return 0;
}

