#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ll n, m;
	cin >> n;
	set <ll> f;
	for (int i = 0; i < n; i++) { ll a; cin >> a; f.insert(a); }
	cin >> m;
	set <ll> s;
	for (int i = 0; i < m; i++) { ll a; cin >> a; s.insert(a); }
	vector <ll> d;
	set_symmetric_difference(f.begin(), f.end(), s.begin(), s.end(), back_inserter(d));
	cout << d.size() << endl;
	for (auto &i : d) cout << i << ' ';
	cout << endl; 
}