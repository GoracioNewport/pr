//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1791791791;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector <string> p;
vv64 used;
ll n, m;

bool valid(ll i, ll j) {
  return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(ll i, ll j, ll d) {
  used[i][j] = d;
  if (valid(i + 1, j) && (used[i + 1][j] == -1) && p[i + 1][j] == 'X') dfs(i + 1, j, d);
  if (valid(i - 1, j) && (used[i - 1][j] == -1) && p[i - 1][j] == 'X') dfs(i - 1, j, d);
  if (valid(i, j + 1) && (used[i][j + 1] == -1) && p[i][j + 1] == 'X') dfs(i, j + 1, d);
  if (valid(i, j - 1) && (used[i][j - 1] == -1) && p[i][j - 1] == 'X') dfs(i, j - 1, d);
}

int main() {
  fast_cin();
  cin >> n >> m;
  p.resize(n);
  used.resize(n, v64 (m, -1));

  forn(i,n) cin >> p[i];
  ll cnt = 0;
  forn(i,n) {
    forn(j,m) {
      if (p[i][j] == 'X' && (used[i][j] == -1)) dfs(i, j, cnt++);
    }
  }

  vv64 t(cnt, v64 (cnt, INF));
  forn(i,n) {
    forn(j,m) {
      if (used[i][j] == -1) continue;
      deque <p64> q;
      vv64 Used(n, v64 (m, INF));
      q.push_back({i, j});
      Used[i][j] = 0;
      while(!q.empty()) {
        ll x = q.front().fi;
        ll y = q.front().se;
//        cout << x << ' ' << y << ln;
        q.pop_front();
        if (p[x][y] == 'X') t[used[x][y]][used[i][j]] = t[used[i][j]][used[x][y]] = min(min(t[used[x][y]][used[i][j]], t[used[i][j]][used[x][y]]), Used[x][y]);

        vp64 cords = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto &c : cords) {
          ll newX = x + c.fi;
          ll newY = y + c.se;

          if (!valid(newX, newY) || p[newX][newY] == '.' || Used[newX][newY] != INF) continue;
          if (p[newX][newY] == 'S') {
            Used[newX][newY] = Used[x][y] + 1;
            q.push_back({newX, newY});
          } else {
            Used[newX][newY] = Used[x][y];
            q.push_front({newX, newY});
          }

        }

      }
    }
  }

//  for (auto &i : t) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }

  vv64 dp((1 << cnt), v64 (cnt, INF));
  forn(i,cnt) {
    dp[0][i] = 0;
    dp[(1 << i)][i] = 0;
  } for (ll i = 1; i < (1 << cnt); i++) {
    for (ll l = 0; l < cnt; l++) {
      if (!(i & (1 << l))) continue;
      v64 v;
      for (ll j = 0; j < cnt; j++) if (i & (1 << j) && j != l) v.pb(j);
      for (auto &z : v) dp[i][l] = min(dp[i][l], dp[i & ~(1 << l)][z] + t[l][z]);
    }
  }  ll ans = INF;
  for (auto &i : dp.back()) ans = min(ans, i);
  cout << ans << ln;


}