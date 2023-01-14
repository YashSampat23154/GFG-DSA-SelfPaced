/*
	Given n integer ranges, the task is to find the maximum occurring integer in these ranges. If more than one such integer exits, find the smallest one. The ranges are given as two arrays L[] and R[].  L[i] consists of starting point of range and R[i] consists of corresponding end point of the range.

	For example consider the following ranges.
	L[] = {2, 1, 3}, R[] = {5, 3, 9)
	
	Ranges represented by above arrays are.
	[2, 5] = {2, 3, 4, 5}
	[1, 3] = {1, 2, 3}
	[3, 9] = {3, 4, 5, 6, 7, 8, 9}
	
	The maximum occurred integer in these ranges is 3.

	Example 1:

	Input:
	n = 4
	L[] = {1,4,3,1}
	R[] = {15,8,5,4}

	Output: 4
	
	Explanation: The given ranges are [1,15] [4, 8] [3, 5] [1, 4]. The number that is most common or appears most times in the ranges is 4.

	Example 2:

	Input:
	n = 5
	L[] = {1,5,9,13,21}
	R[] = {15,8,12,20,30}
	
	Output: 5
	
	Explanation: The given ranges are  [1,15] [5, 8] [9, 12] [13, 20] 
	[21, 30]. The number that is most common or appears most times in 
	the ranges is 5.

	Your Task:
	The task is to complete the function maxOccured() which returns the maximum occured integer in all ranges.

	Expected Time Complexity: O(n+maxx).
	Expected Auxiliary Space: O(maxx).
	-maxx is maximum element in R[]


	Constraints:
	1 ≤ n ≤ 10^6
	0 ≤ L[i], R[i] ≤ 10^6
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        int a[maxx+3] = {0};
        for(int i=0; i<n; i++){
            a[L[i]]++;
            a[R[i]+1]--;
        }
        
        int pos = 0;
        for(int i = 1; i<=maxx; i++){
            a[i] += a[i-1];
            if(a[i]>a[pos]) pos = i;
        }
        
        return a[pos];
    }
};


// { Driver Code Starts.

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    Solution ob;
	    
	    //calling maxOccured() function
	    cout << ob.maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}  // } Driver Code Ends