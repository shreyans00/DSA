#include <iostream>
#include <stack>
using namespace std;

int prec(char c) // to check which has more precedence
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1; // opening bracket
    }
}

string infixToPostfix(string s) // infixToPostfix("(a-b/c)*(a/k-l)") = abc/-ak/l-*
{
    stack<char> st;
    string res; // result string

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i]; // store alphabet in result

        else if (s[i] == '(')
            st.push(s[i]); // push starting bracket

        else if (s[i] == ')') // agr closing bracket hai to pop kro jb tk opening bracket na mile aur tb tk stack ke top values result mai add krte jao
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) // higher precedence, push   and   lower or same precedence, pop
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.top();
    }

    return res;
}

int main()
{
    cout << infixToPostfix("(a-b/c)*(a/k-l)"); //   abc/-ak/l-*
}