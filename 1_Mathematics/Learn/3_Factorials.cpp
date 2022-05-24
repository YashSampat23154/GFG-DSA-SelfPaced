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
    Factorial of a positive interger n, denoted by n!, is the product of all positive numbers less than or equal to n

    Eg : Fact(5) = 120

    0! = 1

*/

// Time Complexity : O(n); Space Complexity : O(1)
ll Factorial_iterative(int n){
    ll ans = 1;
    while(n){
        ans = ans*n--;
    }
    return ans;
}

// Time Complexity : O(n); Space Complexity : O(n)
// Recurrence Relation : T(n) = T(n-1) + O(1)
ll Factorial_recursive(int n){
    if(n == 0) return 1;
    else return n*Factorial_recursive(--n);
}

int main(){

    fastio;

    cout<<Factorial_iterative(5)<<endl;
    cout<<Factorial_recursive(5)<<endl;

    return 0;
}
