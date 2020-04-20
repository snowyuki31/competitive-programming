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
    string S;
    cin >> N >> K >> S;

    vector<ll> X;
    char c = S[0];
    ll ct = 1;
    for (ll i = 1; i < len(S); ++i){
        if(c == S[i]) ++ct;
        else{
            X.pb(ct);
            ct = 1;
            c = S[i];
        }
    }
    X.pb(ct);

    ll x = len(X);
    vector<ll> sum(x);
    rep(i,x){
        if(!i) sum[i] = X[i];
        else sum[i] = X[i] + sum[i-1];
    }

    ll ans = 0;
    rep(i, x){
        ll a = i;
        ll b = min(K * 2 + 1, x);
        ll c = x - a - b;
        if(c < 0) break;

        ll sa, sb, sc;
        if(i == 0) sa = 0;
        else sa = sum[i - 1];

        sb = sum[i + b - 1] - a;
        sc = sum.back() - sa - sb;

        ll tmp = (sa - a) + (sb - 1) + (sc - c);
        ans = max(ans, tmp);
    }

    print(ans);

    return 0;
}