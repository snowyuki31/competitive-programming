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
    ll Q;
    cin >> S >> Q;

    deque<char> que;
    rep(i, len(S)) que.push_back(S[i]);

    bool state = true;
    rep(_,Q){
        ll T;
        cin >> T;
        if(T == 1) state = !state;
        else if(T == 2){
            ll F;
            char C;
            cin >> F >> C;
            if(!state) F = F == 1 ? 2 : 1;
            if(F == 1) que.push_front(C);
            else que.push_back(C);
        }
    }

    if(!state) rrep(i,len(que)) cout << que[i];
    else rep(i,len(que)) cout << que[i];

    return 0;
}