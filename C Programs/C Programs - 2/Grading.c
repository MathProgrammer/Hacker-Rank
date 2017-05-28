#include <stdio.h>

int main()
{
    int no_of_students, grade, i;
    scanf("%d",&no_of_students);

    for(i = 1; i <= no_of_students; i++)
    {
        scanf("%d", &grade);

        grade = (grade < 38 || grade%5 < 3 ? grade : grade + (5 - grade%5));

        printf("%d\n",grade);
    }
    return 0;
}
