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
    Naive method : Brute Force 

    Time Complexity : O(n^2)
*/
ll Odd_Occurring_naive(ll *arr, ll n){
    for(int i = 0; i<n; i++){
        ll count = 0;
        for(int j = 0 ; j<n; j++){
            if(arr[i] == arr[j]) count++;
        }
        if(count%2) return arr[i];
    }
}

/*
    We use the properties of XOR to find the odd occuring number.
    x^x = 0
*/
ll Odd_Occurring_efficient(ll *arr, ll n){
    ll ans = 0;
    for(int i = 0; i<n; i++)    ans^=arr[i];
    return ans;
}

int main(){

    fastio;

    ll arr1[] ={4,3,4,4,4,5,5};
    ll arr2[] ={8,3,3,7,7,8,8};
    cout<<Odd_Occurring_naive(arr1, 7)<<endl;
    cout<<Odd_Occurring_efficient(arr2, 7)<<endl;


    return 0;
}
