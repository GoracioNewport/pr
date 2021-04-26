<<<<<<< HEAD
<<<<<<< HEAD
=======
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
  
<<<<<<< HEAD
=======
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
  fast_cin();

  ll n, k;
  cin >> n;
  v64 m(n);
  for(auto &i : m) cin >> i;
  sort(all(m));
  // for (auto &i : m) cout << i << ' ';
  // cout << endl;

  
  
  cin >> k;
  forn(z,k) {
    ll a, b;
    cin >> a >> b;
    ll l = lower_bound(m.begin(), m.end(), a) - m.begin();
    ll r = upper_bound(m.begin(), m.end(), b) - m.begin();
    cout << abs(l - r) << ' ';
  } 
=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
    fast_cin();

    ll n;
    cin >> n;
    v64 p(n);
    for (auto &i : p) cin >> i;
    ll k;
	cin >> k;
	sort(all(p));
	forn(z, k) {
		ll a, b;
		cin >> a >> b;
		ll l = 0;
		ll r = n;
		while (l + 1 < r) {
			ll m = (l + r) / 2;
			if (p[m] <= a) l = m;
			else r = m;
		} ll ans1 = l;
		l = 0;
		r = n;
		while (l + 1 < r) {
			ll m = (l + r) / 2;
			if (p[m] < b) l = m;
			else r = m;
		} ll ans2 = l;
		cout << ans1 << ' ' << ans2 << ' ';
		cout << abs(ans1 - ans2) + 1 << endl;;
	} cout << endl;
<<<<<<< HEAD
=======
  fast_cin();

  ll n, k;
  cin >> n;
  v64 m(n);
  for(auto &i : m) cin >> i;
  sort(all(m));
  // for (auto &i : m) cout << i << ' ';
  // cout << endl;

  
  
  cin >> k;
  forn(z,k) {
    ll a, b;
    cin >> a >> b;
    ll l = lower_bound(m.begin(), m.end(), a) - m.begin();
    ll r = upper_bound(m.begin(), m.end(), b) - m.begin();
    cout << abs(l - r) << ' ';
  } 
>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a

}
