#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 100000

struct node {
    int value;
    struct node* next;
};

void bucket_sort(int arr[], int n) {
    int i, j;
    struct node** buckets;
    int max_value = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    int num_buckets = max_value / n + 1;
    buckets = (struct node**)malloc(num_buckets * sizeof(struct node*));

    for (i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        int index = arr[i] / n;
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->value = arr[i];
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        struct node* current = buckets[i];
        while (current != NULL) {
            struct node* temp = current;
            arr[index++] = current->value;
            current = current->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    int i;
    FILE* inputFile = fopen("input_100k.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: could not open input file\n");
        return 1;
    }

    int values[BUCKET_SIZE];
    int n = 0;
    int value;
    while (fscanf(inputFile, "%d", &value) == 1 && n < BUCKET_SIZE) {
        values[n++] = value;
    }

    fclose(inputFile);

    bucket_sort(values, n);

   /* FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: could not open output file\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", values[i]);
    }

    fclose(outputFile); */

    return 0;
}
