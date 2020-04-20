#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define to_s to_string
#define len(v) (ll)v.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define print(x) cout << (x) << '\n'
#define drop(x) cout << (x) << '\n', exit(0)
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll deg, dis;
    cin >> deg >> dis;

    vector<string> degs = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    deg *= 10, deg += 1125, deg %= 36000, deg /= 2250;

    dis *= 100, dis /= 60;
    if(dis % 10 >= 5) dis += 10;
    dis -= dis % 10, dis /= 10;

    if(dis <= 2) dis = 0;
    else if(dis <= 15) dis = 1;
    else if(dis <= 33) dis = 2;
    else if(dis <= 54) dis = 3; 
    else if(dis <= 79) dis = 4;
    else if(dis <= 107) dis = 5;
    else if(dis <= 138) dis = 6;
    else if(dis <= 171) dis = 7;
    else if(dis <= 207) dis = 8;
    else if(dis <= 244) dis = 9;
    else if(dis <= 284) dis = 10;
    else if(dis <= 326) dis = 11;
    else dis = 12;

    if(dis == 0) cout << "C" << " " << 0 << '\n';
    else cout << degs[deg] << " " << dis << '\n';

    return 0;
}