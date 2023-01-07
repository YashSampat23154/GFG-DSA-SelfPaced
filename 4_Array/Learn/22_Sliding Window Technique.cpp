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
    For all these type of questions we can use sliding window technique : 

    1) Given an array of integers and a number k, find the maximum sum of k consecutive elements.

    2) Given an array of integers and a number k, find if there is a subarray of size k with given sum. 

*/


/*
    Given an array of integers and a number k, find the maximum sum of k consecutive elements.
*/

// Time Complexity : O((n-k)*k) = O(n*k + k^2)
// Auxillary Space : O(1)
int slidingwindow_naive(int arr[], int n, int k){
    int max_sum = INT_MIN;

    for(int i =0; i<n-k+1; i++){
        int sum = 0;
        for(int j = 0; j<k; j++)
            sum+=arr[i+j];
        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
int slidingwindow_efficient(int arr[], int n, int k){
    int max_sum = INT_MIN;
    int current_sum = 0;

    for(int i=0; i<n; i++){
        current_sum += arr[i];
        if(i>=k){
            current_sum -= arr[i-k];
        }
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}


/*
    Given an array of integers and a number k, find if there is a subarray of size k with given sum.
*/
bool slidingwindow_givensum(int* arr, int n, int k, int sum){
    bool ans = false;
    int current_sum = 0;
    for(int i =0; i<n; i++){
        current_sum += arr[i];
        if(i>=k) current_sum -= arr[i-k];
        if(current_sum == sum) ans = true;
    }
    return ans;
}


int main(){

    fastio;

    int arr1[] = {1, 8, 30, -5, 20, 7};
    int arr2[] = {1, 4, 20, 3, 10, 5};
    int arr3[] = {1, 4, 0, 0, 3, 10, 5};
    int arr4[] = {2, 4};

    cout<<slidingwindow_naive(arr1, 6, 3)<<endl;
    cout<<slidingwindow_efficient(arr1, 6, 3)<<endl;    
    cout<<slidingwindow_givensum(arr2, 6, 3, 33)<<endl; 
    cout<<slidingwindow_givensum(arr3, 7, 4, 7)<<endl; 
    cout<<slidingwindow_givensum(arr4, 2, 1, 3)<<endl; 

    return 0;
}