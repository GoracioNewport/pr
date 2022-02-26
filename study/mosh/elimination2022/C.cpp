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

ll n;

v64 powers;

typedef tree<
    p64,
    null_type,
    less<p64>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

vv64 getT(p64 a) {
  vv64 ans(n, v64(n));

  ll f = ((n / 2) * n);
  for (ll i = 0; i < (n / 2); i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a.fi >= powers[f]) {
        ans[i][j] = 1;
        a.fi -= powers[f];
      }
    }
  } f = n * n - ((n / 2) * n);

  for (ll i = (n / 2); i < n; i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a.se >= powers[f]) {
        ans[i][j] = 1;
        a.se -= powers[f];
      }
    }
  } return ans;

}

p64 getP(vv64 a) {

  p64 ans = {0, 0};

  ll f = ((n / 2) * n);
  for (ll i = 0; i < (n / 2); i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a[i][j]) ans.fi += powers[f];
    }
  } f = n * n - ((n / 2) * n);

  for (ll i = (n / 2); i < n; i++) {
    for (ll j = 0; j < n; j++) {
      f--;
      if (a[i][j]) ans.se += powers[f];
    }
  } return ans;
};


int main() {
  fastCin();


  freopen("/mnt/hdd/pr/study/mosh/elimination2022/c0.txt", "r", stdin);
//  freopen("/mnt/hdd/pr/study/mosh/elimination/a0ans.txt", "w", stdout);

  powers.resize(60);
  powers[0] = 1;
  forsn(i,1,60) powers[i] = powers[i - 1] * 2;

  ll t;
  cin >> t;
  while(t--) {
    cin >> n;
    vv64 p(n, v64(n));
    cin >> p;

    ordered_set visited;

    queue <p64> q1, q2;
    q1.push({0, 0});
    q2.push(getP(p));

    visited.insert({0, 0});
    visited.insert(getP(p));

    ll step = 0;

    const ll MAX_STEP = 4;

    while(true) {
      if (step >= MAX_STEP) {
        cout << "Answer Not Found :(" << endl;
        break;
      } cout << "Step №" << ++step << "..." << endl;



    }


  }

}