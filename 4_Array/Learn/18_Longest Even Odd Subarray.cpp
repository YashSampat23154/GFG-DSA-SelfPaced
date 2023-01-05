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
    To find the length of the longest subarray that has alternating even odd elements.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int longesteosubarray_naive(int* arr, int n){
    int ans = 1;
    for(int i = 0; i<n; i++){
        int current = 1;
        for(int j = i+1; j<n; j++){
            if((arr[j]%2==0 && arr[j-1]%2==1) || (arr[j]%2==1 && arr[j-1]%2==0))
                current++;
            else break;
        }
        ans = max(ans, current);
    }
    return ans; 
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
int longesteosubarray_efficient(int* arr, int n){
    int count = 1;
    int ans = 0;
    
    for(int i = 1; i<n; i++){
        if((arr[i]%2==0 && arr[i-1]%2==1) || (arr[i]%2==1 && arr[i-1]%2==0))
            count++;
        else{
            ans = max(ans, count);
            count = 1;
        }
    }
    ans = max(ans, count);
    return ans;
}


int main(){

    fastio;

    int arr1[] = {10, 12, 14, 7, 8};
    int arr2[] = {7, 10, 13, 14};
    int arr3[] = {10, 12, 8, 4};

    cout<<longesteosubarray_efficient(arr1, 5)<<endl;
    cout<<longesteosubarray_efficient(arr2, 4)<<endl;
    cout<<longesteosubarray_efficient(arr3, 4)<<endl;

    return 0;
}