#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
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
template<class S, class T> inline bool chmax(S &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline ll msb(ll v) { return 1 << (31 - __builtin_clzll(v)); }
inline ll devc(ll x, ll y) { return (x + y - 1) / y; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

template< typename T1, typename T2 >
ostream &operator << (ostream &os, const pair< T1, T2 > &p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
istream &operator >> (istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T1, typename T2, typename T3 >
ostream &operator << (ostream &os, const tuple< T1, T2, T3 > &t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return os;
}

template< typename T1, typename T2, typename T3 >
istream &operator >> (istream &is, tuple< T1, T2, T3 > &t) {
    is >> get<0>(t) >> get<1>(t) >> get<2>(t);
    return is;
}

template< typename T >
ostream &operator << (ostream &os, const vector< T > &v){
    for (int i = 0; i < (int)v.size(); ++i) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator >>  (istream &is, vector< T > &v){
    for(T &in : v) is >> in;
    return is;
}

/*---------------------------------    Tools    ------------------------------------------*/
template< typename T >
vector<T> cumsum(const vector<T> &X){
    vector<T> res(X.size() + 1, 0);
    for(int i = 0; i < X.size(); ++i) res[i + 1] += res[i] + X[i];
    return res;
}

template< typename S, typename T, typename F>
pair<T, T> bisearch(S left, T right, F f) {
    while(abs(right - left) > 1){
        T mid = (right + left) / 2;
        if(f(mid)) right = mid;
        else left = mid;
    }
    return {left, right};
}

template< typename S, typename T, typename F>
double trisearch(S left, T right, F f, int maxLoop = 90){
    double low = left, high = right;
    while(maxLoop--){
        double mid_left = high / 3 + low * 2 / 3;
        double mid_right = high * 2 / 3 + low / 3;
        if(f(mid_left) >= f(mid_right)) low = mid_left;
        else high = mid_right;
    }
    return (low + high) * 0.5;
}

template<int MOD>
struct modint {
    ll val;
    constexpr modint(ll v = 0) noexcept : val(v % MOD){
        if(val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr modint operator-() const noexcept { return val ? MOD - val : 0; }
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

/*------------------------------- Main Code Here -----------------------------------------*/

int main()
{
    ll N;
    cin >> N;
    vec C(N);
    cin >> C;

    vector<vector<ll>> color(N);
    rep(i, N) color[C[i] - 1].pb(i);

    for(auto&&c : color){
        if(c.empty()) continue;
        rep(i, len(c) - 1) if (c[i + 1] == c[i] + 1) c[i] = INF;
        sort(ALL(c));
        while(c.back() == INF) c.pop_back();
    }

    vector<P> ls;
    
    for(auto &&c : color){
        if(c.empty()) continue;
        rep(i, len(c) - 1) ls.pb({c[i], c[i + 1]});
    }

    sort(ALL(ls));

    vector<ll> range(N + 1, 0);
    vector<ll> end(N + 1, 0);

    for(auto l : ls){
        ll f = l.first, s = l.second;
        ++end[s + 1];
        ++range[f + 1];
        --range[s];
    }
    rep1(i, N) range[i] += range[i - 1];
    rep1(i, N) end[i] += end[i - 1];

    print(range);
    print(end);

    mint ans = 0;
    for(auto l : ls){
        ll f = l.first, s = l.second;

        ll E = end.back() - end[s + 1];
        ll R = range[s + 1];
        debug(E);
        debug(R);
        ans += modpow(mint(2), E - R);
    }
    print(ans + 1);

    return 0;
}