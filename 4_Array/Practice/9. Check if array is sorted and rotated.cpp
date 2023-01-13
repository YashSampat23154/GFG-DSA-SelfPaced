/*
    Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated. A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

    Example 1:

    Input:
    N = 4
    arr[] = {3,4,1,2}

    Output: Yes
    
    Explanation: The array is sorted (1, 2, 3, 4) and rotated twice (3, 4, 1, 2).
    
    
    Example 2:

    Input:
    N = 3
    arr[] = {1,2,3}
    
    Output: No
    
    Explanation: The array is sorted (1, 2, 3) is not rotated. Your Task: The task is to complete the function checkRotatedAndSorted() which returns true if an array is sorted and rotated clockwise otherwise false.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 <= N <= 10^6
    1 <= A[i] <= 10^6
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    
    bool sortedIncreasing(int arr[], int num){
        int i = 0;
        while(arr[i] <= arr[i+1]) i++;
        i++;
        
        for(; i<num-1; i++)
            if(arr[i] > arr[i+1])
                return false;
                
        if(arr[0] >= arr[num-1]) return true; 
        else return false;
    }
    
    bool sortedDecreasing(int arr[], int num){
        int i = 0;
        while(arr[i] >= arr[i+1]) i++;
        i++;
        
        for(; i<num-1; i++)
            if(arr[i] < arr[i+1])
                return false;
                
        if(arr[0] <= arr[num-1]) return true; 
        else return false;
    }
    
    bool checkRotatedAndSorted(int arr[], int num){
        
        bool ans1 = sortedIncreasing(arr, num);
        bool ans2 = sortedDecreasing(arr, num);
        
        return ans1||ans2;
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        Solution ob;
        
        //function call
        flag = ob.checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}
// } Driver Code Ends