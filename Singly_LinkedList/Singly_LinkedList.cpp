/*** Singly Linked List ***/

#include<iostream>
using namespace std;

// Create Node Structure
struct node
{
    int data;
    node *next;
};

// Singly Linked List Class
class SinglyLinkedList {

private:

    node *head;       // Pointer To Node To Point To First Node Of Linked List
    node wrongNode;   // Node To Point To WrongNode If It's Exist
    int counter;      // Variable For Counting No. Of Nodes

public:

    // No-arguments Constructor
    SinglyLinkedList()
    {
        head = NULL;
        counter = 0;
        wrongNode.data = 0;
        wrongNode.next = NULL;
    }

    // Check If Linked List Is Empty
    bool isEmpty(void)
    {
        return(head == NULL);
    }

    // Insert Node At First Of linked List
    void insertFirst(node d)
    {
        node *ptr = new node;    // Create New Node
        *ptr = d;                // Put Node Data
        ptr->next = head;        // Put Head Address To Node Next
        head = ptr;              // Put Node Address Into Head
    }

    // Insert Node At Last Of linked List
    void insertLast(node d)
    {
        if (head == NULL)
            insertFirst(d);

        node *ptr;

        // Search For Last Node To Inset After It
        for (ptr = head; ptr->next != NULL; ptr = ptr->next)
            continue;

        // Then Insert It
        ptr->next = new node;
        ptr = ptr->next;
        *ptr = d;
        ptr->next = NULL;
    }

    // Insert Node By Data Ordering In linked List
    void insertByDataOrder(node d)
    {
        if ((head == NULL) || (d.data < head->data))
            insertFirst(d);

        else if(head->next == NULL)
            insertLast(d);

        else{

            node *ptr;

            // Search For First Node Which Its Data Is Greater Than Node d
            for (ptr = head; ptr->next != NULL; ptr = ptr->next)
            {
                if(ptr->next->data < d.data)
                    continue;
                else
                    break;

                // Then Swap Them
                node *temp = new node;
                *temp = d;
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }

    // Insert Node By Index linked List
    void insertByIndex(node d, int index)
    {
        if((index == 0) || (head == NULL))
        {
            insertFirst(d);
            return;
        }

        node *ptr;
        ptr = head;

        // Search For Position
        for(int k = 1; k < index-1; k++)
        {
            if(ptr->next == NULL)
            {
                insertLast(d);
                return;
            }

            else
                ptr=ptr->next;
        }

        // Then Swap
        node *temp = new node;
        *temp = d ;
        temp->next = ptr->next;
        ptr->next = temp;
    }

    // Read First Node Of Linked List
    node readFirst(void)
    {
        if(head == NULL)
            return wrongNode;
        else
            return *head;
    }

    // Read Last Node Of Linked List
    node readLast(void)
    {
        node *ptr;

        if(head == NULL)
            return wrongNode;

        if(head->next == NULL)
            return *head;

        // Search For Last Node
        for(ptr = head ; ptr->next->next != NULL ; ptr = ptr->next)
            continue;

        // Then Return Its Data
        return *(ptr->next);
    }

    // Get Data By Index Of Linked List
    node getDataByIndex(int index)
    {
        if(head == NULL)
            return wrongNode;

        if(index == 1)
            return readFirst();

        int k;
        node *ptr;
        ptr = head;

        for(k = 1 ; k < index ; k++)
        {
            ptr = ptr->next;
            if(ptr == NULL)
                return wrongNode;
        }

        return *ptr;
    }

    // Get Index By Data Of Linked List
    int getIndexByData(node d)
    {
        node *ptr;
        int index = 0;

        // Search For Node's Index
        for(ptr = head; ptr->next != NULL; ptr = ptr->next)
        {
            if(ptr->data != d.data)
            {
                index++;
                continue;
            }
            else
            {
                break;
            }
        }

        cout<<"Data With Value = "<<d.data<<" --> Is Located At Index : "<<index<<endl;

        return index;
    }

    // Get Data If It's Exist In Linked List
    node getExistedData(int d)
    {
        if(head == NULL)
            return wrongNode;

        node *ptr;

        for(ptr = head ; ptr != NULL ; ptr = ptr->next)
            if(ptr->data == d)
            {
                cout<<"Data Existed Successfully";
                return *ptr;
            }

        return wrongNode;
    }

     // Get Number Of Nodes Of Linked List
    int numberOfNodes(void)
    {
        int counter = 0;

        if(head == NULL)
            return 0;

        node *ptr;

        // Count Nodes To The End
        for(ptr = head ; ptr != NULL ; ptr = ptr->next)
            counter++;

        return counter;
    }

    // Delete First Node Of Linked List
    void deleteFirst(void)
    {
        if(head == NULL)
            return;

        node *ptr;
        ptr = head;
        head = head->next;

        delete ptr;
    }

    // Display Linked List
    void display()
    {
        node *temp = new node;
        temp = head;

        while(temp!=NULL)
        {
          cout<<temp->data<<"  ";
          temp = temp->next;
        }
    }
};

// Main
int main(void)
{
    // Create New Singly Linked List
    SinglyLinkedList SLL;

    // Create New Node
    node n1 , n2 , n3 , n4 , n5 , n6 , n7;
    n1.data = 40;
    n2.data = 30;
    n3.data = 0;
    n4.data = 50;
    n5.data = 10;
    n6.data = 20;
    n7.data = 60;

    // Insert Nodes To Linked List
    SLL.insertFirst(n1);         // Output : 40
    SLL.insertFirst(n2);         // Output : 30 40
    SLL.insertFirst(n3);         // Output : 0 30 40
    SLL.insertLast(n4);          // Output : 0 30 40 50
    SLL.deleteFirst();           // Output : 30 40 50
    SLL.insertByDataOrder(n5);   // Output : 10 30 40 50
    SLL.insertByIndex(n6,2);     // Output : 10 20 30 40 50
    SLL.insertByIndex(n7,6);     // Output : 10 20 30 40 50 60

    // Print Index Of Every Node Of Linked List
    cout<<"<< Linked List Data's Indexes>> \n\n";
    SLL.getIndexByData(n5);
    SLL.getIndexByData(n6);
    SLL.getIndexByData(n2);
    SLL.getIndexByData(n1);
    SLL.getIndexByData(n4);
    SLL.getIndexByData(n7);
    cout<<endl;

    // Print Linked List
    cout<<"Linked List : ";
    SLL.display();
    cout<<endl;

    return 0;
}
