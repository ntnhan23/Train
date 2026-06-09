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

const int N = 1000000;

int n;
int freq[N + 5];
int cnt[N + 5];
int g[N + 5];

int C2(int x) {
    return x * (x - 1) / 2;
}

void solve() {
    cin >> n;

    int mx = 0;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    for(int d = 1; d <= mx; d++) {
        for(int j = d; j <= mx; j += d) {
            cnt[d] += freq[j];
        }
    }

    for(int d = mx; d >= 1; d--) {
        g[d] = C2(cnt[d]);

        for(int j = 2 * d; j <= mx; j += d) {
            g[d] -= g[j];
        }
    }

    cout << g[1];
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