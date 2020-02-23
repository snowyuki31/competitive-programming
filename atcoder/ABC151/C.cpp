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

    ll N, M;
    cin >> N >> M;
    map<pair<ll, string>,ll> mp;
    
    rep(_,M){
        ll p; string S;
        cin >> p >> S;
        if(!mp.count({p,"AC"})) mp[{p, S}]++;
    }

    ll cor = 0, pen = 0;
    rep1(i, N){
        cor += mp.count({i, "AC"});
        pen += mp[{i, "WA"}] * mp.count({i,"AC"});
    }

    cout << cor << " " << pen << '\n';
    return 0;
}