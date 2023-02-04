#include <stdio.h>
#include <math.h>
long int factorial(int i){
    if(i==1 || i==0){
        return i;
    }
    return i*factorial(i-1);
}
void math_function(int n){
    long double function[10]= {3/2*n, pow(n, 3), n, pow(2, n), log(n), exp(n), log2(log2(n)), n*log2(n), log2(n), sqrt(log2(n))};
    
    for(int i=0;i<10;i++){
        printf("%.2Lf",function[i]);
        printf("\t");
    }
    long int fact = factorial(n);
    printf("%ld",fact);

}


int main(){
    printf("\t3/2*n\tpow(n,3)\tn\tpow(2,n)\tlog(n)\texp(n)\tlog2(log2(n))\tn*log2(n)\tlog2(n)\tsqrt(log2(n))\tn!\n");
    for(int i=1;i<=20;i++){
        printf("%d\t",i);
        math_function(i);
        printf("\n");
    }
    return 0;
}
