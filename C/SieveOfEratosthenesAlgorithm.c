//Sieve Of Eratosthenes Algorithm to generate prime numbers till a given number 

#include <stdio.h>
int main (void){
    int i,j,prime[10000],n;
    printf("finding primes till");
    scanf("%d",&n);
    for (i=2;i<=n;i++){
        prime[i]=1;
    }
    for (i=2;i<=n;i++){
        if (prime[i]){
            for (j=i;i*j<=n;j++){
                prime[i*j]=0;
            }
                
        }
    }
    printf("the prime numbers are \n");
    for (i=2;i<=n;i++)
    if(prime[i])
    printf("%d\n",i);
    return 0;
}
