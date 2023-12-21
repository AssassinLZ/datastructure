#include <iostream>
#include <cmath>
#include <ctime>
clock_t start, stop;
double duration;
double f0(int n,double a[],double x)
{
    int i;
    double p = a[0];
    for ( i = 1; i <= n; i++)
    {
        p += (a[i] * pow(x, i));
    }
    return p;
}
double f1(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for ( i = n; i >0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}
int main()
{
    std::cout << "hello world" << std::endl;
    start = clock();

    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    system("pause");
    return 0;
}