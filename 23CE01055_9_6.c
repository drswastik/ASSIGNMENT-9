#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Student {
    char name[50];
    int rollNumber;
    float percentage;
};

struct Database {
    struct Student students[100];
    int size;
};
void insert(struct Database *db, struct Student newStudent) {
    int i = db->size - 1;
    while (i >= 0 && db->students[i].rollNumber > newStudent.rollNumber) {
        db->students[i + 1] = db->students[i];
        i--;
    }
    db->students[i + 1] = newStudent;
    db->size++;
}
void sortName(struct Database *db) {
    for (int i = 0; i < db->size - 1; i++) {
        for (int j = 0; j < db->size - i - 1; j++) {
            if (strcmp(db->students[j].name, db->students[j + 1].name) > 0) {
                struct Student temp = db->students[j];
                db->students[j] = db->students[j + 1];
                db->students[j + 1] = temp;
            }
        }
    }
}
char* findOne(struct Database *db, char* prefix) {
    for (int i = 0; i < db->size; i++) {
        if (strncmp(db->students[i].name, prefix, strlen(prefix)) == 0) {
            return db->students[i].name;
        }
    }
    return NULL; 
}
float calculateMean(struct Database *db) {
    float sum = 0;
    for (int i = 0; i < db->size; i++) {
        sum += db->students[i].percentage;
    }
    return sum / db->size;
}
float calculateStandardDeviation(struct Database *db) {
    float mean = calculateMean(db);
    float sum = 0;
    for (int i = 0; i < db->size; i++) {
        sum += pow(db->students[i].percentage - mean, 2);
    }
    return sqrt(sum / db->size);
}
void specs(struct Database *db, int* stats) {
    stats[0] = db->size;

    float highest = db->students[0].percentage;
    float lowest = db->students[0].percentage;
    for (int i = 0; i < db->size; i++) {
        if (db->students[i].percentage > highest)
            highest = db->students[i].percentage;
        if (db->students[i].percentage < lowest)
            lowest = db->students[i].percentage;
    }
    stats[1] = highest;
    stats[2] = lowest;
    stats[3] = calculateMean(db);
    stats[4] = calculateStandardDeviation(db);
}
void delete(struct Database *db, int rollNumber) {
    int i = 0;
    while (i < db->size && db->students[i].rollNumber != rollNumber) {
        i++;
    }
    if (i == db->size) {
        printf("Record with roll number %d not found.\n", rollNumber);
    } else {
        for (int j = i; j < db->size - 1; j++) {
            db->students[j] = db->students[j + 1];
        }
        db->size--;
        printf("Record with roll number %d deleted successfully.\n", rollNumber);
    }
}

int main() {
    struct Database studentDB = { .size = 0 };
    struct Student s1 = { .rollNumber = 101, .percentage = 80.5, .name = "John" };
    struct Student s2 = { .rollNumber = 102, .percentage = 75.3, .name = "Alice" };
    struct Student s3 = { .rollNumber = 103, .percentage = 88.2, .name = "Bob" };

    insert(&studentDB, s1);
    insert(&studentDB, s2);
    insert(&studentDB, s3);

    sortName(&studentDB);

    printf("One student with name starting with 'A': %s\n", findOne(&studentDB, "A"));

    int statistics[5];
    specs(&studentDB, statistics);
    printf("Number of records: %d\n", statistics[0]);
    printf("Highest percentage: %.2f\n", statistics[1]);
    printf("Lowest percentage: %.2f\n", statistics[2]);
    printf("Mean: %.2f\n", statistics[3]);
    printf("Standard deviation: %.2f\n", statistics[4]);

    delete(&studentDB, 102);

    return 0;
}
