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
    Given an array of size n and an integer k, return the count of distinct numbers in all windows of size k.
*/
// Time Complexity : O(n)
// Auxillary Space : O(n)
void count_distinct_elements(int* arr, int n, int k){
    map<int, int> mp;
    int current_count = 0;

    for(int i = 0; i<k; i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==1) current_count++;
    }
    cout<<current_count<<" ";

    for(int i = k; i<n; i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==1) current_count++;

        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0) current_count--;
        
        cout<<current_count<<" ";
    }
    cout<<endl;
}

int main(){

    fastio;

    int arr1[] = {1, 2, 1, 3, 4, 2, 3};
    int arr2[] = {1, 2, 4, 4};

    count_distinct_elements(arr1, 7, 4);
    count_distinct_elements(arr2, 4, 2); 

    return 0;
}