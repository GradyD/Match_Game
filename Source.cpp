#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main () {

	int board[4][4], t, s, x, r1;
	s = 0;
	x = 0;
	r1 = rand() % 4;

/*	for(int i = 1; i < 17; i++){
	t = rand() % 9;
	board[t][t] = s;
	if(i % 2 == 0)
		s++;
	}*/
	for(r1; r1 < 4;){
		do{
			cout << board[r1][x] << endl;
			cout << "r1: " << r1 << " X: " << x << endl;
			x++;
			cout << "X: " << x << endl;
		}while(x < 4);
		x = 0;
	}
	for(int i = 0; i < 4; i++){
		do{
			cout << board[i][x] << endl;
			cout << "I: " << i << " X: " << x << endl;
			x++;
			cout << "X: " << x << endl;
		}while(x < 4);
		x = 0;
	}

	return 0;
}