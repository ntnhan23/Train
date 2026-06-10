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
const int N = 2000005;

int fact[N], invFact[N];

int Pow(int a, int b) {
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
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s;
    cin >> k >> s;

    int n = s.size();
    int lim = n + k + 5;

    fact[0] = 1;
    for(int i = 1; i <= lim; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    invFact[lim] = Pow(fact[lim], mod - 2);
    for(int i = lim - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }

    int ans = 0;

    for(int i = 0; i <= k; i++) {
        int ways = C(n - 1 + i, n - 1);
        ways = ways * Pow(25, i) % mod;
        ways = ways * Pow(26, k - i) % mod;
        ans = (ans + ways) % mod;
    }

    cout << ans;

    return 0;
}