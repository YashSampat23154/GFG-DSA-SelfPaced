#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

// struct Values{
// int x;
// };

using namespace std;

// Time Complexity : O(d) where d is no of digits
int Countdigits_1(int n){
    int count = 0;
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}

// Time Complexity : O(d) where d is no of digits
// Space Complexity : O(d) where d is no of digits
int Countdigits_2(int n){
    if(n == 0)
        return 0;
    else
        return 1+Countdigits_2(n/10);
}

// Time Complexity : O(1)
int Countdigits_3(int n){
    return ceil(log10(n+1));
}

int main(){

    fastio;

    cout<<Countdigits_1(99)<<endl;
    cout<<Countdigits_2(100)<<endl;
    cout<<Countdigits_3(101)<<endl;

    return 0;
}
