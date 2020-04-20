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

    ll W, H, N;
    cin >> W >> H >> N;

    char c[101][101];
    rep(i, 101) rep(j, 101) c[i][j] = 0;

    rep(i,N){
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1) rep(j, x) rep(k, 101) c[j][k] = 1;
        if(a == 2) for(int j = x; j <= 100; ++j) rep(k,101) c[j][k] = 1;
        if(a == 3) rep(k, y) rep(j, 101) c[j][k] = 1;
        if(a == 4) for(int k = y; k <= 100; ++k) rep(j,101) c[j][k] = 1;
    }

    ll ans = 0;
    rep(i, W) rep(j, H) ans += c[i][j] == 0;
    print(ans);

    return 0;
}