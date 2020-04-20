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

    ll A[3][3];
    rep(i, 3) rep(j, 3) cin >> A[i][j];
    ll N;
    cin >> N;
    rep(i, N){
        ll b;
        cin >> b;
        rep(j, 3) rep(k, 3) if (A[j][k] == b) A[j][k] = 0;
    }

    bool flag = false;

    rep(i, 3){
        bool f2 = true;
        rep(j, 3) if (A[i][j] != 0) f2 = false;
        flag = flag || f2;
    }

    rep(j, 3){
        bool f2 = true;
        rep(i, 3) if (A[i][j] != 0) f2 = false;
        flag = flag || f2;
    }

    if(A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0) flag = true;
    if(A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0) flag = true;

    if(flag) print("Yes");
    else    print("No");

    return 0;
}