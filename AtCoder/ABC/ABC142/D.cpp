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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

bool judge(ll X){
    for (ll i = 2; i * i <= X; ++i) if(X % i == 0) return false;
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll A, B;
    cin >> A >> B;

    set<ll> p;
    ll G = gcd(A,B);

    for (ll i = 1; i * i <= G; ++i){
        if(G % i == 0){
            p.insert(i);
            p.insert(G / i);
        }
    }

    ll ans = 0;
    for(auto P : p) ans += judge(P);
    print(ans);

    return 0;
}