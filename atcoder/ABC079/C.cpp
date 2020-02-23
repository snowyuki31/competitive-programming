#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define to_s to_string
#define len(v) (int)v.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define print(x) cout << (x) << '\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll MOD = 1e9 + 7;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;
    vector<ll> X(4);
    rep(i, 4) X[i] = S[i] - '0';

    struct hold{
        ll sum;
        string ans;
        ll counter;
    };
    stack<hold> sk;
    sk.push({X[0],to_string(X[0]),0});

    string ans;

    while(!sk.empty()){
        hold H = sk.top();
        if(H.counter == 3 && H.sum == 7) ans = H.ans;
        sk.pop();
        
        ll now = ++H.counter;
        if(now <= 3){
            sk.push({H.sum + X[now], H.ans + "+" + to_string(X[now]), now});
            sk.push({H.sum - X[now], H.ans + "-" + to_string(X[now]), now});
        }
    }

    print(ans+"=7");

    return 0;
}