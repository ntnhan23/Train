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

/*
phi(a) + phi(2a) + ... + phi(ba)

phi(a*i) = phi(a) * phi(i) * d / phi(d) 
*/

const int mod = 998244353;

void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

int a, b;
int phi[5000005];

void sieve() {
    for(int i = 1; i <= 5000000; i++) phi[i] = i;
    for(int i = 2; i <= 5000000; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= 5000000; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

void solve() {
    sieve();
    cin >> a >> b;
    int res = 0;
    for(int i = 1; i <= b; i++) {
        int d = __gcd(a, i);
        int tmp = phi[a] * phi[i] / phi[d] * d % mod;
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

    solve();
}