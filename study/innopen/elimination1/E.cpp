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

void solveBig(ll n) {
  vp64 ans;

  vp64 c(n);

  multiset <p64> q;
  for (auto& i : c) cin >> i.fi;
  for (auto& i : c) cin >> i.se;
  for (auto& i : c) q.insert({i.fi, i.se});



  for (auto& i : c) cin >> i.fi >> i.se;


  for (auto& i : c) {
    p64 p = i;
    p64 k = {i.se, i.fi};

    auto itP = q.find(p);
    auto itK = q.find(k);

    if (itP != q.end()) {
      ans.pb(p);
      q.erase(itP);
    } else if (itK != q.end()) {
      ans.pb(k);
      q.erase(itK);
    } else {
      cout << "NO" << ln;
      return;
    }
  } cout << "YES" << ln;
  for (auto& i : ans) {
    cout << i.fi << ' ' << i.se << ln;
  }
}

int main() {
  fast_cin();

   ll n;
   cin >> n;
   if (n > 1) {
     solveBig(n);
     return 0;
   }

  vp64 c(n);
  multiset <ll> a, b;
   forn(i,n) {
     ll x;
     cin >> x;
     a.insert(x);
   } forn(i,n) {
    ll x;
    cin >> x;
    b.insert(x);
  }


   for (auto& i : c) cin >> i.fi >> i.se;



   for (ll i = 0; i < (1 << n); i++) {
     multiset <ll> A = a, B = b;
     bool good = true;
     for (ll j = 0; j < n; j++) {
       p64 q;
       if ((1 << j) & i) q = {c[j].se, c[j].fi};
       else q = c[j];

       auto it1 = A.find(q.fi);
       auto it2 = B.find(q.se);

       if (it1 == A.end() || it2 == B.end()) {
         good = false;
         break;
       } A.erase(it1);
       B.erase(it2);
     } if (!good) continue;
     cout << "YES" << ln;

     for (ll j = 0; j < n; j++) {
       p64 q;
       if ((1 << j) & i) q = {c[j].se, c[j].fi};
       else q = c[j];
       cout << q.fi << ' ' << q.se << ln;
     } return 0;
   } cout << "NO" << ln;

}