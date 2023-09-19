#include <stdio.h>

/*

Context I

Company A has a number of employees who are paid every end of the month.
 The office of the HR use manual approach to calculate the net salary from the gross salary.
 While calculating the net salary, the business rules used are as follows:

1. If the gross salary is USD 100 or below: The tax on salary is 0% of the gross salary,
 the social security fund is 3% of the gross salary, and the medical insurance is 2% of the gross salary.

2. If the gross salary is above USD 100 up to USD 400 inclusive: The tax on salary is 20% of
 the gross salary, the social security fund is 3% of the gross salary, and the medical insurance is 2% of the gross salary.

3. If the gross salary is above USD 400: The tax on salary is 28% of the gross salary, the social security
 fund is 3% of the gross salary, and the medical insurance is 2% of the gross salary.

Tasks to complete
1. You will have a list of at least 10 employees (first name and last name for each employee)
2. You will have a list of 10 gross salaries (a salary for each employee)
3. You will have a net salary calculated for every employee considering their category.
4. You will have every employee's name printed on the console against the net salary.

N.B:  You need to have at least 10 employees and there should be the 3 categories of
 salaries (between 0 and 100, between 100 and 400, and above 400).
 */

/* Constant for the number of employees */
#define NUM_EMPLOYEES 10

/**
 * struct Employee - Represents an employee with their salary details.
 *
 * @first_name: First name of the employee, with a max length of 29 characters.
 * @last_name: Last name of the employee, with a max length of 29 characters.
 * @gross_salary: The total salary before deductions.
 * @net_salary: The final salary after deductions.
 */
struct Employee {
    char first_name[30];
    char last_name[30];
    float gross_salary;
    float net_salary;
};

/**
 * calculate_net_salary - Calculate the net salary of an employee.
 *
 * Description: This function takes into account the gross salary of the employee
 * and then determines the tax, social security fund, and medical insurance
 * deductions based on the provided business rules.
 *
 * @param employee - Pointer to the Employee structure.
 */
void calculate_net_salary(struct Employee *employee) {
    float tax_on_salary;
    /* 3% of the gross salary */
    float social_security_fund = employee->gross_salary * 0.03;
    /* 2% of the gross salary */
    float medical_insurance = employee->gross_salary * 0.02;

    if (employee->gross_salary <= 100)
        tax_on_salary = employee->gross_salary * 0.00;
    if (employee->gross_salary > 100 & employee->gross_salary <= 400)
        tax_on_salary = employee->gross_salary * 0.2;
    if (employee->gross_salary > 400)
        tax_on_salary = employee->gross_salary * 0.28;

    employee->net_salary = (employee->gross_salary - tax_on_salary - medical_insurance - social_security_fund);

}

/**
 * Main - Entry point
 * @return (0) - Success
 */
int main() {
    struct Employee employees[NUM_EMPLOYEES] = {
            {"John",    "Doe",     80.0f},
            {"Jane",    "Smith",   120.0f},
            {"Alice",   "Johnson", 350.0f},
            {"Bob",     "Brown",   450.0f},
            {"Charlie", "White",   50.0f},
            {"Eve",     "Black",   130.0f},
            {"Grace",   "Green",   500.0f},
            {"Mallory", "Blue",    90.0f},
            {"Trent",   "Purple",  250.0f},
            {"Oscar",   "Grey",    600.0f}
    };

    int i;
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        calculate_net_salary(&employees[i]);
        printf("%s %s's Net Salary: USD %.2f\n", employees[i].first_name, employees[i].last_name,
               employees[i].net_salary);
    }

    return (0);
}
