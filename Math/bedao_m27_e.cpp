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

const int N = 200000;

int n;
int a[200005];
vector<int> e[200005];

vector<int> uoc[200005];
vector<int> dinh[200005];

int cnt[200005];
int g[200005];
int vi[200005];

void prep() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            uoc[j].pb(i);
        }
    }
}

void solve() {
    cin >> n;

    int mx = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);

        for(auto d : uoc[a[i]]) {
            dinh[d].pb(i);
        }
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    for(int d = 1; d <= mx; d++) {
        for(auto st : dinh[d]) {
            if(vi[st] == d) continue;

            int sz = 0;

            queue<int> q;
            q.push(st);
            vi[st] = d;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                sz++;

                for(auto v : e[u]) {
                    if(vi[v] != d && a[v] % d == 0) {
                        vi[v] = d;
                        q.push(v);
                    }
                }
            }

            cnt[d] += sz * (sz + 1) / 2;
        }
    }

    for(int d = mx; d >= 1; d--) {
        g[d] = cnt[d];

        for(int j = 2 * d; j <= mx; j += d) {
            g[d] -= g[j];
        }
    }

    cout << g[1];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    prep();
    solve();
}