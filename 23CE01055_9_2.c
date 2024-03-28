#include <stdio.h>

struct student {
    int rollNo;
    char name[50];
    char address[100];
    int age;
    float averageMarks;
};

 void read(struct student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);
    getchar(); 
    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);
    printf("Enter Address: ");
    scanf(" %[^\n]", s->address);
    printf("Enter Age: ");
    scanf("%d", &s->age);
    printf("Enter Average Marks: ");
    scanf("%f", &s->averageMarks);
}

void display(struct student s) {
    printf("\nRoll Number: %d\n", s.rollNo);
    printf("Name: %s\n", s.name);
    printf("Address: %s\n", s.address);
    printf("Age: %d\n", s.age);
    printf("Average Marks: %.2f\n", s.averageMarks);
}

int main() {
    struct student students[6];

    printf("Enter details of 6 students:\n");
    for (int i = 0; i < 6; ++i) {
        printf("\nEnter details for student %d:\n", i + 1);
        read(&students[i]);
    }

    printf("\nDetails of 6 students:\n");
    for (int i = 0; i < 6; ++i) {
        printf("\nDetails for student %d:\n", i + 1);
        display(students[i]);
    }

    return 0;
}
