#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <vector <char>> m(8, vector <char> (8));
	vector <vector <ll>> a(8, vector <ll> (8, 0));
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) m[i][j] = s[j];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m[i][j] == 'B') {
				for (int I = i; I >= 0; I--) {
					ll J = j - (abs(i - I));
					if (J < 0 || J > 7) break;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				} 
				for (int I = i; I >= 0; I--) {
					ll J = j + (abs(i - I));
					if (J < 0 || J > 7) break;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				} 
				for (int I = i; I < 8; I++) {
					ll J = j + (abs(i - I));
					if (J < 0 || J > 7) break;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				} 
				for (int I = i; I < 8; I++) {
					ll J = j - (abs(i - I));
					if (J < 0 || J > 7) break;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				} 
			} else if (m[i][j] == 'R') {
				for (int I = i; I >= 0; I--) {
					ll J = j;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				}
				for (int I = i; I < 8; I++) {
					ll J = j;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				}
				for (int J = j; J >= 0; J--) {
					ll I = i;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				}
				for (int J = j; J < 8; J++) {
					ll I = i;
					// cout << I << ' ' << J << endl;
					if (m[I][J] != '*' && I != i) break;
					a[I][J] = 1;
				}
			}
		}
	}

	ll ans = 0;
	for (auto &i : a) for (auto &j : i) if (j == 0) ans++;
	cout << ans << endl;

}