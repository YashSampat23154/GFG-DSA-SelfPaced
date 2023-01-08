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
    Given an array arr[] of size n, its prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i].


    Questions :
    Given a fixed array and multiple queries of the following type on the array, how to efficiently perform the queries?

    I/P : arr[] = {2, 8, 3, 9, 6, 5, 4}
    Querires : 
    getSum(0, 2);
    getSum(1, 3);
    getSum(2, 6);

    O/P : 13 20 27
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
int getSum_naive(int* arr, int n, int l, int r){
    int sum = 0;
    for(int i = l; i<=r; i++) sum+=arr[i];
    return sum;
}

// Time Complexity : O(1)
// Auxillary Space : O(1)
int getSum_efficient(int* cum, int n, int l, int r){
    if(l == 0) return cum[r];
    else return cum[r] - cum[l-1];
}


int main(){

    fastio;

    int arr1[] = {2, 8, 3, 9, 6, 5, 4};
    int prefix_sum1[7];

    // Time complexity to create prefix sum arrary = O(n)
    prefix_sum1[0] = arr1[0];
    for(int i = 1; i<7; i++) prefix_sum1[i] = prefix_sum1[i-1] + arr1[i];

    cout<<getSum_naive(arr1, 7, 0, 2)<<endl;
    cout<<getSum_naive(arr1, 7, 1, 3)<<endl;
    cout<<getSum_naive(arr1, 7, 2, 6)<<endl;

    cout<<getSum_efficient(prefix_sum1, 7, 0, 2)<<endl;
    cout<<getSum_efficient(prefix_sum1, 7, 1, 3)<<endl;
    cout<<getSum_efficient(prefix_sum1, 7, 2, 6)<<endl;

    return 0;
}