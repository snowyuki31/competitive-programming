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

    rep(_, N)
    {
        vector<ll> A(3);
        cin >> A[0] >> A[1] >> A[2];
        sort(ALL(A));
        ll a = A[2], b = A[1], c = A[0];
        ll ans = 0;

        if (a >= 1) a--, ans++;
        if (b >= 1) b--, ans++;
        if (c >= 1) c--, ans++;
        if (a >= 1 && b >= 1) a--, b--, ans++;
        if (a >= 1 && c >= 1) a--, c--, ans++;
        if (b >= 1 && c >= 1) b--, c--, ans++;
        if (a >= 1 && b >= 1 && c >= 1) a--, b--, c--, ans++;

        print(ans);
    }

    return 0;
}