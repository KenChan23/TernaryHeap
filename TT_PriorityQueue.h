//*********************************************************************************************************************************************************
// This is a header file that contains the declaration of the class TT_PriorityQueue.                                                                     *
// The class holds information about a priority queue structured from a ternary heap.                                                                     *
// The definition of the class TT_PriorityQueue is comprised of the following components:                                                                 *
//    - Three private member variables                                                                                                                    *
//          - *array                                                                                                                                      *
//                - A pointer to a memory location of an integer variable that will be used for the dynamic allocation of an array.                       *
//          - size                                                                                                                                        *
//                - An integer variable that holds the capacity of the array.                                                                             *
//          - total_current_elements                                                                                                                      *
//                - An integer variable that holds the total number of elements currently within the array at an instance.                                *
//    - One constructor prototype                                                                                                                         *
//          - TT_PriorityQueue(int maximum_size);                                                                                                         *
//                      - The description of the function is written in the implementation file.                                                          *
//    - One destructor prototype                                                                                                                          *
//          - ~TT_PriorityQueue();                                                                                                                        *
//                      - The description of the function is written in the implementation file.                                                          *
//    - Two public mutator functions' prototypes                                                                                                          *
//          - void push(int data);                                                                                                                        *
//                      - The description of the function is written in the implementation file.                                                          *
//          - int pop();                                                                                                                                  *
//                      - The description of the function is written in the implementation file.                                                          *
//    - One public accessor function's prototype                                                                                                          *
//          - int top();                                                                                                                                  *
//                      - The description of the function is written in the implementation file.                                                          *
//    - One overloaded operator's prototype                                                                                                               *
//          - friend ostream& operator << (ostream&, TT_PriorityQueue &);                                                                                 *
//                      - The description of the operator is written in the implementation file.                                                          *
//*********************************************************************************************************************************************************

#ifndef TT_PriorityQueue_H
#define TT_PriorityQueue_H

#include <iostream>
using namespace std;

class TT_PriorityQueue
{

    friend ostream& operator << (ostream&, TT_PriorityQueue &);

    public:

        TT_PriorityQueue(int maximum_size);
        ~TT_PriorityQueue();
        void push(int data);
        int pop();
        int top();

    private:

        int size;
        int total_current_elements;
        int *array;

};

#endif
