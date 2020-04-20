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

    ll N;
    cin >> N;
    vector<ll> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];
    vector<vector<ll>> dp(N + 100, vector<ll>(3,0));

    dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];

    rep(i, N){
        dp[i + 1][0] = a[i + 1] + max(dp[i][1], dp[i][2]);
        dp[i + 1][1] = b[i + 1] + max(dp[i][2], dp[i][0]);
        dp[i + 1][2] = c[i + 1] + max(dp[i][0], dp[i][1]);
    }

    print(max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}));

    return 0;
}