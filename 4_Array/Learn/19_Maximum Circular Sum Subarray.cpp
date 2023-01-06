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
    The task is to find maximum circular sum subarray of a given array
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int maxsum_in_circular_subarray_naive(int * arr, int n){
    int ans = arr[0];
    for(int i = 0; i<n; i++){
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for(int j =1; j<n ; j++){
            int index = (i+j)%n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }
        ans = max(ans, curr_max);
    }
    return ans;
}

/*
    Idea : Take Maximum of the following two
    1) Maximum sum of a Normal Subarray - Kadane's Algorithm
    2) Maximum Sum of a Circular Subarray - Apply Modified Kadane's Algorithm to find minimum subarray sum. Subtract this sum from total of array. The result is Maximum Sum of a Circular Subarray.
*/
int kadane_algo(int* arr, int n){
    int ans = arr[0], maxEnding = arr[0];
    for(int i = 1; i<n; i++){
        maxEnding = max(arr[i], maxEnding + arr[i]);
        ans = max(ans, maxEnding);
    }
    return ans;
}

// Time Complexity : O(3*n) = O(n)
// Auxillary Space : O(1)
int maxsum_in_circular_subarray_efficient(int * arr, int n){
    int max_normal = kadane_algo(arr, n);

    // Basically if all the elements in the array are -ve max_normal will be the values closest to 0 and it will be the maximum in both circular and normal manner. Hence return it.
    if(max_normal<0) return max_normal;

    int arr_sum = 0;
    for(int i =0; i<n; i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }

    int max_circular = arr_sum + kadane_algo(arr, n);

    return max(max_normal, max_circular);
}

int main(){

    fastio;

    int arr1[] = {10, 5, -5};
    int arr2[] = {5, -2, 3, 4};
    int arr3[] = {2, 3, -4};
    int arr4[] = {8, -4, 3, -5, 4};
    int arr5[] = {-3, 4, 6, -2};
    int arr6[] = {-8, 7, 6};
    int arr7[] = {3, -4, 5, 6, -8, 7};

    cout<<maxsum_in_circular_subarray_naive(arr1, 3)<<endl;
    cout<<maxsum_in_circular_subarray_naive(arr2, 4)<<endl;
    cout<<maxsum_in_circular_subarray_naive(arr3, 3)<<endl;
    cout<<maxsum_in_circular_subarray_naive(arr4, 5)<<endl;
    cout<<maxsum_in_circular_subarray_naive(arr5, 4)<<endl;
    cout<<maxsum_in_circular_subarray_naive(arr6, 3)<<endl;
    cout<<maxsum_in_circular_subarray_naive(arr7, 6)<<endl;

    return 0;
}