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
    Given an array of N elements find the second largest element.
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
int largest_element_efficient(int * arr, int n){
    int largest = 0;
    for(int i=1; i<n; i++){
        largest = arr[largest]>arr[i]? largest: i;
    }
    return largest;
}

int secondlargest_element_naive(int * arr, int n){
    
    int largest = largest_element_efficient(arr, n);

    int secondlargest = -1;
    for(int i = 0; i<n; i ++){
        if(arr[i]!=arr[largest]){
            if(secondlargest == -1) secondlargest = i;
            else if(arr[i]> arr[secondlargest]) secondlargest = i;
        }
    }
    return secondlargest;
}



// Time Complexity : O(n)
// Auxillary Space : O(1)
int secondlargest_element_efficient(int * arr, int n){
    int largest = 0, secondlargest = -1;
    for(int i=1; i<n; i++){
        if(arr[i]>arr[largest]){
            secondlargest = largest;
            largest = i;
        }
        else if(arr[i]<arr[largest]){
            if(secondlargest == -1 || arr[i]>arr[secondlargest]) secondlargest = i;
        }
    }
    return secondlargest;
}


int main(){

    fastio;

    int arr1[] = {10, 5, 20, 8};
    int arr2[] = {40, 8, 50, 100};
    int arr3[] = {10, 10, 10, 10};

    cout<<secondlargest_element_naive(arr1, 4)<<endl;
    cout<<secondlargest_element_naive(arr2, 4)<<endl;
    cout<<secondlargest_element_naive(arr3, 4)<<endl;

    cout<<secondlargest_element_efficient(arr1, 4)<<endl;
    cout<<secondlargest_element_efficient(arr2, 4)<<endl;
    cout<<secondlargest_element_efficient(arr3, 4)<<endl;

    return 0;
}