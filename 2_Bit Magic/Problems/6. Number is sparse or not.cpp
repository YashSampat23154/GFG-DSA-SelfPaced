/*
    Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.

    Example 1:

    Input: N = 2
    Output: 1
    Explanation: Binary Representation of 2 is 10, 
    which is not having consecutive set bits. 
    So, it is sparse number.
    Example 2:

    Input: N = 3
    Output: 0
    Explanation: Binary Representation of 3 is 11, 
    which is having consecutive set bits in it. 
    So, it is not a sparse number.

    Your Task: The task is to complete the function checkSparse() that takes n as a parameter and returns 1 if the number is sparse else returns 0.


    Expected Time Complexity: O(log N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 <= N <= 10^6
*/

// { Driver Code Starts
//Initial Template for C++

// C++ program to check if n is sparse or not
#include<iostream>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if the number is sparse or not.
    bool isSparse(int n)
    {   
        int curr;
        while(n!=0){
            curr = n&1;
            if(curr == 1 && (n>>1)&1 == 1) return false;
            n = n>>1;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t,n;
    
    //testcases
    cin>>t;
    while(t--)
    {
        //initializing n
        cin>>n;
        
        //printing 1 if isSparse() returns true
        //else 0
        Solution ob;
        if(ob.isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}
  // } Driver Code Ends