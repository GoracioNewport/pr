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

string s;
vv64 t;
v64 lo, ps;
v64 p, c;
ll n;

ll getLcp(ll a, ll b) {
	ll i = c[a];
	ll j = c[b];
	if (j < i) swap(i, j);
	i = min(i + 1, n - 1);
	// cout << i << ' ' << j << ln;
	ll x = lo[j - i + 1];
	return min(t[x][i], t[x][min(j - ps[x] + 1, (ll)n - 1)]);
}

bool subSort(p64 a, p64 b) { // < - true
	ll lenA = a.se - a.fi + 1;
	ll lenB = b.se - b.fi + 1;
	// cout << "Sorting " << s.substr(a.fi, lenA) << ' ' << s.substr(b.fi, lenB) << ln;
	// cout << a.fi << ' ' << a.se << ' ' << b.fi << ' ' << b.se << ln;
	ll lcp = (a.fi == b.fi ? min(lenA, lenB) : getLcp(a.fi, b.fi));
	// cout << "LCP: " << lcp << ' ';
	if (lcp >= min(lenA, lenB)) {
		if (lenA < lenB) {
			// cout << "<" << ln;
			return true;
		} else if (lenB < lenA) {
			// cout << ">" << ln;
			return false;
		} else {
			if (a < b) {
				// cout << "<" << ln;
				return true;
			} else {
				// cout << ">" << ln;
				return false;
			}
		}
	} // if (lcp >= )
	if (s[min(a.fi + lcp, (ll)n - 1)] < s[min(b.fi + lcp, (ll)n - 1)]) {
		// cout << "<" << ln;
		return true;
	} // cout << ">" << ln;
	return false;
}

void countSort(v64 &p, v64 &c) {
	ll n = sz(p);
	v64 cnt(n), pos(n), pNew(n);
	for (auto &i : c) cnt[i]++;
	forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1]; 
	for(auto &i : p) pNew[pos[c[i]]++] = i;
	p = pNew;
}

int main() {
  fast_cin();

  cin >> s;
  s = '~' + s + ' ';
  n = sz(s);
  p.resize(n);
  c.resize(n); {
		vector <pair <char, ll>> a(n);
		forn(i,n) a[i] = {s[i], i};
		sort(all(a));
		forn(i,n) p[i] = a[i].se;
		forsn(i,1,n) { 
			if (a[i].fi == a[i - 1].fi) c[p[i]] = c[p[i - 1]];
			else c[p[i]] = c[p[i - 1]] + 1;
		}
  } ll k = 0;
  while ((1 << k) < n) {
  	for (auto &i : p) i = (i - (1 << k) + n) % n;
  	countSort(p,c);
  	v64 cNew(n);
  	forsn(i,1,n) {
  		if ((c[p[i]] == c[p[i - 1]]) && (c[p[i] + (1 << k) % n] == c[p[i - 1] + (1 << k) % n])) cNew[p[i]] = cNew[p[i - 1]];
  		else cNew[p[i]] = cNew[p[i - 1]] + 1;
  	} c = cNew;
  	k++;
  } k = 0;
  v64 lcp(n);
  forn(i,n - 1) {
  	ll pi = c[i];
  	ll j = p[pi - 1];
  	while (s[k + i] == s[k + j]) k++;
  	lcp[pi] = k;
  	k = max((ll)0, k - 1);
  } ps.resize(60, 1);
  lo.resize(n + 1, 0);
  forsn(i,1,60) ps[i] = ps[i - 1] * 2;
  k = 1;
  ll C = -1;
  forsn(i,1,n + 1) {
  	if (i == k) {
  		C++;
  		k *= 2;
  	} lo[i] = C;
  } t.resize(C + 1, v64 (n));
  forn(i,n) t[0][i] = lcp[i];
  forsn(i,1,C + 1) forn(j,n - ps[i] + 1) t[i][j] = min(t[i - 1][j], t[i - 1][j + ps[i - 1]]);
  
  // forn(i,n) {
  // 	cout << i << ' ' << p[i] << ' ' << s.substr(p[i]) << ' ' << lcp[i] << ln; 
  // }

  ll q;
  cin >> q;
  vp64 ans;
  while(q--) {
  	ll l, r;
  	cin >> l >> r;
  	ans.pb({l,r});
  } sort(ans.begin(), ans.end(), subSort);
  // cout << ln;
  for (auto &i : ans) cout << i.fi << ' ' << i.se << ln;
}