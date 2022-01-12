#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> factor (ll n) {

	vector <ll> factors;
	for (ll i = 0; i * i <= n; i++) {
		while (n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}

	if (n > 1) factors.push_back(i);
	return factors;

}
