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
    Given a binary array, we need to find the minimum of number of group flips to make all array elements same.  In a group flip, we can flip any set of consecutive 1s or 0s.
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
void min_consecutive_flips_naive(bool* arr, int n){
    int grp0 = 0, grp1 = 0;
    
    if(arr[0] == 0) grp0++;
    else grp1++;

    for(int i = 1; i<n; i++){
        if(arr[i] != arr[i-1]){
            if(arr[i] == 0) grp0++;
            else grp1++;
        }    
    }

    if(grp0 == 0 || grp1 == 0) {
        cout<<endl;
        return;
    }

    bool ans;

    if(grp1 < grp0) ans = 1;
    else    ans = 0;


    if(arr[0] == ans)   cout<<"From 0 to ";

    for(int i = 0; i<n; i++){

        if(arr[i] == ans){
            
            if(i!=0 && arr[i-1] == (ans^1)) cout<<"From "<<i<<" to ";
            if(i!=n-1 && arr[i+1] == (ans^1)) cout<<i<<endl;
        }    
    }

    if(arr[n-1] == ans)   cout<<n-1<<endl;

    return;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
void min_consecutive_flips_efficient1(bool* arr, int n){
    bool ans;

    if(arr[0] == 0) ans = 1;
    else    ans = 0;

    if(arr[0] == ans)   cout<<"From 0 to ";

    for(int i = 0; i<n; i++){

        if(arr[i] == ans){
            
            if(i!=0 && arr[i-1] == (ans^1)) cout<<"From "<<i<<" to ";
            if(i!=n-1 && arr[i+1] == (ans^1)) cout<<i<<endl;
        }    
    }

    if(arr[n-1] == ans)   cout<<n-1<<endl;

    return;
}


// Another way to code efficient
// Time Complexity : O(n)
// Auxillary Space : O(1)
void min_consecutive_flips_efficient2(bool* arr, int n){
    for(int i = 1; i<n; i++){
        if(arr[i]!=arr[i-1]){
            if(arr[i]!=arr[0])
                cout<<"From "<<i<<" to ";
            else
                cout<<(i-1)<<endl;
        }
    }
    if(arr[n-1]!=arr[0])
        cout<<n-1<<endl;
}


int main(){

    fastio;

    bool arr1[] = {1, 1, 0, 0, 0, 1};
    bool arr2[] = {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1};
    bool arr3[] = {1, 1, 1};
    bool arr4[] = {0, 1};

    min_consecutive_flips_naive(arr1, 6);
    min_consecutive_flips_naive(arr2, 11);
    min_consecutive_flips_efficient1(arr3, 3);
    min_consecutive_flips_efficient2(arr4, 2);

    return 0;
}