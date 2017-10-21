//============================================================================
// Name        : power.cpp
// Author      : Christian Martinez
// Student ID     : 7354
// Description : Using a recursive function to compute 2^n
//============================================================================

#include <iostream>
using namespace std;

int promptInput();
int calcFunc(int);


int main() {
	int exponent = promptInput();
	int result = calcFunc(exponent);
	cout << "Result: " << result << endl;
	return 0;
}

/*
 * Prompt the input from the user.
 * @return input
 */
int promptInput(){
	int input = 0;
	cout << "Enter a Number: " << endl;
	cin >>  input;
	return input;
}
/*
 * recursive function to call to return output of 2^n.
 * @param input: the exponent value
 */
int calcFunc(int input){
	//2^0 = 1, addd 1
	if(input == 0){
		return 1;
	}else{
		//2^5 = 2 ^4 + 2^3 + 2 ^2 + 2 ^ 1 + 2 ^ 1 + 2 ^0 + 1
		input--;
		return 2 * calcFunc(input);
	}

}


