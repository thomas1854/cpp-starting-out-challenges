#ifndef QUICKSORT_H
#define QUICKSORT_H

/**
 * @file quicksort.h
 * @brief Implementation of the QuickSort algorithm with utility functions.
 */

/**
 * @brief Swaps two values of the same type.
 * 
 * @tparam T The type of values to swap (must be copy-assignable).
 * @param first_value Reference to the first value.
 * @param second_value Reference to the second value.
 */
template<typename T>
static void swap(T& first_value, T& second_value)
{
    T temp = first_value;
    first_value = second_value;
    second_value = temp; 
}

/**
 * @brief Partitions an array segment around a pivot element.
 * 
 * This function uses the median-of-three approach by selecting the middle
 * element as the pivot. Elements smaller than the pivot are moved to the left,
 * and elements greater than or equal to the pivot are moved to the right.
 * 
 * @tparam T The type of array elements (must support comparison operator <).
 * @param set The array to partition.
 * @param start The starting index of the segment to partition.
 * @param end The ending index of the segment to partition (inclusive).
 * @return int The final index position of the pivot element after partitioning.
 */
template<typename T>
static int partition(T set[], int start, int end)
{
    int mid = (start + end) / 2;
    swap(set[mid], set[start]);
    int pivotIndex = start;
    T pivotValue = set[start];
    for (int i = start + 1; i <= end; i++)
    {
        if (set[i] < pivotValue)
        {
            pivotIndex++;
            swap(set[pivotIndex], set[i]);
        }
    }
    swap(set[start], set[pivotIndex]);
    return pivotIndex;
}

/**
 * @brief Sorts an array segment using the QuickSort algorithm.
 * 
 * This is a recursive implementation of QuickSort that sorts the array in-place
 * in ascending order. The algorithm has O(n log n) average time complexity and
 * O(n²) worst-case time complexity.
 * 
 * @tparam T The type of array elements (must support comparison operator <).
 * @param set The array to sort.
 * @param start The starting index of the segment to sort.
 * @param end The ending index of the segment to sort (inclusive).
 * 
 * @note The array is sorted in-place, modifying the original data.
 * @note To sort an entire array of size n, call quickSort(array, 0, n-1).
 */
template<typename T>
void quickSort(T set[], int start, int end)
{
    if (start < end)
    {
        int pivotPoint = partition(set, start, end);
        quickSort(set, start, pivotPoint - 1);
        quickSort(set, pivotPoint + 1, end);
    }
}

#endif