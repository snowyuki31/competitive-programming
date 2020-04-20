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

    string S;
    cin >> S;
    ll N = len(S);
    vector<ll> ans(N, 0);

    ll tp = 0;
    rep(i,N){
        if(S[i] == 'R'){
            ++tp;
            if(S[i + 1] == 'L'){
                ans[i] = tp;
                tp = 0;
            }
        }
    }
    tp = 0;
    rrep(i, N){
        if(S[i] == 'L'){
            ++tp;
            if(S[i - 1] == 'R'){
                ans[i] = tp;
                tp = 0;
            }
        }
    }

    rep(i, N - 1){
        ll x = ans[i], y = ans[i + 1];
        if(S[i] == 'R' and S[i+1] == 'L'){
            ans[i] = devc(x, 2) + y / 2;
            ans[i + 1] = x + y - ans[i];
        }
    }

    rep(i, N) cout << ans[i] << " ";
    print("");

    return 0;
}