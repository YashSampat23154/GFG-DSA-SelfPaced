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
    To check whether the array is sorted in non-decreasing order.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
bool sorted_in_non_decresing_order_naive(int* arr, int n){
    for(int i= 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            if(arr[j]<arr[i]) return false;
    return true;

}

// Time Complexity : O(n)
// Auxillary Space : O(1)
bool sorted_in_non_decresing_order_efficient(int* arr, int n){
    for(int i= 0; i<n-1; i++){
        if(arr[i]>arr[i+1]) return false;
    }
    return true;

}

int main(){

    fastio;

    int arr1[] = {8, 12, 15};
    int arr2[] = {8, 10, 10, 12};
    int arr3[] = {100};
    int arr4[] = {100, 20, 200};

    cout<<sorted_in_non_decresing_order_naive(arr1, 3)<<endl;
    cout<<sorted_in_non_decresing_order_naive(arr2, 4)<<endl;
    cout<<sorted_in_non_decresing_order_naive(arr3, 1)<<endl;
    cout<<sorted_in_non_decresing_order_naive(arr3, 3)<<endl;

    cout<<sorted_in_non_decresing_order_efficient(arr1, 3)<<endl;
    cout<<sorted_in_non_decresing_order_efficient(arr2, 4)<<endl;
    cout<<sorted_in_non_decresing_order_efficient(arr3, 1)<<endl;
    cout<<sorted_in_non_decresing_order_efficient(arr3, 3)<<endl;


    return 0;
}