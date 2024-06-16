#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int postfixEval(string s) // postfixEval("46+2/5*7+") = ((((4+6)/2)*5)+7) = 32
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0'); // koi number jaise mile stack mai daal do

        else
        {
            // agr operator mile to stack ke 2 upar wale num nikal ke wo operator ke saath evaluate kr dena
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(num2 + num1);
                break;
            case '-':
                st.push(num2 - num1);
                break;
            case '*':
                st.push(num2 * num1);
                break;
            case '/':
                st.push(num2 / num1);
                break;
            case '^':
                st.push(pow(num2, num1));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << postfixEval("46+2/5*7+"); // ((((4+6)/2)*5)+7) = 32
    return 0;
}
