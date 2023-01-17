/*
    You are given an array of size n. Find the maximum possible length of a subarray such that its elements are arranged alternately either as even and odd or odd and even .

    Example 1:

    Input:
    n = 5
    a[] = {10,12,14,7,8}

    Output: 3  
    
    Explanation: The max length of subarray is 3 and the subarray is {14 7 8}. Here the array starts as an even element and has odd and even elements alternately.


    Example 2:

    Input:
    n = 2
    a[] = {4,6}
    
    Output: 1
    
    Explanation: The array contains {4 6}. So, we can only choose 1 element as that will be the max length subarray.
    
    Your Task:
    You don't need to take any input. Just complete the function maxEvenOdd() that returns the maximum length.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 <= n <= 10^6
    1 <= Ai <= 10^3
*/

//{ Driver Code Starts
//Initial Template for C++
#include<iostream> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
    //Function to find the length of longest subarray of even and odd numbers.
    int maxEvenOdd(int arr[], int n) 
    { 
        int count = 1; 
        bool turn = arr[0]%2 ? 0 : 1;
        int maxi = 1; 
        
        for(int i=1; i<n; i++){
            if(arr[i]%2 == turn){
                count++; 
                turn^=1;
            }
            else{
                count = 1;
                turn = arr[i]%2 ? 0 : 1;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int testcases;
    //testcases
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        //size of array
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        //calling function
        cout  << ob.maxEvenOdd(arr, sizeOfArray)<<endl; 
    }
   return 0; 
} 

// } Driver Code Ends