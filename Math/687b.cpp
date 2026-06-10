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

int lcm_safe(int a, int b) {
    return a / __gcd(a, b) * b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int cur = 1;

    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;

        int d = __gcd(c, k);
        cur = lcm_safe(cur, d);
    }

    if(cur == k) cout << "Yes";
    else cout << "No";

    return 0;
}