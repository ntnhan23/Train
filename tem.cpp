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

const int mod = 998244353;

void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}
void sub(int &x, int y) {
    x -= y;
    if(x < 0) x += mod;
}
int Pow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int f[100005];
int F[100005];
void prep() {
    f[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    F[100000] = Pow(f[100000], mod - 2);
    for(int i = 100000; i >= 1; i--) {
        F[i - 1] = F[i] * i % mod;
    }
}
int nck(int n, int k) {
    if(k > n) return 0;
    return f[n] * F[k] % mod * F[n - k] % mod;
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

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}
