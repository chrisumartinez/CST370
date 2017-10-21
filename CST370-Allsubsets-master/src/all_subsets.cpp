//============================================================================
// Name        : all_subsets.cpp
// Author      : Christian Martinez
// Date			: 2/22/17
// ID			: 7354
// Description : This program should receive n characters and return the
//					subsets of all characters.
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/*
 * Functions
 */
int promptInputNumber();
string promptInputChar();
vector<string> stringSplit(string);
void createSubsets(vector<string>, int);


int main() {
	int num = promptInputNumber();
	string str  = promptInputChar();
	vector<string> newVect = stringSplit(str);
	createSubsets(newVect, num);
	return 0;
}

/*
 * prompts the user for the amount of input characters
 * and the input characters.
 * @returns int, char[]
 */

int promptInputNumber() {
	int inputNumber = 0;
	cout << "Input the amount of input characters: " << endl;
	cin >> inputNumber;
	if (cin.fail()) {
		cin.clear();
		cout << "Enter a Correct Value." << endl;
		promptInputNumber();
	} else {
		if (inputNumber > 15) {
			cout << "Enter a valid amount of characters" << endl;
			promptInputNumber();
		} else {
			return inputNumber;
		}
	}
}
/*
 * prompts the user for the input characters in a string.
 * @returns string
 */
string promptInputChar(){
	string inputChar = "";
	cout << "Enter input Characters: " << endl;
	cin >> inputChar;
	if(cin.fail()){
		cin.clear();
		cout << "Enter a Correct Value." << endl;
		promptInputChar();
	} else {
		return inputChar;
	}
}
/*
 * splits the String into a char vectorList.
 */
vector<string> stringSplit(string s){
	vector<string> charList;
	stringstream ss(s);
	char delim = ',';
	string charLetter;

	while(getline(ss, charLetter, delim)){
		charList.push_back(charLetter);
	}
	return charList;
}
/*
 * Create and print subsets from the string given.
 */
void createSubsets(vector<string> subsets, int num){
	//2^n  = 1 << n
	int length = subsets.size();
	for(int i = 0; i < (1 << length); i++){
		cout << " { ";

		for(int j = 0; j < length; j++){
			if((i & (1 << j)) > 0){
				cout << subsets[j] << ",";
			}
		}
		cout << " } " << endl;;
	}
}
