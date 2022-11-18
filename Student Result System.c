#include<stdio.h>
#include<stdlib.h>
int roll_number, marks[3], total;
float percentage;
char name[10];
FILE *f;
int is_exists(int r_no)
{
    int found = 0;
    while(!feof(f))
    {
        fscanf(f, "%d%s", &roll_number, name);
        for(int i = 0; i <= 2; i++)
        {
            fscanf(f, "%d", &marks[i]);
        }
        fscanf(f, "%d%f", &total, &percentage);
        if(r_no == roll_number)
        {
            found = 1;
            break;
        }
    }
    fclose(f);
    return found;
}
void add_new_student_details()
{
    system("cls");
    int r_no;
    f = fopen("SRS.txt", "r");
    printf("\nEnter roll number: ");
    scanf("%d", &r_no);
    if(!is_exists(r_no))
    {
        fclose(f);
        f = fopen("SRS.txt", "a");
        roll_number = r_no;
        printf("\nEnter name: ");
        scanf("%s", name);
        fprintf(f, "%d %s ", roll_number, name);
        total = 0;
        for(int i = 0; i <= 2; i++)
        {
            printf("\nEnter marks of subject %d: ", i + 1);
            scanf("%d", &marks[i]);
            fprintf(f, "%d ", marks[i]);
            total += marks[i];
        }
        percentage = (float) total / 3;
        fprintf(f, "%d %f\n", total, percentage);
        fclose(f);
        printf("\nStudent details are added successfully\n");
    }
    else
    {
        printf("\nStudent of %d roll number is already added\n", r_no);
    }
}
void view_all_students_details()
{
    system("cls");
    f = fopen("SRS.txt", "r");
    printf("\nDetails of all students are\n");
    while(1)
    {
        fscanf(f, "%d%s", &roll_number, name);
        for(int i = 0; i <= 2; i++)
        {
            fscanf(f, "%d", &marks[i]);
        }
        fscanf(f, "%d%f", &total, &percentage);
        if(feof(f))
        {
            break;
        }
        printf("\nRoll Number: %d\nName: %s\n", roll_number, name);
        for(int i = 0; i <= 2; i++)
        {
            printf("Marks of subject %d: %d\n", i + 1, marks[i]);
        }
        printf("Total: %d\nPercentage: %.2f\n", total, percentage);
    }
    fclose(f);
}
void search_student_details()
{
    system("cls");
    int r_no, found = 0;
    printf("\nEnter roll number: ");
    scanf("%d", &r_no);
    f = fopen("SRS.txt", "r");
    while(!feof(f))
    {
        fscanf(f, "%d%s", &roll_number, name);
        for(int i = 0; i <= 2; i++)
        {
            fscanf(f, "%d", &marks[i]);
        }
        fscanf(f, "%d%f", &total, &percentage);
        if(roll_number == r_no)
        {
            found = 1;
            printf("\nDetails of student are\n");
            printf("\nRoll Number: %d\nName: %s\n", roll_number, name);
            for(int i = 0; i <= 2; i++)
            {
                printf("Marks of subject %d: %d\n", i + 1, marks[i]);
            }
            printf("Total: %d\nPercentage: %.2f\n", total, percentage);
            break;
        }
    }
    fclose(f);
    if(!found)
    {
        printf("\nStudent of %d roll number does not exist\n", r_no);
    }
}
int main()
{
    f = fopen("SRS.txt", "a");
    fclose(f);
    int ch;
    do
    {
        system("cls");
        printf("\nEnter 1 to add new student details\n"
        "\nEnter 2 to view all students details\n"
        "\nEnter 3 to search student details\n"
        "\nEnter 4 to exit from application\n"
        "\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            add_new_student_details();
            break;
        case 2:
            view_all_students_details();
            break;
        case 3:
            search_student_details();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice entered\n");
        }
        printf("\nEnter 0 to goto main menu\n");
        scanf("%d", &ch);
    }
    while(ch == 0);
    return 0;
}
