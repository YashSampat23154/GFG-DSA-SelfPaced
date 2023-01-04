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
    The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earn by buying on day 0, selling on day 3. Again, buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/
// Time Complexity : O(n^2)
// Auxillary Space : O(1)
int buynsell_naive(int* price, int start, int end){
    if(end<=start)  return 0;
    int profit = 0;

    for(int i=start; i<end; i++){
        for(int j = i+1; j<=end; j++){
            if(price[j]>price[i]){
                int curr_profit = price[j]-price[j] + buynsell_naive(price, start, i-1) + buynsell_naive(price, j+1, end);

                profit = max(profit, curr_profit);
            }
        }
    }

    return profit;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
int buynsell_efficient_but_complex(int* arr, int n){
    int profit = 0;
    int buyval = 0;
    bool buy = false;

    for(int i = 0; i<n-1; i++){
        if(!buy){
            if(arr[i]<arr[i+1]){
                buyval = arr[i];
                buy = true;
            }
        }
        else{
            if(arr[i]>arr[i+1]){
                profit += arr[i]-buyval;
                buy = false;
            }
        }
    }
    if(buy) profit += arr[n-1]-buyval;

    return profit;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
int buynsell_efficient(int* arr, int n){
    int profit = 0;
    for(int i =1; i<n; i++){
        if(arr[i]>arr[i-1])
            profit += arr[i]-arr[i-1];
    }
    return profit;
}

int main(){

    fastio;

    int arr1[] = {1, 5, 3, 8, 12};
    int arr2[] = {30, 20, 10};
    int arr3[] = {10, 20, 30};
    int arr4[] = {1, 5, 3, 1, 2, 8};

    cout<<buynsell_naive(arr1, 0, 4)<<endl;
    cout<<buynsell_efficient_but_complex(arr2, 3)<<endl;
    cout<<buynsell_efficient_but_complex(arr3, 3)<<endl;
    cout<<buynsell_efficient(arr4, 6)<<endl;

    return 0;
}