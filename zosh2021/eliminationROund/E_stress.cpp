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

p64 findAns(ll f, ll n) {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (f == 0) return {i, j};
			f--;
		}
	}
}

int main() {
    fast_cin();

    ll b = 1;
    while (true) {
    	ll n = b; n--;
    	// cout << n << endl;
	    pair <ll, p64> ans = {-1, {-1, -1}};
	    v64 sums(12, 0);
	    forn(i,12) sums[i + 1] = sums[i] + i + 1;
	    // ll s = 0;
	    // for (auto &i : sums) s += i;
	    // cout << s << endl;
	    for (int i = 1; i <= sz(sums); i++) {
	    	if (n < sums[i]) {
	    		ans.fi = i + 2;
	    		ans.se = findAns(n, i + 1);
	    		break;
	    	} else n -= sums[i];
	    } if (ans.fi == -1) {
	    	ll cnt = n / 66;
	    	ans.fi = sz(sums) + cnt;
	    	ans.se = findAns(n % 66, 11);
	    } pair <ll, p64> ans1 = {-1, {-1, -1}};
	    n = b;
	    for (int i = 3; i < 1e9; i++) {
	    	for (int j = 2; j < min(i, 13); j++) {
	    		for (int k = 1; k < min(j, 12); k++) {
	    			n--;
	    			if (n == 0) {
	    				ans1.fi = i;
	    				ans1.se = {j, k};
	    				break;
	    			}
	    		} if (n == 0) break;
	    	} if (n == 0) break;
	    } if (ans.fi != ans1.fi || ans.se.fi != ans1.se.fi || ans.se.se != ans1.se.se) {
	    	cout << "COUNTER TEST FOUND " << b << endl;
	    	cout << "Ans Smart -> " << ans.fi << ' ' << ans.se.fi << ' ' << ans.se.se << endl;
	    	cout << "Ans Naive -> " << ans1.fi << ' ' << ans.se.fi << ' ' << ans.se.se << endl;
	    	break;
	    } b++;
	}
}
