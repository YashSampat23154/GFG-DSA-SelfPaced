/*
    Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 
    Example 1:

    Input:
    N = 6
    arr[] = {3,0,0,2,0,4}
    
    Output:
    10
    
    Explanation:  Total trapped water = 3+3+1+3 = 10


    Example 2:

    Input:
    N = 4
    arr[] = {7,4,0,9}

    Output:
    10

    Explanation:
    Water trapped by above block of height 4 is 3 units and above block of height 0 is 7 units. So, the total unit of water trapped is 10 units.
    
    
    Example 3:

    Input:
    N = 3
    arr[] = {6,9,9}
    
    Output:
    0
    
    Explanation:
    No water will be trapped.

    Your Task:
    You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.


    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)


    Constraints:
    3 < N < 10^6
    0 < Ai < 10^8
*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        int Lmax[n] = {0}; 
        Lmax[0] = arr[0];
        for(int i = 1; i<n; i++)
            Lmax[i] = max(Lmax[i-1], arr[i]);
            
            
        int Rmax[n] = {0}; 
        Rmax[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--)
            Rmax[i] = max(Rmax[i+1], arr[i]);
        
        
        long long ans = 0;
        for(int i = 1; i<n-1; i++)
            ans+=min(Lmax[i], Rmax[i]) - arr[i];
            
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends