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

bool outOfRange(p64 a, ll n) {
  return (a.fi < 1 || a.se < 1 || a.fi > n || a.se > n);
}

int main() {
  fast_cin();

  ll n,x,y;
  cin >> n >> x >> y;
  ll a = 8;
  forsn(i,-1,2) {
    forsn(j,-1,2) {
      if (i == 0 && j == 0) continue;
      if (outOfRange({x + i,y + j}, n)) a--;
    }
  } cout << "King: " << a << ln;
  vp64 moves = {{-1, -2}, {-2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1,2}, {2,1}};
  a = 8;
  for (auto &i : moves) if (outOfRange({x + i.fi, y + i.se}, n)) a--;
  cout << "Knight: " << a << ln;
  ll s = n - 1;
  ll b = min(min(x,y),min((n - x + 1), (n - y + 1)));
//  cout << b << ln;
  a = s + ((b - 1) * 2);
  cout << "Bishop: " <<  a << ln;
  cout << "Rook: " << 2 * n - 2 << ln;
  cout << "Queen: " << a + 2 * n - 2 << ln;



}