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

bool ans = false;
vector <vector <string>> p;
vv64 used;
ll m, n;
vector <string> line;

void f(ll dir, ll pos, ll x, v64 &path) {
  if (pos == m) {
    ans = true;
    return;
  } for (ll i = 0; i < n; i++) {
    if ((dir && (!used[i][x] && p[i][x] == line[pos])) || (!dir && (!used[x][i] && p[x][i] == line[pos]))) {
      path.pb(i);
      if (dir) used[i][x] = !used[i][x];
      else used[x][i] = !used[x][i];
      f(!dir, pos + 1, i, path);
      if (ans) return;
      if (dir) used[i][x] = !used[i][x];
      else used[x][i] = !used[x][i];
      path.pop_back();
    }
  }
}

int main() {
//  fast_cin();

  ifstream in;
  ofstream out;
  in.open("C:/Users/bdfyl/CLionProjects/cf/mosh/otbor/b2.txt");
  out.open("C:/Users/bdfyl/CLionProjects/cf/mosh/otbor/b2ans.txt");
  ll t;
  in >> t;
  ll test = 1;
  while(t--) {
    p.clear();
    used.clear();
    line.clear();
    ans = false;
    in >> m;
    line.resize(m);
    for (auto &i : line) in >> i;
    in >> n;
    p.resize(n, vector <string> (n));
    for (auto &i : p) for (auto &j : i) in >> j;
    used.resize(n, v64 (n, 0));
    v64 ans;
    f(0, 0, 0, ans);
    for (auto &i : ans) out << i + 1 << ' ';
    out << ln;
    cout << "Done Test #" << test++ << ln;
    if (test > 10) break;
  } in.close();
  out.close();

}