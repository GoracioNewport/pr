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
        v64 a(n); // Массив исходных покрасок
        v64 b(n); // Как надо покрасить
        v64 c(m); // В какой цвет каждый маляр покарсит
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        for (auto &i : c) cin >> i;
        for (auto &i : a) i--;
        for (auto &i : b) i--;
        for (auto &i : c) i--;

        vector <stack <ll>> q(n, stack <ll> ());
        v64 used(n, 0);
        for (auto &i : b) used[i] = 1;
        v64 ok(n, 0);
        for (ll i = 0; i < n; i++) { 
            if (a[i] != b[i]) q[b[i]].push(i);
            else ok[i] = 1;
        } ll lastInd = -1;
        v64 over(m); // over[i] - такой индекс, что он >= i и мы его в последствии перекрасим
        for (ll i = m - 1; i >= 0; i--) {
            if (used[c[i]]) lastInd = i;
            over[i] = lastInd;
        } v64 last(n, -1);
        for (int i = 0; i < n; i++) last[b[i]] = i;

        // for (auto &i : over) cout << i << ' ';
        // cout << ln;

        bool ans = true;
        v64 ansv;

        for (ll i = 0; i < m; i++) {
            // cout << "-----" << i << "-----" << endl;
            if (!q[c[i]].empty()) {
                // cout << "Not empty" << ln;
                ll x = q[c[i]].top();
                // cout << "Putting to " << x << ln;
                q[c[i]].pop();
                ok[x] = 1;
                ansv.pb(x);
            } else {
                // cout << "Empty" << endl;
                if (last[c[i]] != -1) {
                    // cout << "Last" << endl;
                    ll x = last[c[i]];
                    ok[x] = 1;
                    ansv.pb(x);
                } else if (over[i] != -1) {
                    // cout << "Over" << endl;
                    ll x = 1e9 + over[i];
                    ansv.pb(x);
                } else {
                    // cout << "No" << endl;
                    ans = false;
                     break;
                }
            }
        } for (auto &i : ok) if (i == 0) ans = false;
        if (ans) {
            cout << "YES\n";
            for (auto &i : ansv) {
                if (i < 1e9) cout << i + 1 << ' ';
                else cout << ansv[i - 1e9] + 1 << ' ';
            } cout << ln;
        } else cout << "NO\n";
        
    }

}
