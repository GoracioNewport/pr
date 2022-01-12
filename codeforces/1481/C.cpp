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

        ll ma = 0;
        for (auto &i : b) ma = max(ma, i); // Максимум среди цветов, в который надо покрасить

        vector <stack <ll>> q(n, stack <ll> ()); // Это стеки для того, что бы каждый маляр мог покрасить максимально эффективно

        ll lastInd = -1;
        vector <ll> over(m); // over[i] = первый индекс >= i, который содержит цвет, который существует в исходной покраске. -1 если такого нет
        for (ll i = m - 1; i >= 0; i--) {
            if (c[i] <= ma) lastInd = i;
            over[i] = lastInd;
        }

        v64 ok(n, 0); // Ok[i] - покрашена ли доска в нужный цвет
        for (ll i = 0; i < n; i++) {
            if (a[i] != b[i]) q[b[i]].push(i);
            else ok[i] = 1;
        } 
        

        v64 inds(n, -1); // inds[i] = индекс, который указывает на цвет I. -1 если такого нет.
        for (ll i = 0; i < n; i++) inds[b[i]] = i;
        bool ans = true;
        v64 vans; // Массив ответа
        for (ll i = 0; i < m; i++) {
            if (q[c[i]].empty()) {
                if (inds[c[i]] == -1 && i == m - 1) {
                    ans = false;
                    break;
                } else if (inds[c[i]] == -1) {
                    if (inds[over[c[i]]] == -1) {
                        ans = false;
                        break;
                    } vans.pb(inds[over[c[i]]]);
                } else vans.pb(inds[c[i]]);
            } else {
                ll x = q[c[i]].top();
                q[c[i]].pop();
                vans.pb(inds[x]);
                ok[x] = 1;
            }
        } for (auto &i : ok) if (!i) ans = false;
        if (ans) {
            cout << "YES\n";
            for (auto &i : vans) cout << i + 1 << ' ';
            cout << ln;
        } else cout << "NO\n";
    }

}
