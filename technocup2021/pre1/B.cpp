#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;

pair <string, ll> go(ll j) {
	cout << "GO Initiated from index " << j << endl;
	string ans = "";
	ll a = 0;
	for (int i = j; i < s.size(); i++) {
		if (s[i] == ')') { 
			cout << "Returning shit\n"; 
			string r = "";
			for (int i = 0; i < max(a, (ll)1); i++) r += ans;
			return {ans, i + 1}; 
		} else if (s[i] == '(') {
			cout << "Found ( symbol" << endl;
			auto r = go(i + 1);
			cout << "Calling go from i + 1: " << r.first << ' ' << r.second << endl;
			cout << "A: " << a << endl;
			// for (int i = 0; i < max(a, (ll)1); i++) ans += r.first;
			i = r.second;
		} else if (isdigit(s[i])) { 
			a = a * 10 + (s[i] - '0'); 
			cout << "Digit found\n Now it's " << a << endl;
		} else if (isalpha(s[i])) {ans += s[i]; cout << "Alpha found\n";}
	} return {ans, s.size() - 1};
}

int main() { 
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	cout << go(0).first << endl;
}