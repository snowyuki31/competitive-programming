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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, C;
    cin >> N >> C;
    vec2 grid(N, vec(N));
    vec2 D(C, vec(C));
    rep(i, C) rep(j, C) cin >> D[i][j];
    rep(i, N) rep(j, N) cin >> grid[i][j], --grid[i][j];

    map<ll, ll> x0, x1, x2;
    rep(i, N) rep(j, N){
        if((i + j) % 3 == 0) ++x0[grid[i][j]];
        else if((i + j) % 3 == 1) ++x1[grid[i][j]];
        else ++x2[grid[i][j]];
    }

    ll ans = INF;
    rep(i, C) rep(j, C) rep(k, C){
        if(i == j or j == k or k == i) continue;
        ll tot = 0;
        for(auto x : x0){
            ll c = x.first, v = x.second;
            tot += D[c][i] * v;
        }
        for(auto x : x1){
            ll c = x.first, v = x.second;
            tot += D[c][j] * v;
        }      
        for(auto x : x2){
            ll c = x.first, v = x.second;
            tot += D[c][k] * v;
        }   

        chmin(ans, tot);
    }
    print(ans);

    return 0;
}