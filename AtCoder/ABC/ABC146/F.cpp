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

    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    ll sum = 0;
    ll ans = 0;
    rep(i,len(S)){
        if(S[i] == '0') sum = 0;
        else sum++;
        if(sum >= M){
            print(-1);
            return 0;
        } 
    }

    reverse(ALL(S));
    vector<ll> pos(len(S));

    rep1(i, min(M,N)) if (S[i] != '1') pos[0] = i;

    for (ll i = 1; i <= N; ++i){
        if(S[min(i + M, N)] == '0') pos[i] = min(i + M,N);
        else pos[i] = pos[i-1];
    }

    vector<ll> dice;
    ll now = 0;
    while(now < N){
        dice.pb(pos[now] - now);
        now = pos[now];
    }

    rrep(i, len(dice)) cout << dice[i] << " ";
    cout << '\n';

    return 0;
}