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
    Given an array, we have to move all the zeros present in it towards the end.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
void Move_Zeros_naive(int* arr, int n){
    for(int i =0; i<n; i++){
        if(arr[i]==0){
            for(int j= i+1; j<n; j++)
                if(arr[j]!=0)
                    swap(arr[i], arr[j]);
        }
    }
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
void Move_Zeros_efficient(int* arr, int n){
    int pos = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]!=0)
            swap(arr[pos++], arr[i]);
    }
}

int main(){

    fastio;

    int arr1[] = {8, 5, 0, 10, 0, 20};
    int arr2[] = {0, 0, 0, 10, 0};
    int arr3[] = {10, 20};
    
    cout<<"Before shifting : \n";
    for(int i =0; i<6; i++)     cout<<arr1[i]<<" ";
    cout<<endl;

    Move_Zeros_naive(arr1, 6);

    cout<<"After shifting : \n";
    for(int i =0; i<6; i++)     cout<<arr1[i]<<" ";
    cout<<endl;


    cout<<"Before shifting : \n";
    for(int i =0; i<5; i++)     cout<<arr2[i]<<" ";
    cout<<endl;

    Move_Zeros_efficient(arr2, 5);

    cout<<"After shifting : \n";
    for(int i =0; i<5; i++)     cout<<arr2[i]<<" ";
    cout<<endl;



    cout<<"Before shifting : \n";
    for(int i =0; i<2; i++)     cout<<arr3[i]<<" ";
    cout<<endl;

    Move_Zeros_efficient(arr3, 2);

    cout<<"After shifting : \n";
    for(int i =0; i<2; i++)     cout<<arr3[i]<<" ";
    cout<<endl;

    return 0;
}