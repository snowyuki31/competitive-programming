#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
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
#define drop(x) cout << (x) << '\n', exit(0)
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

template<int MOD>
struct modint {
    ll val;
    constexpr modint(ll v = 0) noexcept : val(v % MOD){
        if(val < 0) val += MOD;
    }
    constexpr modint operator+ (const modint &r) const noexcept { return modint(*this) += r; }
    constexpr modint operator- (const modint &r) const noexcept { return modint(*this) -= r; }
    constexpr modint operator* (const modint &r) const noexcept { return modint(*this) *= r; }
    constexpr modint operator/ (const modint &r) const noexcept { return modint(*this) /= r; }
    constexpr modint& operator++() noexcept {
        val += 1;
        return *this;
    }
    constexpr modint& operator--() noexcept {
        val -= 1;
        return *this;
    }
    constexpr modint& operator+= (const modint &r) noexcept {
        val += r.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator-= (const modint &r) noexcept {
        val -= r.val;
        if(val < 0) val += MOD;
        return *this;
    }
    constexpr modint& operator*= (const modint &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr modint& operator/= (const modint& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator== (const modint &r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!= (const modint &r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator >> (istream &is, modint<MOD>& x) noexcept {
        is >> x.val;
        x += 0;
        return is;
    }
    friend constexpr ostream& operator << (ostream &os, const modint<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr modint<MOD> modpow(const modint<MOD> &a, long long n) noexcept {
        if(n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if(n & 1) t = t * a;
        return t;
    }
};
using mint = modint<MOD>;

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll func(ll x, ll y){
    return COM(x + y - 2, x - 1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    COMinit();

    mint ans = 0;
    for (ll i = 1; i <= H - A; ++i){
        mint tp = func(i, B);
        tp *= func(H - i + 1, W - B);
        ans += tp;
    }
    print(ans);

    return 0;
}