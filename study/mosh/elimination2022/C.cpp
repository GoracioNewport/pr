 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
 #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

// Author: @GoracioNewport

using namespace std;
using namespace __gnu_pbds;



typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}

istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}

istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}

ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}

ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}

ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}

ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}

ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;

ll n;

v64 powers;

typedef tree<
    p64,
    null_type,
    less<p64>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

vv64 getT(p64 a) {
  vv64 ans(n, v64(n));

  ll f = ((n / 2) * n);
  for (ll i = 0; i < (n / 2); i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a.fi >= powers[f]) {
        ans[i][j] = 1;
        a.fi -= powers[f];
      }
    }
  } f = n * n - ((n / 2) * n);

  for (ll i = (n / 2); i < n; i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a.se >= powers[f]) {
        ans[i][j] = 1;
        a.se -= powers[f];
      }
    }
  } return ans;

}

p64 getP(vv64 a) {

  p64 ans = {0, 0};

  ll f = ((n / 2) * n);
  for (ll i = 0; i < (n / 2); i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a[i][j]) ans.fi += powers[f];
    }
  } f = n * n - ((n / 2) * n);

  for (ll i = (n / 2); i < n; i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a[i][j]) ans.se += powers[f];
    }
  } return ans;
};

p64 getBitByCords(ll i, ll j) {
  if (i < (n / 2)) {
    i = (n / 2) - i - 1;
    j = n - j - 1;
    return {1, i * n + j};
  } else {
    i = n - i - 1;
    j = n - j - 1;
    return {2, i * n + j};
  }
}

p64 toggleCross(p64 a, ll x, ll y) {
  forn(i,n) { // vertical
    auto z = getBitByCords(i, y);
    if (z.fi == 1) a.fi ^= powers[z.se];
    else a.se ^= powers[z.se];
  }

  forn(j,n) { // horizontal
    auto z = getBitByCords(x, j);
    if (z.fi == 1) a.fi ^= powers[z.se];
    else a.se ^= powers[z.se];
  }

  auto z = getBitByCords(x, y);
  if (z.fi == 1) a.fi ^= powers[z.se];
  else a.se ^= powers[z.se];

  return a;
}

struct pairHash {
  size_t operator() (const p64& x) const {
    return hash <ll> () (((x.fi * 31) ^ (x.se << 32)));
  }
};

struct block {
  p64 cur;
  int depth;

  block(p64 a): cur(a), depth(0) {};
  block(p64 a, int d): cur(a), depth(d) {};
};

int main() {
  fastCin();


//  freopen("/mnt/hdd/pr/study/mosh/elimination2022/cFinal.txt", "r", stdin);
//  freopen("/mnt/hdd/pr/study/mosh/elimination/a0ans.txt", "w", stdout);

  powers.resize(60);
  powers[0] = 1;
  forsn(i,1,60) powers[i] = powers[i - 1] * 2;

  ll step1 = 1, beginInd1 = 0, step2 = 1, beginInd2 = 0;
  cin >> step1 >> beginInd1 >> step2 >> beginInd2;

  ll t;
  cin >> t;


  forn(Z,t) {
    cout << "TEST CASE №" << Z + 1 << endl;
    ll timeStart = chrono::high_resolution_clock::now().time_since_epoch().count();
    cin >> n;
    vv64 start(n, v64(n, 0));
//    cin >> start;
    vv64 x(n, v64(n));
    cin >> x;


    queue <block> q1, q2; // <cur, <prev, <ij, depth>>>
    unordered_set <p64, pairHash> visited1, visited2;

    q1.push(block(getP(start)));
    q2.push(block(getP(x)));

    ll maxS1 = 1, maxS2 = 1;

    visited1.insert(getP(start));
    visited2.insert(getP(x));

    const int MAX_DEPTH = 5;

    bool ansFound = false;

//    gp_hash_table <p64, vector <pair <p64, p64>>, pairHash> g; // key: tableHashed, value: <tableHashed, move>

    while(true) {

      if (!q1.empty()) { // Q1
        if (q1.front().depth >= MAX_DEPTH) {
          cout << "Answer not found :(" << endl;
          break;
        }

        int prevDepth = q1.front().depth;
        p64 curP = q1.front().cur;
        q1.pop();

        ll iB = 0;
        ll iS = 1;

        if (prevDepth == MAX_DEPTH - 1) {
          iB = beginInd1;
          iS = step1;
        }

        for (ll i = iB; i < n; i += iS) {
          for (ll j = 0; j < n; j++) {

            p64 res = toggleCross(curP, i, j);

            if (visited1.find(res) == visited1.end()) {
//              g[curP].pb({res, {i, j}});
//              g[res].pb({curP, {i, j}});

              q1.push({res, prevDepth + 1});
              visited1.insert(res);
            } maxS1 = max(maxS1, sz(q1));

            if (visited2.find(res) != visited2.end()) {
              cout << "ANSWER FOUND, DEPTH: " << prevDepth << endl;
              ansFound = true;

              vv64 ANS = getT(res);
              cout << ANS << ln;

              break;
            }

          } if (ansFound) break;
        }

      } if (ansFound) break;

      if (!q2.empty()) { // Q2
        if (q2.front().depth >= MAX_DEPTH) {
          cout << "Answer not found :(" << endl;
          break;
        }

        int prevDepth = q2.front().depth;
        p64 curP = q2.front().cur;
        q2.pop();

        ll iB = 0;
        ll iS = 1;

        if (prevDepth == MAX_DEPTH - 1) {
          iB = beginInd2;
          iS = step2;
        }

        for (ll i = iB; i < n; i += iS) {
          for (ll j = 0; j < n; j++) {

            p64 res = toggleCross(curP, i, j);

            if (visited2.find(res) == visited2.end()) {
//              g[curP].pb({res, {i, j}});
//              g[res].pb({curP, {i, j}});

              q2.push({res, prevDepth + 1});
              visited2.insert(res);
            } maxS2 = max(maxS2, sz(q2));

            if (visited1.find(res) != visited1.end()) {
              cout << "ANSWER FOUND, DEPTH: " << prevDepth << endl;

              vv64 ANS = getT(res);
              cout << ANS << ln;

              ansFound = true;
              break;
            }

          } if (ansFound) break;
        }

      } if (ansFound) break;

    }

//    if (ansFound) {
//
//      gp_hash_table <p64, ll, pairHash> dist;
//      gp_hash_table <p64, pair <p64, p64>, pairHash> parent;
//      parent[getP(start)] = {{-1, -1}, {-1, -1}};
//      dist[getP(start)] = 1;
//
//      queue <p64> q;
//      q.push(getP(start));
//
//      while(!q.empty()) {
//        auto y = q.front();
//        q.pop();
//
//        for (auto& [u, z] : g[y]) {
//          if (dist[u] == 0) {
//            dist[u] = dist[y] + 1;
//            parent[u] = {y, z};
//            q.push(u);
//          }
//        }
//      } auto X = getP(x);
//
//      vp64 ans;
//      while(parent[X].fi.fi != -1) {
//        ans.pb(parent[X].se);
//        X = parent[X].fi;
//      } reverse(all(ans));
//      cout << sz(ans) << ln << ans << endl;
//
//    } else {
//      cout << 1 << ln << "0 0" << endl;
//    }

    ll timeFinish = chrono::high_resolution_clock::now().time_since_epoch().count();
    cout << "Time: " << fixed << setprecision(5) << (ld)(timeFinish - timeStart) / 1e9 << 's' << ln;


  }

}