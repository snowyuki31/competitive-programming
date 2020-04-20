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
ll MOD = 998244353;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//modでの累乗(繰り返し二乗法)
ll modpow(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll res = modpow(x, y / 2, m);
    return res * res % m * (y & 1 ? x : 1) % m;
}

//modでの割り算
ll modinv(ll x, ll m) { return modpow(x, m - 2, m); }

//modでの安全な引き算
ll modsub(ll x, ll y, ll m){ return(x + m - y) % m; }

//乗算により二項係数を求める
ll binom(ll n, ll k, ll m)
{
    ll den = 1, num = 1;
    for (int i = 1; i <= k; ++i){
        den *= i;
        num *= (n + 1 - i);
        den %= m;
        num %= m;
    }
    return num * modinv(den,m);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll n, m, L, R;
    cin >> n >> m >> L >> R;

    ll od, ev;
    ll N = R - L + 1;
    if(L % 2 == 0){
        od = devc((R - L), 2);
        ev = N - od;
    }else{
        ev = devc((R - L), 2);
        od = N - ev;
    }

    ll ans = 0;
    ll nm = n * m;

    if(N == 1) ans = 1;
    else{
        ans += modpow(N, nm, MOD);
        ll tp = modpow(od - ev, nm, MOD);
        ans = modsub(ans, tp, MOD);
        ans *= modinv(2, MOD);

        if(nm % 2 == 1) ++ans;

        ans %= MOD;
    }

    print(ans);

    return 0;
}