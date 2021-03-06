#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <Windows.h>

using namespace std;

int gameOver(int gameBoard[]);
int welcomeScreen(int &start);
int userHelp(int &start);
int valid(int start);
void print(int gameBoard[]);
void logo();
int userIntput(int &first, int &second, int check, int gameBoard[], int gamedifficutly);
int gamedifficulty(int &difficulty);
void finish();
 
int main() {
/** Sets color **/
system("color 4e");
    
/** Creats vars **/
	int gameBoard[16], first, second, start, difficulty, gamedifficutly;
	bool check;
	start = 0;
	difficulty = 0;
	first = 0;
	second = 0;
	check = 0;

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
	do{
		if(start == 1){
			userHelp(start);
		}else if(start == 2){ //Sets difficulty
			gamedifficulty(difficulty);
			do{
				if(difficulty == 1){
					gamedifficutly = 100;
				}else if(difficulty == 2){
					gamedifficutly = 50;
				}else if(difficulty == 3){
					gamedifficutly = 25;
				}else
					gamedifficulty(difficulty);
			}while(difficulty != 1 && difficulty != 2 && difficulty != 3);
		}else
			welcomeScreen(start);
	}while(difficulty == 0);

/** Prints game board and gets user input **/
	do{
		system("cls");
		userIntput(first, second, check, gameBoard, gamedifficutly);

		if(first == second)
			cout << "Invalid input, please enter different guesses" << endl;
		
			gameBoard[first] = board[first];
			gameBoard[second] = board[second];
			for(int i = 0; i < 16; i++){
				if(i == 0)
					cout << "    1   2   3   4" << endl;
				cout.width(3); //Creats spacing
				if(i == 0 || i == 4 || i == 8 || i == 12 || i == 16) //Creats Y number row
					cout << i + 1 << " ";
				cout << gameBoard[i] << " ";
				if(i == 3 || i == 7 || i == 11 || i == 15) // Creats grid from 1D array
					cout << endl;
				}
			gameBoard[first] = 0;
			gameBoard[second] = 0;

		if(board[first] == board[second]){
			cout << "You have a match!" << endl;
			gameBoard[first] = board[first];
			gameBoard[second] = board[second];
		}else
			cout << "You did not get a match, please guess again" << endl;

		Sleep(2000); //Pauses two seconds until I figure out the issue with pressing enter to move on

		gamedifficutly = gamedifficutly - 1;

	}while((gameOver(gameBoard) != true) || (gamedifficutly != 0)); //Repeats as long as there are zeros in gameBoard[]
	
	 system("cls");
	 cout << "Game Over" << endl;

	return 0;
}

/** Function to check for zeros on gameBoard **/
int gameOver(int gameBoard[]){
        for(int i = 0; i < 16; i++){
			if(gameBoard[i] == 0)
				return true;
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

	cout << "Press the 'S' key to start the game.";
	char bogus;
	cin >> bogus;
	system("cls");
	start = 2;
	return start;
 }

/** Creats gameBoard **/
void print(int gameBoard[]){
	logo();
		for(int i = 0; i < 16; i++){
			if(i == 0)
				cout << "    1   2   3   4" << endl;
			cout.width(3); //Creats spacing
			if(i == 0 || i == 4 || i == 8 || i == 12 || i == 16) //Creats Y number row
				cout << i + 1 << " ";
			cout << gameBoard[i] << " ";
			if(i == 3 || i == 7 || i == 11 || i == 15) // Creats grid from 1D array
				cout << endl;
		}
};

/** User input and valid number check **/
int userIntput(int &first, int &second, int check, int gameBoard[], int gamedifficutly){
	print(gameBoard);
	
	cout << "You have: " << gamedifficutly << " guesses left" << endl;
	cout << "\nWelcome! Please enter your first guess" << endl;
	cin >> first;
	do{ //Makes sure guess is valid input
		if(first < 1 || first > 16){
			system("cls");
			print(gameBoard);
			cout << "\nNot a valid input, please enter your first guess" << endl;
			cin >> first;
		}else{
			first = first - 1;
			check = 1;
		}
	}while(check != 1);


	cout << "Please enter your second guess" << endl;
	cin >> second;
	do{ //Makes sure guess is valid input
		if(second < 1 || second > 16){
			system("cls");
			print(gameBoard);
			cout << "First guess: " << first + 1 << endl;
			cout << "Not a valid input, please enter your second guess" << endl;
			cin >> second;
		}else{
			second = second - 1;
			check = 0;
		}
	}while(check != 0);	

	return first, second;
};

/** Gets and sets user difficulty level **/
int gamedifficulty(int &difficulty){
	cout << "1.Easy (100 guesses)" << endl;
	cout << "2.Medium (50 guesses)" << endl;
	cout << "3.Hard (25 guesses)" << endl;
	cout << "Please enter the number of the difficulty desired!" << endl;
	cin >> difficulty;

	return difficulty;
};

/** Game Over **/
void finish(){
	cout << "Game Over" << endl;
}