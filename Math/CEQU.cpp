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



void solve() {

    int a, b, c;
    cin >> a >> b >> c;

    if(a == 0 && b == 0) {
        if(c == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    else if(a == 0) {
        if(c % b) cout << "No\n";
        else cout << "Yes\n";
    }
    else if(b == 0) {
        if(c % a) cout << "No\n";
        else cout << "Yes\n";
    }
    else {
        int tmp = __gcd(abs(a), abs(b));
        if(c % tmp) {
            cout << "No\n";
        }
        else cout << "Yes\n";
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
    cin >> t;

    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}