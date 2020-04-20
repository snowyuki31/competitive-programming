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

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> S(N + 1);
    S[0] = 0;
    rep(i,N) S[i + 1] = S[i] + A[i];
    rep(i, N + 1) S[i] = (S[i] - i + K) % K;

    map<ll, ll> mp;

    ll ans = 0;

    rep(i, min(K,N+1)) mp[S[i]]++;

    ans += mp[S[0]] - 1;
    for (ll i = 1; i <= N; ++i){
        mp[S[i - 1]]--;
        if(i + K - 1 <= N) mp[S[i + K - 1]]++;
        ans += mp[S[i]] - 1;
    }

    print(ans);

    return 0;
}