#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

/*
    Find Factorial of a number 
*/
ll fact(ll n){
    if(n == 0) return 1;
    return n*fact(n-1);
}

int main(){

    fastio;

    cout<<fact(5)<<endl;

    return 0;
}
