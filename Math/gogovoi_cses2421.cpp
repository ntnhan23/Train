// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")

#include <bits/stdc++.h>
using namespace std;

//#define double ldb
#define int ll
#define endl '\n'
#define unoset unordered_set
#define unomap unordered_map
#define strstr stringstream
#define SZ(a) (int)a.size()
#define Unique(a) a.resize(unique(all(a)) - a.begin())
#define fi first
#define se second
#define idc cin.ignore()
#define lb lower_bound
#define ub upper_bound
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define rev reverse
#define gcd __gcd
#define pushb push_back
#define popb pop_back
#define pushf push_front
#define popf pop_front
#define emp emplace
#define empb emplace_back
#define empf emplace_front
#define mul2x(a, x) a << x
#define div2x(a, x) a >> x
#define lcm(a, b) (a / __gcd(a, b) * b)
#define log_base(x, base) log(x) / log(base)
#define debug cerr<<"No errors!",exit(0);
#define forw(i, a, b)  for (int i = a; i <= b; ++i)
#define forw2(i, a, b) for (ll i = a; i <= b; ++i)
#define fors(i, a, b)  for (int i = a; i >= b; --i)
#define fors2(i, a, b) for (ll i = a; i >= b; --i)
#define pqueue priority_queue
#define sqrt sqrtl
#define i128 __int128
#define popcount __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(x) ((1LL) << (x))
#define want_digit(x) cout << fixed << setprecision(x);
#define excuting_time 1000.0 * clock() / CLOCKS_PER_SEC
#define mapa make_pair
#define ms(a, x) memset(a, x, sizeof(a))

typedef long long ll;
typedef long double ldb;
typedef double db;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;

const int MOD = 1e9 + 7; // 998244353
const int inf = 1e9;
const ll INF = 1e18; // MASK(63) - 1
const int limN = 5e3 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random(const ll &L, const ll &R) {
    return uniform_int_distribution<ll> (L, R) (rng);
}

/* -------~~~~~~===== END OF TEMPLATE =====~~~~~~------- */

int bpow(int n, int e) {
    int r = 1;
    n %= MOD;
    while (e) {
        if (e & 1) r = r * n % MOD;
        n = n * n % MOD;
        e >>= 1;
    }
    return r;
}

int fact[limN], invf[limN];
void build(int lim = 5e3) {
    fact[0] = 1;
    forw (i, 1, lim) fact[i] = fact[i - 1] * i % MOD;
    invf[lim] = bpow(fact[lim], MOD - 2);
    fors (i, lim, 1) invf[i - 1] = invf[i] * i % MOD;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

int n, cnt[30];
str s;
void solve() {
    build();
    cin >> s;
    n = SZ(s);
    for (char c : s) ++cnt[c - 'a'];

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int cur = 0;
    forw (i, 0, 25) {
        int c = cnt[i];
        if (c == 0) continue;

        vector<int> _dp(n + 1, 0);

        forw (j, 0, cur) {
            if (!dp[j]) continue;

            forw (k, 1, c) {
                int val = (C(c - 1, k - 1) * invf[k]) % MOD;

                if ((c - k) & 1) val = (MOD - val) % MOD;

                add(_dp[j + k], dp[j] * val % MOD);
            }
        }
        dp = move(_dp);
        cur += c;
    }

    int ans = 0;
    forw (i, 1, n) add(ans, dp[i] * fact[i] % MOD);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    #define name "test"
    if (fopen(name".INP", "r")) {
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }
    bool testCase = false;
    int numTest = 1;
    // cin >> numTest;
    forw (i, 1, numTest) {
        if (testCase) cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
