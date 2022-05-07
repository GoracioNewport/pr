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

ll n, m;

bool valid(ll x, ll y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
  fast_cin();

  cin >> n >> m;
  vector <vector <bool>> p(n, vector <bool> (m, false));
  forn(i,n){
    forn(j,m) {
      ll x;
      cin >> x;
      if (x) p[i][j] = true;
    }
  } ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2; x1--; y1--; x2--; y2--;
  swap(x1, y1);
  swap(x2, y2);

  vv64 used(n, v64 (m, -1));
  used[x1][y1] = 0;
  queue <p64> q;
  q.push({x1, y1});

  vp64 moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  while(!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto& i : moves) {
      if (valid(x + i.fi, y + i.se) && !p[x + i.fi][y + i.se] && used[x + i.fi][y + i.se] == -1) {
        used[x + i.fi][y + i.se] = used[x][y] + 1;
        q.push({x + i.fi, y + i.se});
      }
    }

  } if (p[x1][y1] == 1 && (p64){x1, y1} != (p64){x2, y2}) used[x2][y2] = -1;
  cout << used[x2][y2] << ln;

}