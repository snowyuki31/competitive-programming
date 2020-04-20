#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define to_s to_string
#define len(v) (int)v.size()
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
    rep(_, N){
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<ll> p(m);
        rep(i, m) cin >> p[i], --p[i];
        sort(ALL(p));

        map<char, ll> mp;
        rep(i, n){
            ll num = upper_bound(ALL(p),i) - lower_bound(ALL(p), i);
            mp[s[i]] += m + 1;
            m -= num;
        }

        for (char c = 'a'; c <= 'z'; ++c){
            cout << mp[c] << " ";
        }
        print("");
    }

    return 0;
}