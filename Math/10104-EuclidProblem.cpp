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
    if(a >= 0) return a / b;
    return -((-a + b - 1) / b);
}

int ceil_div(int a, int b) {
    return -floor_div(-a, b);
}

void solve(int a, int b) {
    int x, y;
    int d = ext_euclid(a, b, x, y);

    int stepX = b / d;
    int stepY = a / d;

    vector<int> cand;

    int k1 = floor_div(-x, stepX);
    int k2 = ceil_div(-x, stepX);
    int k3 = floor_div(y, stepY);
    int k4 = ceil_div(y, stepY);

    for(int t = -3; t <= 3; t++) {
        cand.pb(k1 + t);
        cand.pb(k2 + t);
        cand.pb(k3 + t);
        cand.pb(k4 + t);
    }

    int bestX = x, bestY = y;
    int bestVal = abs(x) + abs(y);

    for(int k : cand) {
        int X = x + k * stepX;
        int Y = y - k * stepY;
        int val = abs(X) + abs(Y);

        if(val < bestVal) {
            bestVal = val;
            bestX = X;
            bestY = Y;
        }
        else if(val == bestVal) {
            if(X <= Y && !(bestX <= bestY)) {
                bestX = X;
                bestY = Y;
            }
            else if((X <= Y) == (bestX <= bestY) && X < bestX) {
                bestX = X;
                bestY = Y;
            }
        }
    }

    cout << bestX << " " << bestY << " " << d << '\n';
}

signed main() {
    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b;
    while(cin >> a >> b) {
        solve(a, b);
    }
}