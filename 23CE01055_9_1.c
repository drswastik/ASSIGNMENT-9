 #include <stdio.h>

struct company {
    char name[50];
    char address[100];
    char phone[15];
    int noOfEmployee;
};

int main() {
    struct company mycompany;
    printf("Enter the name of the company: ");
    scanf(" %[^\n]", mycompany.name);
    printf("Enter the address of the company: ");
    scanf(" %[^\n]", mycompany.address);
    printf("Enter the phone number of the company: ");
    scanf(" %[^\n]", mycompany.phone);
    printf("Enter the number of employees: ");
    scanf("%d", &mycompany.noOfEmployee);
    printf("\nCompany Details:\n");
    printf("Name: %s\n", mycompany.name);
    printf("Address: %s\n", mycompany.address);
    printf("Phone: %s\n", mycompany.phone);
    printf("Number of Employees: %d\n", mycompany.noOfEmployee);
    return 0;
}
