#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
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
ll MOD = 1e9 + 7;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll t;
    cin >> t;
    rep(TEST,t){
        ll n;
        cin >> n;
        vector<ll> v(n+1,0);
        ll dau = 0;
        rep1(i,n){
            ll x;
            cin >> x;
            vector<ll> ls(x);
            rep(j, x) cin >> ls[j];
            bool flag = false;
            rep(j, x){
                if(v[ls[j]] == 0){
                    v[ls[j]] = i;
                    flag = true;
                    break;
                }
            }
            if(!flag) dau = i; 
        }
        
        if(dau == 0){
            print("OPTIMAL");
            continue;
        }

        rep1(i,n){
            if(v[i] == 0){
                print("IMPROVE");
                cout << dau << " " << i << '\n';
                break;
            }
        }
    }


    return 0;
}