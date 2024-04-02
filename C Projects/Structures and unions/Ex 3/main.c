/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct complex 
{
    float A ;
    float B;
};
int main()
{
    struct complex complex_1, complex_2;
    float sum_of_reals=0;
    float sum_of_imaginaries=0;
    printf("For 1st complex number\n");
    
    
    printf("Enter real and imaginary respectively :\t");
    scanf("%f", &complex_1.A);
    scanf("%f", &complex_1.B);
    printf("\n");
    printf("\n");

    printf("For 2nd complex number\n");
    
    
    printf("Enter real and imaginary respectively :\t");
    scanf("%f", &complex_2.A);
    scanf("%f", &complex_2.B);
    printf("\n");
    printf("\n");
    
    sum_of_reals = complex_1.A + complex_2.A;
    sum_of_imaginaries = complex_1.B + complex_2.B;
    
    
    printf("\n");
    printf("Sum of distances = %.2f+%.2fi\"",sum_of_reals,sum_of_imaginaries);
     

    
    

    return 0;
}
