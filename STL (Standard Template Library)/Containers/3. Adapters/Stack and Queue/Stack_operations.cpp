// Basic Operations - Push, Pop, Top, Empty

#include <iostream>
using namespace std;
#define n 100

class stack
{
    int top; // index at which the top element of stack is present
    int *arr;

public:
    stack()
    {
        top = -1;
        arr = new int[n];
    }

    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element in the stack" << endl;
        }
        top--;
    }

    int Top_element()
    {
        if (top == -1)
        {
            cout << "No element in the stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return (top <= -1);
    }
};

int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.Top_element() << endl;
    st.pop();
    cout << st.Top_element() << endl;
    st.pop();
    st.pop();
    cout << st.empty() << endl;
}
