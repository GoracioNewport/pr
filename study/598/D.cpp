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

    ll q;
    cin >> q;
    forn(z,q) {
    	ll n, k;
    	cin >> n >> k;
    	string s;
    	cin >> s;
    	v64 ind;
    	ll lastInd = -1;
    	ll cnt = 0;
    	forn(i,n) {
    		if (s[i] == '0') {
    			lastInd = i;
    			if (k - (i - cnt) > 0) {
    				k -= (i - cnt);
    				ind.pb(cnt);
    				cnt++;
    			} else {
    				ind.pb(i - k);
    				k = 0;
    				cnt++;
    			}
    		}
    	} string ans;
    	ll li = 0;
    	forn(i, lastInd + 1) {
    		if (i == ind[li]) {
    			li++;
    			ans += '0';
    		} else ans += '1';
    	} forsn(i, lastInd + 1, n) ans += s[i];
    	cout << ans << endl;
    }

}
