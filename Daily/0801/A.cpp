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

template< typename T >
ostream &operator << (ostream &os, const set< T > &st){
    int ct = 0;
    for(auto& s : st) cout << s << (++ct != st.size() ? " " : "");
    return os;
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

/*---------------------------------   Geometry   -----------------------------------------*/
using Point = complex<double>;

struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)){
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] << ',' << l[1] << '}'; }
};

/* ∠ABC */
double degree(Point A, Point B, Point C){
    return arg((A - B) / (C - B));
}

/* ccw : 1のとき、AB//AC ⇔ 3点が同一直線上 */
bool ccw(Point A, Point B, Point C){
    return imag((A - B) / (A - C)) == 0;
}

/* perpendicular bisector */
Line bisector(const Line& L){
    Point X = L[0], Y = L[1];
    Point C = (X + Y) / 2.0;
    Point D = C + (X - Y) * Point(0.0, 1.0);
    return Line(C, D);
}

/* 二直線が平行か? */
bool isParallel(const Line& L1, const Line& L2){
    return imag((L1[0] - L1[1]) / (L2[0] - L2[1])) == 0;
}

/* cross point */
/* 二直線の交点 */
Point crosspoint(const Line& L1, const Line& L2){
    if(isParallel(L1, L2)) return Point(-INF, -INF);
    Point A = L1[0], B = L1[1];
    Point C = L2[0], D = L2[1];
    return A + (B - A) * (imag((A - C) * conj(C - D)) / imag((C - D) * conj(B - A)));
}

/* Line Segment Crossed? */
/* 線分の交差判定 */
bool isSegmentCrossed(const Line& L1, const Line& L2){
    if(isParallel(L1, L2)) return false;
    Point A = L1[0], B = L1[1];
    Point C = L2[0], D = L2[1];
    double t = imag((A - C) * conj(C - D)) / imag((C - D) * conj(B - A));
    double s = imag((C - A) * conj(A - B)) / imag((A - B) * conj(D - C));
    return t >= 0 and t <= 1 and s >= 0 and s <= 1;
}

/* foot of a perpendicular line　*/
/* 垂線の足 */
Point foot(const Point &A, const Line &L){
    return (A + L[0] + L[1] - (A * L[0] * conj(L[1]))) / 2.0;
};

/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    Point A(Ax, Ay), B(Bx, By);

    ll N;
    cin >> N;
    vector<Point> ps(N);
    rep(i, N){
        ll X, Y;
        cin >> X >> Y;
        ps[i] = Point(X, Y);
    }

    Line AB(A, B);

    ll ct = 0;
    rep(i, N){
        Line now(ps[i], ps[(i + 1) % N]);
        ct += isSegmentCrossed(AB, now);
    }
    print(1 + ct / 2);

    return 0;
}