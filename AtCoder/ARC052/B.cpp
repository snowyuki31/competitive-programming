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

    const double pi = 3.14159265358979323846;
    ll N, Q;
    cin >> N >> Q;
    vector<double> V(20001);

    rep(i, N){
        double x, r, h;
        cin >> x >> r >> h;

        for (double i = x; i < x + h; ++i){
            double now = r * (h - (i - x)) / h;
            double next = r * (h - (i + 1 - x)) / h;

            V[i] += now * now * pi * (h - (i - x)) / 3 - next * next * pi * (h - (i + 1 - x)) / 3;
        }
    }

    vector<double> S(20002);
    S[0] = 0;
    rep1(i, 20001) S[i] = S[i - 1] + V[i - 1];

    rep(i, Q){
        ll a, b;
        cin >> a >> b;
        ++a, ++b;
        print(S[b - 1] - S[a - 1]);
    }

    return 0;
}