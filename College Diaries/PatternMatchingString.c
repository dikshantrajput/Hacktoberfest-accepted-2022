#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int main() 
{ 
    char text[20],pat[20];
    int a,b;
    printf("Enter the String : ");
    gets(text);
    printf("Enter the Pattern to Find : ");
    gets(pat);
    
    a = strlen(pat); 
    b = strlen(text); 
  
    for (int i = 0; i <= b - a; i++) { 
        int j; 
  
        for (j = 0; j < a; j++) 
            if (text[i + j] != pat[j]) 
                break; 
  
        if (j == a)
            printf("Pattern Found at Position %d \n", i+1); 
    } 
    return 0;
}