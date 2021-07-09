#include <iostream>
using namespace std;
int factorial(int numb,int power)
{
    if (power <= 0)
        return 1;
    else
        return numb * factorial(numb,power-1);
}//-------------------------------------------
int main()
{
    int n,x;
    cout << " \n Enter no + exponential of that no you want to compute.\n";
    cin >> x>>n;
    cout << "\n Result of " << x << " ^ " << n << " is "<<factorial(x,n);
    return 0;

}// end of main().
