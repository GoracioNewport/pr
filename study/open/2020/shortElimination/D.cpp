#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1791791791;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vp64 cords;

bool solveLine(double x1, double y1, double x2, double y2) {
  double A = (y1 - y2);
  double B = (x2 - x1);
  double C = (x1 * y2 - x2 * y1);
  // cout << A << ' ' << B << ' ' << C << endl;
  for (auto &i : cords) {
    // cout << i.fi << ' ' << i.se << endl;
    if (A != 0) { // Влево-вправо
      double x = (-(B * (double)i.se) - C) / A;
      // cout << x << endl;
      if (A < 0) { // Ищем справа
        if ((i.fi - x) >= 0) return true;
      } else { // Ищем слева
        if ((i.fi - x) <= 0) return true;
      }
    } else { // Вверх-вниз
      double y = (-(A * (double)i.fi) - C) / B;
      // cout << y << endl;
      if (B < 0) {// Ищем снизу
        if ((i.se - y) >= 0) return true;
      } else { // Ищем сверху
        if ((i.se - y) <= 0) return true;
      }
    }
  } return false;
}

bool solveSquare(double x1, double y1, double x2, double y2) {
  double xM = ((x2 - x1) / 2) + x1;
  double yM = ((y2 - y1) / 2) + y1;
  double x3 = xM - (yM - y1);
  double y3 = yM + (xM - x1);
  double x4 = xM + (yM - y1);
  double y4 = yM - (xM - x1);

  // cout << xM << ' ' << yM << endl;
  // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;

  vector <pair <pdd,pdd>> p = {{{x1, y1}, {x3, y3}}, {{x3, y3}, {x2, y2}}, {{x2, y2}, {x4, y4}}, {{x4, y4}, {x1, y1}}};
  for (auto &j : cords) {
    vector <bool> ans;
    for (auto &i : p) {
      double X1 = i.fi.fi;
      double Y1 = i.fi.se;
      double X2 = i.se.fi;
      double Y2 = i.se.se;
      double A = (Y1 - Y2);
      double B = (X2 - X1);
      double C = (X1 * Y2 - X2 * Y1);
      // cout << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << endl;
      // cout << A << ' ' << B << ' ' << C << endl;
      if (A != 0) {
        double x = (-(B * j.se) - C) / A;
        if (A < 0) { // Ищем справа
          if ((j.fi - x) >= 0) ans.pb(true);
          else ans.pb(false);
        } else { // Ищем слева
         if ((j.fi - x) <= 0) ans.pb(true);
         else ans.pb(false);
        }
      } else if (B != 0) {
        double y = (-(A * j.fi) - C) / B;
        if (B < 0) {// Ищем снизу
          if ((j.se - y) >= 0) ans.pb(true);
          else ans.pb(false);
        } else { // Ищем сверху
          if ((j.se - y) <= 0) ans.pb(true);
          else ans.pb(false);
        }
      } else ans.pb(true);
    } bool f = true;
    // for (int i = 0; i < ans.size(); i++) {
    //   if (ans[i]) cout << 1 << ' ';
    //   else cout << 0 << ' ';
    // }
    // cout << endl;
    forn(i, sz(ans) - 1) {
      if (ans[i] != ans[i + 1]) f = false;
    } if (f) return true;
  } return false;
  // return true;
}

int main() {
  fast_cin();
  
  ll n, q;
  cin >> n >> q;
  cords.resize(n);
  for (auto &i : cords) cin >> i.fi >> i.se;
  forn(z,q) {
    ll t;
    double x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    bool ans;
    if (t == 1) ans = solveLine(x1, y1, x2, y2);
    else ans = solveSquare(x1, y1, x2, y2);

    if (ans) cout << "Yes\n";
    else cout << "No\n";
  }  

}
