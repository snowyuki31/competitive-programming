#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <random>
constexpr long long INF = 1LL << 31;
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
#define debug(x) cerr << #x << ": " << (x) << '\n'
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

// #include <atcoder/all>
// using namespace atcoder;
constexpr long long MOD = 1000000007;
/*------------------------------- Main Code Here -----------------------------------------*/

class Item{
    public:
        int num[4];

        friend istream &operator>>(istream &is, Item& x){
            rep(i, 4) is >> x.num[i];
            return is;
        }
        constexpr Item operator-(const Item &r) const noexcept { return Item(*this) -= r; }
        constexpr Item& operator-= (const Item &r) noexcept {
            rep(i, 4) num[i] -= r.num[i];
            return *this;
        }
        constexpr Item operator+(const Item &r) const noexcept { return Item(*this) += r; }
        constexpr Item &operator+=(const Item &r) noexcept
        {
            rep(i, 4) num[i] += r.num[i];
            return *this;
        }
        constexpr int &operator[](const int i) noexcept { return num[i]; }

        int sum(){
            int s = 0;
            rep(i, 4) s += num[i];
            return s;
        };

        bool positive(){
            bool flag = true;
            rep(i, 4) if (num[i] < 0) flag = false;
            return flag;
        };
};

class Action{
    public:
        int actionId;      // the unique ID of this spell or recipe
        string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
        Item delta;
        int price;         // the price in rupees if this is a potion
        int tomeIndex;     // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
        int taxCount;      // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
        bool castable;     // in the first league: always 0; later: 1 if this is a castable player spell
        bool repeatable;   // for the first two leagues: always 0; later: 1 if this is a repeatable player spell

        void read(){
            cin >> actionId >> actionType >> delta >> price >> tomeIndex >> taxCount >> castable >> repeatable;
            cin.ignore();
        };

        bool callable(Item inv){
            bool flag = true;
            Item res = inv + delta;
            return castable and res.positive();
        };
};

class Inventry{
    public:
        Item inv;
        int score; // amount of rupees
        
        void read(){
            cin >> inv >> score;
            cin.ignore();
        }

        bool check(Action& action){
            bool okay = true;
            rep(i, 4) if (inv.num[i] + action.delta.num[i] < 0) okay = false;
            return okay;
        };

        void apply(Action& action){
            rep(i, 4) inv.num[i] += action.delta.num[i];
        };

        void revert(Action& action){
            rep(i, 4) inv.num[i] -= action.delta.num[i];
        };
};

vector<Action> Brew, Cast, Opp_cast;
Inventry Mine, Opp;
void get_inputs(){
    int actionCount; // the number of spells and recipes in play
    cin >> actionCount;
    cin.ignore();

    for (int i = 0; i < actionCount; i++)
    {
        Action A;
        A.read();
        if(A.actionType == "CAST") Cast.pb(A);
        if(A.actionType == "BREW") Brew.pb(A);
        if(A.actionType == "OPPONENT_CAST") Opp_cast.pb(A);
    }

    Mine.read();
    Opp.read();
};

void free(){
    Brew.clear();
    Cast.clear();
    Opp_cast.clear();
};

void DO(string task, int id){
    cout << task << " " << id << endl;
    free();
};

void BREW(int id){
    DO("BREW", id);
};
void CAST(int id){
    DO("CAST", id);
};
void REST(){
    cout << "REST" << endl;
    free();
}

void dfs(ll d){
    if(d == 10) return;
    
}


int main()
{
    // game loop
    while (1)
    {
        get_inputs();

        int mx = -INF;
        int id = 0;
        Item need;
        for(auto& brew : Brew){
            if(Mine.check(brew)){
                if(chmax(mx, brew.price)) id = brew.actionId, need = brew.delta;
            }
        }

        if(mx != -INF){
            BREW(id);
            continue;
        }

        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        shuffle(ALL(Cast), engine);

        bool done = false;
        
        




        if(!done) REST();

        // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT
    }
    return 0;
}