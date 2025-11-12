#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll a, b;
    cin >> n >> a >> b;
    if (a == b) {
        unordered_map<ll, ll> mp;
        mp.reserve(n);
        for (int i = 0; i < n; i++) {
            ll c, d;
            cin >> c >> d;
            mp[d] += c;
        }
        ll ans = 0;
        vector<ll> ids;
        ids.reserve(mp.size());
        for (auto &x : mp) ids.push_back(x.first);
        sort(ids.begin(), ids.end());
        for (ll d : ids) {
            if (2 * d == a) ans += mp[d] / 2;
            else if (2 * d < a) {
                ll o = a - d;
                if (mp.count(o)) ans += min(mp[d], mp[o]);
            }
        }
        cout << ans << "\n";
        return 0;
    }
    vector<pair<ll, ll>> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        ll c, d;
        cin >> c >> d;
        arr.push_back({d, c});
    }
    sort(arr.begin(), arr.end());
    vector<ll> id(n), f(n);
    for (int i = 0; i < n; i++) {
        id[i] = arr[i].first;
        f[i] = arr[i].second;
    }
    unordered_map<ll, int> idx;
    idx.reserve(n);
    for (int i = 0; i < n; i++) idx[id[i]] = i;
    vector<vector<int>> adj(n);
    vector<bool> loop(n, false);
    for (int i = 0; i < n; i++) {
        ll t = a - id[i];
        if (t >= 0) {
            if (t == id[i]) loop[i] = true;
            else if (idx.count(t)) {
                int j = idx[t];
                if (j > i) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ll t = b - id[i];
        if (t >= 0) {
            if (t == id[i]) loop[i] = true;
            else if (idx.count(t)) {
                int j = idx[t];
                if (j > i) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    ll ans = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        queue<int> q;
        q.push(i);
        used[i] = true;
        vector<int> comp;
        comp.push_back(i);
        ll ed = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ed += adj[u].size();
            for (auto &w : adj[u]) {
                if (!used[w]) {
                    used[w] = true;
                    q.push(w);
                    comp.push_back(w);
                }
            }
        }
        ed /= 2;
        int sz = comp.size();
        if (sz == 1) {
            if (loop[comp[0]]) ans += f[comp[0]] / 2;
        } else if (ed == sz) {
            int start = comp[0], p = -1, c = start;
            vector<ll> cyc;
            cyc.push_back(f[c]);
            while (true) {
                int nx = -1;
                for (int w : adj[c]) {
                    if (w != p) {
                        nx = w;
                        break;
                    }
                }
                if (nx < 0) break;
                cyc.push_back(f[nx]);
                p = c;
                c = nx;
            }
            auto check = [&](ll x0) {
                ll s = x0, prev = x0;
                for (int k = 1; k < cyc.size(); k++) {
                    ll av = cyc[k] - prev;
                    if (av < 0) av = 0;
                    ll nxt = (k + 1 < cyc.size() ? cyc[k + 1] : cyc[0]);
                    ll take = min(nxt, av);
                    s += take;
                    prev = take;
                }
                bool ok = (prev + x0 <= cyc[0]);
                return make_pair(ok, s);
            };
            ll hi = min(cyc[0], cyc[1]);
            ll lo = 0, best = 0, bestS = 0;
            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                auto pr = check(mid);
                if (pr.first) {
                    best = mid;
                    bestS = pr.second;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ll res = bestS;
            for (ll t = max(0LL, best - 2); t <= best + 2 && t <= hi; t++) {
                if (t < 0) continue;
                auto p = check(t);
                if (p.first) res = max(res, p.second);
            }
            ans += res;
        } else {
            int st = -1;
            for (auto &u : comp) {
                if (adj[u].size() < 2) {
                    st = u;
                    break;
                }
            }
            vector<ll> cA;
            cA.push_back(f[st]);
            int p = -1, cur = st;
            while (true) {
                int nx = -1;
                for (int w : adj[cur]) {
                    if (w != p) {
                        nx = w;
                        break;
                    }
                }
                if (nx < 0) break;
                cA.push_back(f[nx]);
                p = cur;
                cur = nx;
            }
            ll tot = 0, x = min(cA[0], cA[1]);
            tot += x;
            for (int k = 1; k < cA.size() - 1; k++) {
                ll av = cA[k] - x;
                if (av < 0) av = 0;
                ll nx = min(cA[k + 1], av);
                tot += nx;
                x = nx;
            }
            ans += tot;
        }
    }
    cout << ans << "\n";
}