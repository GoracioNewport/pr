#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

    ll t;
    cin >> t;
    forn(k,t) {
    	ll n;
    	cin >> n;
    	ll al = n;

    	ll maxI = -1, maxN = -1;

    	map <ll, ll> divs;
    	for (ll i = 2; (i * i) <= n; i++) {
    		ll c = 0;
    		while(n % i == 0) {
    			n /= i;
    			c++;
    		} if (c != 0 && c > maxN) {
    			maxN = c;
    			maxI = i;
    		}
    	} if (n > 1) {
    		if (maxN == -1) {
    			maxI = n;
    			maxN = 1;
    		}
    	} vector <ll> ans;
    	ll mul = 1;
    	for (int i = 0; i < (maxN - 1); i++) {
    		ans.pb(maxI);
    		mul *= maxI;
    	} if (al / mul != 1) ans.pb(al / mul);
    	cout << ans.size() << ln;
    	for (auto &i : ans) cout << i << ' ';
    	cout << ln;
    }

}
