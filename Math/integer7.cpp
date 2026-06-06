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

int floor_div(int a, int b) {
    int q = a / b;
    int r = a % b;

    if(r != 0 && ((a < 0) != (b < 0))) q--;

    return q;
}

void solve() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int a = a1;
    int b = -a2;
    int c = b2 - b1;

    int x, y;
    int d = ext_euclid(abs(a), abs(b), x, y);

    if(a < 0) x = -x;
    if(b < 0) y = -y;

    x *= c / d;
    y *= c / d;

    int step_x = b / d;
    int step_y = -a / d;

    int k = oo;

    if(step_x < 0) {
        k = min(k, floor_div(x, -step_x));
    }
    if(step_y < 0) {
        k = min(k, floor_div(y, -step_y));
    }

    x += k * step_x;
    y += k * step_y;

    cout << x << " " << y;
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