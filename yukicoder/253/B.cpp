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
    vector<ll> A(2 * N);
    rep(i, 2 * N) cin >> A[i];

    vector<ll> sum(N);
    rep(i,N) sum[i] = A[2 * i] - A[2 * i + 1];
    for(ll i = 1; i < N; ++i) sum[i] += sum[i-1];

    ll ans = 0;
    rep(i,N){
        ll cum = 0;
        if(!i){
            cum += abs(sum[0]);
            cum -= sum[N - 1] - sum[0];
        }else{
            cum += abs(sum[i] - sum[i - 1]);
            cum += sum[i - 1];
            cum -= sum[N - 1] - sum[i];
        }
        ans = max(ans, cum);
    }
    print(ans);
    return 0;
}