// C++ program for the above approach
#include <iostream>
using namespace std;

// Driver Code
int main()
{
	// Initialize the specific length
	// and character of string
	int L;
	char C;

	// Initialize the empty string
	// for concatenation
	string str = "";

	// Input the specific length and
	// character of string
	cin >> L;
	cin >> C;

	// Run the for loop L times
	for (int i = 0; i < L; i++)
		str = str + C;

	// Output the result string
	cout << str;

	return 0;
}
