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
int board[ 25 ] ;
// 2 will be an empty space, 1 will be Xs, and 0 will be Os.

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
}
// The point of this function is to convert the array to a visual board.
// You would think one should skip the step and just take the array in as
//		chars of Xs and Os, but I tried that for no joke, a couple of hours
//		before realizing it was a fool's errand.

void winCondition() {
	bool winCount = false ;
	bool xWin = false ;
	bool oWin = false ;
	int consecutive = 0 ;
	for ( int i = 0 ; i < ( size * size ) ; i++ ) {	// checks every cell on the board
		if ( ( i % size ) == 0 ) {						// breaks if cell is first in a row
			if ( board[ i ] == board[ i + 1 ] ) {		// checks if cell is same as next cell
				i++	;									// if it is, increments to next
				consecutive++ ;
			}
			if ( consecutive == size ) {
				winCount = true ;
				if ( board[ i ] == 2 ) {
					xWin = true ;		
				}
				if ( board[ i ] == 1 ) {
					oWin = true ;
				}
			}										
				else {									// if not, leaves
					winCount = false ;
				}	
			} while	( i < size ) ;						// increments 
		}
		cout << winCount << xWin << oWin ;
	}
	// Across Condition
int main () {
	int moveCount = 0 ;
	int move ;
	int turn ;
	cout << "Enter a grid size (Options: 3, 4, 5): " ;
	while ( ( size > 5 ) || ( size < 3 ) ) {
		cin >> size ;
	}
	// asking for a grid size and error checking

	while ( moveCount < ( size * size ) ) {
		printBoard() ;
		if ( ( moveCount % 2 ) == 1 ) {
			cout << "Player X: " ;
			cin >> move ;
			turn = 2 ;
		}
		if ( ( moveCount % 2 ) == 0 ) {
			cout << "Player O: " ;
			cin >> move ;
			turn = 1 ;
		}
		// checks whose turn it is
		if ( !( board[ ( move - 1 ) ] == 0 ) ) {
			cout << "This space has already been filled. Please pick another.\n" ;
			move-- ;
		}
		// verifies that the space is empty
		if ( ( move > ( size * size ) ) || ( move < 1 ) ) {
			cout << "You have selected an invalid space. Please pick another.\n" ;
			move-- ;
		}
		// verifies that the space is on the board
		if ( board[ ( move - 1 ) ] == 0 ) {
			board[ ( move - 1 ) ] = turn ;
			moveCount++ ;
		}
		// if the space is empty, passes it on officially to the board and moveCount
	}
	
	winCondition() ;
	printBoard() ;

}
