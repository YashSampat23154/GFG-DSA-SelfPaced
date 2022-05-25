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
    To calculate x^n;
*/

// Time Complexity : O(n)
ll countpower_naive(ll x, ll n){
    ll ans = x;
    for(int i = 2; i<=n ; i++){
        ans*=x;
    }
    return ans;
}

/*
    Recursive Approach : 

    One efficient approach is that we divide n into two parts even and odd and computer using the following concept : 
    
    if(n is even) ans = pow(x,n/2) * pow(x,n/2);
    else ans = pow(x,(n-1)/2) * x;

    We can futher simplify the else part. Since we know that the term n-1 will be even we can simplify it as : 

    if(n is even) ans = pow(x,n/2) * pow(x,n/2);
    else ans = pow(x,n/2) * pow(x,n/2) * x;

    Time Complexity : T(n) = T(n/2) + O(1) = O(log n)
    Space Complexity :  O(log n)
*/
ll countpower_efficient_recursive(ll x, ll n){
    if(n == 1) return x;
    ll temp =  countpower_efficient_recursive(x, n/2);
    if(n%2 == 0) return temp * temp;
    else return temp * x; 
}

/*
    Iterative Approach : 

    Idea : 
    Every number can be written as a sum of power of 2 (set bits in binary representation)
    We can traverse through all bits of a number (from LSB to MSB) in O(log n) time

    This method is also known as binary exponentiation.

    Time Complexity : O(log n)
    Space Complexity : O(1)
*/
ll countpower_efficient_iterative(ll x, ll n){
    ll temp = x, ans = 1;
    while(n!=0){
        if(n&1) ans*=temp;
        temp*=temp;
        n=n>>1;
    }
    return ans;
}

int main(){

    fastio;

    cout<<countpower_naive(2, 5)<<endl;
    cout<<countpower_efficient_recursive(3, 5)<<endl;
    cout<<countpower_efficient_iterative(3, 9)<<endl;
    

    return 0;
}
