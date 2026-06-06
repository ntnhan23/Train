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
const int N = 400000;

void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}
void sub(int &x, int y) {
    x -= y;
    if(x < 0) x += mod;
}

// ax + by = d => tìm nghiệm cặp nghiệm (x, y) với d = gcd(a, b)
// hàm này có thể trả về âm nên sạch nhất là làm việc với a, b dương rồi tìm được x, y thì đổi dấu.
int ext_euclid(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ext_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int x, y;
    cout << x << " " << y << " " << ext_euclid(a, b, x, y);


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