/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct student 
{
    char name[30];
    char roll_num;
    float degree;
};
int main()
{
    struct student info;
    printf("Enter information of the student\n\n");
    
    printf("Enter name:\t");
    gets(info.name);
    fflush(stdin);
    printf("\n");
    printf("Enter roll number:\t");
    scanf("%d", &info.roll_num);
    printf("\n");
    printf("Enter degree:\t");
    scanf("%f", &info.degree);
    
    printf("\n\n\n Displaying information\n\n");
    printf("Name:\t%s\n", info.name);
    printf("Roll number:\t%d\n",info.roll_num);
    printf("Degree:\t%.2f\n", info.degree);
    
    

    return 0;
}
