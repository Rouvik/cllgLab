#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int roll;
    int marks;
    char name[32];
    char address[64];
} Student_t;

void writeStudents()
{
    printf("Enter number of students: ");
    int n;
    scanf("%d", &n);

    FILE *db = fopen("./student.dat", "w");
    if (!db)
    {
        perror("Failed to open student database file");
        exit(1);
    }

    fwrite(&n, sizeof(int), 1, db);

    Student_t students[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter roll: ");
        scanf("%d", &students[i].roll);

        printf("Enter marks: ");
        scanf("%d", &students[i].marks);

        while (getchar() != '\n');    // flush input stream
        
        printf("Enter name: ");
        fgets(students[i].name, 32, stdin);
        
        while (getchar() != '\n');    // flush input stream

        printf("Enter address: ");
        fgets(students[i].address, 64, stdin);
    }

    fwrite(students, sizeof(Student_t), n, db);

    fflush(db);
    fclose(db);
    printf("Write successfull!");
}

void readStudent(int roll)
{
    FILE *db = fopen("./student.dat", "r");
    if (!db)
    {
        perror("Failed to open student database to read");
        exit(1);
    }

    int n;
    fread(&n, sizeof(int), 1, db);

    Student_t students[n];
    fread(students, sizeof(Student_t), n, db);
    fclose(db);

    for (int i = 0; i < n; i++)
    {
        if (students[i].roll == roll)
        {
            printf("Name: %s\nAddress: %s\nMarks: %d\n", students[i].name, students[i].address, students[i].marks);

            return;
        }
    }

    printf("Student record not found...");
}

int main()
{
    printf("Mode: Read(r), Write(w): ");
    char mode;
    scanf("%c", &mode);

    if (mode == 'r')
    {
        printf("Enter student roll number: ");
        int roll;
        scanf("%d", &roll);

        readStudent(roll);
    }
    else
    {
        writeStudents();
    }
    
    return 0;
}