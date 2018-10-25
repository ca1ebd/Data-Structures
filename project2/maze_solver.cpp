/*
    CSCI 262 Data Structures, Fall 2018, Assignment 2 - mazes

    maze_solver.cpp

    Code for the maze_solver class.  This class will use stack-based depth
    first search or queue-based breadth first search to find a solution (if
    one exists) to a simple maze.

    C. Painter-Wakefield
*/

#include "maze_solver.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// TODO: read the complete assignment instructions before beginning.  Also look
// at maze_solver.h - you will need to modify it as well.  In this file you
// will need to complete several methods, and add any others as needed for your
// solution. 


/*
 _read_maze()

 Read in maze information (rows, columns, maze) from the provided input stream.
*/

void maze_solver::_read_maze(istream& in) {
    in >> _rows;
    in >> _columns;
    string temp_string;

    for(int i=0; i<_rows; i++){
        in >> temp_string;
        _maze.push_back(temp_string);
    }
}


/*
 _write_maze()

 Output the (partially or totally solved) maze on the provided output stream.
*/
void maze_solver::_write_maze(ostream& out) {
    for(int i=0; i<_rows; i++){
        out << _maze[i] << endl;
    }
}


/*
 _initialize()

 Find the start point.  Push or enqueue the start point.
*/
void maze_solver::_initialize() {
    Point start_point;

    //find start point
    for(int i=0; i<_rows; i++){
        for(int j=0; j<_columns; j++){
            if(_maze[i][j] == 'o'){
                start_point.row = i;
                start_point.column = j;
            }
        }
    }

    _push(start_point);
}


/*
 _step()

 Take *one* step towards solving the maze, setting _no_more_steps and
 _goal_reached as appropriate.  This implements the essential maze search
 algorithm; take the next location from your stack or queue, mark the
 location with '@', add all reachable next points to your stack or queue,
 etc.

 Notes:

 - Your initial point should have been pushed/enqueued in the _initialize()
   method.

 - Set the _no_more_steps variable to true when there are no more reachable
   points, or when the maze was successfully solved.

 - Set the _goal_reached variable to true if/when the maze was successfully
   solved.

 - You should write an '@' over every location you have previously visited,
   *except* for the start and goal positions - they should remain 'o' and '*',
   respectively.

 - Since the run() method will call _write_maze() in between calls to _step(),
   you probably want to try to make progress on each call to step.  On some
   mazes, depending on your approach, it may be possible to add the same
   point multiple times to your stack or queue - i.e., if a point is reachable
   from multiple other points.  When this happens, your code will work, but
   it may make very slow progress.  To fix the problem, simply run a loop to
   scavenge any already visited points from your stack or queue at the beginning
   or end of _step().

 - There are many approaches to dealing with invalid/unreachable points; you
   can choose to add them and then remove them next time you get into _step(),
   you can choose to not add them in the first place, etc.

 - It is strongly recommended that you make helper methods to avoid code
   duplication; e.g., a function to detect that a point is out of bounds is
   a real help on the mazes with no walls.  You can also think about pulling
   out methods that do the actual acting on stacks/queues - this will reduce
   code duplication, since everything is identical between the two except
   for whether you use your stack or queue.  E.g., you could have methods
   named "_push", "_pop", "_next" which use the appropriate data structure.

 - Make sure you follow the order given in the assignment instructions for
   adding points to your data structure - up, right, down, left - or your
   final maze solution won't match the expected solution.  Check against the
   sample solutions provided.
*/
void maze_solver::_step() {
    //check if empty
    if(_is_empty()){
        _no_more_steps = true;
        return;
    }

    Point current_point = _top();
    _pop();
    char current_char = _maze[current_point.row][current_point.column];

    //check if win
    if(current_char == '*'){
        _goal_reached = true;
        _no_more_steps = true;
        return;
    }

    //mark point as visited ('@') as long as not start
    if(current_char != 'o'){
        _maze[current_point.row][current_point.column] = '@';
    }

    vector<Point> surrounding_points;

    //create above, below, left and right points
//    Point above {current_point.row-1, current_point.column};
//    Point below {current_point.row+1, current_point.column};
//    Point left {current_point.row, current_point.column-1};
//    Point right {current_point.row, current_point.column+1};

    surrounding_points.push_back({current_point.row-1, current_point.column}); //above
    surrounding_points.push_back({current_point.row, current_point.column+1}); //right
    surrounding_points.push_back({current_point.row+1, current_point.column}); //below
    surrounding_points.push_back({current_point.row, current_point.column-1}); //left

    for(int i=0; i<surrounding_points.size(); i++){
        if(_is_valid(surrounding_points[i])){
            _push(surrounding_points[i]);
        }
    }

    if(!_is_empty() and !_is_valid(_top())){
        _pop();
    }
    _no_more_steps = _is_empty();

}

