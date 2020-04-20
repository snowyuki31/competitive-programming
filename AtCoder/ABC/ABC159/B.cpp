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

bool judge(string S){
    string S2 = S;
    reverse(ALL(S));
    return S2 == S;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;

    bool ans = judge(S);

    string S2 = "", S3 = "";
    rep(i, (len(S) - 1) / 2) S2 += S[i];
    for (ll i = (len(S) + 3) / 2 - 1; i < len(S); ++i) S3 += S[i];

    ans = ans and judge(S2) and judge(S3);

    if(ans) print("Yes");
    else print("No");

    return 0;
}