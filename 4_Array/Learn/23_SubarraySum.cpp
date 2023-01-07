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
    Given an unsorted array of non-negative integers, find if there is a subarray with given sum
*/

// Time Complexity : O(n^2)
// Auxillary Space : O(1)
bool subarray_given_sum_naive(int arr[], int n, int sum){
    int current = 0;
    bool ans = false;
    for(int i = 0; i<n; i++){
        current = 0;
        for(int j = i; j<n; j++){
            current+=arr[j];
            if(current == sum) ans = true;
        }
    }
    return ans; 
}

/*
    Idea of efficient solution: 
    Keep adding elements into window till current_sum <= required_sum.
    if(current_sum > required_sum) : remove elements from beginning till current_sum <= required_sum
    if(current_sum == required_sum) return true;
*/
// Time Complexity : O(2*n) = O(n)
// Auxillary Space : O(1)
bool subarray_given_sum_efficient(int arr[], int n, int sum){
    int current_sum = 0, j = 0;
    for(int i =0; i<n; i++){
        current_sum += arr[i];
        while(current_sum>sum && j<i)
            current_sum-=arr[j++];
        if(current_sum == sum) return true;
    }
    return false;
}


int main(){

    fastio;

    int arr1[] = {1, 4, 20, 3, 10, 5};
    int arr2[] = {1, 4, 0, 0, 3, 10, 5};
    int arr3[] = {2, 4};

    cout<<subarray_given_sum_naive(arr1, 6, 33)<<endl;
    cout<<subarray_given_sum_efficient(arr2, 7, 7)<<endl;    
    cout<<subarray_given_sum_efficient(arr3, 2, 4)<<endl;    


    return 0;
}