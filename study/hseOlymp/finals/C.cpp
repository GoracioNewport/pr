#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef long double ld;
typedef pair <ll, ll> p64;
typedef vector <ll> v64;
//typedef vector <ld> vdd;
typedef vector <v64> vv64;
typedef vector <p64> vp64;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define forn(i,e) for(ll i = 0; i < e; i++)
#define ln '\n'
#define fastCin() ios::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll INF = 2e18;
//ld eps = 2e-12;
ll mod = 1791791791;

istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}

istream& operator>>(istream& in, vp64& a) {
  for (auto& i: a) in >> i.fi >> i.se;
  return in;
}

ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}
int main() {

  fastCin();

  ll MAXN = 1000;
  v64 ld(MAXN + 1, 0), primes;

  ll t = chrono::high_resolution_clock::now().time_since_epoch().count();

  for (ll i = 2; i <= MAXN; i++) {
//    if (ld[i] == 0) {
//      primes.push_back(i);
//      ld[i] = i;
//    } for (auto& x : primes) {
//      if (i * x > MAXN) break;
//      ld[i * x] = min(i, x);
//    }
    for (ll j = 2; j <= i; j++) {
      if (i % j == 0) {
        ld[i] = j;
        break;
      }
    }
  } // cout << primes << ln;

//  forn(i,MAXN + 1)  {
//    cout << i << ' ' << ld[i] << ln;
//  }

//  cerr << chrono::high_resolution_clock::now().time_since_epoch().count() - t << ln;

  ll n, k;
  cin >> n >> k;

  v64 a(n);
  cin >> a;

  while(true) {
    p64 ind = {a[0], 0};
    forn(i,n) ind = max(ind, {a[i], i});
    if (ind.fi == 1 || k < ld[ind.fi]) break;
    a[ind.se] /= ld[ind.fi];
    k -= ld[ind.fi];
  } cout << *max_element(all(a)) << ln;

//  multiset <ll> q;
//  forn(i,n) {
//    ll x;
//    cin >> x;
//    q.insert(-x);
//  }
//
//  while(true) {
//    ll x = -(*q.begin());
//    if (ld[x] > k || x == 1) break;
//    q.erase(q.find(-x));
//    q.insert(-(x / ld[x]));
//    k -= ld[x];
//  } cout << -(*q.begin()) << ln;


}