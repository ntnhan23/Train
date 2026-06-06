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
// ax + by = c
// luôn có một nghiệm là x0 * (c/d), y0 * (c/d)
// họ nghiệm thì nếu x tăng 1 thì tổng tăng a, v tăng như nào mà ít nhất bên kia triệu tiêu đươc
// tăng đến LCM => tăng b/d lần, còn y thì giảm a/d lần (một bước)
// nhiều bước thì nhân thêm k
// x = x0 + k * (b/d)
// y = y0 - k * (a/d)

//Tìm 1 nghiệm nguyên của phương trình ax + by + c = 0
ii diophantineSolve(int a, int b, int c)
{
    int x = 0, y = 0;
    int d = ext_euclid(a, b, x, y);
    if (c % d != 0) return {}; // ko có nghiệm
    x *= c / d;
    y *= c / d;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return make_pair(x, y);
}

void solve() {



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