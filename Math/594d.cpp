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
const int mod = 1e9 + 7;
const int N = 200005;
const int LIM = 1000000;

int Pow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int n, q;
int a[N];
int prod[N];
int ans[N];

int spf[LIM + 5];
int last[LIM + 5];

struct nhan {
    int l, r, id;
    nhan(int _l = 0, int _r = 0, int _id = 0): l(_l), r(_r), id(_id) {}
    bool operator < (const nhan &other) const {
        return r < other.r;
    }
};

vector<nhan> val;

int bit[N];

void update(int pos, int val) {
    for(int i = pos; i >= 1; i -= i & -i) {
        bit[i] = bit[i] * val % mod;
    }
}

int get(int pos) {
    int ans = 1;
    for(int i = pos; i <= n; i += i & -i) {
        ans = ans * bit[i] % mod;
    }
    return ans;
}

void sieve() {
    for(int i = 1; i <= LIM; i++) spf[i] = i;

    for(int i = 2; i * i <= LIM; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= LIM; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> getPrime(int x) {
    vector<int> res;

    while(x > 1) {
        int p = spf[x];
        res.pb(p);
        while(x % p == 0) x /= p;
    }

    return res;
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) bit[i] = 1;

    prod[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prod[i] = prod[i - 1] * a[i] % mod;
    }

    cin >> q;
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        val.pb(nhan(l, r, i));
    }

    sort(all(val));

    int pos = 0;

    for(auto [l, r, id] : val) {
        while(pos + 1 <= r) {
            pos++;

            vector<int> cur = getPrime(a[pos]);

            for(int p : cur) {
                int coef = (p - 1) * Pow(p, mod - 2) % mod;

                if(last[p] != 0) {
                    update(last[p], Pow(coef, mod - 2));
                }

                update(pos, coef);
                last[p] = pos;
            }
        }

        int Product = prod[r] * Pow(prod[l - 1], mod - 2) % mod;
        int Coef = get(l);

        ans[id] = Product * Coef % mod;
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    sieve();

    int t = 1;
    while(t--) {
        solve();
    }
}