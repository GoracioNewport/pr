#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	// ios::ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	vector <ll> s(6);
	for (auto &i : s) cin >> i;

	ll m;
	cin >> m;

	vector <ll> n(m);
	for (auto &i : n) cin >> i;

	set <ll> prev;
	set <ll> ans;

	for (int i = 0; i < m; i++) {
		set <ll> cur;
		for (int j = 0; j < 6; j++) {
			cur.insert(n[i] - s[j]);
		}

		cout << "------------- PREV OUTPUT ----------\n";
		for (auto &k : prev) cout << k << ' ';
		cout << endl;

		cout << "------------- CUR OUTPUT ----------\n";
		for (auto &k : cur) cout << k << ' ';
		cout << endl;

		vector <ll> g(6);
		if (prev.size() > 0) {
			auto it = set_intersection(prev.begin(), prev.end(), cur.begin(), cur.end(), g.begin());
			g.resize(it - g.begin());
		} else if (prev.size() == 0) {
			g.clear();
			for (auto &k : cur) g.push_back(k);
		}

		cout << "--------------- G OUTPUT ----------\n";
		for (auto &k : g) cout << k << ' ';
		cout << endl;

		if (g.size() == 0 || i == m - 1) {
			cout << "ans" << g.size() << endl;
			for (auto &k : prev) ans.insert(k);
		}
		
		prev.clear();
		for (auto &k : g) prev.insert(k);
	} 
	// cout << ans.size() << endl;
	for (auto &i : ans) cout << i << ' ';
	cout << endl;
 	cout << abs(*(ans.begin()) - *(--ans.end())) << endl;
}