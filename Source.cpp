#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int gameOver(int gameBoard[]);
int welcomeScreen(int &start);
int userHelp(int &start);
int check(int start, int difficulty);
void print(int gameBoard[]);
void logo();
 
int main() {
/** Sets color **/
system("color 4e");
    
/** Creats vars **/
	int gameBoard[16], first, second, start, difficulty;
	start = 0;
	difficulty = 0;

/** Fills board[] with numbers **/
	int board[16] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};

/** Shuffles board[] randomly **/
	srand(time(0));
	random_shuffle(&board[0], &board[16]);
        
/** Fills gameBoard[] with 0 **/
	for(int i = 0; i < 16; i++)
		gameBoard[i] = 0;

/** Prints welcome screen*/
	welcomeScreen(start);

/** Loops while invalid numbers are entered **/
	/* Remove this commit to test options 1 and 2, leave to test game 
	check(start, difficulty);
	*/

/** Difficulty currently not working **/
	/*switch(difficulty){
		case(1):
			cout << "Unlimted guesses" << endl;
			break;
		case(2):
			cout << "30 guesses" << endl;
			break;
		case(3):
			cout << "16 guesses" << endl;
			break;
		default:
			cout << "Error 001" << endl;
	}*/

/** Prints game board and gets user input **/
	do{
		print(gameBoard);
		cout << "\nWelcome! Please enter your first guess" << endl;
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
        }while(gameOver(gameBoard) != true); //Repeats as long as there are zeros in gameBoard[]

        return 0;
}

/** Function to check for zeros on gameBoard **/
int gameOver(int gameBoard[]){
        for(int i = 0; i < 16; i++){
			if(gameBoard[i] == 0)
				return false;
        };
}

/** Logo for resuse **/
void logo(){
	cout << "___  ___      _       _         _____                        " << endl;
	cout << "|  \\/  |     | |     | |       |  ___\\                       " << endl;
	cout << "| .  . | __ _| |_ ___| |__     | |     ____ ___  ___   ___    " << endl;
	cout << "| |\\/| |/ _` | __/ __| '_ \\    | | __ / _  |  _ ` _ \\ / _ \\   " << endl;
	cout << "| |  | | (_| | || (__| | | |   | |_\\ \\ (_| | | | | | | \\__/   " << endl;
	cout << "\\_|  |_/ \__,_|\\__\\___|_| |_|    \\____/\\__,_|_| |_| |_|\\___|   " << endl;
	cout << endl;
}

/** Displays Welcome Screen **/
int welcomeScreen(int &start) {
	logo();
	cout << "1.Help/User Manual   2.Game on!" << endl;
	cout << "Please enter a number: ";
	cin >> start;
	system("cls");
	return start;
}

/** Displays User Guide **/
int userHelp(int &start) {
 	cout <<"User help" <<endl;
	cout << endl;
	cout << "To play the game select 2 places on the board to see if they match." << endl;
	cout << "The places on the board are as follows: "<< endl;
	cout << "1   2  3  4" << endl;
	cout << "5   6  7  8" << endl;
	cout << "9  10 11 12" << endl;
	cout << "13 14 15 16" << endl;
	cout << "If they don't match try again, if they do select another 2 places until you win the game." << endl;
	cout << "Press enter to play the game.";
	//cin.ignore(); This works but causes issues with the current way our code works
	system("pause"); //Temp work around until above method is working
	system("cls");
	start = 2;
	return start;
 }

/** Displays level difficulty **/
int check(int start, int difficulty){
	do {
		if(start == 1)
			userHelp(start);
		else if(start == 2){
			cout << "1.Easy (Unlimited guesses)" << endl;
			cout << "2.Medium (25 guesses)" << endl;
			cout << "3.Hard (10 guesses)" << endl;
			cout << "Please enter the number of the difficulty desired!" << endl;
			cin >> difficulty;
		}else{
			cout << start << endl;
			welcomeScreen(start);
		}
	}while((start != 1) || (start != 2));	

	return start, difficulty;
};

void print(int gameBoard[]){
	logo();
		for(int i = 0; i < 16; i++){
			cout.width(3); //Creats spacing
			if(i == 0 || i == 4 || i == 8 || i == 12 || i == 16) //Creats Y number row
				cout << i + 1 << " ";
			cout << gameBoard[i] << " ";
			if(i == 3 || i == 7 || i == 11 || i == 15) // Creats grid from 1D array
				cout << endl;
		}
};