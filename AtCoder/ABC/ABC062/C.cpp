#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
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
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
ll MOD = 1e9 + 7;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll solve(ll H, ll W){
    ll ans = 1e18;
    //Wに平行な二本で分割
    if(H % 3 == 0) chmin(ans, 0LL);
    else chmin(ans, W);

    //Wに平行な一本で分割し、さらにHと平行な一本で分割
    for (ll i = 1; i <= H - 1; ++i){
        ll mx = max({i * (W / 2), i * (W - W / 2), (H - i) * W});
        ll mn = min({i * (W / 2), i * (W - W / 2), (H - i) * W});
        chmin(ans, mx - mn);
    }

    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll H, W;
    cin >> H >> W;

    print(min(solve(H, W), solve(W, H)));

    return 0;
}