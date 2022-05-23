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
    Naive Approach : Brute Force

    Time Complexity : O(n^2)
*/
ll* Odd_Occurring_naive(ll *arr, ll n){
    static ll a[2];
    a[0] = 0;
    a[1] = 0; 
    ll k = 0;
    for(int i = 0; i<n; i++){
        ll count = 0;
        for(int j = 0 ; j<n; j++){
            if(arr[i] == arr[j]) count++;
        }
        if(count%2) a[k++] = arr[i];
    }
    return a;
}

/*
    Efficient Approach : 
    Step 1 : Ex-or all the values
    Step 2 : Whatever remains is the exor of the two odd occuring numbers.
    We know that if a bit is set in the result obtained, it indicates that both the numbers (used to obtain the result) have different values for that particular bit.
    Step 3 : Divide the array into two parts : One where that bit is set, another where the bit is unset/reset.
    Step 4 : Exor all elements of these two parts. Whatever elements are obtained at the end of these two parts are our final answer.

    Time Complexity : O(N)
*/
ll* Odd_Occurring_efficient(ll *arr, ll n){
    static ll a[2];
    a[0] = 0;
    a[1] = 0;
    // Step 1
    ll k = 0, xor_res = 0;
    for(int i =0; i<n ;i++) xor_res^= arr[i];
    // Step 2
    ll bit_changed = xor_res&~(xor_res-1);
    // Step 3 and 4
    for(int i =0; i<n ;i++){
        if(arr[i]&bit_changed) a[0]^=arr[i];
        else a[1]^=arr[i];
    }
    return a;
}


int main(){

    fastio;

    ll arr1[] ={4,3,4,4,4,5,5,5};
    ll arr2[] ={8,3,3,7,3,8,8,3};
    ll* res1 = Odd_Occurring_naive(arr1, 8);
    ll* res2 = Odd_Occurring_efficient(arr2, 8);
    cout<<res1[0]<<endl;
    cout<<res1[1]<<endl;
    cout<<res2[0]<<endl;
    cout<<res2[1]<<endl;

    return 0;
}