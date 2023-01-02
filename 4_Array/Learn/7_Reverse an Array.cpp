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
    To reverse the given array
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
void reverse_naive(int* arr, int n){
    int low = 0, high = n-1;
    while(low<high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}


// Time Complexity : O(n)
// Auxillary Space : O(1)
void reverse_efficient1(int* arr, int n){
    int len = n/2;
    for(int i=0; i<len; i++)
        swap(arr[i], arr[n-1-i]);
    return;
}

// Or

// Time Complexity : O(n)
// Auxillary Space : O(1)
void reverse_efficient2(int* arr, int n){
    int low = 0, high = n-1;
    while(low<high)
        swap(arr[low++],arr[high--]);
}

int main(){

    fastio;

    int arr1[] = {10, 5, 7, 30};
    int arr2[] = {30, 20, 5};
    
    cout<<"Before Reversing : \n";
    for(int i =0; i<4; i++)     cout<<arr1[i]<<" ";
    cout<<endl;

    reverse_naive(arr1, 4);

    cout<<"After Reversing : \n";
    for(int i =0; i<4; i++)     cout<<arr1[i]<<" ";
    cout<<endl;


    cout<<"Before Reversing : \n";
    for(int i =0; i<3; i++)     cout<<arr2[i]<<" ";
    cout<<endl;

    reverse_efficient2(arr2, 3);

    cout<<"After Reversing : \n";
    for(int i =0; i<3; i++)     cout<<arr2[i]<<" ";
    cout<<endl;


    return 0;
}