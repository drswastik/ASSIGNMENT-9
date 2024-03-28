 #include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int dates(struct Date date1, struct Date date2) {
    if (date1.year > date2.year)
        return 1;
    else if (date1.year < date2.year)
        return -1;
    else {
        if (date1.month > date2.month)
            return 1;
        else if (date1.month < date2.month)
            return -1;
        else {
            if (date1.day > date2.day)
                return 1;
            else if (date1.day < date2.day)
                return -1;
            else
                return 0;
        }
    }
}

int main() {
    struct Date date1, date2;

    printf("Enter details for first date:\n");
    printf("Enter day: ");
    scanf("%d", &date1.day);
    printf("Enter month: ");
    scanf("%d", &date1.month);
    printf("Enter year: ");
    scanf("%d", &date1.year);

    printf("\nEnter details for second date:\n");
    printf("Enter day: ");
    scanf("%d", &date2.day);
    printf("Enter month: ");
    scanf("%d", &date2.month);
    printf("Enter year: ");
    scanf("%d", &date2.year);

    int result = dates(date1, date2);

    if (result == 1)
        printf("Date 1 is later than Date 2\n");
    else if (result == -1)
        printf("Date 1 is earlier than Date 2\n");
    else
        printf("Date 1 and Date 2 are the same\n");

    return 0;
}
