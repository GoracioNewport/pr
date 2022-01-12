// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    set <p64> leftW, rightW, leftB, rightB, LeftW, RightW, LeftB, RightB;
    vp64 r(n);
    for (auto &i : r) cin >> i.fi;
    for (auto &i : r) {
      char c;
      cin >> c;
      if (c == 'R') i.se = 1;
      else i.se = 0;
    } ll ind = 0;
    for (auto &i : r) {
      if (i.se) {
        if (i.fi % 2) rightB.insert({i.fi, ind++});
        else rightW.insert({i.fi, ind++});
      }
      else {
        if (i.fi % 2) leftB.insert({i.fi, ind++});
        else rightW.insert({i.fi, ind++});
      }
    }



    v64 ans(n, -1);

    // LEFT BLACK - MATCH RIGHT BLACK, ELSE LEFT BLACK
    LeftB = leftB;
    for (auto &i : LeftB) {
      auto closest = prev(rightB.lower_bound(i));

      if (closest == prev(rightB.begin())) { // MIRROR
        auto nex = leftB.upper_bound(i);
        if (nex == leftB.end()) break;
        ll t = (i.fi + (*nex).fi) / 2;
        ans[i.se] = t;
        ans[(*nex).se] = t;
        leftB.erase(leftW.find(i));
        leftB.erase(nex);
      } else {
        ll t = abs(i.fi - (*closest).fi) / 2;
        ans[i.se] = t;
        ans[(*closest).se] = t;
        leftB.erase(leftW.find(i));
        rightB.erase(closest);
      }
    }

    // LEFT WHITE - MATCH RIGHT WHITE, ELSE LEFT WHITE
    LeftW = leftW;
    for (auto &i : LeftW) {
      auto closest = prev(rightW.lower_bound(i));

      if (closest == prev(rightW.begin())) { // MIRROR
        auto nex = leftW.upper_bound(i);
        if (nex == leftW.end()) break;
        ll t = (i.fi + (*nex).fi) / 2;
        ans[i.se] = t;
        ans[(*nex).se] = t;
        leftW.erase(leftW.find(i));
        leftW.erase(nex);
      } else {
        ll t = abs(i.fi - (*closest).fi) / 2;
        ans[i.se] = t;
        ans[(*closest).se] = t;
        leftW.erase(leftW.find(i));
        rightW.erase(closest);
      }
    }

    cout << "FUCK" << endl;

    // RIGHT BLACK - MATCH LEFT BLACK, ELSE RIGHT BLACK
    RightB = rightB;
    for (auto i = RightB.rbegin(); i != RightB.rend(); i++) {
      auto closest = leftB.upper_bound(*i);

      if (closest == leftB.end()) { // MIRROR
        auto nex = prev(i);
        if (i == rightB.rend()) break;
        ll t = ((*i).fi + (*nex).fi) / 2;
        ans[(*i).se] = t;
        ans[(*nex).se] = t;
        rightB.erase(*i);
        rightB.erase(*nex);
      } else {
        ll t = abs((*i).fi - (*closest).fi) / 2;
        ans[(*i).se] = t;
        ans[(*closest).se] = t;
        rightB.erase(*i);
        leftB.erase(*closest);
      }
    }

    cout << "SHIT" << endl;

    // RIGHT WHITE - MATCH LEFT WHITE, ELSE RIGHT WHITE
    RightW = rightW;
    for (auto i = RightW.rbegin(); i != RightW.rend(); i++) {
      auto closest = leftW.upper_bound(*i);

      if (closest == leftW.end()) { // MIRROR
        auto nex = prev(i);
        if (i == rightW.rend()) break;
        ll t = ((*i).fi + (*nex).fi) / 2;
        ans[(*i).se] = t;
        ans[(*nex).se] = t;
        rightW.erase(*i);
        rightW.erase(*nex);
      } else {
        ll t = abs((*i).fi - (*closest).fi) / 2;
        ans[(*i).se] = t;
        ans[(*closest).se] = t;
        rightW.erase(*i);
        leftW.erase(*closest);
      }
    } for (auto &i : ans) cout << i << ' ';
    cout << ln;
  }

}