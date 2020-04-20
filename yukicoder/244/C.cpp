#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
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
template<class S, class T> inline bool chmax(S &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline ll msb(ll v) { return 1 << (31 - __builtin_clzll(v)); }
inline ll devc(ll x, ll y) { return (x + y - 1) / y; }

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

template< typename T1, typename T2 >
ostream &operator << (ostream &os, const pair< T1, T2 > &p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
istream &operator >> (istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T >
ostream &operator << (ostream &os, const vector< T > &v){
    for (int i = 0; i < (int)v.size(); ++i) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator >>  (istream &is, vector< T > &v){
    for(T &in : v) is >> in;
    return is;
}

/*---------------------------------    Tools    ------------------------------------------*/
template< typename T >
vector<T> cumsum(const vector<T> &X){
    vector<T> res(X.size() + 1, 0);
    for(int i = 0; i < X.size(); ++i) res[i + 1] += res[i] + X[i];
    return res;
}

//f :　単調性の関数
template< typename S, typename T, typename F>
pair<T, T> bisearch(S left, T right, F f) {
    while(abs(right - left) > 1){
        T mid = (right + left) / 2;
        if(f(mid)) right = mid;
        else left = mid;
    }
    return {left, right};
}

template< typename S, typename T, typename F>
double trisearch(S left, T right, F f, double precision = 1e-10){
    double low = left, high = right;
    while(high - low > precision){
        double mid_left = high / 3 + low * 2 / 3;
        double mid_right = high * 2 / 3 + low / 3;
        if(f(mid_left) >= f(mid_right)) low = mid_left;
        else high = mid_right;
    }
    return high;
}


/*------------------------------- Main Code Here -----------------------------------------*/

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<pair<string, ll>> S(N);
    cin >> S;

    vec2 f(1e5 + 1, vec(3, INF)); //0 : J, 1 : O, 2 : I
    f[0][0] = f[0][1] = f[0][2] = 0;

    rep(i, N){
        map<char, ll> mp;
        auto [s, v] = S[i];
        for(auto c : s) ++mp[c];

        for (ll j = 0; j <= 1e5; ++j){
            if(j >= mp['J']) chmin(f[j][0], f[j - mp['J']][0] + v);
            if(j >= mp['O']) chmin(f[j][1], f[j - mp['O']][1] + v);
            if(j >= mp['I']) chmin(f[j][2], f[j - mp['I']][2] + v);
        }
        for (ll j = 1e5; j >= 1; --j) rep(k, 3) chmin(f[j - 1][k], f[j][k]);
    }

    if(f[1][0] == INF or f[1][1] == INF or f[1][2] == INF) drop(-1);


    ll ans = f[K][0] + f[K][1] + f[K][2];

    rep(i, N) rep(j, N){
        auto [s1, v1] = S[i];
        auto [s2, v2] = S[j];
        ll l1 = len(s1), l2 = len(s2);

        vec J1(l1), O1(l1), I1(l1);
        vec J2(l2), O2(l2), I2(l2);

        rep(k, l1){
            J1[k] = s1[k] == 'J';
            O1[k] = s1[k] == 'O';
            I1[k] = s1[k] == 'I';
        }
        rep(k, l2){
            J2[k] = s2[k] == 'J';
            O2[k] = s2[k] == 'O';
            I2[k] = s2[k] == 'I';
        }
        vec j1, o1, i1, j2, o2, i2;
        j1 = cumsum(J1);
        o1 = cumsum(O1);
        i1 = cumsum(I1);
        j2 = cumsum(J2);
        o2 = cumsum(O2);
        i2 = cumsum(I2);

        rep(x, l1 + 1) rep(y, l2 + 1){
            ll ctj = j1[x];
            ll cto = o1.back() - o1[x] + o2[y];
            ll cti = i2.back() - i2[y];

            chmin(ans, v1 + v2 + f[max(K - ctj, 0LL)][0] + f[max(K - cto, 0LL)][1] + f[max(K - cti, 0LL)][2]);
        }

        if(j == 0){
            rep(x, l1 + 1) rep(y, l1 + 1) if(x < y) {
                ll ctj = j1[x];
                ll cto = o1[y] - o1[x];
                ll cti = i1.back() - i1[y];

                if(cto >= K) chmin(ans, v1 + f[max(K - ctj, 0LL)][0] + f[max(K - cti, 0LL)][2]);
            }
        }
    }

    print(ans);

    return 0;
}