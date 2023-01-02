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
    To remove duplicates from a sorted array
*/
// Time Complexity : O(n)
// Auxillary Space : O(n)
int remove_duplicates_naive(int* arr, int n){
    int temp[n];
    
    temp[0] = arr[0];
    int pos = 1;
    
    for(int i = 1; i<n; i++){
        if(temp[pos-1]!= arr[i]){
            temp[pos] = arr[i];
            pos++;
        }
    }
    for(int i =0 ; i<pos; i++)
        arr[i] = temp[i];

    return pos;
}


// Time Complexity : O(n)
// Auxillary Space : O(1)
int remove_duplicates_efficient(int* arr, int n){
    int pos = 0;
    for(int i = 1; i<n ;i++){
        if(arr[i]>arr[pos])
            arr[++pos] = arr[i];
    }
    return pos+1;
}

int main(){

    fastio;

    int arr1[] = {10, 20, 20, 30, 30, 30, 30};
    int arr2[] = {10, 10, 10};

    int size;
    
    cout<<"Before removing duplicates : \n";
    for(int i =0; i<7; i++)     cout<<arr1[i]<<" ";
    cout<<endl;

    size = remove_duplicates_naive(arr1, 7);

    cout<<"After removing duplicates : \nSize : "<<size<<endl;
    for(int i =0; i<7; i++)     cout<<arr1[i]<<" ";
    cout<<endl;


    cout<<"Before removing duplicates : \n";
    for(int i =0; i<3; i++)     cout<<arr2[i]<<" ";
    cout<<endl;

    size = remove_duplicates_efficient(arr2, 3);

    cout<<"After removing duplicates : \nSize : "<<size<<endl;
    for(int i =0; i<3; i++)     cout<<arr2[i]<<" ";
    cout<<endl;

    return 0;
}