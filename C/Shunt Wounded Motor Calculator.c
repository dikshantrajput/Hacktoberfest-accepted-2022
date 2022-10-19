#include <stdio.h>
    #include <math.h>

    int main(){  
    float  a,b=5.000000,c,d,f,j,pin,pout,n ,v,w,t,k,s,e,r;
    printf("\n K:");
    scanf("%f",&a);
    printf("\n V:");
    scanf("%f",&v);
    printf("\n Round Shunt external:");
    scanf("%f",&r);
    printf("\n S:");
    scanf("%f",&s);
    printf("\n E:");
    scanf("%f",&e);    
    c = v / (s+e);
    for(a;a<=5;a=a+0.225){
       
        d = c*a/b;
        printf(" \n Kø %f v/s = %f A \n" ,a,d);
        f = a * (r/60);
        s = f;
        f = v - f;
        j = f / (2.8+1.2);
        printf("%f Eb %f iA\n",s,j);
        pin = v * j + v * d;
        printf("%f W\n",pin);
        pout = s * j;
        printf("%f W \n", pout);
        if(pout/pin < 1.00000)
        {n = pout/pin*100;}
        else {
            n =	pin/pout*100;
        }
        printf("n = %f \n",n);

        w = 2*3.14*(r/60);
        t = pout / w;
        printf("w = %f rad/s t = %f Nm \n",w,t);
    }}
