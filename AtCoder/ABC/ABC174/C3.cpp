#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
using namespace std;
static inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int pow(long x, int n, int m){
    long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x, ret %= m;
        x *= x, x %= m;
        n >>= 1; 
    }
    return ret % m;
}

int euler_phi(int n) {
   int ret = n;
   for(int i = 2; i * i <= n; ++i){
       if(n % i == 0) {
           ret -= ret / i;
           while(n % i == 0) n /= i;
       }
   }
   if(n > 1) ret -= ret / n;
   return ret;
}

int main()
{
    int K = 0, c = getchar();
    while(c > 47 && c < 58){
        K = K * 10 + c - 48;
        c = getchar();
    }

    K /= gcd(K, 7);
    if(K == 1){
        putchar('1');
        return 0;
    }

    K *= 9;

    if(gcd(K, 10) != 1) {
        putchar('-');
        putchar('1');
        return 0;
    }

    int res = euler_phi(K);

    int ans = 1000000;
    int now = 10;
    int mx = 0;
    for(int i = 1; i * i <= res; ++i){
        if(res % i == 0) {
            if(now == 1){
                printf("%d\n", i);
                return 0;
            }
        }
        now *= 10, now %= K;
        mx = i;
    }
    for (int i = mx; i >= 1; --i){
        if(res % i == 0){
            if(pow(10, res / i, K) == 1){
                printf("%d\n", res / i);
                return 0;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
