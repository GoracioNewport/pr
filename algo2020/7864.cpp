#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ll n;
	cin >> n;

	multiset <ll> m;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		m.insert(-a);
	} while (m.size() != 1) {
		auto a = m.end()--;
		cout << a << endl;
		m.erase(m.end()--);
		auto b = m.end()--;
		cout << b << endl;
		m.erase(m.end()--);
		m.insert(a + b);
	} cout << m.size() << endl;
}