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

/*

x + y = n, gcd(x, y) = 1 => gcd(x, n - x) = 1 => gcd(x, n) = 1 => đáp án là phi(n)
f(n) = phi(n)
g(n) = tổng (f(d)) = n


F_k(n) = phi(n) nếu k = 1
       = g(phi(n)) = phi(n) nếu k chẵn
       = f(phi(n)) = phi(phi(n)) nếu k lẻ

=> mình phải lấy phi() (k + 1) / 2 lần

nếu n chẵn thì sau khi lấy phi phải giảm ít nhất 1 nửa => cứ sau khoảng 2 lần thì sẽ giảm 1 nửa => số lần giảm rất nhanh
*/

int phi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            ans -= ans/i;
        }
    }
    if(n > 1) ans -= ans/n;
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int cnt = (k + 1) / 2;
    while(n > 1 && cnt > 0) {
        n = phi(n);
        cnt--;
    }
    cout << n % mod;
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