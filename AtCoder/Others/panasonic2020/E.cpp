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

bool match(char x, char y){
    return (x == y || x == '?' || y == '?' || x == 'X' || y == 'X');
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    string a, b, c;
    cin >> a >> b >> c;
    ll A = len(a), B = len(b), C = len(c);

    bool ab[20000], ac[20000], bc[20000];
    char AB[20000], AC[20000], BC[20000];

    rep(i, 20000){
        AB[i] = AC[i] = BC[i] = 'X';
        ab[i] = ac[i] = bc[i] = true;
    }

    rep(i, A) AB[5000 + i] = AC[5000 + i] = a[i];
    rep(i, B) BC[5000 + i] = b[i];

    for (ll i = 1000; i <= 9000; ++i){
        rep(j, B) ab[i] = ab[i] and match(AB[i + j], b[j]);
        rep(j, C) ac[i] = ac[i] and match(AC[i + j], c[j]);
        rep(j, C) bc[i] = bc[i] and match(BC[i + j], c[j]);
    }

    ll ans = 1e18;

    for (ll i = 1000; i <= 9000; ++i)
    {
        for (ll j = 1000; j <= 9000; ++j){
            if(abs(i-j) > 4000) continue;
            if(ab[i] and ac[j] and bc[5000+j-i]){
                ll L = min({5000LL,i,j});
                ll R = max({5000LL + A, B + i, C + j});
                ans = min(ans, R - L);
            }
        }
    }

    print(ans);

    return 0;
}