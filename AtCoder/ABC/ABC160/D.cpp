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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, X, Y;
    cin >> N >> X >> Y;

    map<ll, ll> d;

    rep1(i,N) rep1(j,N) if(i < j){
        ll nowi = i, nowj = j;
        ll D = 0;

        if(nowi <= X) D += X - i, nowi = X;
        if(nowj >= Y) D += j - Y, nowj = Y;

        D += min(nowj - nowi, nowi - X + Y - nowj + 1);
        d[D]++;
    }

    rep1(k,N-1){
        print(d[k]);
    }


    return 0;
}