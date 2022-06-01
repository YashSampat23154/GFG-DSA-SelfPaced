/*
    Given a quadratic equation in the form ax2 + bx + c. Find its roots.

    Note: Return the maximum root followed by the minimum root.

    Example 1:

    Input:
    a = 1
    b = -2
    c = 1
    Output: 1 1
    Explanation:
    Roots of equation x2-2x+1 are 1 and 1.

    Example 2:

    Input:
    a = 1
    b = -7
    c = 12
    Output: 4 3
    Explanation: Roots of equation 
    x2 - 7x + 12 are 4 and 3.
    

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function quadraticRoots() which takes a, b, c as input parameters and returns a list of two integers containing the floor value of its roots in decreasing order. If roots are imaginary, the returning list should contain only 1 integer ie -1. Always return the greatest integer smaller than or equal to the result.
    Note: If roots are imaginary, the generated output will display "Imaginary".


    Expected Time Complexity: O(1)
    Expected Auxiliary Space : O(1)
    

    Constraints:
    -10^3 <= a,b,c <= 10^3
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        vector<int> v;
        double d = b*b - 4*a*c;
        if(d<0){
            v.push_back(-1);
        }
        else if(d == 0){
            v.push_back(floor(-b/(2*a)));
            v.push_back(floor(-b/(2*a)));
        }
        else{
            d = sqrt(d);
            int x1 = floor((-b+d)/(double)(2*a));
            int x2 = floor((-b-d)/(double)(2*a));
            
            if(x1>x2){
                v.push_back(x1);
                v.push_back(x2);
            }
            else {
                v.push_back(x2);
                v.push_back(x1);    
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
