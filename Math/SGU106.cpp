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

int floor_div(int a, int b) {
    int q = a / b;
    int r = a % b;

    if(r != 0 && ((a < 0) != (b < 0))) q--;

    return q;
}

int ceil_div(int a, int b) {
    return -floor_div(-a, b);
}

pair<int, int> get_range(int l, int r, int x, int step) {
    if(step > 0) {
        return {ceil_div(l - x, step), floor_div(r - x, step)};
    }
    else {
        return {ceil_div(r - x, step), floor_div(l - x, step)};
    }
}

void solve() {
    int a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

    c = -c;

    if(a == 0 && b == 0) {
        if(c == 0) {
            cout << (x2 - x1 + 1) * (y2 - y1 + 1);
        }
        else cout << 0;
    }
    else if(a == 0) {
        if(c % b) cout << 0;
        else {
            int y = c / b;

            if(y >= y1 && y <= y2) {
                cout << x2 - x1 + 1;
            }
            else cout << 0;
        }
    }
    else if(b == 0) {
        if(c % a) cout << 0;
        else {
            int x = c / a;

            if(x >= x1 && x <= x2) {
                cout << y2 - y1 + 1;
            }
            else cout << 0;
        }
    }
    else {
        int x, y;
        int d = ext_euclid(abs(a), abs(b), x, y);

        if(c % d) {
            cout << 0;
            return;
        }

        if(a < 0) x = -x;
        if(b < 0) y = -y;

        x *= c / d;
        y *= c / d;

        int step_x = b / d;
        int step_y = -a / d;

        pair<int, int> rx = get_range(x1, x2, x, step_x);
        pair<int, int> ry = get_range(y1, y2, y, step_y);

        int l = max(rx.fi, ry.fi);
        int r = min(rx.se, ry.se);

        if(l > r) cout << 0;
        else cout << r - l + 1;
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

    while(t--) {
        solve();
    }
}