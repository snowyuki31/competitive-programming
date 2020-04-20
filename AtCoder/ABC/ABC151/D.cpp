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

ll func(ll sy, ll sx, ll gy, ll gx, ll H, ll W, char S[21][21])
{
    if (S[sy][sx] == '#' || S[gy][gx] == '#') return -1;

    bool T[21][21];
    rep(i, 21) rep(j, 21) T[i][j] = false;

    struct point
    {
        ll y;
        ll x;
        ll counter;
    };
    queue<point> que;
    que.push({sy, sx, 0});

    ll ans = 0;
    while (!que.empty())
    {
        point now = que.front();
        que.pop();
        if(T[now.y][now.x]) continue;
        else T[now.y][now.x] = true;
        
        if (now.y == gy && now.x == gx)
        {
            ans = now.counter;
            break;
        }

        if (now.y >= 1 && now.y <= H && now.x >= 1 && now.x <= W && S[now.y][now.x] != '#')
        {
            que.push({now.y + 1, now.x, now.counter + 1});
            que.push({now.y - 1, now.x, now.counter + 1});
            que.push({now.y, now.x + 1, now.counter + 1});
            que.push({now.y, now.x - 1, now.counter + 1});
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll H, W;
    cin >> H >> W;
    char S[21][21];
    rep1(i, H) rep1(j, W) cin >> S[i][j];

    ll ans = 0;
    rep1(sy, H) rep1(sx, W) rep1(gy, H) rep1(gx, W)
    {
        ll mv = func(sy, sx, gy, gx, H, W, S);
        ans = max(ans, mv);
    }
    print(ans);

    return 0;
}