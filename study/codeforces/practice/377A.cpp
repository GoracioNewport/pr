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

vv64 used;
ll cnt = 0;

ll n, m;
vector <vector <char>> p;

vp64 mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid (ll i, ll j) {
  return (i >= 0 && i < n && j >= 0 && j < m && p[i][j] == '.');
}

void dfs(ll i, ll j) {

  if (cnt == 0) return;
  used[i][j] = 1;
  cnt--;

  for (auto &u : mov) {
    if (valid(i + u.fi, j + u.se) && !used[i + u.fi][j + u.se]) dfs(i + u.fi, j + u.se);
  }

}

int main() {
  fast_cin();
  ll k;
  cin >> n >> m >> k;
  p.resize(n, vector <char> (m));
  p64 start = {0,0};
  ll ind = 0;
  ll C = 0;
  for (auto &i : p) {
    string s;
    cin >> s;
    forn(j,m) {
      i[j] = s[j];
      if (s[j] == '.') {
        C++;
        if (start.fi == 0) {
          start.fi = ind;
          start.se = j;
        }
      }
    } ind++;
  } cnt = C - k;

  used.resize(n, v64 (m, 0));
  dfs(start.fi, start.se);

  forn(i,n) {
    forn(j,m) {
      if (used[i][j]) cout << '.';
      else {
        if (p[i][j] == '#') cout << '#';
        else cout << 'X';
      }
    } cout << ln;
  }

}