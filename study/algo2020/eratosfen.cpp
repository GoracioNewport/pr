#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ll n;
	cin >> n;

	vector <bool> prime(n + 1, 1);
	prime[0] = prime[1] = 0;
	for (int i = 0; i <= n; i++) {
		if (!prime[i] || i * 1ll * i > n) continue;
		for (int j = i * i; j <= n; j += i) prime[j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (prime[i] == 1) {
			cout << i << endl;
		}
	}
}