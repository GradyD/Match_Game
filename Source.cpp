#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int gameOver(int gameBoard[]);

/** Sets color **/
//system("color 4e");
 
int main() {
    int gameBoard[16], first, second, start;
        
/** Fills board[] with number **/
       int  board[16] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};


/** Shuffles board[] 100% randomly **/
        srand(time(0));
        random_shuffle(&board[0], &board[16]);
        
/** Fills gameBoard[] with 0 **/
        for(int i = 0; i < 16; i++)
                gameBoard[i] = 0;

/** Prints welcome screen 
	cout << "___  ___      _       _       _____                       " << endl;                     
	cout << "|  \\/  |     | |     | |     |  __ \                      " << endl;                    
	cout << "| .  . | __ _| |_ ___| |__   | |  \/ __ _ _ __ ___   ___  " << endl;
	cout << "| |\/| |/ _` | __/ __| '_ \  | | __ / _` | '_ ` _ \ / _ \ " << endl;
	cout << "| |  | | (_| | || (__| | | | | |_\ \ (_| | | | | | |  __/ " << endl;
	cout << "\_|  |_/\__,_|\__\___|_| |_|  \____/\__,_|_| |_| |_|\___| " << endl;
	cout << endl;
Could not test **/
	cout << "1. Help/User Manual    2. Game on!" << endl;
	cout << "Please enter a number: ";
	cin >> start;

/** Loops while invalid numbers are entered **/	
	while(start != 1 || start != 2) {
		cout << "Invalid request, please enter a valid number" << endl;
		cout << "1. Help/User Manual    2. Game on!" << endl;
		cout << "Please enter a number: ";
		cin >> start;
	}

/** Finds value of start and requests function **/
	if(start == 1){
		//Function to display User guide
	}else if(start == 2){
		//Function to get the game difficulty
	}else
		cout << "Error 001" << endl;
		
/** Game levels        Move to function
	cout << "1. Easy (Unlimited guesses)" << endl;
	cout << "2. Medium (25 guesses)" << endl;
	cout << "3. Hard (10 guesses)" << endl;
	cout << "Please enter the number of the difficulty desired!" << endl;
	cin >> difficulty;
**/
		
/** Prints game board and gets user input **/
	do{
        for(int i = 0; i < 16; i++){ //Move to function!
                cout << gameBoard[i] << " ";
				if(i == 3 || i == 7 || i == 11 || i == 15)
					cout << endl;
        }
        cout << "Welcome! Please enter your first guess" << endl;
        cin >> first;
		first = first - 1;
        cout << "Please enter your second guess" << endl;
        cin >> second;
		second = second -1;

/** Checks input **/
		if(board[first] == board[second]){
			cout << "You have a match!" << endl;
			gameBoard[first] = board[first];
			gameBoard[second] = board[second];
		}else
			cout << "You did not get a match, please guess again" << endl;
		for(int i = 0; i < 16; i++){ //Move to function!
                cout << gameBoard[i] << " ";
				if(i == 3 || i == 7 || i == 11 || i == 15)
					cout << endl;
        }
	}while(gameOver(gameBoard) != true); //Repeats as long as there are zeros in gameBoard[]

        return 0;
}

/** Function to check for zeros **/
int gameOver(int gameBoard[]){
	for(int i = 0; i < 16; i++){
		if(gameBoard[i] == 0)
			return false;
		else
			return true;
	};
}