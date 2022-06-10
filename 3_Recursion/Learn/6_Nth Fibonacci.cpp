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
    Find the Nth fibonanci no
*/
ll fibonacci(ll n){
    if(n == 0 || n == 1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){

    fastio;

    cout<<fibonacci(5)<<endl;

    return 0;
}