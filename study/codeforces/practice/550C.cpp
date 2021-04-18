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

int main() {
    fast_cin();

    string s;
    cin >> s;
    ll n = sz(s);
    // for (ll)
    for (ll a = 0; a < n; a++) {
    	for (ll b = a + 1; b < n; b++) {
    		for (ll c = b + 1; c < n; c++) {
    			ll x = (s[a] - '0');
    			ll y = (s[b] - '0');
    			ll z = (s[c] - '0');
    			// cout << x << y << z << ln;
    			if (x == 0) continue;
    			if (((x * 100) + (y * 10) + z) % 8 == 0) {
    				cout << "YES\n";
    				cout << x << y << z << ln;
    				return(0);
    			} 
    		}
    	}
    } 

    for (ll a = 0; a < n; a++) {
    	for (ll b = a + 1; b < n; b++) {
    		ll x = (s[a] - '0');
    		ll y = (s[b] - '0');
    		if (x == 0) continue;
    		if (((x * 10) + y) % 8 == 0) {
    			cout << "YES\n";
    			cout << x << y << ln;
    			return(0);
    		}
    	}
    }

    for (ll a = 0; a < n; a++) {
    	if (s[a] == '0' || s[a] == '8') {
    		cout << "YES\n";
    		cout << s[a] << ln;
    		return(0);
    	}
    }

    cout << "NO\n";

}
