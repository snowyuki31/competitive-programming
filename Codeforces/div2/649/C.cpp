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

//Def of Monoid
//Suppose that S is a set and ● is some binary opeartion S x S -> S
//then S with ● is a monoid if it satisfies the following two:
// Associativity(結合則)
//  For all a,b and c in S, the equation (a ● b) ● c = a ● (b ● c) holds
// Identitiy element(単位元の存在)
//  There exisits an element e in S such that for every element a in S,
//  the equations e ● a = a ● e = a holds

//Eample of Monoid
//+, *, and, or, xor, min, max

//Build O(N)
//Query O(log N)
//- query(a,b) : applay operation to the range [a, b)
//- update(k,x) : change k-th element to x
//- operator[k] : return k-th element

template< typename Monoid >
class SegmentTree{
    private:
        using F = function<Monoid(Monoid, Monoid)>;
        
        long long sz;
        vector<Monoid> seg;
        const F f;
        const Monoid e;

    public:
        SegmentTree(long long n, const F f, const Monoid &e) : f(f), e(e){
            sz = 1;
            while(sz < n) sz <<= 1;
            seg.assign(2 * sz, e);
        }

        void set(long long k, const Monoid &x){
            seg[k + sz] = x;
        }

        void build() {
            for (long long k = sz - 1; k > 0; --k){
                seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
            }
        }

        void update(long long k, const Monoid &x) {
            k += sz;
            seg[k] = x;
            while(k >>= 1) seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }

        Monoid query(long long a, long long b){
            Monoid L = e, R = e;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1){
                if(a & 1) L = f(L, seg[a++]);
                if(b & 1) R = f(seg[--b],R);
            }
            return f(L, R);
        }

        Monoid operator[](const int &k) const {
            return seg[k + sz];
        }
};

/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll n;
    cin >> n;
    vec a(n);
    cin >> a;

    rep(i, n) if(a[i] > i + 1) drop(-1);

    SegmentTree<ll> segtree(n, [](ll x, ll y) { return max(x, y); }, -INF);
    rep(i, n) segtree.set(i, a[i]);
    segtree.build();

    ll mx = *max_element(ALL(a));

    set<ll> need;
    rep(i, mx) need.insert(i);

    vec res(n);
    
    rrep(i, n){
        auto itr = lower_bound(ALL(a), a[i]);
        ll idx = itr - a.begin();

        if(idx == 0){
            if(need.empty()){
                res[i] = a[i] == 0 ? 1e6 : 0;
            }else{
                res[i] = *need.rbegin();
                need.erase(res[i]);
            }
            continue;
        }

        ll now = segtree.query(0, idx);
        if(now != a[i] and i != 0){
            res[i] = now;
            need.erase(now);
        }else{
            if(need.empty()){
                res[i] = a[i] == 0 ? 1e6 : 0;
            }else{
                res[i] = *need.begin();
                need.erase(res[i]);
            }
        }
    }

    print(res);
    return 0;
}