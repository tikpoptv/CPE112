#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

struct data { // Jedsadaporn Pannok 66070503410
    char name[100];
    float score;
};

// Function to calculate and print the average score of students
void calculateAverage(struct data arr[], int size);

// Function to calculate and print the standard deviation of student scores
void calculateStandardDeviation(struct data arr[], int size, float mean);

// Function to find and print the student with the maximum score
void StudentMaximum(struct data arr[], int size);

// Function to find and print the student with the minimum score
void StudentMinimum(struct data arr[], int size);

int main() {
    int size;
    scanf("%d", &size); // Read the number of students

    struct data data[MAX_SIZE]; // Declare an array of structures to store student data

    // Input data for each student
    for (int i = 0; i < size; i++) {
        scanf("%s %f", data[i].name, &data[i].score);
    }

    float sum = 0; // Declare the variable sum and initialize it to 0
    for (int i = 0; i < size; i++) {
        sum += data[i].score; // Calculate the sum of scores
    }
    float average = sum / size; // Calculate the average score
    calculateAverage(data, size); // Call function to print the average score

    calculateStandardDeviation(data, size, average); // Call function to print the standard deviation

    StudentMaximum(data, size); // Call function to print the student with the maximum score

    StudentMinimum(data, size); // Call function to print the student with the minimum score

    return 0;
}

// Function to calculate and print the average score
void calculateAverage(struct data arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i].score; // Calculate the sum of scores
    }
    float average = sum / size; // Calculate the average score
    printf("%.2f", average); 
}

// Function to calculate and print the standard deviation
void calculateStandardDeviation(struct data arr[], int size, float mean) {
    float sum_squared = 0;

    // Calculate the sum of squared differences from the mean
    for (int i = 0; i < size; i++) {
        sum_squared += pow(arr[i].score - mean, 2);
    }

    float variance = sum_squared / size; // Calculate the variance
    float deviation = sqrt(variance); // Calculate the standard deviation

    printf(" %.2f", deviation);
}

// Function to find and print the student with the maximum score
void StudentMaximum(struct data arr[], int size) {
    float maxScore = arr[0].score;
    int max = 0;

    // Find the index of the student with the maximum score
    for (int i = 1; i < size; i++) {
        if (arr[i].score > maxScore) {
            maxScore = arr[i].score;
            max = i;
        }
    }

    printf(" %s", arr[max].name); 
}

// Function to find and print the student with the minimum score
void StudentMinimum(struct data arr[], int size) {
    float minScore = arr[0].score;
    int min = 0;

    // Find the index of the student with the minimum score
    for (int i = 1; i < size; i++) {
        if (arr[i].score < minScore) {
            minScore = arr[i].score;
            min = i;
        }
    }

    printf(" %s", arr[min].name);
}
