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

int ceil_div(int a, int b) {
    return -floor_div(-a, b);
}

int count_two(int a, int b, int n) {
    int x, y;
    int d = ext_euclid(a, b, x, y);

    if(n % d != 0) return 0;

    x *= n / d;
    y *= n / d;

    int step_x = b / d;
    int step_y = a / d;

    int l = ceil_div(-x, step_x);
    int r = floor_div(y, step_y);

    if(l > r) return 0;
    return r - l + 1;
}

void solve(int tc) {
    int a, b, c, p;
    cin >> a >> b >> c >> p;

    int g = __gcd(a, __gcd(b, c));

    if(p % g != 0) {
        cout << "Case " << tc << ": " << 0 << '\n';
        return;
    }

    a /= g;
    b /= g;
    c /= g;
    p /= g;

    int ans = 0;

    for(int z = 0; z * c <= p; z++) {
        int rem = p - z * c;
        ans += count_two(a, b, rem);
    }

    cout << "Case " << tc << ": " << ans << '\n';
}

signed main() {
    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        solve(i);
    }
}