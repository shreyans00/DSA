#include <bits/stdc++.h>
using namespace std;

#define ll long long
int k;
struct st
{
    multiset<int, greater<int>> ms;

    void add(int x)
    {
        ms.insert(x);
    }
    void remove(int x)
    {
        if (ms.find(x) != ms.end())
        {
            ms.erase(ms.find(x));
        }
    }
    ll summation()
    {
        int sumK = 0;
        auto it = ms.begin();
        for (int j = 0; j < k && it != ms.end(); it++, j++)
        {
            sumK += *it;
        }
        return sumK;
    }
};

signed main()
{
    int q;
    cin >> q >> k;
    struct st qu;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            qu.add(x);
        }
        else if (t == 2)
        {
            ll x;
            cin >> x;
            qu.remove(x);
        }
        else if (t == 3)
        {
            char c;
            cin >> c;
            cout << qu.summation() << "\n";
        }
        else
        {
            assert(1 == 0);
        }
    }
}

// class MyStructure {
// private:
// 	multiset<int> M1, M2;
// 	ll sum;
// 	int K;

// public:
// 	MyStructure(int K) : K(K), sum(0LL) {};

// 	void add(int x) {
// 		M1.insert(x);
// 		sum += x;
// 		if((int)M1.size() > K) {
// 			int y = *(M1.begin());
// 			M1.erase(M1.find(y));
// 			sum -= y;
// 			M2.insert(y);
// 		}
// 		return;
// 	}

// 	void remove(int x) {
// 		if(M2.find(x) != M2.end()) {
// 			M2.erase(M2.find(x));
// 		}
// 		else if(M1.find(x) != M1.end()) {
// 			sum -= x;
// 			M1.erase(M1.find(x));
// 			if(M2.empty()) return;
// 			int y = *(M2.rbegin());
// 			sum += y;
// 			M1.insert(y);
// 			M2.erase(M2.find(y));
// 		}
// 		return;
// 	}

// 	ll getSum() {
// 		return sum;
// 	}
// };

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int Q, K; cin >> Q >> K;

//     MyStructure M(K);

//     while(Q--) {
//     	int t; cin >> t;
//     	if(t == 1) {
//     		int x; cin >> x;
//     		M.add(x);
//     	}
//     	else if(t == 2) {
//     		int x; cin >> x;
//     		M.remove(x);
//     	}
//     	else if(t == 3) {
//     		char c; cin >> c;
//     		cout << M.getSum() << "\n";
//     	}
//     	else {
//     		//asserting this condition never happens
//     		assert(1 == 0);
//     	}
//     }

//     return 0;
// }