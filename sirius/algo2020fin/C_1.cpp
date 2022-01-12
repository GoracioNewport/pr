#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll n = 8;
	vector <vector <char>> m(n, vector <char> (n));
	vector <vector <ll>> a(n, vector <ll> (n, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) m[i][j] = s[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] == 'B') {
				for (int I = i; I >= 0; I--) {
					ll J = j + (i - I);
					if (J < 0 || J > 7 || (m[I][J] != '*' && I != i)) break;
					a[I][J] = 1;
				} for (int I = i; I >= 0; I--) {
					ll J = j + (I - i);
					if (J < 0 || J > 7 || (m[I][J] != '*' && I != i)) break;
					a[I][J] = 1;
				} for (int I = i; I < 8; I++) {
					ll J = j + (i - I);
					if (J < 0 || J > 7 || (m[I][J] != '*' && I != i)) break;
					a[I][J] = 1;
				} for (int I = i; I < 8; I++) {
					ll J = j + (I - i);
					if (J < 0 || J > 7 || (m[I][J] != '*' && I != i)) break;
					a[I][J] = 1;
				}
			} else if (m[i][j] == 'R') {
				for (int I = i; I >= 0; I--) {
					ll J = j;
					if (J < 0 || J > 7 || (m[I][J] != '*' && I != i)) break;
					a[I][J] = 1;
				} for (int J = j; J >= 0; J--) {
					ll I = i;
					if (I < 0 || I > 7 || (m[I][J] != '*' && J != j)) break;
					a[I][J] = 1;
				} for (int I = i; I < 8; I++) {
					ll J = j;
					if (J < 0 || J > 7 || (m[I][J] != '*' && I != i)) break;
					a[I][J] = 1;
				} for (int J = j; J < 8; J++) {
					ll I = i;
					if (I < 0 || I > 7 || (m[I][J] != '*' && J != j)) break;
					a[I][J] = 1;
				}
			}
		}
	}

	ll ans = 0;
	for (auto &i : a) for (auto &j : i) if (j == 0) ans++;
	cout << ans << endl; 

}