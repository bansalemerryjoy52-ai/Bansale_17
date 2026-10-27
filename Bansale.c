#include <stdio.h>

int main(void)
{
    int employee_count;
    int overtime_employees = 0;
    double total_payroll = 0.0;

    printf("Enter the number of employees: ");
    if (scanf("%d", &employee_count) != 1 || employee_count <= 0) {
        printf("Please enter a valid positive number of employees.\n");
        return 1;
    }

    for (int employee = 1; employee <= employee_count; employee++) {
        double hours_worked;
        double daily_wage;

        printf("Enter hours worked for employee %d: ", employee);
        if (scanf("%lf", &hours_worked) != 1 || hours_worked < 0.0) {
            printf("Please enter a valid non-negative number of hours.\n");
            return 1;
        }

        if (hours_worked > 8.0) {
            daily_wage = (8.0 * 100.0) + ((hours_worked - 8.0) * 150.0);
            overtime_employees++;
        } else {
            daily_wage = hours_worked * 100.0;
        }

        total_payroll += daily_wage;
        printf("Employee %d daily wage: %.2f pesos\n", employee, daily_wage);
    }

    printf("Total payroll: %.2f pesos\n", total_payroll);
    printf("Employees who worked overtime: %d\n", overtime_employees);

    return 0;
}