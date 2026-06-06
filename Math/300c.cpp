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

const int mod = 1000000007;
const int N = 1000005;

int fact[N], invfact[N];

int power(int a, int b) {
    int ans = 1;

    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}

int C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

bool good(int x, int a, int b) {
    if(x == 0) return false;

    while(x > 0) {
        int digit = x % 10;

        if(digit != a && digit != b) return false;

        x /= 10;
    }

    return true;
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    invfact[n] = power(fact[n], mod - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        int sum = i * a + (n - i) * b;

        if(good(sum, a, b)) {
            ans += C(n, i);
            ans %= mod;
        }
    }

    cout << ans;
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