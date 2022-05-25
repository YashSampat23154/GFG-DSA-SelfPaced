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
    Permutation : Permutation is defined as arrangement of r things that can be done out of total n things.
    It is denoted by nPr which is equal to n!/(n-r)! 

    Combination : Combination is defined as selection of r things that can be donw out of total n things. 
    This is denoted by nCr, which is equal to n!/r!(n-r)!s
*/

ll Permutation(ll n, ll r){
    ll ans = 1; 
    while(r--){
        ans*=n--;
    }
    return ans; 
}

double Combination(ll n, ll r){
    ll num = 1, denom = 1; 
    if(r>n-r) r = n-r;
    while(r){
        num*=n--;
        denom*=r--; 
    }
    return num/(double)denom; 
}

int main(){

    fastio;

    cout<<Permutation(10,3)<<endl;
    cout<<Combination(10,3)<<endl;

    return 0;
}
