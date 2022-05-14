/*
    Given an integer N. Find the number of digits that appear in its factorial. 
    Factorial is defined as, factorial(n) = 1*2*3*4……..*N and factorial(0) = 1.
    

    Example 1:

    Input: N = 5
    Output: 3
    Explanation: Factorial of 5 is 120.
    Number of digits in 120 is 3 (1, 2, and 0)
    

    Example 2:

    Input: N = 120
    Output: 199
    Explanation: The number of digits in
    120! is 199

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function digitsInFactorial() that takes N as input parameter and returns number of digits in factorial of N.


    Expected Time Complexity : O(N)
    Expected Auxilliary Space : O(1)


    Constraints:
    1 ≤ N ≤ 10^5
*/

// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution_self{
    public:
    int digitsInFactorial(int N)
    {
        int count = 0;
        double ans = 1; 
        while(N){
            ans = ans*N--;
            while(ans>=1){
                ans/=10;
                count++;
            }
        }
        return count;
    }
};


/*
    A naive solution would be to calculate the n! first and then calculate the number of digits present in it. However as the value for n! can be very large, it would become cumbersome to store them in a variable (Unless you’re working in python!) . 
    A better solution would be to use the useful property of logarithms to calculate the required answer. 
    

    We know,
    log(a*b) = log(a) + log(b)

    Therefore
    log( n! ) = log(1*2*3....... * n) 
            = log(1) + log(2) + ........ +log(n)

    Now, observe that the floor value of log base 10 increased by 1, of any number, gives the number of digits present in that number.

    Hence, output would be : floor(log(n!)) + 1.
*/


class Solution_efficient1{
    public:
    int digitsInFactorial(int N)
    {
        if (N < 0)  return 0;
        if (N <= 1) return 1;

        double digits = 0;
        for(int i = 1; i<=N; i++){
            digits += log10(i);
        }
        return floor(digits)+1;
    }
};

/*
    The above solution would not be able to handle cases where n >10^6 
    So, can we improve our solution ? 
    Yes ! we can. 
    We can use Kamenetsky’s formula to find our answer ! 
    

    It approximates the number of digits in a factorial by :
    f(x) =    log10( ((n/e)^n) * sqrt(2*pi*n))

    Thus, we can pretty easily use the property of logarithms to,
    f(x) = n* log10(( n/ e)) + log10(2*pi*n)/2 
    And that’s it ! 

    Our solution can handle very large inputs that can be accommodated in a 32 bit integer, and even beyond that ! 

    More about Kamenetsky's formula : https://dev.to/remonhasan/kamenetsky-s-algorithm-3gj9
*/

class Solution_efficient2{
    public:
    int digitsInFactorial(int N)
    {
        if (N < 0)  return 0;
        if (N <= 1) return 1;
 
        double digits = N * log10(N/M_E) + log10(2*M_PI*N)/2.0;
 
    return floor(digits) + 1;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution_efficient2 ob;
        //calling method digitsInFactorial()
        cout<<ob.digitsInFactorial(N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends