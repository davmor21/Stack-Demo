#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack stack;  //Declare a Stack object
	int num;
	char choice;  //user menu selection


	cout << "Welcome to the Stack Demo" << endl << endl;

	do {
		//display menu
		cout << endl;
		cout << "1. Push a node" << endl;
		cout << "2. Pop a node" << endl;
		cout << "3. Print the stack" << endl;
		cout << "4. Check the size" << endl;
		cout << "5. Check the top" << endl;
		cout << "6. Clear the stack" << endl;
		cout << "7. Find an item" << endl;
		cout << "0. Quit" << endl;

		cout << endl << "Enter your selection: ";
		cin >> choice;

		//perform the selected menu option
		switch (choice) {

		case '1':
			cout << "Enter a number to push on the stack: ";
			cin >> num;
			stack.push(num);
			break;
		case '2':
			stack.pop(num);
			break;
		case '3':
			stack.printStack();
			break;
		case '4':
			stack.printSize();
			break;
		case '5':
			stack.peek();
			break;
		case '6':
			stack.clearStack();
			break;
		case '7':
			cout << "Enter the number to find in the stack: ";
			cin >> num;
			stack.findItem(num);
			break;
		case '0':
			break;
		default:
			cout << "That is not a valid option, please try again." << endl;
		} // of of switch
	} while (choice != '0');

	cout << endl << "Goodbye" << endl << endl;
	return 0;
}