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
    Given n ranges, find the maximum appearing element in the range.
*/
// Time Complexity : O(n*m) where n = no of ranges and m = max no of elements in any range
// Auxillary Space : O(n*m)
int max_occuring_naive(int* l , int* r, int n){
    map<int, int> mp;
    for(int i = 0; i<n; i++){
        for(int j = l[i]; j<=r[i]; j++)
            mp[j]++;
    }
    int maxi = 0, no = -1;

    for (auto i = mp.begin(); i!=mp.end(); i++){
        if(i->second>maxi){
            maxi = i->second;
            no = i->first;
        }
    }
    return no;
}
// Time Complexity : O(n) 
// Auxillary Space : O(1)

/*
We can have a much efficient solution provided that we know that the value of r is less than a large value say 1000
*/
int max_occuring_efficient(int L[], int R[], int n)
{
    int arr[1000];
    memset(arr, 0, sizeof(arr));

    for(int i = 0; i<n; i++){
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }

    int maxm = arr[0], res = 0;
    for(int i = 1; i < 1000; i++){
        arr[i] += arr[i - 1];
        if(maxm < arr[i]){
            maxm = arr[i];
            res = i;
        }
    }

    return res;
}

/*
    More questions based on Prefix_Sum Technique : 
    1) Check if a given array can be divided into three parts with equal sum.
    2) Check if there is a subarray with 0 sum
    3) Find the longest subarray with equal 0's and 1's.
*/


int main(){

    fastio;

    int L[] = {1, 2, 3};
    int  R[] = {3, 5, 7}, n = 3;
      
    cout<<max_occuring_naive(L, R, n)<<endl;
    cout<<max_occuring_efficient(L, R, n)<<endl;

    return 0;
}