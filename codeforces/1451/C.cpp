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
  for (ll z = 0; z < t; z++) {
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector <ll> rawA;
    vector <ll> rawB;
    for (ll i = 0; i < n; i++) rawA.push_back(a[i] - 'a');
    for (ll i = 0; i < n; i++) rawB.push_back(b[i] - 'a');
    sort(all(rawA));
    sort(all(rawB));
    // for (auto &i : rawA) cout << i << " ";
    // cout << endl;
    // for (auto &i : rawB) cout << i << " ";
    // cout << endl;
    ll l = 0, r = 0;
    vector <ll> A;
    vector <ll> B;
    while ((l < n) && (r < n)) {
      if (rawA[l] != rawB[r]) {
        A.pb(rawA[l]);
        B.pb(rawB[l]);
        l++; r++;
      } else {
        if (rawA[l] > rawB[r]) r++;
        else l++;
      }
    }

    // for (auto &i : A) cout << i << " ";
    // cout << endl;
    // for (auto &i : B) cout << i << " ";
    // cout << endl;

    n = A.size();

    bool f = true;
    if (k == 1) {
      for (int i = 0; i < n; i++) {
        if (A[i] > B[i]) f = false;
      }
    }
    for (int i = 0; i < n; i += k) {
      for (int j = i; j < i + k - 1; j++) {
        // cout << j << endl;
        if ((A[j] != A[j + 1]) || (B[j] != B[j + 1]) || (A[j] > B[j])) f = false;
      }
    } if (f) cout << "Yes\n";
    else cout << "No\n";

  }  

}
