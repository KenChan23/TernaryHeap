// Ken Chan (Ternary Heaps)
// This program demonstrates the functionality of a priority queue in regards to ternary heaps.
// The following is a general step-by-step procedure the program follows:
//   1.) Employs try and catch blocks to handle thrown exceptions whenever errors are encountered.
//   2.) Declares several integer variables to assist in the progression of the program.
//   3.) Requests for the value of the array's size to be inputted.
//            - If the user inputs a value that is zero or negative, then the program will continuously request for an integer value that is positive.
//   4.) Creates a TT_PriorityQueue object by sending the previously inputted array size as a parameter for the constructor.
//   5.) Requests the user to input individual values to be pushed into the priority queue and prints the array and the top value (root value) after each push.
//   6.) Prints the sorted sequence of the values pushed due to pop function.
//   7.) Terminates upon complete execution of the program.
 
#include "TT_PriorityQueue.h"

#include <iostream>
using namespace std;

int main()
{

    try
    {

        int size, value, count;

        cout << "The purpose of this program is to implement a priority queue by using a ternary heap." << endl << endl;

        cout << "Please input the number of values you wish to process: ";
        cin >> size;

        while(size <= 0)
        {

            cout << "Please input a positive number of values: ";
            cin >> size;

        }

        cout << endl;

        TT_PriorityQueue ttpq(size);

        for(count = 0; count < size; count++)
        {

            cout << "Please input a value to push into the queue: ";
            cin >> value;

            ttpq.push(value);

            cout << "The queue currently holds the following: " << endl;
            cout << ttpq;

            cout << "The top value (root value) is currently the following: " << endl;
            cout << ttpq.top() << endl << endl;

        }

        cout << "The sorted sequence of the inputted values is the following: " << endl;

        for(count = 0; count < size; count++)

            cout << ttpq.pop() << " ";

        cout << endl << endl;

	}

    catch(char const* message)
    {

        cout << message;

    }

    return 0;

}
