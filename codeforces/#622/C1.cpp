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

    vector<ll> m(N);
    rep(i, N) cin >> m[i];

    ll index = -1, summax = 0;
    rep(i, N){
        ll now = m[i];
        ll sum = m[i];
        for (int j = i - 1; j >= 0; --j){
            sum += min(now, m[j]);
            now = min(now, m[j]);
        }
        now = m[i];
        for (int j = i + 1; j < N; ++j)
        {
            sum += min(now, m[j]);
            now = min(now, m[j]);
        }
        if(sum > summax){
            index = i;
            summax = sum;
        }
    }

    vector<ll> ans(N,0);
    ans[index] = m[index];
    ll now = m[index];
    for (int i = index - 1; i >= 0; --i){
        ans[i] = min(now, m[i]);
        now = min(now, m[i]);
    }
    now = m[index];
    for (int i = index + 1; i < N; ++i){
        ans[i] = min(now, m[i]);
        now = min(now, m[i]);
    }

    rep(i, N) cout << ans[i] << " ";

    return 0;
}