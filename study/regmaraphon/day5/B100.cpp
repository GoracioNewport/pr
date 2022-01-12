#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
  ll n;
  cin >> n;
  vector <pair <ll,ll>> p(n); // <height, price>
  for (int i = 0; i < n; i++) cin >> p[i].first;
  for (int i = 0; i < n; i++) cin >> p[i].second;
  sort(p.begin(), p.end());
  // for (auto &i : p) cout << i.first << ' ' << i.second << endl;
  vector <ll> dpL(n + 1, 0);
  vector <ll> dpR(n + 1, 0);
  vector <ll> dpS(n + 1, 0);
  for (int i = 0; i < n; i++) dpS[i + 1] = dpS[i] + p[i].second;
  for (int i = 0; i < n; i++) dpL[i + 1] = dpL[i] + (dpS[i] * abs(p[i].first - p[i - 1].first));
  reverse(p.begin(), p.end());
  // reverse(dpS.begin(), dpS.end());
  vector <ll> dpSR(n + 1, 0);
  for (int i = 0; i < n; i++) dpSR[i + 1] = dpSR[i] + p[i].second;
  for (int i = 0; i < n; i++) dpR[i + 1] = dpR[i] + (dpSR[i] * abs(p[i].first - p[i - 1].first));
  ll ans = 2e18;
  ll ind = -1;
  reverse(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    ll newAns = dpL[i + 1] + dpR[n - i];
    // cout << "CURRENT INDEX: " << i << endl;
    // cout << dpL[i + 1] << ' ' << dpR[n - i] << endl;
    // cout << newAns << endl;
    if (newAns <= ans) {
      ans = newAns;
      ind = p[i].first;
    }
    // ans = min(ans, dpL[i] + dpR[n - i + 1]);
  } cout << ind << ' ' << ans << endl;
  
  
  
  // for (auto &i : dpL) cout << i << ' ';
  // cout << endl;
  // for (auto &i : dpR) cout << i << ' ';
  // cout << endl;

}