#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define to_s to_string
#define len(v) (int)v.size()
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

    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) cin >> d[i];

    rep(_, q){
        ll n, x, m;
        cin >> n >> x >> m;
        --n, x %= m;
        vector<ll> D(k);
        ll sum = 0, z = 0;
        rep(i, k){
            D[i] = d[i] % m;
            sum += D[i];
            if(D[i] == 0) ++z;
        }

        ll ans = (n / k) * z, tot = x + (n / k) * sum;
        rep(i, n % k){
            tot += D[i];
            if(D[i] == 0) ++ans;
        }

        ans += tot / m;
        print(n - ans);
    }

    return 0;
}