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
