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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;
    ll N = len(S);

    vec2 f(N + 1, vec(4, 0));
    f[0][0] = 1;

    rep1(i,N){
        char now = S[i - 1];
        rep(j, 4) f[i][j] = f[i - 1][j];
        if(now == 'A' || now == '?') f[i][1] += f[i - 1][0];
        if(now == 'B' || now == '?') f[i][2] += f[i - 1][1];
        if(now == 'C' || now == '?') f[i][3] += f[i - 1][2];
        if(now == '?') rep(j, 4) f[i][j] += f[i - 1][j] * 2;
        rep(j, 4) f[i][j] %= MOD;
    }

    print(f[N][3]);

    return 0;
}