#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int tab[], long long *index, int N) {
    int i, j, k;
    long long temp;
    for (i = 1; i < N; i++) {
        k = tab[i];
        temp = *(index + i);
        j = i - 1;
        while (j >= 0 && tab[j] > k) {
            tab[j + 1] = tab[j];
            *(index + j + 1) = *(index + j);
            j = j - 1;
        }
        tab[j + 1] = k;
        *(index + j + 1) = temp;
    }
}

void swapint(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swaplong(long long* a, long long* b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

int partition(int tab[], long long *index, int left, int right) {
    int pivot = tab[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (tab[j] <= pivot) {
            i++;
            swapint(&tab[i], &tab[j]);
            swaplong(&index[i], &index[j]); // Swap index along with elements
        }
    }
    swapint(&tab[i + 1], &tab[right]);
    swaplong(&index[i + 1], &index[right]); // Swap index along with elements
    return i + 1;
}

void quickSort(int tab[], long long *index, int left, int right) {
    if (left < right) {
        int pi = partition(tab, index, left, right);

        quickSort(tab, index, left, pi - 1);
        quickSort(tab, index, pi + 1, right);
    }
}

void reverseArray(long long *arr, int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Swap elements
        swaplong(&arr[start], &arr[end]);

        // Move pointers
        start++;
        end--;
    }
}

int binarySearch(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the middle element is the value we're searching for
        if (arr[mid] == value) {
            return mid; // Value found
        }
            // If the value is less than the middle element, search in the left half
        else if (arr[mid] > value) {
            high = mid - 1;
        }
            // If the value is greater than the middle element, search in the right half
        else {
            low = mid + 1;
        }
    }
    return -1; // Value not found
}