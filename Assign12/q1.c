#include <stdio.h>

struct Student
{
    int roll;
    char name[16];
    char address[64];
};

void inputStudent(struct Student *s)
{
    printf("Enter roll: ");
    scanf("%d", &(s->roll));
    printf("Enter name: ");
    fflush(stdin);
    fgets(s->name, 16, stdin);
    printf("Enter address: ");
    fflush(stdin);
    fgets(s->address, 64, stdin);
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    for (int i = 0; i < n; i++) // insersion sort
    {
        struct Student s;
        inputStudent(&s);
        int j = i - 1;
        while (j >= 0 && students[j].roll > s.roll)
        {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = s;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Student: %d\n\tRoll: %d\n\tName: %s\n\tAddress: %s\n", i, students[i].roll, students[i].name, students[i].address);
    }
    
    return 0;
}