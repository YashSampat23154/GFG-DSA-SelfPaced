#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

// struct Values{
// int x;
// };

 /*
    A quadratic equation is representated by : ax^2 + bx + c = 0 
    Here we take the value of a, b, and c from the user.
    We calculate the root via the formula : 

    x = (-b +- sqrt(b^2 - 4*a*c))/2*a;

    Discriminant D = b^2 - 4*a*c;

    if, 
    D < 0 : Imaginary roots
    D = 0 : Two equal roots
    D > 0 : Two distinct roots

 */

using namespace std;

void QuadraticRoots(int a, int b, int c){
    double d = b*b - 4*a*c;
    double x1 = (-b + sqrt(d))/(2*a);
    double x2 = (-b - sqrt(d))/(2*a);

    cout<<"Roots are : "<<x1<<" and "<<x2<<endl;
}

int main(){

    fastio;

    QuadraticRoots(6, 11, -35);

    return 0;
}
