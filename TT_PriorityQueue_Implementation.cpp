// * The runtime of the push and pop functions is logarithmic time.

#include "TT_PriorityQueue.h"

#include <iostream>
using namespace std;

//*********************************************************************************************************************************************************
//                                                          void swap(int* data, int x, int y)                                                            *
// - This function swaps the values in two positions, x and y, of an array called data.                                                                   *
// - This function operates in the following manner:                                                                                                      *
//       - Establishes an integer variable called temporary to contain the value held within an array position (data[x]).                                 *
//       - Sets the value in the array position (data[x]) to the value contained in another array position (data[y]).                                     *
//       - Sets the value in the array position (data[y]) to the value contained in the temporary variable.                                               *
//       - Returns no values upon completion.                                                                                                             *
//*********************************************************************************************************************************************************
void swap(int* data, int x, int y)
{

	int temporary = data[x];
	data[x] = data[y];
	data[y] = temporary;

}

//*********************************************************************************************************************************************************
//                                                              int minimum(int* data, int x, int y)                                                      *
// - This function compares the elements at two positions, x and y, of an array called data and determines the position that holds the smallest value.    *
// - This function operates in the following manner:                                                                                                      *
//       - Returns position x if the value in position x is smaller than the value in position y.                                                         *
//       - Returns position y if otherwise.                                                                                                               *
//*********************************************************************************************************************************************************
int minimum(int* data, int x, int y)
{

	if (data[x] <= data[y])

		return x;

	return y;

}

//*********************************************************************************************************************************************************
//                                                      TT_PriorityQueue::TT_PriorityQueue(int maximum_size)                                              *
// - This function serves as a constructor of the TT_PriorityQueue class that accepts a parameter that denotes the maximum size of the array.             *
// - This function operates in the following manner:                                                                                                      *
//       - Sets the private member variable size to the value contained in the maximum_size variable.                                                     *
//       - Sets the private member variable total_current_elements to zero.                                                                               *
//       - Dynamically allocates an array of a size determined by the user in the main program.                                                           *
//*********************************************************************************************************************************************************
TT_PriorityQueue::TT_PriorityQueue(int maximum_size)
{

	size = maximum_size;
	total_current_elements = 0;
	array = new int[size];

}

//*********************************************************************************************************************************************************
//                                                          TT_PriorityQueue::~TT_PriorityQueue()                                                         *
// - This function serves as a destructor of the TT_PriorityQueue class.                                                                                  *
// - This function operates in the following manner:                                                                                                      *
//       - Releases the memory pointed to by the pointer of type integer array.                                                                           *
//*********************************************************************************************************************************************************
TT_PriorityQueue::~TT_PriorityQueue()
{

	delete[] array;

}

//*********************************************************************************************************************************************************
//                                                                  void TT_PriorityQueue::push(int data)                                                 *
// - This function enables the pushing of elements into a priority queue and proper modification of this queue each time a new element is pushed.         *
// - This function receives one parameter that contains the data to be pushed.                                                                            *
// - This function operates in the following manner:                                                                                                      *
//       - Throws a message that indicates the queue is full if the current total number of elements in the queue equals its capacity.                    *
//       - Pushes an element while retaining the complete property of ternary trees.                                                                      *
//       - Makes modifications by swapping if the parent element is larger than the child element and continues towards the root of the tree until        *
//         the conditions within the while loop are not satsified.                                                                                        *
//       - Returns no values upon completion.                                                                                                             *
//*********************************************************************************************************************************************************
void TT_PriorityQueue::push(int data)
{

	if (total_current_elements == size)

		throw "Queue is full.";

	array[total_current_elements] = data;
	total_current_elements++;

	// * Subsequent code within this function enables the insertion of the pushed element into the correct position.

	int child, parent;

	child = total_current_elements - 1;
	parent = (child - 1) / 3;

	while(parent >= 0 && array[parent] > array[child])
	{

		swap(array, parent, child);
		child = parent;
		parent = (child - 1) / 3;

	}

}

//*********************************************************************************************************************************************************
//                                                          int TT_PriorityQueue::pop()                                                                   *
// - This function enables the popping of elements from the priority queue and proper modification of this queue each time a new element is pushed.       *
// - This function operates in the following manner:                                                                                                      *
//       - Throws a message that indicates the queue is empty if the current total number of elements in the queue equals zero.                           *
//       - Pops an element while retaining the complete property of ternary trees.                                                                        *
//       - Makes modifications by determining the position of the smallest of the three children of a parent node and swapping the value contained        *
//         at this position with the value stored at the parent node continues towards the root of the tree until the condition within the while          *
//         loop is not satsified.                                                                                                                         *
//       - Returns the popped value upon completion.                                                                                                      *
//*********************************************************************************************************************************************************
int TT_PriorityQueue::pop()
{

	if (total_current_elements == 0)

		throw "Queue is empty.";

	int popped_value = array[0];

	array[0] = array[--total_current_elements];

	// * Subsequent code within this function readjusts the heap to perpetually satsify the properties of the priority queue.

	int parent = 0, child1, child2, child3, first_minimum_child, second_minimum_child;

	while((3 * parent + 1) < total_current_elements)
	{

		child1 = 3 * parent + 1;
		child2 = child1 + 1;
		child3 = child2 + 1;
		first_minimum_child = minimum(array, child1, child2);
        second_minimum_child = minimum(array, first_minimum_child, child3);

		if (array[parent] <= array[second_minimum_child])

			break;

		swap(array, parent, second_minimum_child);
		parent = second_minimum_child;

	}

	return popped_value;

}

//*********************************************************************************************************************************************************
//                                                          int TT_PriorityQueue::top()                                                                   *
// - This function returns the value of the top element of the array (the value at the root of the ternary tree).                                         *
// - If there are no elements in the priority queue, then an exception is thrown to handle this error.                                                    *
//*********************************************************************************************************************************************************
int TT_PriorityQueue::top()
{

	if (total_current_elements == 0)

		throw "Queue is empty.";

	return array[0];

}

//*********************************************************************************************************************************************************
//                                ostream& operator << (ostream& out, TT_PriorityQueue &ternary_tree)                                                     *
// - This function overloads the outstream operator to output data.                                                                                       *
//*********************************************************************************************************************************************************
ostream& operator << (ostream& out, TT_PriorityQueue &ternary_tree)
{

	int count;

	for(count = 0; count < ternary_tree.total_current_elements; count++)

		out << ternary_tree.array[count] << " ";

	out << endl;

	return out;

}
