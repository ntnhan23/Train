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

int Pow(int p, int q, int mod) {
    if(q == 0) return 1 % mod;
    if(q == 1) return p % mod;
    int x = Pow(p, q / 2, mod);
    x = x * x % mod;
    if(q % 2) x = x * p % mod;
    return x;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int mu = Pow(b, c, mod - 1);
    cout << Pow(a, mu, mod) << "\n";
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