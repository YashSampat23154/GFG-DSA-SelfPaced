/*
    Given an array arr[] of size N of positive integers which may have duplicates. The task is to find the maximum and second maximum from the array, and both of them should be different from each other, so If no second max exists, then the second max will be -1.

    Example 1:

    Input:
    N = 3
    arr[] = {2,1,2}
    Output: 2 1
    
    Explanation: From the given array 
    elements, 2 is the largest and 1 
    is the second largest.
    Example 2:

    Input:
    N = 5
    arr[] = {1,2,3,4,5}
    Output: 5 4
    
    Explanation: From the given array 
    elements, 5 is the largest and 4 
    is the second largest.
    
    Your Task:
    The task is to complete the function largestAndSecondLargest(), which should return maximum and second maximum element from the array with first element as maximum element and second element as second maximum(if there is no second maximum the  second element should be -1)

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 <= N <= 10^6
    1 <= arr[i] <= 10^6
*/

// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
     

class Solution{
  public:
    /* Function to find largest and second largest element
    *sizeOfArray : number of elements in the array
    * arr = input array
    */
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
        int max1 = arr[0], max2= -1;
        
        for(int i = 1; i<sizeOfArray; i++){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
            }
            else if(arr[i] < max1)
                if(arr[i] > max2) max2 = arr[i];
        }
         
        vector<int> v = {max1, max2};
         
        return v;
    }
};

// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    Solution obj;
	    vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}  // } Driver Code Ends