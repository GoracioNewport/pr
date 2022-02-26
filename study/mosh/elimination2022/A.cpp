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

int main() {
  fastCin();

  freopen("/mnt/hdd/pr/study/mosh/elimination2022/a2.txt", "r", stdin);
//  freopen("/mnt/hdd/pr/study/mosh/elimination/a0ans.txt", "w", stdout);

  vv64 bars = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
    {0, 0, 0, 0, 0, 0, 0} // null
  };

  vv64 cost(11, v64(11));

  for (ll i = 0; i < 11; i++) {
    for (ll j = 0; j < 11; j++) {
      forn(k,7) if (bars[i][k] != bars[j][k]) cost[i][j]++;
    }
  }

  ll n;
  cin >> n;
  vp64 q(n);

  forn(i,n) {
    cin >> q[i].fi;
    q[i].se = i;
  } sort(all(q));

  v64 Ans(n);

  ll ind = 0;

  ll cur = 0;

  ll ans = 0;

  while(true) {
    string prevS = to_string(cur);
    cur++;
    string curS = to_string(cur);

    reverse(all(prevS));
    reverse(all(curS));

    forn(i,max(sz(prevS), sz(curS))) {
      ll prevI, curI;
      if (i >= sz(prevS)) prevI = 10;
      else prevI = prevS[i] - '0';

      if (i >= sz(curS)) curI = 10;
      else curI = curS[i] - '0';

      ans += cost[prevI][curI];
    } while(q[ind].fi == cur) {
      Ans[q[ind].se] = ans;
      ind++;
      cout << ind << '/' << n << endl;
    } if (ind == n) break;
  } for (auto& i : Ans) cout << i << ln;

}