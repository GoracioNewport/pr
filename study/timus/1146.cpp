#include <bits/stdc++.h>
using namespace std;
#define ll long long
<<<<<<< HEAD
<<<<<<< HEAD
 
=======

>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======

=======
 
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
int main() {
  ll n, m;
  cin >> n;
  m = n;
  vector <vector <ll>> a(n, vector <ll> (m));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
<<<<<<< HEAD
<<<<<<< HEAD
 
=======

>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======

=======
 
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
  vector <vector <ll>> prefSum(n, vector <ll> (m + 1));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      prefSum[i][j + 1] = prefSum[i][j] + a[i][j];
    }
  }
<<<<<<< HEAD
<<<<<<< HEAD
 
  ll ans = (ll)-2e18;
 
=======

  ll ans = (ll)-2e18;

>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======

  ll ans = (ll)-2e18;

=======
 
  ll ans = (ll)-2e18;
 
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
  for (ll l = 0; l < m; l++) {
    for (ll r = l; r < m; r++) {
      vector <ll> b(m);
      for (ll i = 0; i < n; i++) {
        b[i] = prefSum[i][r + 1] - prefSum[i][l];
      }

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
      // cout << l << ' ' << r << endl;
      // for (auto &i : b) {
      //   cout << i << ' ';
      // } cout << endl;
 
<<<<<<< HEAD
=======
>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
      ll locans = b[0];
      ll sum = 0;
      ll minSum = 0;
      for (ll r1 = 0; r1 < n; r1++) {
        sum += b[r1];
<<<<<<< HEAD
<<<<<<< HEAD
=======
        locans = max(ans, sum - minSum);
        minSum = min(minSum, sum);
      } ans = max(ans, locans);
    }
  } cout << ans << endl;

}
=======
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
        locans = max(locans, sum - minSum);
        minSum = min(minSum, sum);
      } 

      // cout << locans << endl;

      ans = max(ans, locans);
    }
  } cout << ans << endl;
 
}
<<<<<<< HEAD
=======
        locans = max(ans, sum - minSum);
        minSum = min(minSum, sum);
      } ans = max(ans, locans);
    }
  } cout << ans << endl;

}
>>>>>>> 3ea0f8c3a53376f9682af1b30d62f919759f2cdf
=======
>>>>>>> 687ac2dc6a6be5ff52518558462a7a29bf8e3088
>>>>>>> 4cedac459bab408b206c83f5a244494e5c8c244a
