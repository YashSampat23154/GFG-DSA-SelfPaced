/*
    Given an array arr[] of size N and two elements x and y, use counter variables to find which element appears most in the array, x or y. If both elements have the same frequency, then return the smaller element.
    Note:  We need to return the element, not its count.

    Example 1:

    Input:
    N = 11
    arr[] = {1,1,2,2,3,3,4,4,4,4,5}
    x = 4, y = 5

    Output: 4
    
    Explanation: 
    frequency of 4 is 4. frequency of 5 is 1.
    

    Example 2:

    Input:
    N = 8
    arr[] = {1,2,3,4,5,6,7,8}
    x = 1, y = 7

    Output: 1
    
    Explanation: 
    frequency of 1 is 1. frequency of 7 is 1. Since 1 < 7, return 1.
    

    Your Task:
    You don't need to read input or print anything. Complete the function majorityWins() that takes array, n, x, y as input parameters and return the element with higher frequency.


    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= n <= 10^3
    0 <= arri , x , y <= 10^8
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // Function to find element with more appearances between two elements in an
    // array.
    int majorityWins(int arr[], int n, int x, int y) {
        int xcount = 0, ycount = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] == x) xcount++;
            else if(arr[i] == y) ycount++;
        }
    
        if(xcount<ycount) return y;
        else if(ycount<xcount) return x;
        else return min(x, y);
    }
};

//{ Driver Code Starts.
int main() {

    int t; // Testcases
    cin >> t; // Input the testcases
    while (t--) // Until all testcases are exhausted
    {
        int n; // Size of array
        cin >> n; // Input the size
        int arr[n]; // Declaring array of size n
        for (int i = 0; i < n;
             i++) // Running a loop to input all elements of arr
            cin >> arr[i];

        int x, y; // declare x and y
        cin >> x >> y; // input x and y
        Solution obj;
        cout << obj.majorityWins(arr, n, x, y)
             << endl; // calling the function that you complete
    }

    return 0;
}
// } Driver Code Ends