/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct distance 
{
    int feet ;
    float inches;
};
int main()
{
    struct distance distance_1, distance_2;
    int sum_of_feet=0, temp =0;
    float sum_of_inches=0;
    printf("Enter information for the 1st distance\n");
    
    
    printf("Enter feet:\t");
    scanf("%d", &distance_1.feet);
    printf("\n");
    printf("Enter inches:\t");
    scanf("%f", &distance_1.inches);
    printf("\n");
    printf("\n");

    printf("Enter information for the 2nd distance\n");
    
    
    printf("Enter feet:\t");
    scanf("%d", &distance_2.feet);
    printf("\n");
    printf("Enter inches:\t");
    scanf("%f", &distance_2.inches);
    
    sum_of_inches = distance_1.inches + distance_2.inches;
    sum_of_feet = distance_1.feet + distance_2.feet + (sum_of_inches/12);
    temp = sum_of_inches / 12;
    sum_of_inches = sum_of_inches - (temp *12);
    printf("\n");
    printf("Sum of distances = %d\'-%.1f\"",sum_of_feet,sum_of_inches);
     

    
    

    return 0;
}
