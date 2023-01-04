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
    To find the frequencies of each element in the given array.
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
void frequencies(int* arr, int n){
    
    int count = 1, currentval = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i]!= currentval){
            cout<<currentval<<" "<<count<<endl;
            currentval = arr[i];
            count = 1;
            continue;
        }
        count++;
    }
    cout<<currentval<<" "<<count<<endl;
}


//Or

// Time Complexity : O(n)
// Auxillary Space : O(1)
void printFreq(int* arr, int n){
    int freq = 1, i = 1;
    while(i<n){
        while(i<n && arr[i] == arr[i-1]){
            freq++; 
            i++;
        }
        cout<<arr[i-1]<<" "<<freq<<endl;
        i++;
        freq = 1;
    }
    if(n==1 || arr[n-1]!=arr[n-2])
        cout<<arr[i-1]<<" "<<1<<endl;
}


int main(){

    fastio;

    int arr1[] = {10, 10, 10, 25, 30, 30};
    int arr2[] = {10, 10, 10, 10};
    int arr3[] = {10, 20, 30};
    int arr4[] = {50};

    frequencies(arr1, 6);
    frequencies(arr2, 4);
    frequencies(arr3, 3);
    frequencies(arr4, 1);

    return 0;
}