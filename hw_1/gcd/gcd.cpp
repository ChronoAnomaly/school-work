/*
  Brett Worley
  CS 3100 - 01
  8/28/14 */



#include <iostream>

using namespace std;

void gcd(int x, int y);

/* Prompts the user to enter two numbers. The program will then
 call the gcd function to find the largest GCD. */
int main ()
{

	int x, y;

	cout << "Enter two number to find the GCD between them: " << endl;
	cin >> x >> y;

	gcd(x, y);
	
	return 0;
}

/* Finds the largest GCD of the two numbers x and y. */
void gcd(int x, int y)
{

	int i, div;
	div = 0;

	for(i = 1; i <= x && i <= y; i++){
		
		if((x % i == 0) && (y % i == 0)){
			div = i;
		}
	}
	
	cout << "The GCD of " << x << " and " << y << " is : " << div << endl;
}
