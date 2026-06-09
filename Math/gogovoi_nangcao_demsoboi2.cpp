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

int n, k;
int a[21];

void solve() {

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans_1 = 0, ans_2 = 0;

    for(int mask = 1; mask < (1<<n); mask++) {
        int tmp = 1;
        for(int i = 0; i < n; i++) {
            if((mask>>i)&1) {
                if(tmp == k + 1) continue;
                int gcd = __gcd(tmp, a[i]);
                tmp /= gcd;
                //tmp * a[i] <= k
                if(tmp <= k / a[i]) {
                    tmp = tmp * a[i];
                }
                else tmp = k + 1;
            }
        }
        int cnt = __builtin_popcount(mask);
        if(cnt % 2) {
            ans_1 += k / tmp;
            ans_2 += cnt * (k / tmp);
        }
        else {
            ans_1 -= k / tmp;
            ans_2 -= cnt * (k / tmp);
        }
    }

    cout << ans_1 << " " << ans_2;

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
