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

    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(N + 10, vector<ll>(N * 1000 + 10, 1e15));

    dp[0][0] = 0;
    dp[0][v[0]] = w[0];

    rep(i, N) rep(j, N * 1000 + 10){
        if(j >= v[i + 1]) dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i + 1]] + w[i + 1]);
        else dp[i + 1][j] = dp[i][j];
    }

    ll ans = 0;
    rep(j, N * 1000 + 10) if(dp[N - 1][j] <= W) ans = j;

    print(ans);

    return 0;
}