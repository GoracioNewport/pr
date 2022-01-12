#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll k = 239, mod = 1791791791;

vector <ll> hrg;
vector <ll> hrv;
vector <ll> ks;

ll subhash(vector <ll> &h, ll l, ll r) {
	return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {

    string s;
    cin >> s;
    ll n = s.size();

    hrg.resize(n + 1, 0);
    hrv.resize(n + 1, 0);
    ks.resize(n + 1, 1);

    pair <ll, ll> ans = {-1, -1};

    for (int i = 0; i < n; i++) {
    	ks[i + 1] = (ks[i] * k) % mod;
    	ll x = (s[i] - 'a' + 1);
    	ll y = (s[n - i - 1] - 'a' + 1);
    	hrg[i + 1] = ((hrg[i] * k) + x) % mod;
    	hrv[i + 1] = ((hrv[ i] * k) + y) % mod;
    }


    ll r = (n / 2) + 1;
    if (n % 2 == 0) r--;
    for (int i = (n / 2) + 1; i < n; i++) {
    	// cout << 1 << ' ' << i << endl;
    	// cout << r << ' ' << n << endl;
    	if (subhash(hrg, 1, i) == subhash(hrg, r, n)) {
    		// cout << "Shit found " << 1 << ' ' << i << endl; 
    		// cout << s.substr(0, i) << endl;
    		ans = {1, i};
    	}
    	r--;
    	// if (subhash(hrg, 1, i) == subhash(hrg, (n / 2) - i + 1, n))
    } if (ans.first != -1) {
    	cout << "YES" << endl;;
    	cout << s.substr(ans.first - 1, ans.second) << endl;
    } else cout << "NO" << endl;
}
