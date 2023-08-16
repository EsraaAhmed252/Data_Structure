/*** Queue ***/

#include<iostream>
using namespace std;

// Queue Class
class myQueue {

private:

    int f;      // Front : Point To First Element Of Queue
    int r;      // Rear  : Point To Next Empty Place Of Queue
    int *arr;   // Pointer To Create Dynamic Array
    int size;   // Variable For Size Of Queue

public:

    // No-arguments Constructor
    myQueue(void)
    {
        f = r = 0;
        size = 100;
        arr = new int[size];
    }

    // Parameterized Constructor
    myQueue(int s)
    {
        f = r =0;
        size = s+1;    // +1 To Set One Empty Space In Order To Make Circular Queue
        arr = new int[size];
    }

    // Check If Queue Is Empty
    bool isEmpty(void)
    {
        return (r == f);
    }

    // Check If Queue Is Full
    bool isFull(void)
    {
        return (r+1)%size == f;
    }

    // Put Elements On Queue
    void enqueue(int data)
    {
        arr[r] = data;
        r = (r+1)%size;
    }

    // Get Elements From Queue
    int dequeue(void)
    {
        int temp = f;
        f = (f+1)%size;
        return arr[temp];
    }

    // Get Size
    int getSize()
    {
        return size;
    }

    // Get Actual Size
    int ActualSize(void)
    {
        return((r-f+size)%size);
    }
};

// Main
int main(void)
{
    // Variables For Size , Flags And Elements Of Queue
    int s , num , eFlag = 0 , oFlag = 0;

    // Get Size From User
    cout<<"Enter Size Of Queue : ";
    cin>>s;
    cout<<endl;

    // Create Two Queues For Even & Odd Numbers
    myQueue even(s);
    myQueue odd(s);

    // Put Elements On Queues
    for(int i=1; i<=s; i++)
    {
        cout<<"Enter Number "<<i<<" : ";
        cin>>num;

        if(num%2 == 0 || num == 0)
        {
            if(even.isFull() == false)
            {
                even.enqueue(num);
                eFlag++;
            }
        }

        else
        {
            if(odd.isFull() == false)
            {
                odd.enqueue(num);
                oFlag++;
            }
        }
    }

    // Get Elements From Queues And Print Them
    cout<<"\nEven Numbers : ";
    for(int i=0; i<eFlag; i++)
        cout<<even.dequeue()<<"  ";

    cout<<"\nOdd Numbers  : ";
    for(int i=0; i<oFlag; i++)
        cout<<odd.dequeue()<<"  ";

    return 0;
}
