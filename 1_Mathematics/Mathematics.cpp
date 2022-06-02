#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

/*
    Count the digits of a number.

    Time Complexity : O(1) 
    Space Complexity : O(1)   
*/
int Countdigits(int n){
    return ceil(log10(n+1));
}


/*
    To check if a no is palindrome.
   
    Time Complexity : O(d) where d is the number of digits in our number.
    Space Complexity : O(1)
*/
void PalindromeNumber(int n){
    int temp = n;
    int rev = 0;
    while(temp!=0){
        rev = rev*10+temp%10;
        temp/=10;
    }
    if(rev == n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


/*
    To find factorial of a number.

    Time Complexity : O(n) 
    Space Complexity : O(1)
*/
ll Factorial(int n){
    ll ans = 1;
    while(n){
        ans = ans*n--;
    }
    return ans;
}


/*
    To calculate the no of trailing zero of any factorial.

    Time Complexity : O(log5(n))
    Space Complexity : O(1)
*/
ll Trailing_Zero_in_Factorial(ll n){
    ll temp = n;
    ll ans = 0;
    while(temp!=0){
        ans+= temp/5;
        temp/=5;
    }
    return ans;
}


/*
   To calculate GCD/HCF and LCM 
*/
// Time Complexity : O(log(min(a, b))
// Space Complexity : O(1)
ll EuclideanAlgo(ll a, ll b){
    if(b == 0)  return a;
    else return EuclideanAlgo(b, a%b);
}

// Time Complexity : O(log(min(a, b))
// Space Complexity : O(1)
ll ExtendedEuclideanAlgo(ll a, ll b, ll *x, ll *y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a; 
    }
    else{
        ll x1, y1; 
        ll gcd = ExtendedEuclideanAlgo(b, a%b, &x1, &y1);

        *x = y1;
        *y = x1 - (a/b)*y1;

        return gcd;
    }
}

// Time Complexity : O(log(min(a, b))
// Space Complexity : O(1)
ll lcm_efficient(ll a, ll b){
    return a/__gcd(a,b)*b;
}


/*
    To check whether a number is prime.

    Time Complexity : O(sqrt(n)/3)
    Space Complexity : O(1)
*/
bool isPrime(ll n){
    if(n == 2 || n == 3) return true;
    if(n == 1 || n%2 == 0 || n%3 == 0) return false;    
    for(int i = 5; i*i<=n; i+=6)
        if(n%i == 0 || n%(i+2) == 0) return false;
    return true;
}


/*
    To find prime factors of a number.

    Time Complexity : O(sqrt(n)/6)
    Space Complexity : O(1)
*/
void PrimeFactors(ll n){
    if(n <= 1) return;

    while(n%2 == 0){
        cout<<"2 ";
        n/=2;
    }
    while(n%3 == 0){
        cout<<"3 ";
        n/=3;
    } 

    for(int i=5; i*i<=n; i+=6){
        while(n%i == 0){
            cout<<i<<" ";
            n/=i;
        
        }
        while(n%(i+2) == 0){
            cout<<i+2<<" ";
            n/=(i+2);
        }
         
    }
    if(n>3) cout<<n<<" ";

    cout<<endl;
    return;
}


/*
    To find all the prime numbers <=n

    Time Complexity : O(nloglog(sqrt(n))) = O(nloglogn)
    Space Complexity : O(n)
*/
void Sieve_of_Eratosthenes(ll n){
    vector<bool> prime(n+1, true);
    
    for(int i=2; i<=n; i++){ 
        if(prime[i]){
            cout<<i<<" ";
            for(int j = i*i; j<=n; j+=i) 
                prime[j] = false;
        }
    }

    cout<<endl;

    return;
}


/*
    To calculate x^n;

    Time Complexity : O(log n)
    Space Complexity : O(1)
*/
ll CountPower(ll x, ll n){
    ll temp = x, ans = 1;
    while(n!=0){
        if(n&1) ans*=temp;
        temp*=temp;
        n=n>>1;
    }
    return ans;
}


/*
    To calculate mean and median.
    
    Mean = The mean is found by adding up all the given data and dividin by the number of data entries.

    Median : The middle number : found by ordering all data points and picking out the one in the middle (or if there are two middle numbers, taking the mean of those two numbers)
*/
// Time Complexity : O(n)
// Space Complexity : O(n)
double Mean(int a[], int n){
    double result = 0;
    for(int i = 0; i<n; i++){
        result += a[i];
    }
    return result/n;
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)
double Median(int a[], int n){
    sort(a, a+n);
    if(n%2 == 0)
        return (double)(a[n/2-1] + a[n/2])/2;
    else return a[n/2];
}


/*
    To calculate permutations and combinations.
*/
// Time Complexity : O(r)
// Space Complexity : O(1)
ll Permutation(ll n, ll r){
    ll ans = 1; 
    while(r--){
        ans*=n--;
    }
    return ans; 
}

// Time Complexity : O(r)
// Space Complexity : O(1)
double Combination(ll n, ll r){
    ll num = 1, denom = 1; 
    if(r>n-r) r = n-r;
    while(r){
        num*=n--;
        denom*=r--; 
    }
    return num/(double)denom; 
}

/*
    To solve a quadratic equation.

    Time Complexity : O(1)
    Space Complexity : O(1)
*/
void QuadraticRoots_print(int a, int b, int c){
    double d = b*b - 4*a*c;
    double x1 = (-b + sqrt(d))/(2*a);
    double x2 = (-b - sqrt(d))/(2*a);

    cout<<"Roots are : "<<x1<<" and "<<x2<<endl;
}


vector<int> QuadraticRoots_return(int a, int b, int c) {
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



/*
    To find Modulor Inverse.
    
    We can use Extended Eucleadian Algorithm or Fermats Little Theorum.

    Extended Euclidean Algorithm: This method can be used when a and M are co-prime.
    Fermat Little Theorem: This method can be used when M is prime.

    Let us look at each of the above two methods in details:

    Extended Euclidean algorithm that takes two integers 'a' and 'b', finds their gcd and also find 'x' and 'y' such that,
    ax + by = gcd(a, b)

    To find the modulo inverse of 'a' under 'M', we put b = M in the above formula. Since we know that a and M are relatively prime, we can put value of gcd as 1.

    So, the formula becomes:
    ax + My = 1 

    If we take modulo M on both sides, we get:
    ax + My ≡ 1 (mod M)

    We can remove the second term on the left side, as 'My (mod M)' would always be 0 for an integer y.

    Therefore,
    ax  ≡ 1 (mod M) 

    So the 'x' that we can find using Extended Euclid Algorithm is modulo inverse of 'a'.



    Fermat Little Theorem: The Fermat’s little theorem states that if M is a prime number, then for any integer a, the number a^M – a is an integer multiple of M.

    a^M – a = kM

    So, 
    a^M - kM = a

    That is,
    a^M ≡ a (mod M).


    Since, a and M are co-prime to each other then a^(M-1) is an integral multiple of M.
    That is,
    a^(M-1) ≡ 1 (mod M)
    If we multiply both sides by a^(-1), we get:
    a^(-1) ≡ a(M-2) mod M

    Therefore, if M is a prime number to find modulo inverse of a under M, find modular exponentiation of a^(M-2) under modulo M.
*/
// Time Complexity : O(nloglogn)
// Space Complexity : O(1)
ll EEA_M(ll a, ll b, ll *x, ll *y, ll M){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a; 
    }
    else{
        ll x1, y1; 
        ll gcd = EEA_M(b, a%b, &x1, &y1, M);

        *x = y1%M;
        *y = (x1%M - ((a/b)*y1)%M + M)%M;

        return gcd;
    }
}

// This fails to work for relatively large values of a or b
// Time Complexity : O(logn)
// Space Complexity : O(1)
ll BE_M(ll a, ll b, ll M){
    ll ans = 1, temp = a;

    while(b!=0){
        if(b&1) ans=(ans*temp)%M;
        temp=(temp*temp)%M;
        b = b>>1;
    }

    return ans;
}


/*
    To find 'x' which satisfies the chinese remainder theorum.

    Chinese Remainder Theorem Statement: 
    Let num[0], num[1], …num[k-1] be positive integers that are pairwise coprime. Then, for any given sequence of integers rem[0], rem[1], … rem[k-1], there exists an integer x solving the following system of simultaneous congruences.
    Futhermore, all solutions x of this system are congruent modulo the product, prod = num[0] * num[1] * ...* num[n-1]

    The efficient solution is based on the formula : 
    x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod; Where 0 <= i <= n-1

    rem[i] is given array of remainders

    prod is product of all given numbers
    prod = num[0] * num[1] * ... * num[k-1]

    pp[i] is product of all divided by num[i]
    pp[i] = prod / num[i]

    inv[i] = Modular Multiplicative Inverse of pp[i] with respect to num[i]

    Time Complexity : O(k*N*loglogN)
    Auxiliary Space : O(1)
*/
ll chinese_remainder_theorem_efficient(ll num[], ll rem[], ll k)
{
    ll prod = 1;
    for (int i = 0; i < k; i++){
        prod *= num[i];
    }
      
    ll result = 0, pp, x, y, gcd;
    for (int i = 0; i < k; i++) {
        pp = prod / num[i];
        gcd = EEA_M(pp, num[i], &x, &y, prod);
        result = (result + (rem[i]%prod * x%prod * pp%prod)%prod)%prod;
    }
 
    return result;
}


/*
    To count the no of digits in N!

    The best solution would be to use the useful property of logarithms to calculate the required answer. 
    

    We know,
    log(a*b) = log(a) + log(b)

    Therefore
    log( n! ) = log(1*2*3....... * n) 
            = log(1) + log(2) + ........ +log(n)

    Now, observe that the floor value of log base 10 increased by 1, of any number, gives the number of digits present in that number.

    Hence, output would be : floor(log(n!)) + 1.

    Time Complexity : O(N)
    Auxilliary Space : O(1)
*/
int digitsInFactorial1(int N){
    if (N < 0)  return 0;
    if (N <= 1) return 1;

    double digits = 0;
    for(int i = 1; i<=N; i++){
        digits += log10(i);
    }
    return floor(digits)+1;
}

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

    Time Complexity : O(1)
    Auxilliary Space : O(1)
*/

int digitsInFactorial2(int N){
    if (N < 0)  return 0;
    if (N <= 1) return 1;

    double digits = N * log10(N/M_E) + log10(2*M_PI*N)/2.0;

    return floor(digits) + 1;
}


/*
    Given a positive integer value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.

    Time Complexity : O(N^1/2 * N^1/4)
    Auxilliary Space :  O(1)
*/
int exactly3Divisors(int N){
    int count = 0;
    if(N>=4) count++;
    if(N>=9) count++;
    
    for(int i = 5; i*i <= N ; i+=6){
        if(isPrime(i)) count++;
        if((i+2)*(i+2) <= N && isPrime(i+2)) count++;
    }
    
    return count;
}

int main(){

    fastio;

    return 0;
}
