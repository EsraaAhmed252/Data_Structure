/*** Stack ***/

#include<iostream>
using namespace std;

// Stack Class
class mystack {

private:
    int *arr;    // Pointer To Create Dynamic Array
    int top;     // Point To Next Empty Place In Stack
    int size;    // Variable For Size Of Dynamic Array

public:

    // No-arguments Constructor
    mystack(void)
    {
        top = 0;
        size = 100;
        arr = new int[size];
    }

    // Parameterized Constructor
    mystack(int ss)
    {
        top = 0;
        size = ss;
        arr = new int[size];
    }

    // Check If Stack Is Empty
    bool isEmpty(void)
    {
        return (top == 0);
    }

    // Check If Stack Is Full
    bool isFull(void)
    {
        return (top >= size);
    }

    // Add Elements To Stack
    void push(int data)
    {
        if(isFull() == false)
        {
            arr[top] = data;
            top++;
            // arr[top++] = data; "Same Like Previous Two Lines"
        }
    }

    // Get Elements From Stack
    int pop(void)
    {
        top--;
        return arr[top];
        // return arr[--top]; "Same Like Previous Two Lines"
    }

    // Get Size Of Stack
    int get_size(void)
    {
        return size;
    }

    // Get Actual Size Of Stack
    int get_actual_length(void)
    {
        return top;
    }

    // Double Size Of Stack
    void doubleSize(void)
    {
        int *temp;
        temp = new int[size * 2];

        for(int k = 0 ; k < size ; k++)
            temp[k] = arr[k];

        size = size * 2;
        delete arr;
        arr = temp;
    }
};

// Main
int main(void)
{
    // Variables For Size And Stack Elements
    int s , num;

    // Get Size From User
    cout<<"Enter Size Of Stack : ";
    cin>>s;
    cout<<endl;

    // Create New Stack With Size From User
    mystack st(s);

    // Push Elements From User To Stack
    for(int i = 1; i <= s; i++)
    {
        cout<<"Enter Number "<<i<<" : ";
        cin>>num;
        st.push(num);
    }

    // Pop Elements From Stack And Print Them
    cout<<"\nElements From Stack :  ";
    for(int i = 0; i < s; i++)
        cout<<st.pop()<<"  ";

    return 0;
}
