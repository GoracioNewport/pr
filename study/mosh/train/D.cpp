// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
// Author: @GoracioNewport
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;
 
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}
 
istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}
 
istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}
 
istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}
 
ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}
 
ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}
 
ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}
 
ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}
 
ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;

ll charToLong(char a, char b) {
  return (a - '0') * 10 + (b - '0');
}

bool can(string& s, vector <bool>& used) {
  ll n = s.size();

  bool one = true, two = used[s[0] - '0'];

  for (ll i = 2; i <= n; i++) {

    bool cur = false;
    if (one + two == 0) return false;

    if (two && used[s[i - 1] - '0']) cur = true;
    if (s[i - 2] == '0') continue;
    if (one && used[charToLong(s[i - 2], s[i - 1])]) cur = true;

    one = two;
    two = cur;

  } return two;
}

bool comp(pair <string, pair <v64, ll>>& a, pair <string, pair <v64, ll>>& b) {
  return a.se.fi.size() < b.se.fi.size();
}

v64 ans;

void f(v64& selected, vector <bool>& used, v64& pos, string& s, ll len, ll d = 0) {
  if (d > len) return;
  if (can(s, used)) { 
    if (selected.size() < ans.size()) ans = selected;
    return;
  } for (ll i = 0; i < pos.size(); i++) {
    if (used[pos[i]]) continue;

    used[pos[i]] = true;
    selected.pb(pos[i]);
    f(selected, used, pos, s, len, d + 1);
    used[pos[i]] = false;
    selected.pop_back();
  }
}

int main() {
  fastCin();

  freopen("d2.txt", "r", stdin);
  freopen("d2ans.txt", "w", stdout);
 

	ll t;
	cin >> t;
  vector <pair <string, pair <v64, ll>>> q(t);

  vector <v64> Ans(t);

	forn(z,t) {
		string s;
		cin >> s;
		v64 pos, posS;

    ll n = sz(s);

    forn(i,n - 1) {
      pos.pb(charToLong(s[i], s[i + 1]));
      pos.pb(s[i] - '0');
      posS.pb(s[i] - '0');
    } pos.pb(s.back() - '0');
    posS.pb(s.back() - '0');
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    sort(all(posS));
    posS.erase(unique(all(posS)), posS.end());

    // cout << sz(pos) << ln;

    Ans[z] = {posS};

    q[z] = {s, {pos, z}};
	} sort(all(q), comp);

  ll cnt = 0;

  ll LIMIT = 2e6;

  for (auto& z : q) {

    // if (GetAsyncKeyState(VK_ESCAPE)) break;

    for (ll len = 1; len <= 5; len++) {

      // if ((ll)pow(z.se.fi.size(), len) * z.fi.size() > LIMIT) break;

      vector <bool> used(100);
      ans.clear();
      ans.resize(100);

      // for (auto& i : z.se.fi) used[i] = true;

      v64 selected, pos;
      f(selected, used, z.se.fi, z.fi, len);
      if (ans.size() != 100) {
        Ans[z.se.se] = ans;
        cout << "TEST №" << ++cnt << ", size: " << z.se.fi.size() << endl;
        // cnt++;
        break;
      } 
    } if (cnt > 300) break;
  }

  for (auto& i : Ans) {
    cout << i.size() << ln;
    for (auto& j : i) cout << j << ' ';
    cout << ln << ln;
  }
 
}

