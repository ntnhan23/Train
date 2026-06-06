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

int ext_euclid(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ext_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

void solve() {

    int a, b, c;
    cin >> a >> b >> c;
    int tmp = __gcd(a, b);
    if(c % tmp) {
        cout << "No";
    }
    else {
        int x, y;
        int d = ext_euclid(a, b, x, y);
        x *= (c / d);
        y *= (c / d);

        // x = x + k * ()
        int step_x = b / d;
        int step_y = a / d;
        for(int k = -10000; k <= 10000; k++) {
            int _x = x + k * step_x;
            int _y = y - k * step_y;
            if(_x >= 0 && _y >= 0) {
                cout << "Yes";
                return;
            }
        }
        cout << "No";
    }


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

    for(int i = 1; i <= t; i++) {
        solve();
    }
}