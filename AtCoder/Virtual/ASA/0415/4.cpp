#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MAX max<ll>
#define MIN min<ll>
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
ll devc(ll x, ll y) { return (x + y - 1) / y; }

//素数判定表
vector<ll> eratosthenes_sieve(ll n) {
    vector<ll> ps(n + 1);
    iota(ps.begin() + 2, ps.end(), 2);
    for (ll i = 2; i * i <= n; ++i)
        if (ps[i])
            for (ll j = i * i; j <= n; j += i) ps[j] = 0;
    return ps;
}

//素数表
vector<ll> make_primes(ll n) {
    vector<ll> ps = eratosthenes_sieve(n);
    ps.erase(std::remove(ps.begin(), ps.end(), 0), ps.end());
    return ps;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    vector<ll> pm = make_primes(100000 + 1);
    vec ans(100001);
    for(auto p : pm){
        if(p <= 100000) ++ans[p];
        if(2 * p - 1 <= 100000) ++ans[2 * p - 1];
    }
    rep1(i, 100000) ans[i] /= 2;
    rep1(i, 100000) ans[i] += ans[i - 1];

    ll Q;
    cin >> Q;
    rep(_, Q){
        ll l, r;
        cin >> l >> r;
        print(ans[r] - ans[l - 1]);
    }

    return 0;
}