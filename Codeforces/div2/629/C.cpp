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

    ll N;
    cin >> N;

    rep(_,N){
        ll t;
        string x;
        cin >> t >> x;
        string a = "", b = "";
        bool flag = false;
        rep(i,t){
            if(x[i] == '2'){
                if(flag) a += '0', b += '2';
                else a += '1', b += '1';
            }else if(x[i] == '1'){
                if(flag) a += '0', b += '1';
                else a += '1', b += '0';
                flag = true;
            }else{
                a += '0', b += '0';
            }
        }
        print(a);
        print(b);
    }

    return 0;
}