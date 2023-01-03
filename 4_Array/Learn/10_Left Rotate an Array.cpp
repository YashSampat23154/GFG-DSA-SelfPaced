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
    To Left Rotate an Array by one place
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
void left_rotate_by_one(int* arr, int n){
    int temp = arr[0];
    for(int i =1; i<n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}



/*
    To Left Rotate an Array by D places
*/
// Time Complexity : O(n*d)
// Auxillary Space : O(1)
void left_rotate_by_d_naive(int* arr, int n, int d){
    while(d--)
        left_rotate_by_one(arr, n);
}


// Time Complexity : O(d + n-d + d) = O(n+d) = O(n)
// Auxillary Space : O(d)
void left_rotate_by_d_slightlyefficient(int* arr, int n, int d){
    int temp[d];
    
    for(int i = 0; i<d; i++)
        temp[i] = arr[i];

    for(int i = d; i<n; i++)
        arr[i-d] = arr[i];
    
    for(int i = 0; i<d; i++)
        arr[n-d+i] = temp[i];
}


// Time Complexity : O(d/2 + (n-d)/2 + (n)/2) = O(2n) = O(n)
// Auxillary Space = O(1)

void reverse(int* arr, int low, int high){
    while(low<high)
        swap(arr[low++], arr[high--]);
}

// Also know as reversal method
void left_rotate_by_d_reversalmethod(int* arr, int n, int d){
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}


int main(){

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {30, 5, 20};
    int arr3[] = {1, 2, 3, 4, 5};

    cout<<"Before rotating : \n";
    for(int i =0; i<5; i++)     cout<<arr1[i]<<" ";
    cout<<endl;

    left_rotate_by_one(arr1, 5);

    cout<<"After rotating : \n";
    for(int i =0; i<5; i++)     cout<<arr1[i]<<" ";
    cout<<endl;



    cout<<"Before rotating : \n";
    for(int i =0; i<3; i++)     cout<<arr2[i]<<" ";
    cout<<endl;

    left_rotate_by_d_naive(arr2, 3, 2);

    cout<<"After rotating : \n";
    for(int i =0; i<3; i++)     cout<<arr2[i]<<" ";
    cout<<endl;


    cout<<"Before rotating : \n";
    for(int i =0; i<5; i++)     cout<<arr3[i]<<" ";
    cout<<endl;

    left_rotate_by_d_reversalmethod(arr3, 5, 2);

    cout<<"After rotating : \n";
    for(int i =0; i<5; i++)     cout<<arr3[i]<<" ";
    cout<<endl;


    return 0;
}