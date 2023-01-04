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
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

    Examples:  

    Input: arr[]   = {2, 0, 2}
    Output: 2
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int trapRainWater_naive(int arr[], int n){
    int ans = 0;

    for(int i =1; i<n-1; i++){
        
        int lmax = arr[i];
        for(int j = 0; j<i; j++) lmax = max(lmax, arr[j]);

        int rmax = arr[i];
        for(int j = i+1; j<n; j++) rmax = max(rmax, arr[j]);
        
        ans += min(rmax, lmax)-arr[i];
    }
    return ans;
}


// Time Complexity : O(n)
// Auxillary Space : O(n)
int trapRainWater_efficient(int arr[], int n){
    int ans = 0;
    int lmax[n], rmax[n];

    lmax[0] = arr[0];
    for(int i = 1; i<n; i++) lmax[i] = max(lmax[i-1], arr[i]);

    rmax[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--) rmax[i] = max(rmax[i+1], arr[i]);

    for(int i =1; i<n-1; i++){        
        ans += min(rmax[i], lmax[i])-arr[i];
    }

    return ans;
}

int main(){

    fastio;

    int arr1[] = {2, 0, 2};
    int arr2[] = {3, 0, 1, 2, 5};
    
    cout<<trapRainWater_naive(arr1, 3)<<endl;
    cout<<trapRainWater_efficient(arr2, 5)<<endl;

    return 0;
}