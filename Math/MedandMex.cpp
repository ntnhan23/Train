#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
long long test;
const int mod = 998244353;
long long fact[N],inv[N];
long long mu(long long x,long long y) {
    long long tich = 1;
    while(y > 0){
        if (y % 2 == 1) {
            tich *= x;
            tich %= mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return tich;
}
long long Cnk(long long n,long long k) {
    if (n < k) return 0;
    return ((fact[n]*inv[k])%mod *inv[n-k])%mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = inv[0] = 1;
    for (int i = 1; i<= 2e5; i++) fact[i]= (fact[i-1]*i)%mod,inv[i] = mu(fact[i],mod-2);
    cin>> test;
    while(test--) {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            long long ans = (Cnk(n-i-1,i-2)*fact[2*i-2])%mod;
            ans *= fact[n-(i*2-2)+1];
            ans %= mod;
            cout << ans << " ";
        }
        cout <<"\n";
    }
}