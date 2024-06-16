#include <bits./stdc++.h>
using namespace std;

// Method 1 : push is costly
class stac
{
    queue<int> q1;
    queue<int> q2;
    int n;

public:
    stac()
    {
        n = 0;
    }
    void push(int x) // push option is costly
    {
        q2.push(x);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        // reverse q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        q1.pop();
        n--;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return n;
    }
};

// Method 2 : pop is costly
// class stac
// {

//     queue<int> q1;
//     queue<int> q2;
//     int n;

// public:
//     stac()
//     {
//         n = 0;
//     }
//     void push(int x)
//     {
//         q1.push(x);
//         n++;
//     }
//     void pop() // pop option is costly as pop runs in order of n
//     {
//         if (q1.empty())
//         {
//             return;
//         }
//         while (q1.size() != 1)  // last ko chhorkr baki elements ko dusre queue mai daldo and then last ko pop kr do
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.pop();
//         n--;

//         queue<int> temp = q1; // reverse is necessary as q1 is our primary queue
//         q1 = q2;
//         q2 = temp;
//     }

//     int top()
//     {
//         if (q1.empty())
//         {
//             return -1;
//         }
//         while (q1.size() != 1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int ans = q1.front();
//         q2.push(ans);

//         queue<int> temp = q1;
//         q1 = q2;
//         q2 = temp;

//         return ans;
//     }

//     int size()
//     {
//         return n;
//     }
// };

int main()
{
    stac st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.size() << endl;
}
