#include <iostream>

/*
 * Helper function to print the array elements using pointer arithmetic.
 * - arr: The const array pointer.
 * - size: The size of the array.
 */
void print_array(const int* arr, int size) {
    std::cout << "{";
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            std::cout << *(arr + i);
        }
        else {
            std::cout << *(arr + i) << ",";
        }
         
    }
    std::cout << "}" << std::endl;
}

/*
 * Swaps the values of two integers using references.
 * - a: Reference to the first integer.
 * - b: Reference to the second integer.
 */
void swap_values(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
 * Implements the partition scheme for Quicksort.
 * Rearranges elements in the sub-array arr[low...high] around the pivot (arr[high]).
 * - arr: The array pointer.
 * - low: The starting index of the sub-array.
 * - high: The ending index (where the pivot is initially located).
 * Returns the final index of the pivot element.
 */
int partition(int* arr, int low, int high) {
    // Select the last element as the pivot (read using pointer arithmetic)
    int pivot = *(arr + high);

    // Index 'i' is the boundary for elements smaller than the pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (*(arr + j) <= pivot) {
            i++;
            swap_values(*(arr + j), *(arr + i));
        }
    }
    swap_values(*(arr + high), *(arr + i + 1));
    return i + 1;
   
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        // 1. Divide: Get the pivot's final index (partition point)
        int pivot_index = partition(arr, low, high);

        // 2. Conquer (Recurse Left): Sort the sub-array to the left of the pivot
        quicksort(arr, low, pivot_index - 1);

        // 3. Conquer (Recurse Right): Sort the sub-array to the right of the pivot
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    const int N = 7;
    int data_array[N] = { 80, 10, 40, 70, 20, 90, 30 };

    std::cout << "Initial Array: ";
    print_array(data_array, N);

    // Call partition on the full array (low=0, high=N-1)
    int final_pivot_index = partition(data_array, 0, N - 1);

    std::cout << "\nArray after Partition (Pivot: 30):\n";
    std::cout << "Pivot final position: Index " << final_pivot_index << std::endl;

    // Call the full recursive quicksort function
    quicksort(data_array, 0, N - 1);

    std::cout << "\nArray after full Quicksort:\n";
    std::cout << "Final Array: ";
    print_array(data_array, N);
    // Expected Result: {10, 20, 30, 40, 70, 80, 90}

    return 0;
}
