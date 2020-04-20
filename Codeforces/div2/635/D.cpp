#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MAX max<ll>
#define MIN min<ll>
#define pb push_back
#define to_s to_string
#define len(v) (ll)v.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define print(x) cout << (x) << '\n'
#define drop(x) cout << (x) << '\n', exit(0)
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll devc(ll x, ll y) { return (x + y - 1) / y; }

ll dist(ll x, ll y, ll z){
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

void solve(ll &ans, vec &a, vec &b, vec &c){
    ll L = len(b);
    rep(i, L){
        ll y = b[i];
        auto itrx = upper_bound(ALL(a), y);
        if(itrx == a.begin()) continue;
        --itrx;

        auto itrz = lower_bound(ALL(c), y);
        if(itrz == c.end()) continue;

        ll x = *itrx, z = *itrz;

        chmin(ans, dist(x, y, z));
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll t;
    cin >> t;
    rep(_, t){
        ll nr, ng, nb;
        cin >> nr >> ng >> nb;
        vec r(nr), g(ng), b(nb);
        rep(i, nr) cin >> r[i];
        rep(i, ng) cin >> g[i];
        rep(i, nb) cin >> b[i];
        sort(ALL(r)), sort(ALL(g)), sort(ALL(b));

        ll ans = 5e18;
        solve(ans, r, g, b);
        solve(ans, r, b, g);
        solve(ans, g, r, b);
        solve(ans, g, b, r);
        solve(ans, b, r, g);
        solve(ans, b, g, r);

        print(ans);
    }

    return 0;
}