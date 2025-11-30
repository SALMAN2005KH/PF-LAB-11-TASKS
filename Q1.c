#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float marks[3];
    float percentage;
    char grade[3];
};

void calculateGrade(struct Student *s) {
    float total = s->marks[0] + s->marks[1] + s->marks[2];
    s->percentage = total / 3;

    if (s->percentage >= 90) strcpy(s->grade, "A+");
    else if (s->percentage >= 80) strcpy(s->grade, "A");
    else if (s->percentage >= 70) strcpy(s->grade, "B+");
    else if (s->percentage >= 60) strcpy(s->grade, "B");
    else if (s->percentage >= 50) strcpy(s->grade, "C");
    else strcpy(s->grade, "F");
}

int main() {
    struct Student s[100];
    int n, choice;
    float classAvg, sum = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter marks in 3 subjects: ");
        scanf("%f %f %f", &s[i].marks[0], &s[i].marks[1], &s[i].marks[2]);

        calculateGrade(&s[i]);
        sum += s[i].percentage;
    }

    classAvg = sum / n;

    while (1) {
        printf("\n1. Display all students\n2. Find students by grade\n3. Show class average\n4. Students above/below average\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            for (int i = 0; i < n; i++)
                printf("\nName: %s  Roll: %d  %%: %.2f  Grade: %s",
                       s[i].name, s[i].roll, s[i].percentage, s[i].grade);
        }

        else if (choice == 2) {
            char g[3];
            printf("Enter grade to search: ");
            scanf("%s", g);

            for (int i = 0; i < n; i++)
                if (strcmp(s[i].grade, g) == 0)
                    printf("\nName: %s  Roll: %d  %%: %.2f  Grade: %s",
                           s[i].name, s[i].roll, s[i].percentage, s[i].grade);
        }

        else if (choice == 3) {
            printf("\nClass Average: %.2f\n", classAvg);
        }

        else if (choice == 4) {
            printf("\nStudents Above Average:\n");
            for (int i = 0; i < n; i++)
                if (s[i].percentage > classAvg)
                    printf("%s (%.2f)\n", s[i].name, s[i].percentage);

            printf("\nStudents Below Average:\n");
            for (int i = 0; i < n; i++)
                if (s[i].percentage < classAvg)
                    printf("%s (%.2f)\n", s[i].name, s[i].percentage);
        }

        else if (choice == 5) {
            break;
        }
    }

    return 0;
}
