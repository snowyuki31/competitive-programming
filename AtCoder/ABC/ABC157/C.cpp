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

    ll X = 1;
    rep(i,N) X *= 10;
    --X;

    vector<ll> s(M), c(M);

    rep(i, M) cin >> s[i] >> c[i];

    if(N == 1 && M == 0){
        print(0);
        return 0;
    }

    if(N == 1){
        bool f = true;
        rep(i, M) if(c[i] != 0) f = false;
        if(f){
            print(0);
            return 0;
        }
    }


    for (int i = X/10 + 1; i <= X; ++i){
        string XX = to_string(i);
        bool flag = true;

        rep(j, M){
            flag = flag && XX[s[j] - 1] - '0' == c[j];
        }
        if(flag){
            print(i);
            return 0;
        }
    }

    print(-1);

    return 0;
}