#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	static string original_string = "Invention, my dear friends, is 93 % perspiration, 6 % electricity, 4 % evaporation, and 2 % butterscotch ripple";  // Define the original, static string
	vector<string> new_string;  // Initializing new_string as a vector
	vector<string>::iterator itr;  // Initializing an iterator
	string temp_string;  // Initializing string variable

	new_string.clear();  // Clear the nre string

	for (unsigned int i = size(original_string); i > 0; i--)	// Loop backward through the static string
	{
		temp_string = original_string[i-1];  // taking element from original string
		new_string.push_back(temp_string);  // add that element to the end of a vector nre_string
	}

	cout << "new string contains:\n";  // print the string that explain what should be printed

	for (itr = new_string.begin(); itr < new_string.end(); itr++)  // iterate a vector
		cout << *itr;  // print vector elements

	return 0;
}