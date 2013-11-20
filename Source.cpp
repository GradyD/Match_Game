#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
int main () {
	int board[16], number;
	number = 0;

/** Fills board[] with number **/
	for(int i = 0; i < 16; i++){
		board[i] = number;
		if(i % 2 == 0)
			number++;
	}

/** Shuffles board[] 100% randomly **/
	srand(time(0));
	random_shuffle(&board[0], &board[16]);
	
/** Prints board[] for testing **/
	for(int i=0; i<16; i++){
		cout << "Board: " << board[i] << endl;
	}
	
	return 0;
}