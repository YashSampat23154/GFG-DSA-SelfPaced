#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

/*
    Given an array of integers, find if it has a equilibrium point.

    Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
void equilibrium_index_naive(int* arr, int n){
    int lval = 0, rval = 0;
    bool ans = false;
    for(int i = 0; i<n; i++){
        lval = 0;
        for(int j = 0; j<i; j++) lval += arr[j];

        rval = 0;
        for(int j = i+1; j<n; j++) rval += arr[j];

        if(lval == rval) ans = true;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

// Time Complexity : O(n)
// Auxillary Space : O(n)
void equilibrium_index_efficient1(int* cum, int n){
    if(cum[n-1] - cum[0] == 0){
        cout<<"YES"<<endl;
        return;
    }
    bool ans = false;
    for(int i = 1; i<n; i++){
        if(cum[i-1] == cum[n-1]-cum[i]) ans = true;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
bool equilibrium_index_efficient2(int* arr, int n){
    int csum = 0;
    for(int i = 0; i<n; i++) csum+=arr[i];

    int lsum = 0;
    for(int i = 0; i<n; i++){
        if(lsum == csum-arr[i]) return true;
        lsum += arr[i];
        csum -= arr[i];
    }
    return false;
}


int main(){

    fastio;

    int arr1[] = {3, 4, 8, -9, 20, 6};
    int arr2[] = {4, 2, -2};
    int arr3[] = {4, 2, 2};

    int prefix_sum1[6];
    int prefix_sum2[3];
    int prefix_sum3[3];

    // Time complexity to create prefix sum arrary = O(n)
    prefix_sum1[0] = arr1[0];
    for(int i = 1; i<6; i++) prefix_sum1[i] = prefix_sum1[i-1] + arr1[i];

    prefix_sum2[0] = arr2[0];
    for(int i = 1; i<3; i++) prefix_sum2[i] = prefix_sum2[i-1] + arr2[i];

    prefix_sum3[0] = arr3[0];
    for(int i = 1; i<3; i++) prefix_sum3[i] = prefix_sum3[i-1] + arr3[i];

    equilibrium_index_naive(arr1, 6);
    equilibrium_index_naive(arr2, 3);
    equilibrium_index_naive(arr3, 3);

    equilibrium_index_efficient1(prefix_sum1, 6);
    equilibrium_index_efficient1(prefix_sum2, 3);
    equilibrium_index_efficient1(prefix_sum3, 3);

    cout<<equilibrium_index_efficient2(arr1, 6)<<endl;
    cout<<equilibrium_index_efficient2(arr2, 3)<<endl;
    cout<<equilibrium_index_efficient2(arr3, 3)<<endl;

    return 0;
}