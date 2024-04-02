/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define pi 3.14
#define Area(r) (pi * r * r)
int main()
{
 float radius = 0;
 printf("please enter the radius\t");
 scanf("%f",&radius);
 printf("Area = %.2f", Area(radius));

    return 0;
}
