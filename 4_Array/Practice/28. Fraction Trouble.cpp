/*
    Consider the set of irreducible fractions A = {n/d | n≤d and d ≤ 10000 and gcd(n,d) = 1}.You are given a member of this set and your task is to find the largest fraction in this set less than the given fraction.
    Note : this is a set and so all the members are unique.

    Example 1:

    Input: n = 1, d = 8
    
    Output: 1249 9993

    Explanation: 1/8 >= 1249/9993 and this is the largest fraction. 
    
    Example 2:

    Input: n = 2, d = 53
    
    Output: 377 9991
    
    Explanation: 2/53 >= 377/9991 and this is the largest fraction.
    

    Your Task:
    You don't need to read or print anything. Your task is to complete the function LargestFraction() which takes n and d as input parameter and returns the largest irreducible fraction in a list where the first element denotes the numerator and second elements denotes the denominator of the fraction.

    Expected Time Complexity: O(K) where K <= 10000
    Expected Space Complexity: O(1)

    Constraints: 
    1 <= n <= d <= 10000
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int>LargestFraction(int n, int d){
	    
	    int num = -1, den = 1;
        
        for(int y = 10000; y>=2 ; --y){
            
            int x = (n * y -1)/d;
            
            if((__gcd(x, y) == 1) && x*den >= y*num){
                num = x;
                den = y;
            }
        }
        
        return {num, den};
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, d;
		cin >> n >> d;
		Solution ob;
		vector<int>ans = ob.LargestFraction(n, d);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends