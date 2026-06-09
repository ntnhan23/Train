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

const int mod = 1e9 + 7;

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

int m, t;
int a[100005];

void solve() {

    cin >> m >> t;
    for(int i = 1; i <= t; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for(int i = 1; i <= m; i++) a[i] += a[i - 1];

    int dem = 0;
    for(int i = 1; i <= m; i++) {
        if(a[i] > 0) {
            int pos = i;
            while(pos + 1 <= m && a[pos + 1] > 0) pos++;
            dem += (pos - i + 1);
            i = pos;
        }
    }

    int res = 0;
    for(int i = 0; i <= dem; i++) {
        if(i % 2 == 0) {
            add(res, nck(dem, i) * f[m - i] % mod);
        }
        else {
            sub(res, nck(dem, i) * f[m - i] % mod);
        }
    }
    cout << res;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    int t = 1;
    // cin >> t;
    prep();
    while(t--) {
        solve();
    }
}
