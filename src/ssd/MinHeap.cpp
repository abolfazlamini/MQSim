#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 
// Data structure for Min Heap
struct PriorityQueue 
{
private:
    // vector to store heap elements
    vector<int> A;
 
    // return parent of A[i]
    // don't call this function if i is already a root node
    int PARENT(int i) 
    { 
        return (i - 1) / 2; 
    }
 
    // return left child of A[i]    
    int LEFT(int i) 
    { 
        return (2 * i + 1); 
    }
 
    // return right child of A[i]    
    int RIGHT(int i) 
    { 
        return (2 * i + 2); 
    }
 
    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    // violates the heap property
    void heapify_down(int i)
    {
        // get left and right child of node at index i
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int smallest = i;
 
        // compare A[i] with its left and right child
        // and find smallest value
        if (left < size() && A[left] < A[i])
            smallest = left;
 
        if (right < size() && A[right] < A[smallest])
            smallest = right;
 
        // swap with child having lesser value and 
        // call heapify-down on the child
        if (smallest != i) {
            swap(A[i], A[smallest]);
            heapify_down(smallest);
        }
    }
 
    // Recursive Heapify-up algorithm
    void heapify_up(int i)
    {
        // check if node at index i and its parent violates 
        // the heap property
        if (i && A[PARENT(i)] > A[i]) 
        {
            // swap the two if heap property is violated
            swap(A[i], A[PARENT(i)]);
            
            // call Heapify-up on the parent
            heapify_up(PARENT(i));
        }
    }
    
public:
    // return size of the heap
    unsigned int size()
    {
        return A.size();
    }
 
    // function to check if heap is empty or not
    bool empty()
    {
        return size() == 0;
    }
    
    // insert key into the heap
    void push(int key)
    {
        // insert the new element to the end of the vector
        A.push_back(key);
 
        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }
 
    // function to remove element with lowest priority (present at root)
    void pop()
    {
        try {
            // if heap has no elements, throw an exception
            if (size() == 0)
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
 
            // replace the root of the heap with the last element
            // of the vector
            A[0] = A.back();
            A.pop_back();
 
            // call heapify-down on root node
            heapify_down(0);
        }
        // catch and print the exception
        catch (const out_of_range& oor) {
            cout << "\n" << oor.what();
        }
    }
 
    // function to return element with lowest priority (present at root)
    int top()
    {
        try {
            // if heap has no elements, throw an exception
            if (size() == 0)
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
 
            // else return the top (first) element
            return A.at(0);    // or return A[0];
        }
        // catch and print the exception
        catch (const out_of_range& oor) {
            cout << "\n" << oor.what();
        }
    }
};
 
// Min Heap C++ Implementation
// int main()
// {
//     PriorityQueue pq;
    
//     // Note - Priority is decided by element's value
    
//     pq.push(3);
//     pq.push(2);
//     pq.push(15);
    
//     cout << "Size is " << pq.size() << endl;    
    
//     cout << pq.top() << " ";
//     pq.pop();
 
//     cout << pq.top() << " ";
//     pq.pop();
 
//     pq.push(5);
//     pq.push(4);
//     pq.push(45);
 
//     cout << endl << "Size is " << pq.size() << endl;
    
//     cout << pq.top() << " ";
//     pq.pop();
 
//     cout << pq.top() << " ";
//     pq.pop();
 
//     cout << pq.top() << " ";
//     pq.pop();
 
//     cout << pq.top() << " ";
//     pq.pop();
 
//     cout << endl << std::boolalpha << pq.empty();
    
//     pq.top();    // top operation on an empty heap
//     pq.pop();    // pop operation on an empty heap
 
//     return 0;
// }