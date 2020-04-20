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
ll MOD = 1e9 + 7;
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
 
const int MAX = 510000;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
 
    ll N, K;
    cin >> N >> K;
    vec coef(K + 10, 0);
    coef[0] = 1;
    rep(i, N){
        ll a;
        cin >> a;
        ++a;
        for (ll j = K - a; j >= 0; --j) coef[j + a] = modsub(coef[j + a], coef[j], MOD), coef[j + a] %= MOD;
    }
    COMinit();
    ll ans = 0;
 
    rep(i, K + 1) ans += COM(i + N - 1, i) * coef[K - i] % MOD, ans %= MOD;
 
    print(ans);
 
    return 0;
}
