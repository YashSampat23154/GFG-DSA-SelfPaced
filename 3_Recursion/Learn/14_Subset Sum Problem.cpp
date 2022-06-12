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
    Given a set of non-negative integers, and a value sum, find the number of subsets of the given set with sum equal to given sum. 

    Example: 

    Input: set[] = {10,5,2,3,6}, sum = 8
    Output: 2  
    Subsets are (5, 3) and (2, 6)

    Input: set[] = {1,2,3}, sum = 4
    Output: 1
    Ssubset is (1, 3)
*/

/*
    Method 1 : Calculate all subset moving from left to right
    Time Complexity : O(2^n)
*/
ll subset_sum_LR(ll* arr, ll n, ll sum, ll curr, ll i){
    if(i == n)  return (curr == sum)? 1 : 0;

    return subset_sum_LR(arr, n, sum, curr, i+1)+ subset_sum_LR(arr, n, sum, curr+arr[i], i+1);
}

/*
    Method 2 : Calculate all subset moving from right to left
    Time Complexity : O(2^n)
*/
ll subset_sum_RL(ll* arr, ll sum, ll curr, ll i){
    if(i == -1) return (curr == sum)? 1 : 0;

    return subset_sum_RL(arr, sum, curr, i-1)+ subset_sum_RL(arr, sum, curr+arr[i], i-1);
}

/*
    Method 2 : Calculate all subset by subtracting the sum. If sum = 1 then increment the count.
    Time Complexity : O(2^n)
*/
ll subset_sum_subtract_sum(ll* arr, ll sum, ll n){
    if(n == 0)  return (sum == 0)? 1 : 0;

    return subset_sum_subtract_sum(arr, sum, n-1)+ subset_sum_subtract_sum(arr, sum-arr[n-1], n-1);
}



int main(){

    fastio;

    ll arr1[] = {10,5,2,3,6};
    ll arr2[] = {1,2,3};
    ll arr3[] = {10,20,15};
    ll arr4[] = {10,20,15};

    cout<<subset_sum_LR(arr1, 5, 8, 0, 0)<<endl;
    cout<<subset_sum_RL(arr2, 4, 0, 2)<<endl;
    cout<<subset_sum_subtract_sum(arr3, 37, 3)<<endl;
    cout<<subset_sum_subtract_sum(arr4, 0, 3)<<endl;


    return 0;
}