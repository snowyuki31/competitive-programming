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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<vector<ll>> node;
deque<ll> ls;
vector<bool> flag;

void dfs(ll n){
    if(!flag[n]) return;
    
    flag[n] = false;
    for (auto e : node[n]) dfs(e);
    ls.push_front(n);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, M;
    cin >> N >> M;

    node.resize(N);
    flag.resize(N, true);

    rep(i,M){
        ll x, y;
        cin >> x >> y;
        --x, --y;
        node[x].pb(y);
    }

    rep(i, N) dfs(i);

    vector<ll> dp(N);

    ll ans = 0;
    ll ct = 0;
    for (auto l : ls){
        for(auto n : node[l]){
            chmax(dp[n], dp[l] + 1);
            chmax(ans, dp[n]);
            ++ct;
        }
    }

    print(ans);

    return 0;
}