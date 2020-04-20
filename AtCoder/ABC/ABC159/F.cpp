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
ll MOD = 998244353;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N,S;
    cin >> N >> S;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> coef(S+5,0);

    ll ans = 0;

    rep(i,N){
        vector<ll> now(S+5);
        ++now[0];
        if(A[i] <= S) ++now[A[i]];
        rep(j, S+5){
            now[j] += coef[j];
            if(j + A[i] <= S) now[j+A[i]] += coef[j];

            now[j] %= MOD;
        }
        coef = now;

        ans += coef[S], ans %= MOD;
    }


    print(ans);

    return 0;
}