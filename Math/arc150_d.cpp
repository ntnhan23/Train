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

int n;
vector<int> e[200005];
int cnt[200005];

void dfs(int u, int hi) {
    cnt[1]++;
    cnt[hi + 1]--;
    for(auto v: e[u]) {
        dfs(v, hi + 1);
    }
}


void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        e[x].pb(i);
    }

    dfs(1, 1);

    int res = 0;
    for(int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        int tmp = Pow(i, mod - 2);
        tmp = tmp * cnt[i] % mod;
        add(res, tmp);
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
