#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
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

    string N;
    ll K;
    cin >> N >> K;
    ll L = len(N);
    vec3 f(L + 1, vec2(4, vec(2, 0)));
    f[0][0][0] = 1;

    rep1(i, L){
        rep(j, 4){
            f[i][j][0] += f[i - 1][j][0];
            if(j >= 1) f[i][j][0] += f[i - 1][j - 1][0];

            f[i][j][1] += f[i - 1][j][1] + f[i - 1][j][0];
            if(j >= 1) f[i][j][1] += f[i - 1][j - 1][1] * 9 + f[i - 1][j - 1][0] * max(N[i] - '0' - 1, 0);
        }
    }

    print(f[L][K][0] + f[L][K][1]);

    return 0;
}