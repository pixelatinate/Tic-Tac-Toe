// lab 1, toe.cpp
// This lab plays a little game of tic tac toe with you.
// COSC 140
// Swasti Mishra
// 01/24/21
// Professor Emrich
// Students: Trish Nguyen, Katie Nuchols

# include <iostream>
# include <limits> 
# include <vector>
# include <string.h>
# include <stdio.h> 
# include <array>

using namespace std ;

int size ;
int moveCount = 0 ;
int board[ 25 ] ;
// 2 will be an empty space, 1 will be Xs, and 0 will be Os.

/*
void printBoard() {
	int counter ; 
	for ( int i = 0 ; i < ( size * size ) ; i++ ) {
		if ( board[i] == 2 ) {
			cout << 'X' << " " ;
			counter++ ;
		}
		// converts the value 2 to X

		if ( board[i] == 1 ) {
			cout << 'O' << " " ;
			counter++ ;
		}
		// converts the value 1 to O

		if ( board[i] == 0 ) {
			cout << '-' << " " ;
			counter++ ;
		}
		// converts the value 0 to a dash

		if ( counter == size ) {
			cout << "\n" ;
			counter = 0 ;
		}
		// formats for better readability
	}
} */
// The point of this function is to convert the array to a visual board.
// You would think one should skip the step and just take the array in as
//		chars of Xs and Os, but I tried that for no joke, A COUPLE OF HOURS
//		before realizing I would have to take the L.

