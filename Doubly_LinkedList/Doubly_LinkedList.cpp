/*** Doubly Linked List ***/

#include<iostream>
using namespace std;

// Node Structure
struct node
{
    int data;
    node* next;
    node* prev;
};

// Class
class DoublyLinkedList {

private:

    node *head;          // Pointer To First Node
    node *tail;          // Pointer To Last Node
    int counter;         // Variable To Count No. Of Nodes

public:

    // No-arguments Constructor
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Check If Linked List Is Empty
    bool isEmpty()
    {
        return (head == NULL);
    }

    // Insert Node At First Of Linked List
    void insertFirst(node d)
    {
        node *ptr = new node;

        if(head == NULL)    // Empty List
        {
            *ptr = d;
            head = tail = ptr;
            ptr->next = ptr->prev = NULL;
        }

        else
        {
            *ptr = d;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }

    // Insert Node At End Of Linked List
    void insertLast(node d)
    {
        node *ptr = new node;

        if(head == NULL)    // Empty List
            insertFirst(d);

        else
        {
            *ptr = d;
            ptr->prev = tail;
            ptr->next = NULL;
            tail->next = ptr;
            tail = ptr;
        }
    }

    // Read First Node Of Linked List
    int readFirst()
    {
        return head->data;
    }

    // Read Last Node Of Linked List
    int readLast()
    {
        return tail->data;
    }

    // Delete First Node Of Linked List
    void deleteFirst()
    {
        if(head == NULL)  // Empty List
            return;

        if(head == tail)  // One Element In The List
        {
            node* ptr;
            ptr = head;
            head = NULL;
            tail = NULL;
            delete ptr;
        }

        else
        {
            node *ptr;
            ptr = head;
            head = head->next;
            head->prev = NULL;
            delete ptr;
        }
    }

    // Delete Last Node Of Linked List
    void deleteLast()
    {
        if(head == NULL)  // Empty List
            return;

        if(head == tail)  // One Element In The List
        {
            node* ptr;
            ptr = tail;
            head = NULL;
            tail = NULL;
            delete ptr;
        }

        else
        {
            node *ptr;
            ptr = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete ptr;
        }
    }

    // Display Linked List Forward
    void displayForward()
    {
        node *ptr;
        ptr = head;    // Forward : Start From Head

        // Go Through All Nodes In List
        while(ptr != NULL)
        {
            cout<<ptr->data<<"  ";
            ptr = ptr->next;
        }
    }

    // Display Linked List Backward
    void displayBackward()
    {
        node *ptr;
        ptr = tail;    // Backward : Start From Tail

        // Go Through All Nodes In List
        while(ptr != NULL)
        {
            cout<<ptr->data<<"  ";
            ptr = ptr->prev;
        }
    }
};

// Main
int main()
{
    // Create New Doubly Linked List
    DoublyLinkedList DLL;

    // Create New Nodes
    node n1 , n2 , n3 , n4 , n5;
    n1.data = 50;
    n2.data = 40;
    n3.data = 30;
    n4.data = 20;
    n5.data = 10;

    // Insert Node To Linked List
    DLL.insertFirst(n1);    // Output : 50
    DLL.insertFirst(n2);    // Output : 40 50
    DLL.insertLast(n3);     // Output : 40 50 30
    DLL.deleteFirst();      // Output : 50 30
    DLL.deleteLast();       // Output : 50
    DLL.insertFirst(n2);    // Output : 10 50
    DLL.insertFirst(n3);    // Output : 10 20 50
    DLL.insertFirst(n4);    // Output : 10 20 30 50
    DLL.insertFirst(n5);    // Output : 10 20 30 40 50

    // Print Linked List Forward
    cout<<"Linked List Forward  : ";
    DLL.displayForward();
    cout<<endl;

    // Print Linked List Backward
    cout<<"Linked List Backward : ";
    DLL.displayBackward();
    cout<<endl;

    return 0;
}
