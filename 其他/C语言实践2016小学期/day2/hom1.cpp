#include <iostream>
/*斐波那契数列1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233，377，610，987，1597，2584，4181.......*/
using namespace std;
int fib(int n)
{
    if(n==1||n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}
int main(int argc, char *argv[]) {
    int n,x;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>x;
            cout<<fib(x);
        }
    }
}