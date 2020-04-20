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

ll solve(vec &a){
    ll n = len(a);
    vec2 f(n + 1, vec(201, 0LL));
    rep(i, n) ++f[i + 1][a[i]];
    rep(i, n) rep(j, 201) f[i + 1][j] += f[i][j];

    vec freq(n + 1, 0LL);

    rep1(i, n){
        ll tp = 0;
        rep1(x, 200) if (chmax(tp, f[i][x])) freq[i] = x;
    }

    ll ans = 1;
    rep1(i, n){
        if(i == 1){
            chmax(ans, f[n][freq[n]]);
            continue;
        }
        ll a = freq[i - 1];
        ll ct = f[i - 1][a];

        ll l = -1, r = n + 1;
        while(r - l > 1){
            ll m = (r + l) / 2;
            if(f[n][a] - f[m][a] < ct) r = m;
            else l = m;
        }
        if(l < i) continue;

        ll tp = 0;
        rep1(x, 200) chmax(tp, f[l][x] - f[i - 1][x]);

        chmax(ans, tp + 2 * ct);
    }

    return ans;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
 
    ll t;
    cin >> t;
    rep(_, t){
        ll n;
        cin >> n;
        vec a(n);
        rep(i, n) cin >> a[i];
        vec b = a;
        reverse(ALL(b));

        print(max(solve(a), solve(b)));
    }
 
    return 0;
}