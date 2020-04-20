#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define to_s to_string
#define len(v) (ll)v.size()
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

    string s, t;
    cin >> s >> t;
    ll S = len(s), T = len(t);

    vector<vector<ll>> dp(S + 10, vector<ll>(T + 10, 0));

    rep(i,S) rep(j,T){
        if(s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1; 
        else dp[i + 1][j + 1] = max({dp[i][j + 1], dp[i + 1][j]});
    }

    string ans = "";

    ll i = S, j = T;
    while(i and j){
        if(dp[i][j] == dp[i-1][j]) --i;
        else if(dp[i][j] == dp[i][j-1]) --j;
        else ans += s[i-1], --i, --j;
    }

    reverse(ALL(ans));
    print(ans);

    return 0;
}