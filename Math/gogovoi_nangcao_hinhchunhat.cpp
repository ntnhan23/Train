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

struct nhan {
    int x, y, u, v;
    nhan(int _x = 0, int _y = 0, int _u = 0, int _v = 0): x(_x), y(_y), u(_u), v(_v) {}
};

int n;
nhan a[16];

void solve() {

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v;

    int ans = 0;
    for(int mask = 1; mask < (1<<n); mask++) {
        int min_x = 1e9, max_x = 0;
        int min_y = 1e9, max_y = 0;
        for(int i = 0; i < n; i++) {
            if((mask>>i)&1) {
                min_x = min(min_x, a[i].u);
                max_x = max(max_x, a[i].x);
                min_y = min(min_y, a[i].v);
                max_y = max(max_y, a[i].y);
            }
        }
        int tmp = max(0ll, min_x - max_x) * max(0ll, min_y - max_y);
        if((__builtin_popcount(mask))&1) ans += tmp;
        else ans -= tmp;
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

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
