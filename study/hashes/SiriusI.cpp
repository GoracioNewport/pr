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

const ll mod = 1791791791, k = 10501, q = 239;
const ll mod1 = 1e9 + 7, k1 = 15083, q1 = 113;
vv64 h;
vv64 h1;
v64 ks, qs;
v64 ks1, qs1;
vector <string> s;

ll subHash(ll x1, ll y1, ll x2, ll y2) {
  ll fullHash = h[x2 + 1][y2 + 1];
  ll oHash = h[x2 + 1][y1] * ks[y2 - y1 + 1] % mod;
  ll tHash = h[x1][y2 + 1] * qs[x2 - x1 + 1] % mod;
  ll xHash = h[x1][y1] * ks[y2 - y1 + 1] % mod * qs[x2 - x1 + 1] % mod;
//  dbg(fullHash);
//  dbg(oHash);
//  dbg(tHash);
//  dbg(xHash);

  return ((((((((fullHash - oHash) + mod) % mod) - tHash) + mod) % mod) + xHash) + mod) % mod;
}

ll subHash1(ll x1, ll y1, ll x2, ll y2) {
  ll fullHash = h1[x2 + 1][y2 + 1];
  ll oHash = h1[x2 + 1][y1] * ks1[y2 - y1 + 1] % mod1;
  ll tHash = h1[x1][y2 + 1] * qs1[x2 - x1 + 1] % mod1;
  ll xHash = h1[x1][y1] * ks1[y2 - y1 + 1] % mod1 * qs1[x2 - x1 + 1] % mod1;
//  dbg(fullHash);
//  dbg(oHash);
//  dbg(tHash);
//  dbg(xHash);

  return ((((((((fullHash - oHash) + mod1) % mod1) - tHash) + mod1) % mod1) + xHash) + mod1) % mod1;
}

