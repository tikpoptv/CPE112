// Grading
// Write a program to store the data for students, including their name and scores. Then, calculate students average score and standard deviation also display student name that got the highest and lowest score.

// To find average or mean use this equation: (∑value)/size
// To find Standard deviation use this equation: √((∑(each value-mean)^2 )/(size-1))

// Hint: use math.h for power and root function

// Input
// The input consists of size+1 lines
// First Line: An integer size in which 1≤size≤100 as the number of students.
// Second to size + 1th lines: The string name which has a length of 1≤length≤100 and a float n in which 0≤n≤100 as the score of the student separate with whitespace

// Output
// The output consists of 1 line
// First Line: Display the Mean and SD of the data in 2 decimal point float (%.2f) and display the name of student maximum and minimum score (if the maximum and minimum is the same, prioritize the sequence of the data [Eg. Testcase No.2] )
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

struct data {
    char name[100];
    float score;
};

void calculateAverage();
void calculateStandardDeviation();
void StudentMaximum();
void StudentMinimum();

int main() {
    int size;
    scanf("%d", &size);

    struct data data[MAX_SIZE];

    for (int i = 0; i < size; i++) {
        scanf("%s %f", data[i].name, &data[i].score);
    }

    float sum = 0; 
    for (int i = 0; i < size; i++) {
        sum += data[i].score;
    }
    float average = sum / size;
    calculateAverage(data, size);

    calculateStandardDeviation(data, size, average);

    StudentMaximum(data, size);

    StudentMinimum(data, size);

    return 0;
}

void calculateAverage(struct data arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i].score;
    }
    float average = sum / size;
    printf("%.2f ", average);
}

void calculateStandardDeviation(struct data arr[], int size, float mean) {
    float sum_squared = 0;

    for (int i = 0; i < size; i++) {
        sum_squared += pow(arr[i].score - mean, 2);
    }
    float variance = sum_squared / size;  
    float Deviation = sqrt(variance);

    printf("%.2f ", Deviation);
}

void StudentMaximum(struct data arr[], int size) {
    float maxScore = arr[0].score;
    int max = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i].score > maxScore) {
            maxScore = arr[i].score;
            max = i;
        }
    }

    printf("%s ", arr[max].name);
}

void StudentMinimum(struct data arr[], int size) {
    float minScore = arr[0].score;
    int min = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i].score < minScore) {
            minScore = arr[i].score;
            min = i;
        }
    }

    printf("%s", arr[min].name);
}


