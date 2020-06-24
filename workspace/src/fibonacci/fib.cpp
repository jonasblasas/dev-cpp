#include <bits/stdc++.h>

using namespace std;

int fib_rec(int n)
{
    if(n <= 2)
    {
        return 1;
    }

    return fib_rec(n-1)+fib_rec(n-2);
}

int fib_loop(int n)
{
    int f[n+1];
    int i;

    f[0] = 1;
    f[1] = 1;

    for(i = 2; i <= n; i++)
    {
        f[i] = f[i-1]+f[i-2];
    }

    return f[n-1];
}

int main()
{
    cout << "program start" << endl;

    cout << "recursive fibonacci n=10: " << fib_rec(10) << endl;
    cout << "looped fibonacci n=10: " << fib_loop(10) << endl;

    cout << "program finish" << endl;

    return 0;
}