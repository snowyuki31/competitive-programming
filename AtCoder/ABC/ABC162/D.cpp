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
    string S;
    cin >> N >> S;
    vec R(N + 1), G(N + 1), B(N + 1);

    rep(i, N){
        if(S[i] == 'R') R[i + 1] = 1;
        if(S[i] == 'G') G[i + 1] = 1;
        if(S[i] == 'B') B[i + 1] = 1;
    }
    rep(i, N) R[i + 1] += R[i], G[i + 1] += G[i], B[i + 1] += B[i];

    ll ans = 0;
    rep(i, N) rep(j, N) if(i < j){
        if((S[i] == 'R' and S[j] == 'G') or (S[i] == 'G' and S[j] == 'R')){
            ans += B[N] - B[j];
            if(2 * j - i < N) if(S[2 * j - i] == 'B') --ans;
        }
        if((S[i] == 'R' and S[j] == 'B') or (S[i] == 'B' and S[j] == 'R')){
            ans += G[N] - G[j];
            if(2 * j - i < N) if(S[2 * j - i] == 'G') --ans;
        }
        if((S[i] == 'G' and S[j] == 'B') or (S[i] == 'B' and S[j] == 'G')){
            ans += R[N] - R[j];
            if(2 * j - i < N) if(S[2 * j - i] == 'R') --ans;
        }
    }

    print(ans);

    return 0;
}