#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n + 1, 0);
        for(int i = 1; i <= n; ++i) cin >> s[i];

        int ans = 0;
        auto dfs = [&](auto &&self, int now, int ct = 1) -> void {
            for (int k = 2; k <= n; ++k){
                int next = now * k;
                if(next > n) break;
                if(s[next] > s[now]) self(self, next, ct + 1); 
            }

            ans = max(ans, ct);
        };

        for (int i = 1; i <= n; ++i) dfs(dfs, i);

        cout << ans << '\n';
    }

    return 0;
}