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

string BASE_CONVERSION(ll num, ll base, ll digit)
{
    string s = "";
    ll x = pow(base, digit - 1);
    for (ll i = 0; i < digit; i++)
        s += to_s(num / x + 1), num %= x, x /= base;
    return s;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll K, N;
    cin >> K >> N;
    vector<string> v(N), w(N);
    rep(i, N) cin >> v[i] >> w[i];

    map<ll, ll> dig;
    map<ll, string> ans;
    ll X = pow(3, K);

    rep(i, X){
        string d = BASE_CONVERSION(i, 3, K);
        rep1(j, K) dig[j] = d[j - 1] - '0', ans[j] = "-";

        bool flag = true;
        rep(j, N){
            string V = v[j], W = w[j];
            ll sum = 0;
            for(auto c : V) sum += dig[c - '0'];
            if(sum != len(W)){
                flag = false;
                continue;
            }

            ll now = 0;
            for(auto c : V){
                string s = "";
                for (ll k = now; k < now + dig[c - '0']; ++k) s += W[k];
                now = now + dig[c - '0'];
                if(ans[c - '0'] == "-") ans[c - '0'] = s;
                else if(ans[c - '0'] != s){
                    flag = false;
                    continue;
                }
            }
        }

        if(flag){
            rep1(j, K) print(ans[j]);
            return 0;
        }
    }




    return 0;
}