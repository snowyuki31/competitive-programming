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

struct dice{
    ll x, y, z;
};

dice roll(dice d, ll dir){
    ll x = d.x, y = d.y, z = d.z;
    if(dir == 0) d.x = y, d.y = 7 - x;
    if(dir == 1) d.x = z, d.z = 7 - x;
    if(dir == 2) d.x = 7 - y, d.y = x;
    if(dir == 3) d.x = 7 - z, d.z = x;
    return d;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll H, W;
    cin >> H >> W;
    int s[105][105];
    rep(i, H + 2) rep(j, W + 2) if(i == 0 || j == 0 || i == H + 1 || j == W + 1) s[i][j] = -1;

    rep1(i,H){
        string S;
        cin >> S;
        rep1(j, len(S)){
            if(S[j - 1] == '#') s[i][j] = -1;
            else s[i][j] = S[j - 1] - '0';
        }
    }

    stack<pair<P,dice>> sk;
    sk.push({{1, 1},{6,2,3}});

    while(!sk.empty()){
        ll h = sk.top().first.first, w = sk.top().first.second;
        dice d = sk.top().second;
        sk.pop();
        if(s[h][w] != d.x) continue;
        if (h == H && w == W){
            print("YES");
            return 0;
        }

        sk.push({{h + 1, w}, roll(d, 0)});
        sk.push({{h, w + 1}, roll(d, 1)});
        sk.push({{h - 1, w}, roll(d, 2)});
        sk.push({{h, w - 1}, roll(d, 3)});

        s[h][w] = -1;
    }

    print("NO");

    return 0;
}