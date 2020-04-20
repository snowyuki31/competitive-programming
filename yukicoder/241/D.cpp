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

    ll N, Q;
    cin >> N >> Q;
    vector<P> bag;
    rep(i,N){
        ll x, w;
        cin >> x >> w;
        bag.pb({x, w});
    }
    sort(ALL(bag));

    vector<ll> x(N), xs(N), ws(N);

    rep(i, N) x[i] = bag[i].first, xs[i] = bag[i].first * bag[i].second, ws[i] = bag[i].second;
    rep1(i, N - 1) xs[i] += xs[i - 1], ws[i] += ws[i - 1];

    rep(i,Q){
        ll X;
        cin >> X;
        ll p = upper_bound(ALL(x), X) - x.begin();
        ll tws = p == 0 ? 0 : ws[p - 1];
        ll txs = p == 0 ? 0 : xs[p - 1];
        print(2 * X * tws - X * ws[N - 1] + xs[N - 1] - 2 * txs);
    }

    return 0;
}