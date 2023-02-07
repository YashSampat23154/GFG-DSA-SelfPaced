/*
    Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.
    Note: The elements greater than N in the array can be ignored for counting and do modify the array in-place.

    Example 1:

    Input:
    N = 5
    arr[] = {2, 3, 2, 3, 5}
    P = 5

    Output:
    0 2 2 0 1

    Explanation: 
    Counting frequencies of each array element

    We have:
    1 occurring 0 times.
    2 occurring 2 times.
    3 occurring 2 times.
    4 occurring 0 times.
    5 occurring 1 time.


    Example 2:

    Input:
    N = 4
    arr[] = {3,3,3,3}
    P = 3

    Output:
    0 0 4 0

    Explanation: 
    Counting frequencies of each array element

    We have:
    1 occurring 0 times.
    2 occurring 0 times.
    3 occurring 4 times.
    4 occurring 0 times.

    Your Task:
    You don't need to read input or print anything. Complete the function frequencycount() that takes the array and n as input parameters and modify the array itself in place to denote the frequency count of each element from 1 to N. i,e element at index 0 should represent the frequency of 1, and so on.


    Can you solve this problem without using extra space (O(1) Space)?


    Constraints:
    1 ≤ N ≤ 10^5
    1 ≤ P ≤ 4*10^4 
    1 <= A[i] <= P

*/


// O(n) Space solution : 
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int maxi = max(P,N);
    	vector<int> count(maxi+1,0);
        for(int i=0;i<N;i++){
            count[arr[i]]+=1;
        }
        for(int i=0;i<N;i++){
            arr[i] = count[i+1];
        }
    }
};


// { Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}




  // } Driver Code Ends



// O(1) Space solution : 
// C++ program to print frequencies of all array
// elements in O(1) extra space and O(n) time
#include<bits/stdc++.h>
using namespace std;
 
// Function to find counts of all elements present in
// arr[0..n-1]. The array elements must be range from
// 1 to n
void printfrequency(int arr[],int n)
{
    // Subtract 1 from every element so that the elements
    // become in range from 0 to n-1
    for (int j =0; j<n; j++)
        arr[j] = arr[j]-1;
 
    // Use every element arr[i] as index and add 'n' to
    // element present at arr[i]%n to keep track of count of
    // occurrences of arr[i]
    for (int i=0; i<n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;
 
    // To print counts, simply print the number of times n
    // was added at index corresponding to every element
    for (int i =0; i<n; i++)
        cout << i + 1 << " ->  " << arr[i]/n << endl;
}
 
// Driver program to test above function
int main()
{
    int arr[] = {2, 3, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printfrequency(arr,n);
    return 0;
}


