#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	vector <vector<int> > dist(n + 1, vector<int> (n+1,0));
	for (int i = 0; i <= n; i++) {
		dist[i][0] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < dist[i].size(); j++){
			if (j - i >= 0){
				dist[i][j] = dist[i - 1][j]+dist[i - 1][j - i];
			}else{
			 	dist[i][j] = dist[i - 1][j];
			 }
		}
	}
	cout<<dist[n][n];
}
