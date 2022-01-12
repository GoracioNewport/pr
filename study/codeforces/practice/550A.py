#include<bits/stdc++.h>
using namespace std;
char s[200005], *a;
 
int main(){
//      пояснение strstr(s, "AB") = s.find("AB") 
	cin >> s;
	if((a = strstr(s, "AB")) && strstr(a + 2, "BA"))
		cout << "YES" << '\n';
	else if((a = strstr(s, "BA")) && strstr(a + 2, "AB")) 
		cout << "YES" << '\n';
	else 
		cout << "NO" << '\n';
	return 0;
  