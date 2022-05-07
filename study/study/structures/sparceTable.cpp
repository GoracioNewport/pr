<<<<<<< HEAD
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

int main() {
//  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  ll m = 1;
  while (m < n) m *= 2;
  vv64 t(m, v64 (n, INF));
  for (ll k = 1; k < n; k *= 2) {
    for (ll i = 0; i < n; i++) {
      t[k][i] = min(a[i], t[k][i]);
    }
  } v64 powers(n + 1, 0);
  for (auto &i : t) {
    for (auto &j : i) cout << j << ' ';
    cout << ln;
  }
  ll k = 1;
  ll c = 0;
  for (ll i = 1; i <= n; i++) {
    if (i == k) {
      k *= 2;
      c++;
    } powers[i] = c - 1;
  } for (auto &i : powers) cout << i << ' ';

  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll p = powers[r - l];
//    cout << min()
  }

}
=======
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
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

int main() {
  // fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  v64 ps(60, 1), l(n + 1, 0);
	forsn(i,1,60) ps[i] = ps[i - 1] * 2;
	// for (auto &i : ps) cout << i << ' ';
	// cout << ln;
	ll k = 1;
	ll c = -1;
	forsn(i,1,n + 1) {
		if (i == k) {
			c++;
			k *= 2;
		} l[i] = c;
	} // for (auto &i : l) cout << i << ' ';
	vv64 t(c + 1, v64 (n));
	forn(i,n) t[0][i] = a[i];
	forsn(i,1,c + 1) forn(j,n - ps[i] + 1) t[i][j] = min(t[i - 1][j], t[i - 1][j + ps[i - 1]]);
	ll q;
	cin >> q;
	while(q--) {
		ll L, R;
		cin >> L >> R; L--; R--;
		ll x = l[R - L + 1];
 		cout << min(t[x][L], t[x][R - ps[x] + 1]) << ln;
	}

}
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
