#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll c = gcd(abs(a), b);

	cout << a / c << ' ' << b / c << endl;
}