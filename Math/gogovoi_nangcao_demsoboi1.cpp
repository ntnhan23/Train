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

vector<int> nt;
int n, k;

bool c(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> k;
    for(int i = 2; i <= k; i++) {
        if(c(i)) nt.pb(i);
    }

    int res = 0;
    int sz = nt.size();
    for(int mask = 1; mask < (1<<sz); mask++) {
        int tmp = 1;
        for(int i = 0; i < sz; i++) {
            if((mask>>i)&1) tmp = tmp * nt[i];
        }
        if((__builtin_popcount(mask))&1) {
            res += n/tmp;
        }
        else {
            res -= n/tmp;
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

    while(t--) {
        solve();
    }
}
