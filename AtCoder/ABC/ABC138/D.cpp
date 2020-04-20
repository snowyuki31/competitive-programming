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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, Q;
    cin >> N >> Q;

    typedef vector<ll> Edge;
    struct Node{
        Edge edge;
        ll value;
        bool flag;
    };
    typedef vector<Node> Graph;

    Graph tree(N, {{},0, false});
    rep(i, N - 1){
        ll a, b;
        cin >> a >> b;
        --a, --b;
        tree[a].edge.pb(b);
        tree[b].edge.pb(a);
    }    

    rep(_, Q){
        ll p, x;
        cin >> p >> x;
        --p;
        tree[p].value += x;
    }

    stack<Node> sk;
    sk.push(tree[0]);
    tree[0].flag = true;

    while(!sk.empty()){
        Node now = sk.top();
        sk.pop();
        ll s = now.value;

        for(auto e : now.edge){
            if(tree[e].flag) continue;
            tree[e].value += s;
            tree[e].flag = true;
            sk.push(tree[e]);
        }
    }

    rep(i,N) cout << tree[i].value << " ";

    return 0;
}