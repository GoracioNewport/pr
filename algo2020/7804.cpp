#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {

	deque <ll> q;
	string s = "";

	while (s != "exit") {
		cin >> s;
		if (s == "push_front") {
			ll a;
			cin >> a;
			q.push_front(a);
			cout << "ok" << endl;
		} else if (s == "push_back") {
			ll a;
			cin >> a;
			q.push_back(a);
			cout << "ok" << endl;
		} else if (s == "pop_front") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop_front();
			} else cout << "error" << endl;
		} else if (s == "pop_back") {
			if (!q.empty()) {
				cout << q.back() << endl;
				q.pop_back();
			} else cout << "error" << endl;
		} else if (s == "front") {
			if (!q.empty()) cout << q.front() << endl;
			else cout << "error" << endl;
		} else if (s == "back") {
			if (!q.empty()) cout << q.back() << endl;
			else cout << "error" << endl;
		}else if (s == "size") cout << q.size() << endl;
		else if (s == "clear") {
			deque <ll> e;
			swap(q, e);
			cout << "ok" << endl;
		}
	} cout << "bye" << endl;
}