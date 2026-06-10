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

int Pow(int a, int b, int mod) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, p, x;
    cin >> a >> b >> p >> x;

    int M = p * (p - 1);
    int invA = Pow(a, p - 2, p);

    int invPow = 1;
    int ans = 0;

    for(int j = 0; j <= p - 2; j++) {
        int i = b * invPow % p;

        int t = (j - i) % (p - 1);
        if(t < 0) t += p - 1;

        int r = i + p * t;

        if(r <= x) {
            ans += (x - r) / M + 1;
        }

        invPow = invPow * invA % p;
    }

    cout << ans;
    return 0;
}