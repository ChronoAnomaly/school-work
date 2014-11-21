/*
 *	Brett Worley
 *	CS-3100-01
 *	11/20/14
 */
#include <iostream>

/*
 *	This program prints out the shortest path between two nodes that the 
 *	user types in.  The graph is based on the path matrix that is shown
 *	in lecture 35.
 */
int main()
{

	const int ROW = 4;
	const int COLUMN = 4;

	int path[ROW][COLUMN] = {
		{ -1, -1, 1, 1},
		{ 3, -1, -1, -1},
		{ 1, -1, -1, 1},
		{ -1, 2, -1, -1},
	};

	int row, column;

	std::cout << "Select the starting node and the node you want to end at: ";
	std::cin >> row >> column;
	std::cout << std::endl;

	if( (row < ROW) && (column < COLUMN) && (row >= 0) && (column >= 0) ){

		while( path[row][column] != -1) {
			std::cout << row << " -> ";
			row = path[row][column];
		}
	
		std::cout << row << " -> " << column << std::endl;
	
	} else {
		std::cout << "One of the nodes do not exist." << std::endl;
	}

	return 0;
}
