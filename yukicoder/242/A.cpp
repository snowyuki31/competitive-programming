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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    priority_queue<ll> A;
    rep(i, N){
        ll a;
        cin >> a;
        a = (a / 1000 + 1) * 1000;
        A.push(a);
    }

    while(!A.empty()){
        ll now = A.top();
        ll next;
        A.pop();

        if(now > 10000){
            Z -= now / 10000;
            next = now % 10000;
        }else if(now > 5000){
            if(Z > 0){
                --Z;
                next = 0;
            }else{
                --Y;
                next = now % 5000;
            }
        }else{
            if(Z > 0) --Z, next = 0;
            else if(Y > 0) --Y, next = 0;
            else{
                X -= now / 1000;
                next = 0;
            }
        }

        if(Z < 0) Y -= abs(Z) * 2, Z = 0;
        if(Y < 0) X -= abs(Y) * 5, Y = 0;
        if(X < 0){
            print("No");
            return 0;
        }


        if(next != 0) A.push(next);
    }

    print("Yes");

    return 0;
}