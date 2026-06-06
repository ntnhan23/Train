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

int phi[1000005];
void sieve() {
    for(int i = 1; i <= 1000000; i++) phi[i] = i;
    for(int i = 2; i <= 1000000; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= 1000000; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int sum[1000005];
void prep() {
    for(int i = 1; i <= 1000000; i++) {
        for(int j = 2 * i; j <= 1000000; j += i) {
            sum[j] += i * phi[j / i];
        }
    }
    for(int i = 1; i <= 1000000; i++) sum[i] += sum[i - 1];
}

void solve() {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        cout << sum[n] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    sieve();
    prep();
    solve();
}