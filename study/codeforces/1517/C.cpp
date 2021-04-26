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

vv64 p;
bool pos = true;
ll n;

void dfs(ll x, ll y, ll c, ll l) {
  p[x][y] = c;
  if (l == 1) return;
  if (y != 0 && p[x][y - 1] == 0) dfs(x, y - 1, c, l - 1);// left
  else if (x != n - 1 && p[x + 1][y] == 0) dfs(x + 1, y, c, l - 1); // down
  else if (y != n - 1 && p[x][y + 1] == 0) dfs(x, y + 1, c, l - 1); // right
  else pos = false;
}

int main() {
  fast_cin();


  cin >> n;
  pos = true;
  p.clear();
  p.resize(n, v64(n, 0));
  forn(i,n) forn(j,n) if (j > i) p[i][j] = -1;
  forn(i,n) {
    ll x;
    cin >> x;
    p[i][i] = x;
  }


  forn(i,n) dfs(i,i,p[i][i], p[i][i]);
  if (!pos) cout << -1 << ln;
  else {
    forn(i,n) {
      forn(j,i + 1) cout << p[i][j] << ' ';
      cout << ln;
    }
  }

}