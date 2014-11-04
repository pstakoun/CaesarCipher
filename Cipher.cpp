//______________________________________________________________________________
//
// Cipher
//
// This class prompts the user for a string and a key.
// The given string is the encoded using the given key.
//

#include <iostream>
#include <string>
using namespace std;

string encode(string, int);

int main()
{
	// Get values from user and print encoded string.

	// Create variables
	string str;
	int key;

	// Get string from user.
	cout << "String to encode: ";
	getline(cin, str);

	// Get key from user.
	cout << "Key to encode with: ";
	cin >> key;

	// Print the encoded string.
	cout << encode(str, key) << "\n";

	system("pause");
	return 0;
}

// Encode the given string using the given key.
string encode(string str, int key)
{
	// Encode the given string with the given key.

	string newStr = "";

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];

		// Check if the given character is alpha
		if (isalpha(c)) {
			// Record whether or not the character is uppercase.
			bool upper = isupper(c);

			// Convert the character to lowercase for easier calculations.
			c = tolower(c);

			// Encode the character.
			c = (((c - 97) + key) % 26) + 97;

			// Put the character into its beginning case.
			if (upper) {
				newStr += toupper(c);
			} else {
				newStr += c;
			}
		} else {
			newStr += c;
		}
	}
	// Return the encoded string.
	return newStr;
}
