#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd (ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ll t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		ll n;
		cin >> n;
		vector <ll> ans;
		for (int i = 0; i < n / 2; i++) {
			ll a, b;
			cin >> a >> b;
			ans.push_back(b);
			ans.push_back(-a);
		}
		for (auto &i : ans) cout << i << ' ';
		cout << endl;
	} 
}