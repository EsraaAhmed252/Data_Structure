/*** Stack By Linked List ***/

#include <iostream>
using namespace std;

// StackNode Structure
struct stackNode
{
    int data;
    stackNode *next;
};

// Class
class LinkedListStack {

private:

    stackNode *top;

public:

    // No-arguments Constructor
    LinkedListStack()
    {
        top = NULL;
    }

    // Check If Stack Is Empty
    bool isEmpty(void)
    {
        return (top == NULL);
    }

    // Add Data To Stack
    void push(int d)
    {
        stackNode *ptr = new stackNode;
        ptr->data = d;
        ptr->next = top;
        top = ptr;
    }

    // Get Data From Stack
    int pop(void)
    {
        int d;
        stackNode *ptr;
        d = top->data;
        ptr = top;
        top = top->next;
        delete ptr;
        return d;
    }

    // Get No. Of Elements
    int getNumberOfElements(void)
    {
        int counter = 0;
        stackNode *ptr;

        for(ptr = top; ptr != NULL; ptr = ptr->next)
            counter++;

        return counter;
    }

    // Print Stack
    void display(void)
    {
        stackNode *ptr;

        cout << "Stack : ";
        for(ptr = top ; ptr != NULL ; ptr = ptr->next)
            cout << ptr->data <<"  ";
    }
};

// Main
int main()
{
    // Create New Stack By Linked List
    LinkedListStack LLS;

    // Add Data To Stack
    LLS.push(50);
    LLS.push(40);
    LLS.push(30);
    LLS.push(20);
    LLS.push(10);

    // Print Stack
    LLS.display();
    cout<<endl;

    return 0;
}
