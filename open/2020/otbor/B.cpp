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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
    fast_cin();

    ll n, m, k;
    cin >> n >> m >> k; // n - кол-во работ, m - общее кол-во проверяющих, k - минимальное кол-во людей, которые должны проверить, a - высота матрицы
    vector <ll> teachers(m);
    forn(i, m) teachers[i] = i + 1;

    ll a = ceil((double)(n * k) / m);
    ll beginInd = -1;

    // cout << n << ' ' << a << endl;

    vv64 p(a, v64 (n, 0));
    // cout << "Shit" << endl;
    forn(i,a) {
    	// cout << beginInd << endl;
    	if (beginInd == 0) rotate(teachers.begin(), teachers.begin() + 1, teachers.end());
    	else if (beginInd == -1) beginInd = 0;
    	ll localInd = 0;
    	forsn(j, beginInd, min(n, beginInd + m)) {
    		p[i][j] = teachers[localInd];
    		localInd++;
    	} if (localInd < m) {
    		ll localInd2 = localInd;
    		forn(j, (m - localInd)) {
    			// cout << i << ' ' << j << ' ' << localInd << ' ' << m <<  endl;
    			p[i][j] = teachers[localInd2];
    			localInd2++;
    		}
    	} 
    	beginInd = (beginInd + m) % n;
    } cout << a << endl;
    for (auto &i : p) {
    	for (auto &j : i) cout << j << ' ';
    	cout << endl;

}
