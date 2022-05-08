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


ll MAXN = 1e6;
v64 l, primes;

ll ans;

void f(vp64& a, ll i, vp64& selected, ll b, ll IN) { // selected - <num, cnt>
  if (i == a.size()) {
    ll c = 0, x = 1;
    for (auto& i : selected) {
      c += i.fi * i.se;
      x = (x * (ll)pow(i.fi, i.se));
    } if ((IN / x) <= b) ans = min(ans, c);
    return;
  } for (ll j = 0; j <= a[i].se; j++) {
    selected.push_back({a[i].fi, j});
    f(a, i + 1, selected, b, IN);
    selected.pop_back();
  }
}

bool ok(v64 a, ll x, ll k) {
  for (auto& i : a) {
    v64 divs;
    ll IN = i;
    while(i != 1) {
      divs.push_back(l[i]);
      i /= l[i];
    } unordered_map <ll, ll> cnt;
    for (auto& i : divs) cnt[i]++;
    vp64 z;
    for (auto& i : cnt) z.push_back(i);
    ans = INF;
    vp64 s;
    f(z, 0, s, x, IN);
    if (ans == INF) return false;
    k -= ans;
  } return k >= 0;
}

int main() {

  fastCin();


  l.resize(MAXN + 1);
  for (ll i = 2; i <= MAXN; i++) {
    if (l[i] == 0) {
      l[i] = i;
      primes.push_back(i);
    } for (auto& x : primes) {
      if (i * x > MAXN) break;
      l[i * x] = min(i, x);
    }
  } l[1] = 1;


  ll n, k;
  cin >> n >> k;
  v64 a(n);
  cin >> a;

  ll l = 0; // точно нет
  ll r = 1e6; // точно да
  while(l + 1 < r) {
    ll m = (l + r) / 2;
    if (ok(a, m, k)) r = m;
    else l = m;
  } cout << r << ln;


}