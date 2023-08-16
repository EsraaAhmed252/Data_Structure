/*** Queue By Linked List ***/

#include<iostream>
using namespace std;

// QueueNode Structure
struct QueueNode
{
   int data;
   QueueNode *next;
};

// Queue Class
class LinkedListQueue {

private :

   QueueNode *f, *r;  // Front & Rear

public :

    // No-arguments Constructor
    LinkedListQueue() {
      f = r = NULL;
   }

    // Add Data To Queue
    void enqueue(int data)
    {
        QueueNode *ptr = new QueueNode;
        ptr->data = data;
        ptr->next = NULL;

        if (f == NULL)
           f = r = ptr;

        else
        {
          // Next Of Rear is Front In Circular Queue
          r->next = ptr;
          r = ptr;
        }

        r->next = f;
    }

    // Get Data From Queue
    int dequeue()
    {
        int data;

        if (f == NULL)
           cout<<"Cannot Dequeue From Empty Queue!\n";

        else if (f == r)
        {
           // Only 1 Node In Circular Queue
           data = f->data;
           delete f;
           f = r = NULL;
        }

        else
        {
           QueueNode *ptr = f;
           data = ptr->data;
           f = f->next;
           // Next Of Rear is Front In Circular Queue
           r->next = f;
           delete ptr;
        }

        return data;
    }

    // Print Queue
    void PrintQueue()
    {
        QueueNode *ptr = f;

        cout<<"Queue : ";
        do
        {
           cout<<ptr->data<<" ";
           ptr = ptr->next;
        } while (ptr != f);

        cout<<endl;
    }
};

// Main
int main() {

   // Create New Queue By Linked List
   LinkedListQueue Q;

   // Add Data To Queue
   Q.enqueue(10);
   Q.enqueue(20);
   Q.enqueue(30);
   Q.enqueue(40);
   Q.enqueue(50);

   // Print Queue
   Q.PrintQueue();
   cout<<endl;

   return 0;
}
