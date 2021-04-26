<<<<<<< HEAD
<<<<<<< HEAD
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

const ll mod = 1791791791, k = 239;

v64 ks;
v64 hr;
v64 hz;

ll sub_hash(v64 &h, ll l, ll r) {
	return ((h[r] - ((h[l + 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
    fast_cin();

    string s;
    cin >> s;
    ll n = sz(s);

    ks.resize(n + 1, 1);
    hr.resize(n + 1, 0);
    hz.resize(n + 1, 0);

    forn(i,n) {
    	ks[i + 1] = (ks[i] * k) % mod;
    	ll x = (s[i] - 'a' + 1);
    	ll y = (s[n - i - 1] - 'a' + 1);
    	hr[i + 1] = ((hr[i] * k) % mod) + x;
    	hz[i + 1] = ((hz[i] * k) % mod) + y;
    }

    // for (auto &i : hr) cout << i << ' ';
    // cout << endl;
    // for (auto &i : hz) cout << i << ' ';
    // cout << endl;

    // while (true) {
    // 	char a;
    // 	ll l, r;
    // 	cin >> a >> l >> r;
    // 	if (a == 'f') cout << sub_hash(hr, l, r) << endl;
    // 	else cout << sub_hash(hz, l, r) << endl; 
    // }

    ll ans = 0;

    // Пробегаемся по палиндромам четной длины
    forn(i, n) {
    	ll l = 0;
    	ll r = min(i, n - i - 2) + 1;
    	cout << i << ' ' << l << ' ' << r << endl;
    	while (l + 1 < r) {
    		ll m = (l + r) / 2;
    		ll a = i - m;
    		ll b = i + m + 1;
    		ll c = (n - i + 1) + m - 1;
    		ll d = (n - i + 1) - m;
    		// cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    		l = m;
    		// if (sub_hash(hr, i - m, i + m + 1) == sub_hash(hz, ()))
    	}
    }


    cout << ans << endl;

}
=======
=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
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

const ll mod = 1791791791, k = 239;
v64 ks;
v64 hs;
v64 hr;
ll n;

ll subhash(v64 &h, ll l, ll r) {
  l++; r++;
  return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

bool isPalindromeEven(ll i, ll x) {
  if (i - x < 0 || i + x > n) return false;
  ll strH = subhash(hs, i - x, i + x);
  ll revI = n - i - 1;
  if (revI - x < 0 || revI + x > n) return false;
  ll revH = subhash(hr, revI - x, revI + x);
  return (strH == revH);
}

bool isPalindromeOdd(ll i, ll x) {
  if (i - x + 1 < 0 || i + x > n) return false;
  ll strH = subhash(hs, i - x + 1, i + x);
  ll revI = n - i - 2;
  if (revI - x + 1 < 0 || revI + x > n) return false;
  ll revH = subhash(hr, revI - x + 1, revI + x);
  return (strH == revH);
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  n = sz(s);
  ks.resize(n + 1, 1);
  hs.resize(n + 1, 0);
  hr.resize(n + 1, 0);
  forn(i,n) ks[i + 1] = (ks[i] * k) % mod;
  forn(i,n) {
    ll x = (s[i] - 'a' + 1);
    ll y = (s[n - i - 1] - 'a' + 1);
    hs[i + 1] = (((hs[i] * k) % mod) + x) % mod;
    hr[i + 1] = (((hr[i] * k) % mod) + y) % mod;
  } ll ans = 0;
  for (ll i = 1; i < n - 1; i++) { // Перебор палиндромов нечетной длины
    ll l = 0;
    ll r = min(i,n - i - 1) + 1;
    while (l + 1 < r) {
      ll m = (l + r) / 2;
      if (isPalindromeEven(i,m)) l = m;
      else r = m;
    } ans += l;
  } for (ll i = 0; i < n - 1; i++) { // Перебор палиндромов четной длины. Середина после i-ого символа
    ll l = 0;
    ll r = (i + 1, n - i) + 1;
    while(l + 1 < r) {
      ll m = (l + r) / 2;
      if (isPalindromeOdd(i,m)) l = m;
      else r = m;
    } ans += l;
  } cout << ans << ln;


}
<<<<<<< HEAD
>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
=======
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

const ll mod = 1791791791, k = 239;

v64 ks;
v64 hr;
v64 hz;

ll sub_hash(v64 &h, ll l, ll r) {
	return ((h[r] - ((h[l + 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
    fast_cin();

    string s;
    cin >> s;
    ll n = sz(s);

    ks.resize(n + 1, 1);
    hr.resize(n + 1, 0);
    hz.resize(n + 1, 0);

    forn(i,n) {
    	ks[i + 1] = (ks[i] * k) % mod;
    	ll x = (s[i] - 'a' + 1);
    	ll y = (s[n - i - 1] - 'a' + 1);
    	hr[i + 1] = ((hr[i] * k) % mod) + x;
    	hz[i + 1] = ((hz[i] * k) % mod) + y;
    }

    // for (auto &i : hr) cout << i << ' ';
    // cout << endl;
    // for (auto &i : hz) cout << i << ' ';
    // cout << endl;

    // while (true) {
    // 	char a;
    // 	ll l, r;
    // 	cin >> a >> l >> r;
    // 	if (a == 'f') cout << sub_hash(hr, l, r) << endl;
    // 	else cout << sub_hash(hz, l, r) << endl; 
    // }

    ll ans = 0;

    // Пробегаемся по палиндромам четной длины
    forn(i, n) {
    	ll l = 0;
    	ll r = min(i, n - i - 2) + 1;
    	cout << i << ' ' << l << ' ' << r << endl;
    	while (l + 1 < r) {
    		ll m = (l + r) / 2;
    		ll a = i - m;
    		ll b = i + m + 1;
    		ll c = (n - i + 1) + m - 1;
    		ll d = (n - i + 1) - m;
    		// cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    		l = m;
    		// if (sub_hash(hr, i - m, i + m + 1) == sub_hash(hz, ()))
    	}
    }


    cout << ans << endl;

}
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
