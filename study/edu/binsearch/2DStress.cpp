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

struct Clown {
    ll t; // Время надувания одного шара
    ll z; // Количество шаров до передышки
    ll y; // Время передышки
};

ll m, n;

ll findP(Clown a, ll x) {
  ll ans = 0;
  ll t = (a.t * a.z) + a.y; // Время одного цикла
  ans += (x / t);
  t = x % t;
  t = min(t, a.t * a.z);
  ans += (t / a.t);
  return ans;
}

bool ok(vector <Clown> &a, ll x) {
  ll cnt = 0;
  for (auto &i : a) cnt += findP(i, x);
//  cout << "Time: " << x << ", Count: " << cnt << ln;
  return (cnt < m);
}

pair <ll, v64> smart(vector <Clown> &a) {
  ll l = 0;
  ll r = 1000000000;
  while(l + 1 < r) {
    ll m = (l + r) / 2;
//    cout << m << ln;
    if (ok(a, m)) l = m;
    else r = m;
  } v64 ans;
  for(auto &i : a) ans.pb(findP(i, r));
  return {r, ans};
}

enum {WORKING, IDLE};

pair <ll, v64> stupid(vector <Clown> &a) {
  ll ans = 0;
  vp64 status(n);
  v64 cooldown(n);
  forn(i,n) {

  }
  while (ans < m) {

  }

}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  fast_cin();

  while(true) {
    n = (rng() % 100) + 1;
    m = (rng() % 1000);
    vector <Clown> a;
    forn(i,n) {
      ll t = (rng() % 100) + 1;
      ll z = (rng() % 100) + 1;
      ll y = (rng() % 100) + 1;
      a.pb({t,z,y});
    }
  }

}