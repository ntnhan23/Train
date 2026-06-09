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

const int N = 1000000;

int n, k;
vector<int> a;

bool isPrime[N + 5];
int pref[N + 5];

void prep() {
    for(int i = 0; i <= N; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;

    for(int i = 2; i * i <= N; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + isPrime[i];
    }
}

void solve(int tc) {
    cin >> n >> k;

    a.clear();

    int givenPrime = 0;

    for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        a.pb(x);
        if(x <= n) givenPrime++;
    }

    int res = 0;

    for(int mask = 0; mask < (1 << k); mask++) {
        int tmp = 1;
        bool ok = 1;

        for(int i = 0; i < k; i++) {
            if(mask >> i & 1) {
                if(tmp <= n / a[i]) tmp *= a[i];
                else {
                    ok = 0;
                    break;
                }
            }
        }

        if(!ok) continue;

        int cnt = n / tmp;

        if(__builtin_popcount(mask) & 1) res -= cnt;
        else res += cnt;
    }

    int primeNotGiven = pref[n] - givenPrime;

    res = res - 1 - primeNotGiven;

    cout << "Case " << tc << ": " << res << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    prep();

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        solve(i);
    }
}