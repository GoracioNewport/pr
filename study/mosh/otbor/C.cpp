//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

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

enum { PARTY, TEST };

struct Event {
    ll type;
    ll date;
    ll i;
    ll result;
    v64 guests;

    bool operator <(Event &o) {
      if (date != o.date) return date < o.date;
      else return type > o.type;
    }
};

int main() {
//  fast_cin();

  ifstream in;
  ofstream out;
  in.open("C:/Users/bdfyl/CLionProjects/cf/mosh/otbor/c2.txt");
  out.open("C:/Users/bdfyl/CLionProjects/cf/mosh/otbor/c2ans.txt");
  ll t;
  in >> t;
  ll test = 1;
  while(t--) {
    cout << "Start Test " << test++ << "... ";

    ll n, m, k, a, b;
    in >> n >> m >> k >> a >> b;
    vector <Event> e;
    forn(i,m) {
      ll d, v;
      in >> d >> v;
      v64 g(v);
      for (auto &i : g) {
        in >> i;
        i--;
      }
      e.pb({PARTY, d, v, 0, g});
    } forn(i,k) {
      ll p, u, r;
      in >> p >> u >> r;
      e.pb({TEST, p, u - 1, r, {}});
    } sort(all(e));
//    for (auto &i : e) {
//      cout << i.type << ' ' << i.date << ln;
//    }
    p64 ans = {-1, -1};
    ll maxCase = 0;
    forn(z,n) { // Перебираем нулевого пациента
      // Теперь надо найти первую дату, когда он поучаствовал в чем-то.
      ll mi = INF;
      for (auto &i : e) {
        if (i.type == PARTY) for (auto &j : i.guests) if (j == z) mi = min(mi, i.date);
        else if (i.i == z) mi = min(mi, i.date);
      } if (mi == INF) continue;
      forsn(start, max((ll)0,mi - b), mi + 1) { // Перебираем дату начала
//        cout << z + 1 << ' ' << start << ln;
        vp64 status(n, {INF, start});
        status[z].fi = b;
        ll okCases = k;
        for (auto &event : e) {
          ll t = event.date;
          if (t < start) continue;
          for (auto &i : status) {
            if (i.fi != INF && i.fi != -1) {
              i.fi -= (t - i.se);
              if (i.fi <= 0) i.fi = -1;
              i.se = t;
            }
          } if (event.type == PARTY) {
            bool infected = false;
            for (auto &i : event.guests) if (status[i].fi <= (b - a) && status[i].fi > 0) infected = true;
            if (infected) for (auto &i : event.guests) if (status[i].fi == INF) status[i] = {b, t};
          } else {
            // date, i, result - дата, номер, результат
            bool result = false;
            if (status[event.i].fi != INF && status[event.i].fi != -1) result = true;
            if (result != event.result) {
//              cout << "Fail at T " << t << ln;
//              cout << "Number " << event.i + 1 << ' ' << status[event.i].fi << ' ' << status[event.i].se << ln;
//              cout << "Expected " << event.result << ", got " << result << ln;
              okCases--;
            }
          }
        } if (okCases > maxCase) {
          maxCase = okCases;
          ans = {z, start};
        }
      }
    } if (ans.fi == -1) out << "1 1";
    else out << ans.fi + 1 << ' ' << ans.se;
    out << ln;

    cout << "Done, Case Match: " << maxCase << "/" << k << ln;
  } in.close();
  out.close();

}