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

bool ok;
ll n;

void f(v64 &a, v64 &used, ll d, v64 &p, ll x, ll i) {
	if (ok) return;
	if (!d) {
		ll s = 0;
		for (auto &i : p) s += a[i];
		if (s == x) ok = true;
		return;
	} for (ll j = i; j < n; j++) {
		if (used[j]) continue;
		p.pb(j);		
		f(a, d - 1, p, x, i + 1);
		if (ok) return;
		p.erase(prev(p.end()));

	}
}

int main() {
  fast_cin();

  freopen("c0.in","r",stdin);
  freopen("c0ansMy.out","w",stdout);

  ll t;
  cin >> t;
  while(t--) {
  	cin >> n;
  	vp64 a(n);
  	multiset <ll> b;
  	ll ind = 0;
  	for (auto &i : a) {
  		cin >> i.fi;
  		i.se = ind++;
  		b.insert(i);
  	} sort(all(a));
  	reverse(all(a));
  	v64 used(n, 0);
  	forn(i,n) {
  		used[i] = 1;
  		for (ll len = 1; len <= sz(b); len++) {
  			v64 lens(len, -1);
  			ok = false;
  			v64 p;
				f(a, used, len, p, a[i] - 1, i + 1);
				if (ok) {
					for (auto &i : p) {
						used[i] = 1;

					}
					break;
				}  			
  		}
  	}

  }


}
 