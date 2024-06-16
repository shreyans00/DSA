#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixEval(string s) // prefixEval("-+7*45+20") = ((7+(4*5))-(2+0)) = 25
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--) // bs LOOP REVERSE kr dena, baki same rhega postfix expression se
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(num1 + num2);
                break;
            case '-':
                st.push(num1 - num2);
                break;
            case '*':
                st.push(num1 * num2);
                break;
            case '/':
                st.push(num1 / num2);
                break;
            case '^':
                st.push(pow(num1, num2));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << prefixEval("-+7*45+20"); // ((7+(4*5))-(2+0)) = 25
    return 0;
}
