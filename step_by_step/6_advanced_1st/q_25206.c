#include <stdio.h>
#include <string.h>

int main()
{
    double sum_credit;
    double sum_grade;
    double graduate_grade;

    for(int i = 0; i < 20; i++)
    {
        char subject[52];
        double credit;
        char grade[3]; // [2]grade + [1]NULL

        scanf("%s %lf %s", &subject, &credit, &grade);

        if(strcmp(grade, "P") == 0)
            continue;
        
        else if(strcmp(grade, "A+") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 4.5;
        }

        else if(strcmp(grade, "A0") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 4.0;
        }

        else if(strcmp(grade, "B+") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 3.5;
        }

        else if(strcmp(grade, "B0") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 3.0;
        }

        else if(strcmp(grade, "C+") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 2.5;
        }

        else if(strcmp(grade, "C0") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 2.0;
        }

        else if(strcmp(grade, "D+") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 1.5;
        }

        else if(strcmp(grade, "D0") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 1.0;
        }

        else if(strcmp(grade, "F") == 0)
        {
            sum_credit += credit;
            sum_grade += credit * 0;
        }
    }

    if(sum_credit != 0.0)
        graduate_grade = sum_grade / sum_credit;


    printf("%lf", graduate_grade);

    return 0;
}