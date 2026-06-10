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

const int N = 1000005;

int n, m, k;
int posA[N], posB[N];
vector<int> same;

int ext_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = ext_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return d;
}

int inv_mod(int a, int mod) {
    int x, y;
    ext_gcd(a, mod, x, y);
    x %= mod;
    if(x < 0) x += mod;
    return x;
}

int get_same_day(int x, int y) {
    int g = __gcd(n, m);
    if((y - x) % g != 0) return -1;

    int n1 = n / g;
    int m1 = m / g;
    int lcm = n / g * m;

    int delta = (y - x) / g;
    delta %= m1;
    if(delta < 0) delta += m1;

    int inv = inv_mod(n1, m1);
    int t = delta * inv % m1;

    int res = x + n * t;
    res %= lcm;
    if(res == 0) res = lcm;

    return res;
}

int count_same(int T) {
    int g = __gcd(n, m);
    int L = n / g * m;

    int full = T / L;
    int rem = T % L;

    int ans = full * (int)same.size();
    ans += upper_bound(all(same), rem) - same.begin();

    return ans;
}

int count_diff(int T) {
    return T - count_same(T);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    int mx = 2 * max(n, m);

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        posA[x] = i;
    }

    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        posB[x] = i;
    }

    for(int c = 1; c <= mx; c++) {
        if(posA[c] && posB[c]) {
            int day = get_same_day(posA[c], posB[c]);
            if(day != -1) same.pb(day);
        }
    }

    sort(all(same));

    int l = 1, r = oo, ans = oo;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(count_diff(mid) >= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}