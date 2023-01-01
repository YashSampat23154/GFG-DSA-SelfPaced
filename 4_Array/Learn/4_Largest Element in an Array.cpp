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
    Given an array of N elements find the largest element.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int largest_element_naive(int * arr, int n){
    for(int i=0; i<n; i++){
        bool largest = true;
        for(int j = 0; j<n; j++){
            if(arr[i]<arr[j]){
                largest = false;
                break;
            }
        }
        if(largest) return i;
    }
    return -1;
}


// Time Complexity : O(n)
// Auxillary Space : O(1)
int largest_element_efficient(int * arr, int n){
    int largest = 0;
    for(int i=1; i<n; i++){
        largest = arr[largest]>arr[i]? largest: i;
    }
    return largest;
}


int main(){

    fastio;

    int arr1[] = {10, 5, 20, 8};
    int arr2[] = {40, 8, 50, 100};

    cout<<largest_element_naive(arr1, 4)<<endl;
    cout<<largest_element_naive(arr2, 4)<<endl;

    cout<<largest_element_efficient(arr1, 4)<<endl;
    cout<<largest_element_efficient(arr2, 4)<<endl;

    return 0;
}