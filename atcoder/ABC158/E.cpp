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

    ll N, P;
    string S;
    cin >> N >> P >> S;

    vector<ll> T(N);

    ll ans = 0;
    if(P == 2 || P == 5){
        rep(i, N) T[i] = (S[i] - '0') % P;
        rep(i, N) if(T[i] == 0) ans += i + 1;
        print(ans);
        return 0;
    }

    ll dig = 1;
    rrep(i,N){
        T[i] = (S[i] - '0') * dig % P;
        dig *= 10;
        dig %= P;
    }

    vector<ll> X(P);
    ++X[0];
    ++X[T[0]%P];

    for (int i = 1; i < N; ++i){
        T[i] += T[i-1];
        T[i] %= P;
        ++X[T[i]];
    }

    rep(i,P) ans += X[i] * (X[i] - 1) / 2;

    print(ans);

    return 0;
}