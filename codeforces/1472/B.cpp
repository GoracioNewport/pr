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

int main() {
  fast_cin();
  
  ll t;
  cin >> t;
  forn(z,t) {
    ll n;
    cin >> n;
    v64 c(n);
    ll cnto = 0;
    ll cntt = 0;
    for (auto &i : c) {
      ll a;
      cin >> a;
      if (a == 1) cnto++;
      else cntt++;
    } ll cnttO = cntt;
    ll cntoO = cnto;

    bool ans1, ans2, ans3, ans4, ans5, ans6 = true;
    
    cntt = cnttO;
    cnto = cntoO;
    while (cnto >= 2 && cntt >= 1) {
      cnto -= 2;
      cntt--;
    } 
    while (cntt >= 2) {
      cntt -= 2;
    } 
    while (cnto >= 2) {
      cnto -= 2;
    } 
    ans1 = (cntt % 2 == 0 && cnto % 2 == 0);

    cntt = cnttO;
    cnto = cntoO;
    while (cntt >= 2) {
      cntt -= 2;
    } 
    while (cnto >= 2 && cntt >= 1) {
      cnto -= 2;
      cntt--;
    } 
    while (cnto >= 2) {
      cnto -= 2;
    } 
    ans2 = (cntt % 2 == 0 && cnto % 2 == 0);

    cntt = cnttO;
    cnto = cntoO;
    while (cntt >= 2) {
      cntt -= 2;
    } 
    while (cnto >= 2) {
      cnto -= 2;
    } 
    while (cnto >= 2 && cntt >= 1) {
      cnto -= 2;
      cntt--;
    } 
    ans3 = (cntt % 2 == 0 && cnto % 2 == 0);

    cntt = cnttO;
    cnto = cntoO;
    while (cnto >= 2 && cntt >= 1) {
      cnto -= 2;
      cntt--;
    } 
    while (cnto >= 2) {
      cnto -= 2;
    } 
    while (cntt >= 2) {
      cntt -= 2;
    } 
    ans4 = (cntt % 2 == 0 && cnto % 2 == 0);

    cntt = cnttO;
    cnto = cntoO;
    while (cnto >= 2) {
      cnto -= 2;
    } 
    while (cnto >= 2 && cntt >= 1) {
      cnto -= 2;
      cntt--;
    } 
    while (cntt >= 2) {
      cntt -= 2;
    } 
    ans5 = (cntt % 2 == 0 && cnto % 2 == 0);

    cntt = cnttO;
    cnto = cntoO;
    while (cnto >= 2) {
      cnto -= 2;
    } 
    while (cntt >= 2) {
      cntt -= 2;
    } 
    while (cnto >= 2 && cntt >= 1) {
      cnto -= 2;
      cntt--;
    } 
    ans6 = (cntt % 2 == 0 && cnto % 2 == 0);

    if (ans1 || ans2 || ans3 || ans4 || ans5 || ans6) cout << "YES\n";
    else cout << "NO\n";

    

  }  

}
