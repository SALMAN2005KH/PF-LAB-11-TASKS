#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeId;
    char employeeName[50];
    char employeeDepartment[20];
    char employeeDesignation[20];
    float employeeSalary;
    char joiningDate[20];
    char employeePhone[20];
    char employeeEmail[50];
    int yearsOfExperience;
};

int calculateExperience(int joiningYear) {
    int currentYear = 2025;
    return currentYear - joiningYear;
}

void calculateDepartmentWiseSalary(struct Employee employees[], int totalEmployees) {
    float totalIT = 0, totalHR = 0, totalFinance = 0, totalMarketing = 0, totalOperations = 0;

    for (int i = 0; i < totalEmployees; i++) {
        if (strcmp(employees[i].employeeDepartment, "IT") == 0) totalIT += employees[i].employeeSalary;
        else if (strcmp(employees[i].employeeDepartment, "HR") == 0) totalHR += employees[i].employeeSalary;
        else if (strcmp(employees[i].employeeDepartment, "Finance") == 0) totalFinance += employees[i].employeeSalary;
        else if (strcmp(employees[i].employeeDepartment, "Marketing") == 0) totalMarketing += employees[i].employeeSalary;
        else if (strcmp(employees[i].employeeDepartment, "Operations") == 0) totalOperations += employees[i].employeeSalary;
    }

    printf("\nIT Salary Total: %.2f", totalIT);
    printf("\nHR Salary Total: %.2f", totalHR);
    printf("\nFinance Salary Total: %.2f", totalFinance);
    printf("\nMarketing Salary Total: %.2f", totalMarketing);
    printf("\nOperations Salary Total: %.2f\n", totalOperations);
}

void applyAppraisal(struct Employee *emp) {
    int performanceRating;
    printf("Enter performance rating (1-3): ");
    scanf("%d", &performanceRating);

    float incrementPercentage;
    if (performanceRating == 1) incrementPercentage = 0.15;
    else if (performanceRating == 2) incrementPercentage = 0.10;
    else incrementPercentage = 0.05;

    float incrementAmount = emp->employeeSalary * incrementPercentage;
    emp->employeeSalary += incrementAmount;

    printf("New Salary: %.2f\n", emp->employeeSalary);
}

void displayEmployee(struct Employee emp) {
    printf("\nID: %d", emp.employeeId);
    printf("\nName: %s", emp.employeeName);
    printf("\nDepartment: %s", emp.employeeDepartment);
    printf("\nDesignation: %s", emp.employeeDesignation);
    printf("\nSalary: %.2f", emp.employeeSalary);
    printf("\nJoining Date: %s", emp.joiningDate);
    printf("\nPhone: %s", emp.employeePhone);
    printf("\nEmail: %s", emp.employeeEmail);
    printf("\nExperience: %d years\n", emp.yearsOfExperience);
}

int main() {
    struct Employee employees[50];
    int totalEmployees;
    int userChoice;

    printf("Enter number of employees: ");
    scanf("%d", &totalEmployees);

    for (int i = 0; i < totalEmployees; i++) {
        int joiningYear;

        printf("\nEnter employee ID: ");
        scanf("%d", &employees[i].employeeId);

        printf("Enter name: ");
        scanf("%s", employees[i].employeeName);

        printf("Enter department (IT/HR/Finance/Marketing/Operations): ");
        scanf("%s", employees[i].employeeDepartment);

        printf("Enter designation (Intern/Junior/Senior/Manager/Director): ");
        scanf("%s", employees[i].employeeDesignation);

        printf("Enter salary: ");
        scanf("%f", &employees[i].employeeSalary);

        printf("Enter joining date (DD-MM-YYYY): ");
        scanf("%s", employees[i].joiningDate);

        printf("Enter joining year: ");
        scanf("%d", &joiningYear);

        employees[i].yearsOfExperience = calculateExperience(joiningYear);

        printf("Enter phone number: ");
        scanf("%s", employees[i].employeePhone);

        printf("Enter email: ");
        scanf("%s", employees[i].employeeEmail);
    }

    while (1) {
        printf("\n1. Display All Employees");
        printf("\n2. Search by Department");
        printf("\n3. Search by Designation");
        printf("\n4. Search by Experience");
        printf("\n5. Department Salary Statistics");
        printf("\n6. Apply Appraisal");
        printf("\n7. Employees Eligible for Promotion");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 1) {
            for (int i = 0; i < totalEmployees; i++)
                displayEmployee(employees[i]);
        }

        else if (userChoice == 2) {
            char searchDept[20];
            printf("Enter department: ");
            scanf("%s", searchDept);

            for (int i = 0; i < totalEmployees; i++)
                if (strcmp(employees[i].employeeDepartment, searchDept) == 0)
                    displayEmployee(employees[i]);
        }

        else if (userChoice == 3) {
            char searchDesig[20];
            printf("Enter designation: ");
            scanf("%s", searchDesig);

            for (int i = 0; i < totalEmployees; i++)
                if (strcmp(employees[i].employeeDesignation, searchDesig) == 0)
                    displayEmployee(employees[i]);
        }

        else if (userChoice == 4) {
            int requiredExperience;
            printf("Enter minimum years of experience: ");
            scanf("%d", &requiredExperience);

            for (int i = 0; i < totalEmployees; i++)
                if (employees[i].yearsOfExperience >= requiredExperience)
                    displayEmployee(employees[i]);
        }

        else if (userChoice == 5)
            calculateDepartmentWiseSalary(employees, totalEmployees);

        else if (userChoice == 6) {
            int empId;
            printf("Enter employee ID for appraisal: ");
            scanf("%d", &empId);

            for (int i = 0; i < totalEmployees; i++)
                if (employees[i].employeeId == empId)
                    applyAppraisal(&employees[i]);
        }

        else if (userChoice == 7) {
            for (int i = 0; i < totalEmployees; i++)
                if (employees[i].yearsOfExperience > 3)
                    printf("%s eligible for promotion (%d years)\n",
                           employees[i].employeeName,
                           employees[i].yearsOfExperience);
        }

        else if (userChoice == 8)
            break;
    }

    return 0;
}
