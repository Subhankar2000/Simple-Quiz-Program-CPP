#include <iostream>

using namespace std;

int main()
{
	// Declaring variables
	int a, b, c;

	// Accepting values from users
    cout << "Enter value for a :: ";
    cin >> a;
    
    cout << "Enter value for b :: ";
    cin >> b;
    
    cout << "Enter value for c :: ";
    cin >> c;
	
	// Comparing with if-else-if structure
	if (a > b && a > c)
	   cout <<  "a is largest"  <<  endl;
	else if (b > a && b > c)
	   cout <<  "b is largest"  <<  endl;  
	else if (c > a && c > b)
	   cout <<  "c is largest"  <<  endl; 
	else
	   cout <<  "None of them is the largest" << endl;
	   

}
