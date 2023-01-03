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
    An element is called the leader of an array if there is no element greater than it on the right side.
    Give an array we have to print all the leaders.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
void leaders_naive(int* arr, int n){
    for(int i =0; i<n; i++){
        bool lead = true;
        for(int j = i+1; j<n; j++){
            if(arr[i]<arr[j]){
                lead = false;
                break;
            }
        }
        if(lead) cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// Time Complexity : O(n)
// Auxillary Space : O(1)
// Note : This prints leaders from right to left. To print the leaders from left to right we can maintain an array. This will use O(n) extra space. However 
void leaders_efficient(int* arr, int n){
    cout<<arr[n-1]<<" ";
    
    int maxi = arr[n-1];

    for(int i = n-2; i>=0; i--){
        if(arr[i]>maxi){
            cout<<arr[i]<<" ";
            maxi = arr[i];
        } 
    }
    cout<<endl;
}


int main(){

    fastio;

    int arr1[] = {7, 10, 4, 3, 6, 5, 2};
    int arr2[] = {10, 20, 30};
    int arr3[] = {30, 20, 10};

    leaders_naive(arr1, 7);
    leaders_efficient(arr2, 3);
    leaders_efficient(arr3, 3);

    return 0;
}