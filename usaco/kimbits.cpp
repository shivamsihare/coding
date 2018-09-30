/*
ID: sihare11
TASK: kimbits
LANG: C++                 
*/


#include <bits/stdc++.h>

using namespace std;

long long getQthNumber(long long n, long long l, long long q, long long curValue) {
    if (n == l) return q;
   if (n-l == 1) {
       curValue<<=n;
       curValue+=((1<<n) - 1);
       if (q < curValue) {
           return q;
       } else {
           return q + 1;
       }
   }
   if (l == 0) {
       curValue<<=n;
       if (q <= curValue) {
           return q;
       } else {
           return q + ((1<<n) - 1);
       }
   }
   curValue<<=1;
   q = getQthNumber(n-1, l, q, curValue);
   curValue++;
   return getQthNumber(n-1, l-1, q, curValue);
}

int main() {
    //freopen("input.txt", "r", stdin);
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    long long n,l,q;
    cin>>n>>l>>q;
    //cout<<q<<endl;
    bitset<32> res(getQthNumber(n,l,q-1,0));
    cout<<res.to_string().substr(32 - n)<<endl;
    return 0;
}
