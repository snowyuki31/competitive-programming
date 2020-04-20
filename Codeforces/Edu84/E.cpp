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
ll MOD = 998244353;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

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

    ll N;
    cin >> N;

    rep1(L,N){
        ll ans = 0;
        if(L == N){
            cout << 10 << '\n';
            return 0;
        }

        ans += 2 * 10 * 9 * modpow(10, N - L - 1, MOD);
        ans %= MOD;
        ans += (N - L - 1) * 10 * 9 * 9 * modpow(10, N - L - 2, MOD);
        ans %= MOD;

        cout << ans << " ";
    }



    return 0;
}