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

    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    vector<ll> S(N);
    rep(i, N) {
        if(!i) S[i] = a[i];
        else S[i] = a[i] + S[i-1];
    }

    ll ans = 1e18;
    rep(i, N-1){
        ll x = S[i], y = S.back() - S[i];
        ans = min(ans, abs(x - y));
    }
    print(ans);

    return 0;
}