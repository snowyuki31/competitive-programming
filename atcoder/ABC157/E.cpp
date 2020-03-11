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
//- update(k,x) : change k-th element to x (k = 0...)
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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;

    typedef vector<bool> alph;
    
    auto f = [](alph a, alph b) {
        alph c(26, 0);
        rep(i, 26) c[i] = a[i] || b[i];
        return c;
    };

    alph e(26, true);
    SegmentTree<alph> Tree(N, f, e);

    rep(i, N){
        alph a(26, false);
        a[S[i] - 'a'] = true;
        Tree.set(i, a);
    }

    Tree.build();
    rep(i,26) print(Tree[1][i]);

    rep(_, Q){
        ll x, y;
        cin >> x >> y;
        if(x == 1){
            char z; cin >> z;
            --y;
            alph a(26,0);
            a[z - 'a'] = true;
            Tree.update(y, a);
        }
        else{
            ll z;
            cin >> z;
            --y, --z;
            alph a = Tree.query(y, z + 1);
            ll ans = 0;
            for(auto x : a) ans += x;
            print(ans);
        }
    }

    return 0;
}