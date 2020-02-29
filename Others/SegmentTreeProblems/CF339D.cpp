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

    ll N, Q;
    cin >> N >> Q;
    ll A[18][1000001];
    rep(i, 1 << N) cin >> A[0][i];
    rep(i, N) rep(j, 1<<(N-1-i)){
        if(i % 2) A[i + 1][j] = A[i][2 * j] ^ A[i][2 * j + 1];
        else A[i + 1][j] = A[i][2 * j] | A[i][2 * j + 1];
    }

    rep(_, Q){
        ll x, y;
        cin >> x >> y;
        x--;
        A[0][x] = y;
        rep(j, N){
            if(j % 2) A[j + 1][x / 2] = A[j][x] ^ A[j][x ^ 1];
            else A[j + 1][x / 2] = A[j][x] | A[j][x ^ 1];
            x /= 2;
        }
        print(A[N][0]);
    }

    return 0;
}