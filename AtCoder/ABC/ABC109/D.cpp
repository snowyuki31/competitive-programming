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

    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vector<pair<P,P>> ans;
    rep(i, H) rep(j, W - 1){
        if(A[i][j] % 2 == 0) continue;
        else{
            ans.pb({{i, j}, {i, j + 1}});
            --A[i][j];
            ++A[i][j + 1];
        }
    }

    rep(i, H - 1){
        if(A[i][W-1] % 2 == 0) continue;
        else{
            ans.pb({{i, W - 1}, {i + 1, W - 1}});
            --A[i][W-1];
            ++A[i + 1][W - 1];
        }
    }

    print(len(ans));
    for(auto p : ans){
        cout << p.first.first + 1 << " " << p.first.second + 1 << " ";
        cout << p.second.first + 1 << " " << p.second.second + 1 << '\n';
    }

    return 0;
}