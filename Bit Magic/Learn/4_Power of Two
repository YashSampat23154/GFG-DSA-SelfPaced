#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

/*
    Keep dividing number by 2. If at any point it becomes odd then no is a power of 2.
    If at the end it becomes 1 then no is power of 2

    Time Complexity : O(log n)
*/
bool power_of_2_naive(ll n){
    if(n == 0) return false;
    while(n!=1){
        if(n%2 != 0) return false;
        n = n/2;
    } 
    return true;   
}

/*
    If no is a power of 2 then it will have only 1 set bit.

    Time Complexity : O(1)
*/
bool power_of_2_efficient(ll n){
    return n!=0 && n&(n-1) == 0;
}

int main(){

    fastio;

    cout<<power_of_2_naive(4)<<endl;
    cout<<power_of_2_efficient(6)<<endl;

    return 0;
}
