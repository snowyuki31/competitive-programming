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

    ll N, M, K;
    cin >> N >> M >> K;

    ll x, y;
    rep(i,K) cin >> x >> y;
    ll p, q;
    rep(i, K) cin >> p >> q;

    string ans = "";
    rep(i, N - 1) ans += "U";
    rep(i, M - 1) ans += "L";

    rep(j, M){
        if(j % 2 == 0) rep(i, N - 1) ans += "D";
        else rep(i, N - 1) ans += "U";
        ans += "R";
    } 

    print(len(ans));
    print(ans);

    return 0;
}