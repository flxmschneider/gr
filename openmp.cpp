#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

double integral(int N, double a)
{
    double sum=0;
    double dx = 1/(double)(N);
    
#pragma omp parallel for reduction(+:sum)
    for(int j=0; j <= N; ++j)
    {
        double x = dx*( j - 0.5 );
        sum += 1/(1 + a*x*x);
    }
    return dx*sum;
}  

int main(void)
{   
    int startTime = time(NULL);
    double integral(int,double);
  
    for (int i = 1; i <= 10; ++i)
    {
    printf("a=%i: Integral=%e, Difference=%e \n"
        ,i,integral(10000000,i)
        ,integral(100000000,i)-atan(sqrt(i))/sqrt(i));
    }
    
    printf("Time needed: %i seconds\n"
        ,(int)(time(NULL)-startTime));
    return 0;
}


