#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> p64;
typedef vector <ll> v64;
typedef vector <ld> vdd;
typedef vector <v64> vv64;
typedef vector <p64> vp64;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define forn(i,e) for(ll i = 0; i < e; i++)
#define ln '\n'
#define fastCin() ios::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll INF = 2e18;
ld eps = 2e-12;
ll mod = 1791791791;

istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}

istream& operator>>(istream& in, vp64& a) {
  for (auto& i: a) in >> i.fi >> i.se;
  return in;
}

ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}

void solve(ll n, ll q) {
  v64 a(n);
  cin >> a;
  multiset <ll> p;
  for (auto& i : a) p.insert(i);

  while(q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      multiset <ll> newP;
      for (auto& i : p) newP.insert(i + 1);
      swap(p, newP);
    } else if (t == 2) {
      ll x; cin >> x;
      p.insert(x);
    } else {
      ll x; cin >> x;
      auto it = p.find(x);
      if (it != p.end()) p.erase(it);
    } ll res = 0;
    for (auto& i : p) res ^= i;
    cout << res << ln;
  }
}

int main() {

  fastCin();

  ll n, q;
  cin >> n >> q;
  if (n <= 100 && q <= 100) {
    solve(n, q);
    return 0;
  }

  v64 nums(101, 0);
  v64 a(n);
  for (auto& i : a) cin >> i;
  for (auto& i : a) nums[i]++;

  ll offset = 0;
  while(q--) {
    ll t; cin >> t;
    if (t == 1) offset++;
    else {
      ll x; cin >> x;
      if (x - offset >= 0 && x - offset <= 100 && nums[x - offset] > 0) nums[x - offset]--;
    } ll res = 0;
    forn(i,101) {
      if (nums[i] % 2) {
        res ^= (i + offset);
      }
    } cout << res << ln;
  }



}