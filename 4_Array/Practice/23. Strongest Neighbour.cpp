/*
    Given an array arr[] of n positive integers. The task is to find the maximum for every adjacent pairs in the array.

    Example 1:

    Input:
    n = 6
    arr[] = {1,2,2,3,4,5}

    Output: 2 2 3 4 5

    Explanation: Maximum of arr[0] and arr[1] is 2, that of arr[1] and arr[2] is 2, ... and so on. For last two elements, maximum is 5.


    Example 2:

    Input:
    n = 2
    arr[] = {5, 5}
    
    Output: 5
    
    Explanation: We only have two elements so max of 5 and 5 is 5 only.
    
    Your Task:
    The task is to complete the function maximumAdjacent(), which takes sizeOfArray (n) and array(arr) as parameters and prints the maximum of all adjacent pairs (space separated).

    Expected Time Complexity: O(n).
    Expected Auxiliary Space: O(1).

    Constraints:
    2 <= n <= 10^6
    1 <= arr[i] <= 10^6
*/

// { Driver Code Starts
//Initial Template for C++

// CPP code to find maximum of 
// all subarray of size two
#include <iostream>
#include <climits>
using namespace std;

void maximumAdjacent(int, int[]);


 // } Driver Code Ends
//User function Template for C++

// Function to find maximum for every adjacent pairs in the array.
void maximumAdjacent(int sizeOfArray, int arr[]){
    for(int i = 0; i<sizeOfArray-1; i++){
        cout<<max(arr[i], arr[i+1])<<" ";
    }
}

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
	    
	    maximumAdjacent(sizeOfArray, arr);
	    cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends