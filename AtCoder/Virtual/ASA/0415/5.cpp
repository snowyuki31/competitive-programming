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

    ll N;
    cin >> N;
    vec2 D(N + 1, vec(N + 1, 0));
    rep1(i, N) rep1(j, N) cin >> D[i][j];
    rep1(i, N) rep1(j, N) D[i][j] += D[i - 1][j];
    rep1(i, N) rep1(j, N) D[i][j] += D[i][j - 1];

    vector<ll> ans(N * N + 1, 0);
    rep1(x1, N) rep1(y1, N) rep1(x2, N) rep1(y2, N){
        ll sum = D[x2][y2] - D[x2][y1 - 1] - D[x1 - 1][y2] + D[x1 - 1][y1 - 1];
        ll S = (x2 - x1 + 1) * (y2 - y1 + 1);
        chmax(ans[S], sum);
    }



    ll Q;
    cin >> Q;
    rep(_, Q){
        ll P;
        cin >> P;

        ll res = 0;
        rep1(i, P) chmax(res, ans[i]);
        print(res);
    }

    return 0;
}