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

vector<string> ans;

void func(string S, ll prev, ll N){
    if(len(S) == N){
        ans.pb(S);
        return;
    }

    rep(i,prev+1){
        char x = 'a' + i;

        ll tmp = 0;
        rep(j, len(S)) tmp = max(tmp, ll(S[j] - 'a'));

        if(i > tmp) func(S + x, prev + 1, N);
        else func(S+x, prev, N);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;

    func("a", 1, N);
    sort(ALL(ans));
    for(auto s : ans) print(s);
    return 0;
}