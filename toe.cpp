// lab 1, toe.cpp
// This lab plays a little game of tic tac toe with you.
// COSC 140
// Swasti Mishra
// 01/24/21
// Professor Emrich
// Students:

# include <iostream>
# include <limits> 
# include <vector>
# include <string>

using namespace std ;

int main () {

	unsigned int size ;

	cout << "Enter a grid size (Options: 3, 4, 5) " ;
	while ( ( size > 5 ) || ( size < 3 ) ) {
		cin >> size ;
	}
	// asking for a grid size and error checking

	char board[ size ][ size ] ;
	for ( unsigned int i = 0 ; i < size ; i++ ) {
		for ( unsigned int j = 0 ; j < size ; j++ ) {
			board[ j ] = { '-' } ;
		}
	}
	// builds the board AFTER accepting the size

	for ( unsigned int i = 0 ; i < ( size * size ) ; i++ ) {
			cout << board << "\n" ;
	}
}
	

