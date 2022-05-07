// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
 
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
 
ll mod = 998244353;
ld eps = 1e-12;
ll INF = 2e18;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  if (n % 2) return binPow(a, n - 1) * a % mod;
  else {
    ll b = binPow(a, n / 2);
    return b * b % mod;
  }
}

ll rev(ll x) {
  return binPow(x, mod - 2);
}
 
int main() {
  fastCin();
 
	ll n, c;
	cin >> n >> c;

	ll ans = 1;

  ll maxn = 5e7 + 1;

  v64 factorial(maxn);
  factorial[0] = 1;
  for(ll i = 1; i <= maxn; i++) factorial[i] = factorial[i - 1] * i % mod;
 
  // cout << "0 1" << ' ';
 	forsn(i,2,c + 1) {

    // cout << i << ":\n";

 		unordered_map <ll, ll> z;
 		ll I = i;
 		for (ll x = 2; x * x <= I; x++) {
 			while(I % x == 0) {
 				z[x]++;
 				I /= x;
 			}
 		} if (I != 1) z[I]++;
    ll locAns = 1; 



 		for (auto& j : z) {
      // cout << j.fi << ' ' << j.se << ln;

      locAns = (locAns * factorial[n + j.se - 1] % mod * rev(factorial[n - 1]) % mod * rev(factorial[j.se]));
 		} ans = (ans + locAns) % mod;
    // cout << locAns << ' ';
 	} cout << ans << ln;
}

