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
    Find count of maximum consecutive 1s in a binary array.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int count1s_naive(bool arr[], int n){
    int ans = 0;

    for(int i =0; i<n; i++){
        int curr = 0;
        for(int j = i; j<n; j++){
            if(arr[j] == 1) curr++;
            else break;
        }
        ans = max(ans, curr);
    }
    return ans;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
int count1s_efficient(bool arr[], int n){
    int count = 0, ans = 0;

    for(int i=0; i<n; i++){
        if(arr[i]!=1){
            ans = max(ans, count);
            count = 0;
        }
        else count++;
    }
    ans = max(ans, count);
    return ans;
}

int main(){

    fastio;

    bool arr1[] = {0, 1, 1, 0, 1, 0};
    bool arr2[] = {1, 1, 1, 1};
    bool arr3[] = {0, 0, 0};
    bool arr4[] = {1, 0, 1, 1, 1, 1, 0, 1, 1};

    cout<<count1s_naive(arr1, 6)<<endl;
    cout<<count1s_naive(arr2, 4)<<endl;
    cout<<count1s_efficient(arr3, 3)<<endl;
    cout<<count1s_efficient(arr4, 9)<<endl;

    return 0;
}