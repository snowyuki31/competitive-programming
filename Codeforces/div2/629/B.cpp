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

//素数判定表
vector<ll> eratosthenes_sieve(ll n)
{
    vector<ll> ps(n + 1);
    iota(ps.begin() + 2, ps.end(), 2);
    for (ll i = 2; i * i <= n; ++i)
        if (ps[i])
            for (ll j = i * i; j <= n; j += i)
                ps[j] = 0;
    return ps;
}

//素数表
vector<ll> make_primes(ll n)
{
    vector<ll> ps = eratosthenes_sieve(n);
    ps.erase(std::remove(ps.begin(), ps.end(), 0), ps.end());
    return ps;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll t;
    cin >> t;

    vector<ll> primes = make_primes(1e5);

    map<ll, ll> inv;
    rep(i, len(primes)) inv[primes[i]] = i;

    rep(_,t){
        ll n, k;
        cin >> n >> k;
        string ans = "";
        if(k == 1){
            rep(i, n - 2) ans += "a";
            rep(i, 2) ans += "b";
            print(ans);
            continue;
        } 
        rep(i,n-2){
            if(k <= (n-i)*(n-i-1)/2 and k >= (n-i-1)*(n-i-2)/2 + 1){
                ll x = k - (n - i - 1) * (n - i - 2) / 2 - 1;
                rep(j, i) ans += "a";
                ans += "b";
                rep(j, n - 2 - i - x) ans += "a";
                ans += "b";
                rep(j, x) ans += "a";

                print(ans);
                break;
            }
        }
    }

    return 0;
}