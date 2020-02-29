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

template< typename T >
class BinaryIndexedTree{
    private:
        vector<T> array;

    public:
        // Constructer
        BinaryIndexedTree(long long sz){
            array.assign(++sz, 0LL);
        }

        // Culuclate sum in the inclusive range [0,k]
        T sum(long long k) {
            T ret = 0;
            for (++k; k > 0; k -= k & -k) ret += array[k];
            return (ret);
        }

        // Add x to k th element
        void add(long long k, T x){
            for (++k; k < array.size(); k += k & -k) array[k] += x;
        }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll Q;
    cin >> Q;
    BinaryIndexedTree<ll> BIT(200000*2);
    rep(_, Q){
        ll T, X;
        cin >> T >> X;
        if(T == 1){
            BIT.add(X, 1);
        }else{
            ll l = 0, r = 200000*2;
            while(r - l > 1){
                ll m = (l + r) / 2;
                if(BIT.sum(m) >= X) r = m;
                else l = m;
            }
            print(r);
            BIT.add(r, -1);
        }
    }

    return 0;
}