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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, K;
    cin >> N >> K;

    if(K > (N-1)*(N-2)/2){
        print(-1);
        return 0;
    }

    vector<P> edge;
    rep1(i, N - 1) edge.pb({i, N});

    vector<P> pool;
    rep1(i, N - 1) rep1(j, N - 1) if (i < j) pool.pb({i, j});

    rep(i, (N - 1) * (N - 2) / 2 - K) edge.pb(pool[i]);

    print(len(edge));
    rep(i, len(edge)) cout << edge[i].first << " " << edge[i].second << '\n';

    return 0;
}