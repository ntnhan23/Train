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

const int mod = 1000000007;

// số lớn nhất không thể tạo được là ab - a - b
// số bé nhất mà từ đó đều tạo được hết là ab - a - b + 1 = (a - 1) * (b - 1)
// số của mình có dạng ax + by (x, y >= 0)

// gcd(a, b) = 1 => xét trên modulo a, bắt đầu từ 0, mỗi lần nhảy + b thì phải sau a lần mới 
// quay lại vị trí ban đầu được (do nó ko có phần chung) => từ 0, 1b, 2b....(a - 1)b mình có thể
// tạo ra mọi số dư trên modulo a.

// xét một số n bất kỳ thì mình luôn chọn được y (0 <= y < a) thoả:
// yb đồng dư n (mod a)
// (n - yb) chia hết cho a lúc đó chọn x = (n - yb) / a là được.

// quan trọng là n - yb phải đủ lớn để n - yb >= 0 mà 0 <= y < a
// n >= yb
// max(yb) là (a - 1)*b => mình có thể chọn n = (a - 1) * b - a thì chắc chắn ko tạo đc
// do nó phải dùng (a - 1) * b mà (a - 1) * b lại lớn hơn (a - b) * b - a
// vậy số lớn nhất ko thể tạo thành là ab - a - b
void solve() {
    int a, b;
    cin >> a >> b;
    int tmp = __gcd(a, b);
    if(tmp != 1) cout << -1 << "\n";
    else {
        cout << (a - 1) * (b - 1) << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    int t; cin >> t;
    while(t--) {
        solve();
    }
}