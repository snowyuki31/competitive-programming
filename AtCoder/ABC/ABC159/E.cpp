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

    ll H, W, K;
    cin >> H >> W >> K;
    ll S[15][1005];
    rep(i, H){
        string s;
        cin >> s;
        rep(j, len(s)) S[i][j] = s[j] - '0';
    }

    ll ans = 1e18;
    rep(i, 1 << (H-1)){
        bitset<10> x(i);
        string X = x.to_string();
        reverse(ALL(X));

        vector<ll> v(10,0);
        ll sum = 0;
        rep(j, H - 1) sum += X[j] == '1';

        rep(j, W){
            ll now = 0, smx = 0, vmx = 0;
            vector<ll> s(10, 0);
            rep(k, H){
                s[now] += S[k][j];
                v[now] += S[k][j];
                smx = max(smx, s[now]);
                vmx = max(vmx, v[now]);
                if (X[k] == '1') ++now;
            }
            if(smx > K){
                sum = 1e18;
                break;
            }
            if(vmx > K){
                v = s;
                ++sum;
            }
        }
        ans = min(ans, sum);
    }

    print(ans);

    return 0;
}