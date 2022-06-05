#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

/*
    Given two arrays of numbers a1, a2, a3,...an and b1, b2, .. bn where each number is 0 or 1, the fastest algorithm to find the largest span(i, j) such that ai + ai+1, ....aj = bi + bi+1, .. bj. or report that there is not such span,
*/


/*
    Naive Approach : Check for all subarrays. 
    
    Time Complexity : O(n^2)
*/
int longestSum_naive(int arr1[], int arr2[], int n){
    int maxi = 0;
    for(int i = 0; i<n; i++){
        int sum1 = 0, sum2 = 0;
        for(int j = i; j<n; j++){
            sum1 += arr1[j];
            sum2 += arr2[j];

            if(sum1 == sum2) maxi = max(maxi, j-i+1);
        } 
    }

    return maxi;    
}

/*
    The idea is based on below observations.
    Since there are total n elements, maximum sum is n for both arrays.
    Difference between two sums varies from -n to n. So there are total 2n + 1 possible values of difference.
    
    If differences between prefix sums of two arrays become same at two points, then subarrays between these two points have same sum.
    
    Below is Complete Algorithm.
    Create an auxiliary array of size 2n+1 to store starting points of all possible values of differences (Note that possible values of differences vary from -n to n, i.e., there are total 2n+1 possible values)
    
    Initialize starting points of all differences as -1.
    
    Initialize maxLen as 0 and prefix sums of both arrays as 0, preSum1 = 0, preSum2 = 0
    
    Traverse both arrays from i = 0 to n-1.
    
    Update prefix sums: preSum1 += arr1[i], preSum2 += arr2[i]
    
    Compute difference of current prefix sums: curr_diff = preSum1 – preSum2
    
    Find index in diff array: diffIndex = n + curr_diff // curr_diff can be negative and can go till -n
    
    If curr_diff is 0, then i+1 is maxLen so far
    
    Else If curr_diff is seen first time, i.e., starting point of current diff is -1, then update starting point as i
    
    Else (curr_diff is NOT seen first time), then consider i as ending point and find length of current same sum span. If this length is more, then update maxLen

Return maxLen
*/
int longestSum_efficient(int arr1[], int arr2[], int n){
    int maxi = 0, sum1 = 0, sum2 = 0;

    int diff[n*2 + 1];
    memset(diff, -1, sizeof(diff));

    for(int i = 0; i<n; i++){
        sum1+=arr1[i];
        sum2+=arr2[i];

        if(sum1-sum2 == 0)  maxi = i+1;
        else if(diff[n+sum1-sum2] == -1)   diff[n+sum1-sum2] = i;
        else{
            maxi = max(maxi, i - diff[n+ sum1-sum2]);
        }
    }

    return maxi;
}


int main(){

    fastio;

    int arr1[] = {1,1,0,1,1,1,1};
    int arr2[] = {1,1,1,1,1,0,1};

    cout<<longestSum_naive(arr1, arr2, 7)<<endl;
    cout<<longestSum_efficient(arr1, arr2, 7)<<endl;

    return 0;
}