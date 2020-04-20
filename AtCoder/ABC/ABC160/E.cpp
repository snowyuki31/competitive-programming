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

    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    priority_queue<ll> pq;
    rep(i, A) cin >> p[i];
    rep(i, B) cin >> q[i];
    rep(i, C) cin >> r[i];

    sort(ALL(p));
    reverse(ALL(p));
    sort(ALL(q));
    reverse(ALL(q));
    sort(ALL(r));
    reverse(ALL(r));

    rep(i, X) pq.push(p[i]);
    rep(i, Y) pq.push(q[i]);
    rep(i, C) pq.push(r[i]);

    ll ans = 0;

    rep(i, X + Y) ans += pq.top(), pq.pop();

    print(ans);

    return 0;
}