void winCondition() {
	int xWin = 0 ;
	int oWin = 0 ;

	if ( size == 3 ) {
		if ( 
			( ( board[0] == board[1] ) && ( board[1] == board[2] ) && ( board[2] == 2 ) ) ||
			( ( board[3] == board[4] ) && ( board[4] == board[5] ) && ( board[5] == 2 ) ) ||
			( ( board[6] == board[7] ) && ( board[7] == board[8] ) && ( board[8] == 2 ) ) ||
			// Across Condition
		    ( ( board[0] == board[3] ) && ( board[3] == board[6] ) && ( board[6] == 2 ) ) ||
			( ( board[1] == board[4] ) && ( board[4] == board[7] ) && ( board[7] == 2 ) ) ||							    
			( ( board[2] == board[5] ) && ( board[5] == board[8] ) && ( board[8] == 2 ) ) ||
			// Down Condition
			( ( board[0] == board[4] ) && ( board[4] == board[8] ) && ( board[8] == 2 ) ) ||
			( ( board[2] == board[4] ) && ( board[4] == board[6] ) && ( board[6] == 2 ) ) 
			// Diagonal Condition
		) {
			xWin = 1 ; 
			}
		if (
			( ( board[0] == board[1] ) && ( board[1] == board[2] ) && ( board[2] == 1 ) ) ||
			( ( board[3] == board[4] ) && ( board[4] == board[5] ) && ( board[5] == 1 ) ) ||
			( ( board[6] == board[7] ) && ( board[7] == board[8] ) && ( board[8] == 1 ) ) ||
			// Across Condition
			( ( board[0] == board[3] ) && ( board[3] == board[6] ) && ( board[6] == 1 ) ) ||
			( ( board[1] == board[4] ) && ( board[4] == board[7] ) && ( board[7] == 1 ) ) ||    
			( ( board[2] == board[5] ) && ( board[5] == board[8] ) && ( board[8] == 1 ) ) ||
			// Down Condition
			( ( board[0] == board[4] ) && ( board[4] == board[8] ) && ( board[8] == 1 ) ) ||
			( ( board[2] == board[4] ) && ( board[4] == board[6] ) && ( board[6] == 1 ) ) 
			// Diagonal Condition
		) {
			oWin = 1 ;
			}
	}
	if ( size == 4 ) {
		if (
			( ( board[0] == board[1] ) && ( board[1] == board[2] ) && ( board[2] == board[3] ) && ( board[3] == 2 ) ) ||
			( ( board[4] == board[5] ) && ( board[5] == board[6] ) && ( board[6] == board[7] ) && ( board[7] == 2 ) ) ||
			( ( board[8] == board[9] ) && ( board[9] == board[10] ) && ( board[10] == board[11] ) && ( board[11] == 2 ) ) ||
			( ( board[12] == board[13] ) && ( board[13] == board[14] ) && ( board[14] == board[15] ) && ( board[15] == 2 ) ) ||
			// Across Condition
			( ( board[0] == board[4] ) && ( board[4] == board[8] ) && ( board[8] == board[12] ) && ( board[12] == 2 ) ) ||
			( ( board[1] == board[5] ) && ( board[5] == board[9] ) && ( board[9] == board[13] ) && ( board[13] == 2 ) ) ||
			( ( board[2] == board[6] ) && ( board[6] == board[10] ) && ( board[10] == board[14] ) && ( board[14] == 2 ) ) ||
			( ( board[3] == board[7] ) && ( board[7] == board[11] ) && ( board[11] == board[15] ) && ( board[15] == 2 ) ) ||
			// Down Condition
			( ( board[0] == board[5] ) && ( board[5] == board[10] ) && ( board[10] == board[15] ) && ( board[15] == 2 ) ) ||
			( ( board[3] == board[6] ) && ( board[6] == board[9] ) && ( board[9] == board[12] ) && ( board[12] == 2 ) )
			// Diagonal Condition
		) {
			xWin = 1 ;
			}
		if (
			( ( board[0] == board[1] ) && ( board[1] == board[2] ) && ( board[2] == board[3] ) && ( board[3] == 2 ) ) ||
			( ( board[4] == board[5] ) && ( board[5] == board[6] ) && ( board[6] == board[7] ) && ( board[7] == 2 ) ) ||
			( ( board[8] == board[9] ) && ( board[9] == board[10] ) && ( board[10] == board[11] ) && ( board[11] == 2 ) ) ||
			( ( board[12] == board[13] ) && ( board[13] == board[14] ) && ( board[14] == board[15] ) && ( board[15] == 2 ) ) ||
			// Across Condition
			( ( board[0] == board[4] ) && ( board[4] == board[8] ) && ( board[8] == board[12] ) && ( board[12] == 2 ) ) ||
			( ( board[1] == board[5] ) && ( board[5] == board[9] ) && ( board[9] == board[13] ) && ( board[13] == 2 ) ) ||
			( ( board[2] == board[6] ) && ( board[6] == board[10] ) && ( board[10] == board[14] ) && ( board[14] == 2 ) ) ||
			( ( board[3] == board[7] ) && ( board[7] == board[11] ) && ( board[11] == board[15] ) && ( board[15] == 2 ) ) ||
			// Down Condition
			( ( board[0] == board[5] ) && ( board[5] == board[10] ) && ( board[10] == board[15] ) && ( board[15] == 2 ) ) ||
			( ( board[3] == board[6] ) && ( board[6] == board[9] ) && ( board[9] == board[12] ) && ( board[12] == 2 ) )
			// Diagonal Condition
		) {
			oWin = 1 ;
			}
	}
	if ( size == 5 ) {
		if (
			( ( board[0] == board[1] ) && ( board[1] == board[2] ) && ( board[2] == board[3] ) && ( board[3] == board[4] ) && ( board[4] == 2 ) ) ||
			( ( board[5] == board[6] ) && ( board[6] == board[7] ) && ( board[7] == board[8] ) && ( board[8] == board[9] ) && ( board[9] == 2 ) ) ||
			( ( board[10] == board[11] ) && ( board[11] == board[12] ) && ( board[12] == board[13] ) && ( board[13] == board[14] ) && ( board[14] == 2 ) ) ||
			( ( board[15] == board[16] ) && ( board[16] == board[17] ) && ( board[17] == board[18] ) && ( board[18] == board[19] ) && ( board[19] == 2 ) ) ||
			( ( board[20] == board[21] ) && ( board[21] == board[22] ) && ( board[22] == board[23] ) && ( board[23] == board[24] ) && ( board[24] == 2 ) ) ||
			// Across Condition
			( ( board[0] == board[5] ) && ( board[5] == board[10] ) && ( board[10] == board[15] ) && ( board[15] == board[20] ) && ( board[20] == 2 ) ) ||
			( ( board[1] == board[6] ) && ( board[6] == board[11] ) && ( board[11] == board[16] ) && ( board[16] == board[21] ) && ( board[21] == 2 ) ) ||
			( ( board[2] == board[7] ) && ( board[7] == board[12] ) && ( board[12] == board[17] ) && ( board[17] == board[22] ) && ( board[22] == 2 ) ) ||
			( ( board[3] == board[8] ) && ( board[8] == board[13] ) && ( board[13] == board[18] ) && ( board[18] == board[23] ) && ( board[23] == 2 ) ) ||
			( ( board[4] == board[9] ) && ( board[9] == board[14] ) && ( board[14] == board[19] ) && ( board[19] == board[24] ) && ( board[24] == 2 ) ) ||
			// Down Condition
			( ( board[0] == board[6] ) && ( board[6] == board[12] ) && ( board[12] == board[18] ) && ( board[18] == board[24] ) && ( board[24] == 2 ) ) ||
			( ( board[4] == board[8] ) && ( board[8] == board[12] ) && ( board[12] == board[16] ) && ( board[16] == board[20] ) && ( board[20] == 2 ) ) 
			// Diagonal Condition
		) {
			xWin = 1 ;
			}
		if (
			( ( board[0] == board[1] ) && ( board[1] == board[2] ) && ( board[2] == board[3] ) && ( board[3] == board[4] ) && ( board[4] == 1 ) ) ||
			( ( board[5] == board[6] ) && ( board[6] == board[7] ) && ( board[7] == board[8] ) && ( board[8] == board[9] ) && ( board[9] == 1 ) ) ||
			( ( board[10] == board[11] ) && ( board[11] == board[12] ) && ( board[12] == board[13] ) && ( board[13] == board[14] ) && ( board[14] == 1 ) ) ||
			( ( board[15] == board[16] ) && ( board[16] == board[17] ) && ( board[17] == board[18] ) && ( board[18] == board[19] ) && ( board[19] == 1 ) ) ||
			( ( board[20] == board[21] ) && ( board[21] == board[22] ) && ( board[22] == board[23] ) && ( board[23] == board[24] ) && ( board[24] == 1 ) ) ||
			// Across Condition
			( ( board[0] == board[5] ) && ( board[5] == board[10] ) && ( board[10] == board[15] ) && ( board[15] == board[20] ) && ( board[20] == 1 ) ) ||
			( ( board[1] == board[6] ) && ( board[6] == board[11] ) && ( board[11] == board[16] ) && ( board[16] == board[21] ) && ( board[21] == 1 ) ) ||
			( ( board[2] == board[7] ) && ( board[7] == board[12] ) && ( board[12] == board[17] ) && ( board[17] == board[22] ) && ( board[22] == 1 ) ) ||
			( ( board[3] == board[8] ) && ( board[8] == board[13] ) && ( board[13] == board[18] ) && ( board[18] == board[23] ) && ( board[23] == 1 ) ) ||
			( ( board[4] == board[9] ) && ( board[9] == board[14] ) && ( board[14] == board[19] ) && ( board[19] == board[24] ) && ( board[24] == 1 ) ) ||
			// Down Condition
			( ( board[0] == board[6] ) && ( board[6] == board[12] ) && ( board[12] == board[18] ) && ( board[18] == board[24] ) && ( board[24] == 1 ) ) ||
			( ( board[4] == board[8] ) && ( board[8] == board[12] ) && ( board[12] == board[16] ) && ( board[16] == board[20] ) && ( board[20] == 1 ) )
			// Diagonal Condition
		) {
			oWin = 1 ;
			}
	}
	
	if ( xWin == 1 ) {
		cout << "X wins\n" ;
		exit(0) ;
	}
	if ( oWin == 1 ) {
		cout << "O wins\n" ;
		exit(0) ;
	}
	if ( moveCount < ( size * size ) ) {
	}
	else {
		cout << "Tie\n" ; 
		exit(0) ;
	}
}
	
int main () {
	int move ;
	int turn ;
	while ( cin >> size ) {
	// asking for a grid size and error checking

	while ( moveCount < ( size * size ) ) {
		if ( ( move > ( size * size ) ) || ( move < 1 ) ) {
			if ( moveCount == 0 ) {
			}
			else {
				move-- ;
				moveCount-- ;
			}
		}
		// checks that the space is available for play
			if ( ( moveCount % 2 ) == 1 ) {
				cin >> move ;
				turn = 2 ;
			}	
			if ( ( moveCount % 2 ) == 0 ) {
				cin >> move ;
				turn = 1 ;
			}
			// checks whose turn it is
			if ( !( board[ ( move - 1 ) ] == 0 ) ) {
				move-- ;
			}
			// verifies that the space is empty
			if ( board[ ( move - 1 ) ] == 0 ) {
				board[ ( move - 1 ) ] = turn ;
				moveCount++ ;
			}
			// if the space is empty, passes it on officially to the board and moveCount
		winCondition() ;
	}
	}
	return 0 ;
}
