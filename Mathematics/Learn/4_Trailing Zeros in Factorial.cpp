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
    To calculate the no of trailing zero of any factorial.
*/

ll Factorial_iterative(int n){
    ll ans = 1;
    while(n){
        ans = ans*n--;
    }
    return ans;
}

// Time Complexity : O(n)
// Main issue is that it will cause overflow for slightly higher values of n for eg n = 20
int Trailing_Zero_in_Factorial_naive(ll n){
    ll fact = Factorial_iterative(n);
    int ans = 0;
    while(fact%10 == 0){
        ans++;
        fact/=10;
    }
    return ans;
}

// Time Complexity : O(log5(n))
int Trailing_Zero_in_Factorial_efficient(ll n){
    ll temp = n;
    int ans = 0;
    while(temp!=0){
        ans+= temp/5;
        temp/=5;
    }
    return ans;
}

int main(){

    fastio;

    cout<<Trailing_Zero_in_Factorial_naive(5)<<endl;    
    cout<<Trailing_Zero_in_Factorial_naive(10)<<endl; 

    cout<<Trailing_Zero_in_Factorial_efficient(100)<<endl;
    cout<<Trailing_Zero_in_Factorial_efficient(130)<<endl;
    cout<<Trailing_Zero_in_Factorial_efficient(251)<<endl;           

    return 0;
}