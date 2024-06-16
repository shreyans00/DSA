/*
Approach 1: Using 2 Stacks and deQueue operation costly
    enQueue - push val to stack1
    deQueue - if both stacks are empty, error
              if stack2 is empty while stack1 is not empty, push everything from stack1 to stack2.
              pop the element from stack2 and return it.

*/

#include <iostream>
#include <stack>
using namespace std;

// Method 1 : using 2 stacks
class queu
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "queue is empty\n";
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};

// Method 2 : using 1 stack and recursion

// class queu
// {
//     stack<int> s;

// public:
//     void push(int x)
//     {
//         s.push(x);
//     }
//     int pop()
//     {
//         if (s.empty())
//         {
//             cout << "queue is empty\n";
//             return -1;
//         }
//         int x = s.top();
//         s.pop();
//         if (s.empty())
//         {
//             return x;
//         }
//         int item = pop(); // by recursion
//         s.push(x);
//         return item;
//     }
//     bool empty()
//     {
//         if (s.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };

// Method 3 : to use pop and front differently

// class que
// {
//     stack<long long int> s1;
//     stack<long long int> s2;

// public:
//     void push(long long int x)
//     {
//         s1.push(x);
//     }

//     void pop()
//     {

//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s2.pop();
//         while (!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int front()
//     {
//         stack<long long int> temp = s1;
//         stack<long long int> temp2;
//         while (!temp.empty())
//         {
//             temp2.push(temp.top());
//             temp.pop();
//         }
//         return temp2.top();
//     }
// };

int main()
{
    queu q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
}