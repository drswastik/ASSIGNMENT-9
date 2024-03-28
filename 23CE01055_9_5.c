#include <stdio.h>
#include <stdbool.h>
struct CourseRecord {
    char firstName[50];
    char lastName[50];
    int rollNumber;
    char department[50];
    char courseCode[20];
    int testMarks[3];
};
float average(struct CourseRecord cr) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += cr.testMarks[i];
    }
    return (float)sum / 3;
}
bool check(struct CourseRecord cr) {
    float averageMarks = average(cr);
    return (averageMarks >= 35);
}

int main() {
    struct CourseRecord student1 = {"John", "Doe", 101, "Computer Science", "CS101", {80, 75, 60}};
    struct CourseRecord student2 = {"Alice", "Smith", 102, "Electrical Engineering", "EE201", {50, 45, 55}};
    printf("Average test marks for %s %s: %.2f\n", student1.firstName, student1.lastName, average(student1));
    if (check(student1))
        printf("%s %s passed the test.\n", student1.firstName, student1.lastName);
    else
        printf("%s %s failed the test.\n", student1.firstName, student1.lastName);

    printf("Average test marks for %s %s: %.2f\n", student2.firstName, student2.lastName, average(student2));

    if (check(student2))
        printf("%s %s passed the test.\n", student2.firstName, student2.lastName);
    else
        printf("%s %s failed the test.\n", student2.firstName, student2.lastName);

    return 0;
}
