#include <stdio.h>
#include <math.h>
#include <omp.h>

double integral(int N, double a)
{
    double sum=0;
    double dx = 1/(double)(N);
    
    for(int j=0; j <= N; ++j)
    {
        double x = dx*( j - 0.5 );
        sum += 1/(1 + a*x*x);
    }
    return dx*sum;
}  

int main(void)
{   
    double integral(int,double);

#pragma omp parallel for
    for (int i = 1; i <= 10; ++i)
    {
    printf("a=%i: Integral=%e, Difference=%e \n"
        ,i,integral(10000000,i)
        ,integral(10000000,i)-atan(sqrt(i))/sqrt(i));
    }
    
    return 0;
}

