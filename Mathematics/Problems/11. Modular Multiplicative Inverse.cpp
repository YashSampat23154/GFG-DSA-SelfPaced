/*
    Given two integers ‘a’ and ‘m’. The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’.

    Example 1:

    Input:
    a = 3
    m = 11
    Output: 4
    Explanation: Since (4*3) mod 11 = 1, 4 
    is modulo inverse of 3. One might think,
    15 also as a valid output as "(15*3)
    mod 11"  is also 1, but 15 is not in 
    ring {0, 1, 2, ... 10}, so not valid.
    

    Example 2:

    Input:
    a = 10
    m = 17
    Output: 12
    Explanation: Since (12*10) mod 17 = 1,
    12 is the modulo inverse of 10.
    

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function function modInverse() that takes a and m as input parameters and returns modular multiplicative inverse of ‘a’ under modulo ‘m’. If the modular multiplicative inverse doesn't exist return -1.

  
    Expected Time Complexity : O(m)
    Expected Auxilliary Space : O(1)

    

    Constraints:
    1 <= a <= 104
    1 <= m <= 104
*/

// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int gcd(int a, int b){
        if(b == 0) return a; 
        return gcd(b, a%b);
    }
    
    int EEA_M(int a, int b, int *x, int *y, int M){
        if(b == 0){
            *x = 1;
            *y = 0;
            return a;
        }
        else{
            int x1, y1;
            EEA_M(b, a%b, &x1, &y1, M);
            *x = y1%M;
            *y = (x1%M - ((a/b)*y1)%M + M)%M;
            
            return *x;
        }
    }
    
    
    int modInverse(int a, int m)
    {
        if(gcd(a,m) != 1 || m==1) return -1;
        int x, y;
        return EEA_M(a, m, &x, &y, m);
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends