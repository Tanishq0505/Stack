// How to implement stack using array in c++  (gfg)
// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

#include <iostream>
#include <stack>
using namespace std;
// https://youtu.be/_6COl6V6mng?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 12 min 50 sec lec 54
class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;
    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        // when no element present in stack top is -1
        top = -1;
    }

    void push(int element)
    {
        // here we check that if index of top  is equal to size-1 then stack is not empty
        //  we does not make top == size  bcoz top follow 0 base indexing (let size of stack =1)
        //  when 1 element is present in stack top is 0 in that case and size is 1
        //  so top==size-1 (0==1-1) (0==0) so stack is full
        if (top == size - 1)

        {
            // overflow means stack is full
            cout << "Stack OverFlow" << endl;
        }
        else
        {
            // if space is present so increase index of top and insert elemennt in it
            top++;
            arr[top] = element;
        }
    }

    void pop()
    {
        if (top == -1)
        {

            cout << "Stack UnderFlow" << endl;
        }
        else
        {
            // we do top-- to delete the top element
            top--;
        }
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Stack st(5);

    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << "peak element is " << st.peek() << endl;

    st.pop();

    cout << "peak element is " << st.peek() << endl;

    st.pop();

    cout << "peak element is " << st.peek() << endl;

    st.pop();

    cout << "peak element is " << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is Empty mere dost " << endl;
    }
    else
    {
        cout << "Stack is not Empty mere dost " << endl;
    }
    return 0;
}
