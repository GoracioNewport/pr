#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <ll> st(6);
	for (auto &i : st) cin >> i;
	
	ll n;
	cin >> n;
	vector <ll> notes(n);
	for (auto &i : notes) cin >> i;

	set <ll> ans;
	set <ll> prev;
	set <ll> na;

	for (int i = 0; i < n; i++) {
		na.clear();
		cout << i << "------------" << endl;
		for (int j = 0; j < 6; j++) {
			cout << i << ' ' << j << endl;
			cout << notes[i] << ' ' << st[j] << endl;
			cout << notes[i] - st[j] << endl;
			na.insert((ll)(notes[i] - st[j]));
			cout << "inserted\n";
		} 
		cout << "shish\n";
		vector <ll> g(6, -1);
		cout << "double shish\n";
		if (prev.size() > 0) {
			cout << "yay\n";
			set_union(na.begin(), na.end(), prev.begin(), prev.end(), g.begin());
			vector <ll> ma = g;
			g.clear();
			for (int k = 0; k < ma.size(); k++) if (ma[k] != -1) g.push_back(ma[k]);
		}
		else {
			g.clear();
			for (auto &k : na) g.push_back(k);
		}

		if (g.size() == 0) {
			for (auto &k : prev) ans.insert(k);
		}


		prev.clear();
		for (auto &k : g) prev.insert(k);		
	} cout << abs(*(ans.begin()) - *(ans.end()--)) << endl;
}