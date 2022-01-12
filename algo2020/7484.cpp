#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ll k;
	cin >> k;

	ll n = 1300000;
	vector <ll> prime(n, 1);
	int i = 1;

	while (k > 0) {
		i++;
		if (!prime[i]) continue;
		for (int j = i * i; j <= n; j += i) prime[j] = 0;
		k--;	
	}

	cout << i << endl;
}