#include <stdio.h>

#define MAX_NUMS 1000000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int nums[MAX_NUMS];
    int n = 0;
    int i;
    FILE *input_file = fopen("input_1000k.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return 1;
    }

    while (fscanf(input_file, "%d", &nums[n]) == 1) {
        n++;
        if (n == MAX_NUMS) {
            break;
        }
    }

    bubble_sort(nums, n);

  /*  for (i = 0; i < n; i++) {
        fprintf(output_file, "%d\n", nums[i]);
    }
*/
    fclose(input_file);
    fclose(output_file);
    return 0;
}
