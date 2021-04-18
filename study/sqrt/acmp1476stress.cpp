// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct block {
  ll len;
  ll seg;
  ll sum;
};

ll ans = 0;
const ll n = 1e5 + 20;
const ll len = sqrt(n) + 1;
vector <block> sd(n / len + 1, {len, 0, 0});
vector <ll> aStupid(n, 0);
v64 a(n, 0);


void modify(ll l, ll x) {
  ll r = n - 1;
  for(ll i = l; i <= r;) {
    if (i % len == 0 && i + len <= (r - 1)) {
      if (x == sd[i / len].seg) {
        if (x) {
          sd[i / len].seg = 0;
          sd[i / len].sum = 0;
          ans -= sd[i / len].len;
        } else {
          sd[i / len].seg = 1;
          sd[i / len].sum = sd[i / len].len;
          ans += sd[i / len].len;
        }
      } else if (sd[i / len].seg != INF) {
        sd[i / len].seg = INF;
        a[i] = x;
        if (x) {
          sd[i / len].sum++;
          ans++;
        } else {
          sd[i / len].sum--;
          ans--;
        } return;
      } else {   
        sd[i / len].seg = INF;
        ll l1 = (i / len) * len;
        ll r1 = l1 + sd[i / len].len - 1;
        for(ll i = l1; i <= r1; i++) {
          if (a[i] == x) {
            a[i] = !x;
            if (x) {
              sd[i / len].sum--;
              ans--;
            } else {
              sd[i / len].sum++;
              ans++;
            }
          } else {
            a[i] = !a[i];
            if (x) {
              sd[i / len].sum++;
              ans++;
            } else {
              sd[i / len].sum--;
              ans--;
            } return;
          }
        }
      } i += len;
    } else {
      sd[i / len].seg = INF;
      if (a[i] == x) {
        a[i] = !x;
        if (x) {
          sd[i / len].sum--;
          ans--;
        } else {
          sd[i / len].sum++;
          ans++;
        }
      } else {
        a[i] = !a[i];
        if (x) {
          sd[i / len].sum++;
          ans++;
        } else {
          sd[i / len].sum--;
          ans--;
        } return;
      } i++;
    }
  }
}

int main() {
  // fast_cin();

  while(true) {

		ll q = (rng() % 100) + 1;
		cout << "-------------\n" << q << ln;
		sd.assign(n / len + 1, {len,0,0});
		sd.back() = {n - (sz(sd) - 1) * len, INF, 0};
		a.assign(n, 0);
		aStupid.assign(n, 0);
		ans = 0;

		// for (auto &i : sd) cout << i.len << ' ' << i.seg << ' ' << i.sum << ln;
		// for (auto &i : a) cout << i << ' ';
		// cout << endl;

		while(q--) {

		  ll t = (rng() % 2);


		  ll maxO = INF;
		  ll cntO = 0;
		  for(ll i = 0; i < n; i++) {
		  	if (a[i] == 1) {
		  		maxO = i;
		  		cntO++;
		  	}
		  }



		  ll l = (rng() % 1000) + 1;
		  if (!t && (cntO < 1 || maxO < l)) t = !t;
		  
		  if (t) cout << "add ";
		  else cout << "sub ";

		  cout << l << ln;
		  // cin >> cmd >> l;
		  ll x = t;
		  modify(l, x);
		  // cout << ans << ln;
		  
		  // for (auto &i : a) cout << i << ' ';
		  // cout << ln;

		  for (ll i = l; i < n; i++) {
		  	if (aStupid[i] == x) aStupid[i] = !aStupid[i];
		  	else {
		  		aStupid[i] = !aStupid[i];
		  		break;
		  	}
		  } ll ansStupid = 0;
		  for (auto &i : aStupid) if (i) ansStupid++;

		  for (auto &i : sd) {

		    // cout << i.len << ' ' << i.sum << ' ' << i.seg << ln;
 	
		    if (i.sum == 0) i.seg = 0;
		    else if (i.sum == i.len) i.seg = 1;
		  }

		  if (ans != ansStupid) {
		  	cout << "COUNTERTEST FOUND" << ln;
		  	cout << ans << ' ' << ansStupid << ln;
		  	return(0);
		  }



		} 


  }

}
