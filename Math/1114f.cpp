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

int n, q;
int a[400005];

vector<int> prime;
int invPrime[305];
unsigned long long maskVal[305];

int pw(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init() {
    for(int i = 2; i <= 300; i++) {
        bool ok = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) ok = false;
        }
        if(ok) prime.pb(i);
    }

    for(int i = 0; i < prime.size(); i++) {
        int p = prime[i];
        invPrime[p] = pw(p, mod - 2);
    }

    for(int x = 1; x <= 300; x++) {
        for(int i = 0; i < prime.size(); i++) {
            if(x % prime[i] == 0) {
                maskVal[x] |= (1ULL << i);
            }
        }
    }
}

struct Node {
    int prod;
    unsigned long long mask;
};

struct SegTree {
    int n;
    vector<Node> st;
    vector<int> lazyMul;
    vector<unsigned long long> lazyMask;

    SegTree(int _n) {
        n = _n;
        st.assign(4 * n + 5, {1, 0});
        lazyMul.assign(4 * n + 5, 1);
        lazyMask.assign(4 * n + 5, 0);
    }

    Node mergeNode(Node A, Node B) {
        return {A.prod * B.prod % mod, A.mask | B.mask};
    }

    void build(int id, int l, int r, int a[]) {
        if(l == r) {
            st[id] = {a[l] % mod, maskVal[a[l]]};
            return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid, a);
        build(id * 2 + 1, mid + 1, r, a);

        st[id] = mergeNode(st[id * 2], st[id * 2 + 1]);
    }

    void apply(int id, int l, int r, int mulVal, unsigned long long addMask) {
        st[id].prod = st[id].prod * pw(mulVal, r - l + 1) % mod;
        st[id].mask |= addMask;

        lazyMul[id] = lazyMul[id] * mulVal % mod;
        lazyMask[id] |= addMask;
    }

    void down(int id, int l, int r) {
        if(lazyMul[id] == 1 && lazyMask[id] == 0) return;

        int mid = (l + r) / 2;

        apply(id * 2, l, mid, lazyMul[id], lazyMask[id]);
        apply(id * 2 + 1, mid + 1, r, lazyMul[id], lazyMask[id]);

        lazyMul[id] = 1;
        lazyMask[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if(l > v || r < u || u > v) return;

        if(l >= u && r <= v) {
            apply(id, l, r, val, maskVal[val]);
            return;
        }

        down(id, l, r);

        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);

        st[id] = mergeNode(st[id * 2], st[id * 2 + 1]);
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    Node get(int id, int l, int r, int u, int v) {
        if(l > v || r < u || u > v) return {1, 0};

        if(l >= u && r <= v) return st[id];

        down(id, l, r);

        int mid = (l + r) / 2;
        Node lef = get(id * 2, l, mid, u, v);
        Node rig = get(id * 2 + 1, mid + 1, r, u, v);

        return mergeNode(lef, rig);
    }

    Node get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

void solve() {
    cin >> n >> q;

    init();

    for(int i = 1; i <= n; i++) cin >> a[i];

    SegTree ST(n);
    ST.build(1, 1, n, a);

    while(q--) {
        string type;
        int l, r;
        cin >> type >> l >> r;

        if(type == "MULTIPLY") {
            int x;
            cin >> x;
            ST.update(l, r, x);
        }
        else {
            Node cur = ST.get(l, r);

            int ans = cur.prod;

            for(int i = 0; i < prime.size(); i++) {
                if((cur.mask >> i) & 1ULL) {
                    int p = prime[i];
                    ans = ans * (p - 1) % mod * invPrime[p] % mod;
                }
            }

            cout << ans << '\n';
        }
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