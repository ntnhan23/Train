#include<bits/stdc++.h>
#define int long long
#define oo 1000000000000000000
#define ii pair<int, int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pb push_back
using namespace std;

// phi(n) = n * (1 - 1/p)
int Phi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            ans -= ans / i;
        }
    }
    if(n != 1) ans -= ans / n;
    return ans;
}

// sang phi
int phi[1000005];

// tổng (phi(d)) = n với d là ước của n.
void sievePhi(int n){
    for(int i = 1; i <= n; ++i) phi[i] = i;
    for(int i = 1; i <= n; ++i){
        for(int j = i + i; j <= n; j += i){
           phi[j] -= phi[i];
        }
    }
}

void sieve_phi(int n) {
    for(int i = 1; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
} 

void solve() {

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    solve();
}