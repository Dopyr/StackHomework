#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>

using namespace std;
#define arraySize 100

class StackChar {

public:

	int index;
	char charList[arraySize];

	StackChar()
	{
		index = -1;
	}


	int size();
	void push(char letter);
	char pop();
};

class StackInteger {

public:

	int index;
	int intList[arraySize] = {};
	
	StackInteger() 
	{
		index = -1;
	}

	int size();
	void push(char number);
	int pop();
};

int StackInteger::size() {

	return index + 1;
}

int StackChar::size() {

	return index + 1;
}


void StackInteger::push(char element) {

	if (size() == arraySize) {

		return;
	
	} else {
			element = element - '0';
			intList[++index] = element;
			cout << intList[index] << " pushed to integer stack " << endl;

	}
}

int StackInteger::pop() {

	if (size() == 0) {
	
		return 0;
	
	} else {

		int deleteInt = intList[index--];
		cout << deleteInt << " popped" << endl;
		return deleteInt;
	}
}

void StackChar::push(char element) {

	if (size() == arraySize) {

		return;

	} else {

			charList[++index] = element;
			cout << charList[index] << " pushed to char stack" << endl;
	}
}

char StackChar::pop() {

	if (size() == 0) {
	
		return 0;
	
	} else {

		return charList[index--];
	}
}

string createPattern(string previousResult, StackChar charStack, StackInteger intStack) {

	string buffer;
	string result;
	char ch = '#';

	while (ch != '[') {

		ch = charStack.pop();

		if (ch == '[') {

			int reps = intStack.pop();

			previousResult += buffer;

			for (int i = 0; i < reps; i++) {

				result += previousResult;

			}

		}
		else if (ch == ']') {

			continue;

		} else {

			buffer += ch;

		}
	}

	if (charStack.size() > 0) {

		return createPattern(result, charStack, intStack);

	} else {

		return result;

	}
}

int main() {

	StackChar charStack;
	StackInteger intStack;

	string str;
	cin >> str;
	
	for (char ch : str) {

		if (isalpha(ch) || '[' == ch || ']' == ch) {

			charStack.push(ch);

		} else if (isdigit(ch)) {
			
			intStack.push(ch);

		} else if (']' == ch) {
			charStack.pop();

		} 
	}

	cout << createPattern(str = "",  charStack ,  intStack) << endl;

}
