#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
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
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
 
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
 
template< typename T1, typename T2, typename T3 >
ostream &operator << (ostream &os, const tuple< T1, T2, T3 > &t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return os;
}
 
template< typename T1, typename T2, typename T3 >
istream &operator >> (istream &is, tuple< T1, T2, T3 > &t) {
    is >> get<0>(t) >> get<1>(t) >> get<2>(t);
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
double trisearch(S left, T right, F f, int maxLoop = 90){
    double low = left, high = right;
    while(maxLoop--){
        double mid_left = high / 3 + low * 2 / 3;
        double mid_right = high * 2 / 3 + low / 3;
        if(f(mid_left) >= f(mid_right)) low = mid_left;
        else high = mid_right;
    }
    return (low + high) * 0.5;
}

template< typename F >
ll ternarySearch(ll L, ll R, F f) { //[L, R)
    ll lo = L - 1, hi = R - 1;
    while (lo + 1 != hi) {
        ll mi = (lo + hi) / 2;
        if (f(mi) <= f(mi + 1)) hi = mi;
        else lo = mi;
    }
    return hi;
}

/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll T;
    cin >> T;
    typedef tuple<ll, ll, ll> camel;
    typedef tuple<ll, ll, ll, ll> CAMEL;

    while (T--)
    {
        ll N;
        cin >> N;
        vector<CAMEL> camef;
        vector<CAMEL> cameb;
        ll sum = 0;
        vector<camel> came(N);

        rep(i, N){
            ll K, L, R;
            cin >> K >> L >> R;
            came[i] = {K, L, R};
            if(L == R) sum += L;
            else if(L > R){
                camef.pb({-(L - R), K, L, R});
            }
            else{
                cameb.pb({(R - L), K, L, R});
            }
        }


        sort(ALL(camef));
        sort(RALL(cameb));

        for(auto [K, sc, L, R] : cameb){
            cout << K << " " << sc << endl;
        }

        vector<CAMEL> res(N, {0, 0, 0, 0});

        set<ll> st;
        rep(i, len(camef)) st.insert(i);

        rep(i, len(camef)){
            auto [sc, K, L, R] = camef[i];

            if(st.empty()){
                res[i] = camef[i];
                continue;
            }

            //K - 1以内で最大のst
            auto itr = st.upper_bound(K - 1);
            if(itr == st.begin()){
                sum += R;
                continue;
            }
            --itr;
            res[*itr] = camef[i];
            sum += R;
            st.erase(itr);
        }

        st = {};
        rep(i, len(cameb)) st.insert(N - 1 - i);
        rep(i, len(cameb)){
            auto [sc, K, L, R] = cameb[i];

            if(st.empty()){
                res[i] = cameb[i];
            }

            //K - 1より大きい最小のst
            auto itr = st.upper_bound(K - 1);
            if(itr == st.end()){
                sum += L;
                continue;
            }
            res[*itr] = cameb[i];
            sum += R;
            st.erase(itr);
        }

        print(sum);
    }

    return 0;
}