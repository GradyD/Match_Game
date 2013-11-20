#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
int main () {
	int board[16], gameBoard[16], number, x, y;
	number = 0;

/** Fills board[] with number **/
	for(int i = 0; i < 16; i++){
		board[i] = number;
		if(i % 2 == 0)
			number++;
	}
	
/** Possible fix for the numbers... would prefer better method so we can expand up to all 52 cards in a deck
	board[16] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
******/

/** Shuffles board[] 100% randomly **/
	srand(time(0));
	random_shuffle(&board[0], &board[16]);
	
/** Prints board[] for testing **/
	for(int i=0; i<16; i++){
		cout << "Board: " << i << " : " << board[i] << endl;
	}
	
/** Fills gameBoard[] with 0 **/
	for(int i = 0; i < 16; i++)
		gameBoard[i] = 0;
	
/** Prints game board and gets user input **/
	cout << "Match Game" << endl;
	for(int i = 0; i < 16; i++){
		cout << gameBoard[i] << " ";
		if(i == 3 || i == 7 || i == 11 || i = 15)
			cout << endl;
	}
	cout << "Welcome! Please enter your X value" << endl;
	cin >> x;
	cout << "Please enter your Y value" << endl;
	cin >> y;

	return 0;
}