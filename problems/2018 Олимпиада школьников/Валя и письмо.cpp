#include <bits/stdc++.h>

using namespace std;


int main() {

    long long m,n,h,w;
    std::cin >> m >> n >> h >> w;

    long long m2=m,n2=n,h2=h,w2=w;



    int otvet = 0;
    while(m > h){
        h *= 2;
        otvet++;
    }
    while(n > w){
        w *= 2;
        otvet++;
    }

    int otvet2 = 0;
    while(m2 > w2){
        w2 *= 2;
        otvet2++;
    }
    while(n2 > h2){
        h2 *= 2;
        otvet2++;
    }
    cout << min(otvet, otvet2);

    return 0;
} 
