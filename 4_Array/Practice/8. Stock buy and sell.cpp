/*
    The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and sell the stock so that in between those days your profit is maximum.

    Note: Since there can be multiple solutions, the driver code will print 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will print the string "No Profit" for a correct solution.

    Example 1:

    Input:
    N = 7
    A[] = {100,180,260,310,40,535,695}

    Output:
    1
    
    Explanation:
    One possible solution is (0 3) (4 6). We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit. Now, we buy stock on day 4 and sell it on day 6.


    Example 2:

    Input:
    N = 5
    A[] = {4,2,2,2,4}
    
    Output:
    1
    
    Explanation:
    There are multiple possible solutions. One of them is (3 4). We can buy stock on day 3, and sell it on 4th day, which will give us maximum profit.

    Your Task:
    The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs i.e. first value of pair will represent the day on which you buy the stock and second value represent the day on which you sell that stock. If there is No Profit, return an empty list.


    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)


    Constraints:
    2 ≤ N ≤ 10^6
    0 ≤ A[i] ≤ 10^6
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> ans;
        
        bool buy = false;
        int start = -1, end = -1; 
        
        for(int i = 0; i<n-1; i++){
            
            if(!buy && A[i]<A[i+1]){
                start = i;
                buy = true;
            }
            
            if(buy && A[i]>A[i+1]){
                end = i;
                
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                
                ans.push_back(temp);
                
                start = -1; end = -1;
                buy = false;
            }
        }
        
        if(start != -1){
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(n-1);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends