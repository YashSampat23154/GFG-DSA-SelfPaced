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
    Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int maximum_difference_naive(int* arr, int n){
    int maxi = -1;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if((arr[j]-arr[i]) > maxi)
                maxi = arr[j]-arr[i];
        }
    }
    return maxi;
}


/*
    The effient solution is that we traverse the array from left to right and at every i index we subtract the minimum value till i-1th index from array arr.
    If this value is greater than our max then max value is updated.
    If the value of array at index i is smaller than current minimum value then minimum value is updated.
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
int maximum_difference_efficient(int* arr, int n){
    int maxi = arr[1]-arr[0];
    int mini = arr[0];
    
    for(int i = 1; i<n; i++){
        maxi = max(maxi, arr[i]-mini);
        mini = min(arr[i], mini);
    }
    return maxi;
}

int main(){

    fastio;

    int arr1[] = {2, 3, 10, 6, 4, 8, 1};
    int arr2[] = {7, 9, 5, 6, 3, 2};
    int arr3[] = {10, 20, 30};
    int arr4[] = {30, 10, 8, 2};

    cout<<maximum_difference_naive(arr1, 7)<<endl;
    cout<<maximum_difference_naive(arr2, 6)<<endl;
    cout<<maximum_difference_efficient(arr3, 3)<<endl;
    cout<<maximum_difference_efficient(arr4, 4)<<endl;

    return 0;
}