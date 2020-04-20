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
    ll sum = 0;
    rep(i, N) cin >> A[i], sum += A[i];
    sort(ALL(A));

    vector<ll> div;

    for (ll i = 1; i <= sqrt(sum) + 1; ++i){
        if(sum % i == 0) div.pb(i), div.pb(sum/i);
    }
    sort(ALL(div));

    ll ans = 1;

    for(auto d : div){
        if(d == 1) continue;
        vector<ll> tmp(N), S1(N), S2(N);
        rep(i, N) tmp[i] = A[i] % d;
        sort(ALL(tmp));

        rep(i,N){
            if(!i) S1[i] = tmp[i];
            else S1[i] = tmp[i] + S1[i-1];
        }
        rrep(i,N){
            if(i == N - 1) S2[i] = d - tmp[i];
            else S2[i] = d - tmp[i] + S2[i+1];
        }

        rep(i, N) rep(j,N) if(N - 1 - j > i) if(N - 1 - j - i == 1){
            if(S1[i] == S2[N - 1 - j]){
                if(S1[i] <= K) ans = max(ans, d);
                break;
            }
        }
    }

    print(ans);

    return 0;
}