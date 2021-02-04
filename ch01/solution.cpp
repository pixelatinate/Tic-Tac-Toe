// challenge 1, solution.cpp
// This lab reads in a tic-tac-toe board and checks if 
//		it's the right size
//	COSC 140
//	Swasti Mishra
//	02/04/21
//	Professor Emrich
//	Students: Trish Nguyen, Katie Nuchols, Jacob Malloy

# include <iostream>
# include <sstream>
# include <vector>
# include <string>
# include <fstream>

using namespace std ;

int main( int argc, char *argv[]  ) {

	unsigned int boardsize ;
	vector <int> board ;
	char bufferCharacter ;
	// handle the incorrect number of arguments
	
	if ( argc != 2 ) {
		cout << "Error!  Invalid no. of command line arguments!\n" ;
		return 1 ;
	}

	// read the boardsize using stringstream and check for incorrect input
	stringstream stream( argv[1] ) ;	// from Dr. Emrich's Lecture
	
	if ( !( stream >> boardsize ) ){
		cout << "Error!  Invalid no. of command line arguments!\n" ;
		return 1 ;
	}

	// add all of the input characters to the vector 
	while ( cin >> bufferCharacter ){
		board.push_back( bufferCharacter ) ;
	}

	// compare the size of the vector to the expected and output the result
	if ( board.size() == ( boardsize * boardsize ) ){
			cout << "Valid board\n" ;
	}
	else if ( board.size() > ( boardsize * boardsize ) ){
		cout << "Too many cells for a " << boardsize << " x " << boardsize << " board\n" ;
	}
	else if ( board.size() < ( boardsize * boardsize ) ){
		cout << "Too few cells for a " << boardsize << " x " << boardsize << " board\n" ;
	}

	return 0 ;
}
