#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack;
    stack.push(21); // stack.emplace(21)
    stack.size();
    stack.pop();
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
    stack1.swap(stack2); // to swap elements of both the stacks.
}
