//
// Created by Julian Vives on 20/05/2017.
//

#include <vector>
#include <iostream>

/**
 * This algorithm maintains the loop invariant of finding the lowest element in the sequence.
 * We only have to run on the first n-1 elements because the last element will always be sorted because all element before were sorted.
 * Let A to be an array of numbers to sort.
 * Let n = A.length
 * Let min = Integer - Loop invariant
 *
 * for (i = 0; i < n; i++) {
 *  min = 0; // Initialization - min E A[0...0] - Always sorted
 *  for (j = i+1; j < n; j++) {
 *      if (A[j] < A[min]) then
 *          min = j; // maintenance - min E A[0...n-1] - SubArray always sorted
 *      end
 *  }
 *  tmp = A[i]
 *  A[i] = A[min];
 *  A[min] = tmp;// Termination - min E A[0...n-1]
 * }
 *
 * Worst case time = Best case time in any case because we iterate through the array each loop time. = O(n^2)
 * @see https://www.khanacademy.org/computing/computer-science/algorithms/sorting-algorithms/a/analysis-of-selection-sort
 * @param A
 * @return A
 */
std::vector<int>    &SelectionSort(std::vector<int> &A)
{
    size_t min;
    for (size_t i = 0; i < A.size(); i++) { // n
        min = i;
        for (size_t j = i+1; j< A.size(); j++) { // Sigma j = i+1 to A.length (n - j)
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
    }
    return A;
}

std::ostream    &operator<<(std::ostream &os, const std::vector<int> &list) {
    for (auto &item: list) {
        os << item;
        os << " ";
    }
    return os;
}

int main()
{
    std::vector<int> A = {23, 5, 53, 45, 45, 23, 64};
    //std::vector<int> A = {23, 23, 23, 23, 23, 23, 5};
    std::cout << SelectionSort(A) << std::endl;
    return 0;
}