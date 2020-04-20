#include <bits/stdc++.h>
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
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
ll MOD = 1e9 + 7;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<ll> cum(vector<ll> a, ll N){
    vector<ll> S;
    ll sum = 0;
    priority_queue<ll> que;
    rep(i, N) sum += a[i], que.push(-a[i]);
    S.pb(sum);

    for (ll i = N; i < 2 * N; ++i){
        ll mn = -que.top();
        if(a[i] > mn){
            que.pop();
            que.push(-a[i]);
            sum -= mn;
            sum += a[i];
        }
        S.pb(sum);
    }

    return S;
}

vector<ll> cum2(vector<ll> a, ll N)
{
    vector<ll> S;
    ll sum = 0;
    priority_queue<ll> que;
    rep(i, N) sum += a[i], que.push(a[i]);

    S.pb(sum);
    for (ll i = N; i < 2 * N; ++i)
    {
        ll mx = que.top();
        if (a[i] < mx)
        {
            que.pop();
            que.push(a[i]);
            sum -= mx;
            sum += a[i];
        }
        S.pb(sum);
    }

    return S;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vec a(3 * N);
    rep(i, 3 * N) cin >> a[i];

    vec s = cum(a, N);
    reverse(ALL(a));
    vec sr = cum2(a, N);

    ll ans = -1e18;
    rep(i, N + 1) chmax(ans, s[i] - sr[N - i]);
    print(ans);

    return 0;
}