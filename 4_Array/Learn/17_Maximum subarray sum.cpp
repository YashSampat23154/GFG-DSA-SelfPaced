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
    Given an array we want to print the maximum sum of any subarray.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int maxsubarraysum_naive(int arr[], int n){
    int ans = arr[0];
    for(int i =0; i<n; i++){
        int current = 0;
        for(int j = i; j<n; j++){
            current+=arr[j];
            ans = max(ans, current);
        }
    }
    return ans;
}


/*  
    Kadane's Algorithm
    Time Complexity : O(n)
    Auxillary Space : O(1)
*/
int maxsubarraysum_efficient(int arr[], int n){
    int maxending = arr[0], ans = arr[0];

    for(int i = 1; i<n; i++){
        maxending = max(arr[i], maxending + arr[i]);
        ans = max(ans, maxending);
    }
    return ans;
}


int main(){

    fastio;

    int arr1[] = {2, 3, -8, 7, -1, 2, 3};
    int arr2[] = {5, 8, 3};
    int arr3[] = {-6, -1, -8};

    cout<<maxsubarraysum_efficient(arr1, 7)<<endl;
    cout<<maxsubarraysum_efficient(arr2, 3)<<endl;
    cout<<maxsubarraysum_efficient(arr3, 3)<<endl;

    return 0;
}