int main() {
//  fast_cin();

  ll n, m;
  cin >> n >> m;
  h.resize(n + 1, v64 (m + 1, 0));
  h1.resize(n + 1, v64 (m + 1, 0));
  s.resize(n);
  ks.resize(n + 1, 1);
  qs.resize(n + 1, 1);
  ks1.resize(n + 1, 1);
  qs1.resize(n + 1, 1);
  for (auto &i : s) cin >> i;
  forn(i,n) {
    ks[i + 1] = ks[i] * k % mod;
    ks1[i + 1] = ks1[i] * k1 % mod1;
    forn(j,m) {
      qs[i + 1] = qs[i] * q % mod;
      qs1[i + 1] = qs1[i] * q1 % mod1;
      ll x = (s[i][j] - 'a' + 1);
      h[i + 1][j + 1] = ((h[i + 1][j] * k) % mod) + x;
      h[i + 1][j + 1] = (((h[i][j + 1] * q) % mod) + h[i + 1][j + 1]) % mod;
      h[i + 1][j + 1] = ((h[i + 1][j + 1] - ((((h[i][j] * q) % mod) * k) % mod)) + mod) % mod;
      h1[i + 1][j + 1] = ((h1[i + 1][j] * k1) % mod1) + x;
      h1[i + 1][j + 1] = (((h1[i][j + 1] * q1) % mod1) + h1[i + 1][j + 1]) % mod1;
      h1[i + 1][j + 1] = ((h1[i + 1][j + 1] - ((((h1[i][j] * q1) % mod1) * k1) % mod1)) + mod1) % mod1;
    }
  }

//  for (auto &i : h) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }

//  ll q = 100;
//  while(q--) {
//    ll x1, y1, x2, y2;
//    cin >> x1 >> y1 >> x2 >> y2;
//    cout << subHash(x1,y1,x2,y2) << ln;
//  }

  ll l = 0;
  ll r = min(n,m) + 1;
  ll ansK = 0;
  pair <pair <ll,ll>, pair <ll,ll>> ans;
  while(l + 1 < r) {
    ll x = (l + r) / 2;
//    dbg(x);
    bool ok = false;
    map <p64, p64> p;
    forn(i,n - x + 1) {
      forn(j,m - x + 1) {
        ll hash = subHash(i,j,i + x - 1, j + x - 1);
        ll hash1 = subHash1(i,j,i + x - 1, j + x - 1);
//        cout << hash << ln;
        if (p.find({hash,hash1}) != p.end()) {
          if (x > ansK) {
//            cout << x << " OK" << ln;
//            cout << i << ' ' << j << ' ' << p[hash].fi << ' ' << p[hash].se << ln;
            ansK = x;
            ans = {{i,j}, {p[{hash,hash1}]}};
          } ok = true;
        } p[{hash,hash1}] = {i,j};
      } if (ok) break;
    } if (ok) l = x;
    else r = x;
//    cout << x << ' ' << ok << ln;
  } cout << ansK << ln;
  if (ansK) cout << ans.fi.fi + 1 << ' ' << ans.fi.se + 1 << ln << ans.se.fi + 1 << ' ' << ans.se.se + 1 << ln;
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
ll mod = 1791791791;
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

const ll k = 239, q = 10559;

vector <string> s;
vv64 h;
v64 ks, qs;

ll subHash(ll x1, ll y1, ll x2, ll y2) {
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	ll fullHash = h[x2 + 1][y2 + 1];
	ll oHash = ((h[x2 + 1][y1]) * ks[y2 - y1 + 1]) % mod; // слева
	ll tHash = ((h[x1][y2 + 1]) * qs[x2 - x1 + 1]) % mod; // сверху
	ll xHash = ((((h[x1][y1]) * ks[y2 - y1 + 1]) % mod) * qs[x2 - x1 + 1]) % mod; // слева сверху
	dbg(fullHash);
	dbg(oHash);
	dbg(tHash);
	dbg(xHash);
	return ((fullHash - oHash - tHash + xHash) + mod) % mod;
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  s.resize(n);
  ks.resize(n + 1, 1);
  qs.resize(m + 1, 1);
  for (auto &i : s) cin >> i;
  h.resize(n + 1, v64 (m + 1, 0));
	forn(i,n) {
		ks[i + 1] = (ks[i] * k) % mod;
		forn(j,m) {
			if (i == 0) qs[i + 1] = (qs[i] * q) % mod;
			ll x = (s[i][j] - 'a' + 1);
			h[i + 1][j + 1] = (((h[i + 1][j] * k) % mod) + x) % mod;
			h[i + 1][j + 1] = (((h[i][j + 1] * q) % mod) + h[i + 1][j + 1]) % mod;
		}
	} 
	
	// for (auto &i : h) {
	// 	for (auto &j : i) cout << j << ' ';
	// 	cout << ln;
	// }

	pair <pair <ll,ll>, pair <ll,ll>> ans = {{-1,-1},{-1,-1}};
	ll maxAns = 0;

	ll l = 0;
	ll r = min(n,m) + 1;
	while(l + 1 < r) {
		ll M = (l + r) / 2;
		cout << M << endl;
		map <ll, pair <ll,ll>> p;
		bool ok = false;
		forn(i,n - M + 1) {
			forn(j,m - M + 1) {
				// cout << i << ' ' << j << endl;
				ll hash = subHash(i, j, i + M - 1, j + M - 1);
				if (p.find(hash) != p.end()) {
					if (M > maxAns) {
						maxAns = M;
						ans = {{i,j}, p[hash]};
					} ok = true;
				} else p[hash] = {i,j};
			} if (ok) break;
		} if (ok) l = M;
		else r = M;
	} cout << maxAns << ln;
	if (maxAns > 0) cout << ans.fi.fi + 1 << ' ' << ans.fi.se + 1 << ln << ans.se.fi + 1 << ' ' << ans.se.se + 1 << ln;
	

}
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
