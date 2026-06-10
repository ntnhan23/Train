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
const int N = 100000;

int n;
int a[N + 5];
int spf[N + 5];

int max_e[N + 5];
int rem_val[N + 5];
int pow_val[N + 5];

int Pow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void sieve() {
    for(int i = 1; i <= N; i++) spf[i] = i;
    for(int i = 2; i * i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

bool add_condition(int idx, int val) {
    int x = idx;

    while(x > 1) {
        int p = spf[x];
        int pe = 1;
        int e = 0;

        while(x % p == 0) {
            x /= p;
            pe *= p;
            e++;
        }

        int cur = val % pe;

        if(max_e[p] == 0) {
            max_e[p] = e;
            rem_val[p] = cur;
            pow_val[p] = pe;
        }
        else {
            int old_pe = pow_val[p];

            if(e <= max_e[p]) {
                if(rem_val[p] % pe != cur) return false;
            }
            else {
                if(cur % old_pe != rem_val[p]) return false;

                max_e[p] = e;
                rem_val[p] = cur;
                pow_val[p] = pe;
            }
        }
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        if(a[i] != -1) {
            if(!add_condition(i, a[i])) {
                cout << 0;
                return 0;
            }
        }
    }

    int ans = 1;

    for(int p = 2; p <= n; p++) {
        if(spf[p] == p) {
            int pe = p;
            int e_all = 1;

            while(pe * p <= n) {
                pe *= p;
                e_all++;
            }

            int e_fixed = max_e[p];

            ans = ans * Pow(p, e_all - e_fixed) % mod;
        }
    }

    cout << ans;
    return 0;
}