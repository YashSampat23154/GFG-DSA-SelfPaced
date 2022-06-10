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
    Find sum of N natural numbers

    Time Complexity : O(n)
    T(n) = T(n-1) + O(1)
    Auxillary Space : O(n)
*/
ll sum_till_N(ll n){
    if(n == 1) return 1;
    return n+sum_till_N(n-1);
}

int main(){

    fastio;

    cout<<sum_till_N(5)<<endl;

    return 0;
}