#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main(){
    ll a, b, d;
    cin >> a >> b >> d;

    if ((a+b) % 2 == 0){
    ll Min = min((abs((a+b)/2)) % d, d - ((abs((a+b)/2)) % d));
    cout << (a+b) / 2 << " " << Min;
    }

    else{
    ll N_1 = (a+b)/2, N_2;
    N_2 = N_1;

    if (a < b){
    if ((N_1 - b) < (a - N_1))
    N_2 += 1;
    else
    N_2 -= 1;
    }
    else{
    if((N_1 - a) < (b - N_1))
    N_2 +=1;
    else
    N_2 -= 1;
    }

    ll Min_1 = min(abs(N_1) % d, d - (abs(N_1) % d));
    ll Min_2 = min(abs(N_2) % d, d - (abs(N_2) % d));

    if (Min_1 > Min_2)
    cout << N_2 << " " << Min_2;
    else
    cout << N_1 << " " << Min_1;
    }
}