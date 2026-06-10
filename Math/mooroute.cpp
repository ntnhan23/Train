#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;

int N;
int a[maxn];
int p[maxn], inv[maxn];

int modpow(int x, int y) {
    int ans = 1LL;
    while (y > 0) {
        if (y % 2 == 1) ans = ans * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return ans;
}

void precalc() {
    int lim = 2e6;
    p[0] = 1LL;
    for (int i = 1; i <= lim; i++) p[i] = p[i-1] * i % mod;
    inv[lim] = modpow(p[lim], mod - 2);
    for (int i = lim-1; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % mod;
}

int C(int x, int y) {
    if (y > x || y < 0) return 0;
    return p[x] * inv[y] % mod * inv[x-y] % mod;
}

int ChiaKeoEuler(int n, int m) {
    /** chia m vien keo cho n nguoi **/
    return C(n + m - 1, n - 1);
}

void nhap() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
}

void xuat() {
    int ans = 1LL;
    int last = 1;
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 1) ans = 0;
        else {
            int x = a[i] / 2;
            if (x >= last) ans = ans * ChiaKeoEuler(last, (a[i] / 2) - last) % mod;
            else ans = ans * C(last, x) % mod;
            last = x;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    precalc();
    nhap();
    xuat();
}
