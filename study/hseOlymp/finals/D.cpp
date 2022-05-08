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
int main() {

  fastCin();

  ll n;
  cin >> n;
  vector <string> a(n), b(n);
  for (auto& i : a) cin >> i;
  forn(i,n) {
    b[i] = a[i];
    reverse(all(b[i]));
  }

  v64 ans(n, INF);
  forn(i,n) {
    p64 M = {0, 0};
    forn(j,n) {
      if (i == j) continue;
      ll ind = 0;
      while(ind < a[i].size() && ind < a[j].size() && a[i][ind] == a[j][ind]) ind++;
      ll ind1 = 0;
      while(ind1 < b[i].size() && ind1 < b[j].size() && b[i][ind1] == b[j][ind1]) ind1++;
      M = max(M, {min(ind + ind1, (ll)min(a[i].size(), a[j].size())), j});
    } ans[i] = M.se + 1;
  } cout << ans << ln;


}