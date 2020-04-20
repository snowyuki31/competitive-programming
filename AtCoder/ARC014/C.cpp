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
    string S;
    cin >> N >> S;
    N = len(S);

    deque<char> que;

    for (ll i = 0; i < N; ++i){
        char l = 'X', r = 'X';
        if(!que.empty()){
            l = que.front();
            r = que.back();
        }

        if(S[i] == l) que.pop_front();
        else if(S[i] == r) que.pop_back();
        else{
            if(i != N - 1){
                if(S[i + 1] == l) que.push_back(S[i]);
                else que.push_front(S[i]);
            }else{
                que.push_front(S[i]);
            }
        }
    }

    print(len(que));

    return 0;
}