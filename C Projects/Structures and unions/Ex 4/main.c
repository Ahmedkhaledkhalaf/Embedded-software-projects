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
    struct student info[10];
    printf("Enter information of the students\n\n");
    for(int i = 0; i<10; i++)
    {
        
    info[i].roll_num = i+1;
    printf("For roll number %d:\n",info[i].roll_num);
    fflush(stdin);
    fflush(stdout);
    printf("Enter name:\t");
    scanf("%s", &info[i].name);
    printf("\n");
    printf("Enter degree:\t");
    scanf("%f", &info[i].degree);
    printf("\n");
    printf("\n");
    }
    printf("\n\n\n Displaying information\n\n");
    for(int i = 0; i<10; i++)
    {
        
    printf("Information for roll number %d:\n",info[i].roll_num);
    printf("Name:\t%s\n", info[i].name);
    printf("Degree:\t%.2f\n", info[i].degree);
    printf("\n");
    printf("\n");
    }
    

    return 0;
}
