#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

ll lcd(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  fast_cin();
  
  ll n, x, y;
  cin >> n >> x >> y;

  ll oneBlockTime = lcd(x, y);
  ll oneBlockAmount = (oneBlockTime / x) + (oneBlockTime / y);
  ll minBlock = (n - 1) / oneBlockAmount;
  ll preAmount = 1 + minBlock * oneBlockAmount;
  ll preTime = min(x, y) + minBlock * oneBlockTime;
  ll leftAmount = n - preAmount;
  ll timerX = 0, timerY = 0;
  ll t = 0;
  while (leftAmount > 0) {
    t++;
    timerX++;
    timerY++;
    if (timerX == x) {
      leftAmount--;
      timerX = 0;
    } if (timerY == y) {
      leftAmount--;
      timerY = 0;
    }
  } cout << preTime + t << endl;



}
