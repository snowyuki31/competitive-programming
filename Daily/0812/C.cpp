#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
constexpr long long INF = 1LL << 60;
constexpr long long MOD = 1000000007;
double PI = acos(-1.0);
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> tpl;
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

template <typename T>
constexpr set<T> &operator|= (set<T> &st1, const set<T> &st2) { 
    for(auto& s : st2) st1.insert(s);
    return st1; 
}

template <typename T>
constexpr set<T> &operator-= (set<T> &st1, const set<T> &st2) {
    for(auto& s : st2) if(st1.count(s)) st1.erase(s);
    return st1;
}

template <typename T>
constexpr set<T> &operator&= (set<T> &st1, const set<T> &st2) {
    auto itr = st1.begin();
    while(itr != st1.end()){
        if(!st2.count(*itr)) itr = st1.erase(itr);
        else ++itr;
    }
    return st1;
}

template <typename T>
constexpr set<T> operator| (const set<T> &st1, const set<T> &st2) {
    set<T> res = st1;
    res |= st2;
    return res;
}

template <typename T>
constexpr set<T> operator- (const set<T> &st1, const set<T> &st2) {
    set<T> res = st1;
    res -= st2;
    return res;
}

template <typename T>
constexpr set<T> operator& (const set<T> &st1, const set<T> &st2) {
    set<T> res = st1;
    res &= st2;
    return res;
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
using ld = long double;
using Point = complex<ld>;
const ld EPS = 1e-10;

ld cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag() * b.real(); }
ld dot(const Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }


struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)){
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] << ',' << l[1] << '}'; }
};

/* ∠ABC */
double degree(Point A, Point B, Point C){
    if(B == C) return 0;
    return arg((A - B) / (C - B));
}

/* counter-clockwise */
/*
                    CCW

 -- BEHIND -- [a -- ON -- b] --- FRONT --

                    CW
 */
/*  AB, ACの関係性を調べる*/
/* 同一直線上 : positive, 非同一直線上 : negative*/
/* 同一直線上だが、CはAB上に無い : 3 */
/* 同一直線上でCはAB上の点 : 2 */
/* 同一直線上で逆向きにCが存在 : 1 */
/* AB -> ACが反時計周り : -1 */
/* AB -> ACが時計周り : -2 */
//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
enum CCW_RESULT { CCW = +1, CW = -1, BACK = +2, FRONT = -2, ON = 0 };
int ccw(Point A, Point B, Point C){
    B -= A, C -= A;
    if(cross(B, C) > EPS) return CCW;
    if(cross(B, C) < -EPS) return CW;
    if(dot(B, C) < 0) return BACK;
    if(norm(B) < norm(C)) return FRONT;
    return ON;
}
 
/* perpendicular bisector */
Line bisector(const Line& L){
    Point X = L[0], Y = L[1];
    Point C = (X + Y) / ld(2.0);
    Point D = C + (X - Y) * Point(0.0, 1.0);
    return Line(C, D);
}

/* 二直線間の角度, 平行, 垂直 */
//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
double lineAngle(const Line& L1, const Line& L2){
    return degree(Point(L1[1] - L1[0] ), Point(0.0, 0.0), Point(L2[1] - L2[0]));
}

bool isParallel(const Line& L1, const Line& L2){
    return abs(sin(lineAngle(L1, L2))) <= EPS;
}

bool isOrthogonal(const Line& L1, const Line& L2){
    return abs(cos(lineAngle(L1, L2))) <= EPS;
}

/* cross point */
/* 二直線の交点 */
// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Line& L1, const Line& L2){
    if(isParallel(L1, L2)) return Point(-INF, -INF);
    Point A = L1[0], B = L1[1];
    Point C = L2[0], D = L2[1];
    return A + (B - A) * (imag((A - C) * conj(C - D)) / imag((C - D) * conj(B - A)));
}

/* Line Segment Crossed? */
/* 線分の交差判定 */
// VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool isSegmentCrossed(const Line& L1, const Line& L2){
    Point A = L1[0], B = L1[1];
    Point C = L2[0], D = L2[1];

    if(isParallel(L1, L2)){
        if(ccw(A, B, C) == 2 or ccw(A, B, D) == 2 or ccw(C, D, A) == 2 or ccw(C, D , B) == 2) return true;
        return false;
    }


    double t = imag((A - C) * conj(C - D)) / imag((C - D) * conj(B  - A));
    double s = imag((C - A) * conj(A - B)) / imag((A - B) * conj(D - C));
    return t + EPS >= 0 and t - EPS <= 1 and s + EPS >= 0 and s - EPS <= 1;
}

/* foot of a perpendicular line　*/
/* 垂線の足 */
//TODO : バグってる
Point foot(const Point &A, const Line &L){
    return (A + L[0] + L[1] - (A * L[0] * conj(L[1]))) / ld(2.0);
};

//凸包
//VERIFIED : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
vector<Point> ConvexHull(vector<Point> X){
    sort(ALL(X), [](Point A, Point B){ return A.real() != B.real() ? A.real() < B.real() : A.imag() < B.imag(); });
    int k = 0;
    int n = X.size();
    vector<Point> res(2 * n);
    for(int i = 0; i < n; ++i){
        while(k > 1 and ccw(res[k - 2], res[k - 1], X[i]) == CW) --k;
        res[k++] = X[i];
    }
    for(int i = n - 2, t = k; i >= 0; --i){
        while(k > t and ccw(res[k - 2], res[k - 1], X[i]) == CW) --k;
        res[k++] = X[i];
    }
    res.resize(k - 1);
    return res;
}

//回転キャリパー法
//凸包に対してO(N)で最遠点対問題を解く
ld RotatingCalipers(vector<Point> CH){
    ll N = CH.size();
    if(N == 2) return abs(CH[0] - CH[1]);
    int i = 0, j = 0; //任意の方向に対する最遠点対

    auto comp_x = [](Point a, Point b)->bool{
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    };

    // x軸方向に対する最遠点対を求める
    for(int k = 0; k < N; ++k){
        if(!comp_x(CH[i], CH[k])) i = k;
        if(comp_x(CH[j], CH[k])) j = k;
    }

    ld res = 0;
    int si = i, sj = j;
    while(i != sj || j != si){
        chmax(res, abs(CH[i] - CH[j]));

        if(cross(CH[(i + 1) % N] - CH[i], CH[(j + 1) % N] - CH[j]) < 0){
            i = (i + 1) % N;
        }else{
            j = (j + 1) % N;
        }
    }
    return res;
}


/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll N;
    cin >> N;
    vector<Point> X(N);
    rep(i, N){
        long double x, y;
        cin >> x >> y;
        X[i] = {x, y};
    }

    //愚直解
    // ld mx = 0;
    // rep(i, N) rep(j, N) if(i < j){
    //     chmax(mx, abs(X[i] - X[j]));
    // }
    // print(mx);

    print(RotatingCalipers(X));

    return 0;
}   