bool maze_solver::_is_empty() {
    if(_use_stack){
        return _my_stack.empty();
    }
    else{
        return _my_queue.empty();
    }
}

Point maze_solver::_top() {
    if(!_is_empty()){
        if(_use_stack){
            return _my_stack.top();
        }
        else{
            return _my_queue.front();
        }
    }
}

void maze_solver::_pop(){
    if(_use_stack){
        return _my_stack.pop();
    }
    else{
        return _my_queue.pop();
    }
}

void maze_solver::_push(Point my_point){
    if(_use_stack){
        _my_stack.push(my_point);
    }
    else{
        _my_queue.push(my_point);
    }
}

bool maze_solver::_is_valid(Point my_point){
    return ((my_point.row >= 0) and
    (my_point.row < _rows) and
    (my_point.column >= 0) and
    (my_point.column < _columns) and
    (_maze[my_point.row][my_point.column] != '@') and
    (_maze[my_point.row][my_point.column] != 'o') and
    (_maze[my_point.row][my_point.column] != '#'));
}

//Point maze_solver::_next(){
//    if(_use_stack){
//        return _my_stack.nex
//    }
//}





/***************************************************************************
    You should not need to modify code below this point.  Touch at your own
    risk!
****************************************************************************/

/*
 maze_solver constructor

 You should not need to modify this.  It opens the maze file and passes
 the input stream to read_maze(), along with setting up some internal state
 (most importantly, the variable telling you whether to use a stack or
 a queue).
*/
maze_solver::maze_solver(string infile, bool use_stak, bool pause) {
	_use_stack = use_stak;
	_do_pause = pause;

	_no_more_steps = false;
	_goal_reached = false;

	// parse out maze name for later use in creating output file name
	int pos = infile.find(".");
	if (pos == string::npos) {
		_maze_name = infile;
	} else {
		_maze_name = infile.substr(0, pos);
	}

	// open input file and read in maze
	ifstream fin(infile);

	_read_maze(fin);

	fin.close();
}

/*
 run()

 Initializes the maze_solver, then runs a loop to keep moving forward towards
 a solution.

 While more steps are possible (while no_more_steps == false), run() calls
 step(), then calls() write_maze() on cout, then pause().  Once there are no
 more steps, it prints a success/failure message to the user (based on the
 goal_reached flag) and writes the final maze to a solution file.
*/

void maze_solver::run() {
    _initialize();

	cout << "Solving maze '" << _maze_name << "'." << endl;
	cout << "Initial maze: " << endl << endl;
	_write_maze(cout);
	cout << endl;
	_pause();

	// main loop
	while (!_no_more_steps) {
		_step();
		cout << endl;
		_write_maze(cout);
		cout << endl;
		_pause();
	}

	// final output to user
	cout << "Finished: ";
	if (_goal_reached) {
		cout << "goal reached!" << endl;
	} else {
		cout << "no solution possible!" << endl;
	}

	// save solution file
	string outfile;
	if (_use_stack) outfile = _maze_name + "-stack-solution.txt";
	else outfile = _maze_name + "-queue-solution.txt";
	
	ofstream fout(outfile);
	if (!fout) {
		cerr << "Could not open file \"" << outfile << "\" for writing." << endl;
		cerr << "Solution file could not be saved!" << endl;
	}
	else {
		_write_maze(fout);
		fout.close();
	}
}


/*
 pause()

 Pauses execution until user hits enter (unless do_pause == false).
*/
void maze_solver::_pause() {
	if (!_do_pause) return;
	string foo;
	cout << "Hit Enter to continue...";
	getline(cin, foo);
}

