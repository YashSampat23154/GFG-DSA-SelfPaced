/*
    Given an array Arr of n integers arranged in a circular fashion. Your task is to find the minimum absolute difference between adjacent elements.

    Example 1:

    Input:
    n = 7
    Arr[] = {8,-8,9,-9,10,-11,12}
    
    Output: 4
    
    Explanation: The absolute difference between adjacent elements in the given array are as such: 16 17 18  19 21 23 4 (first and last). Among the calculated absolute difference the minimum is 4.
    
    
    Example 2:

    Input:
    n = 8
    Arr[] = {10,-3,-4,7,6,5,-4,-1}
    
    Output: 1
    
    Explanation: The absolute difference between adjacent elements in the given array are as such: 13 1 11 1 1 9 3 11 (first and last).  Among the calculated absolute difference, the minimum is 1.
    
    Your Task:
    The task is to complete the function minAdjDiff() which returns the minimum difference between adjacent elements in circular array.

    Expected Time Complexity: O(n).
    Expected Auxiliary Space: O(1).

    Constraint:
    2 <= n <= 10^6
    -10^6 <= Arr[i] <= 10^6
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find minimum adjacent difference in a circular array.
    // arr[]: input array
    // n: size of array
    int minAdjDiff(int arr[], int n){    
        
        int mini = abs(arr[0]-arr[n-1]);
        
        for(int i = 1; i<n; i++){
            int diff = abs(arr[i] - arr[i-1]);
            mini = min(diff, mini);
        }
        
        return mini;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        Solution ob;
        
        cout << ob.minAdjDiff(arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
