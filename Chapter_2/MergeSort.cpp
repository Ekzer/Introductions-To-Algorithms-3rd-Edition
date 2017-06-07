//
// Created by Julian Vives on 30/05/2017.
//


#include <vector>
#include <iostream>

std::ostream    &operator<<(std::ostream &os, const std::vector<int> &list)
{
    for (auto &item: list) {
        os << item;
        os << " ";
    }
    return os;
}

/**
 * @see Page 31
 * @note It doesn't work with the second sequence in comment because this implementation doesn't skip same values by iterating in the subarrays
 * @param A
 * @param p
 * @param q
 * @param r
 * @return
 */
std::vector<int>        &_Merge(std::vector<int> &A, size_t p, size_t q, size_t r)
{
    size_t  n1 = (q - p),
            n2 = (r - q),
            i = 0,
            j = 0;
    std::vector<int> L, R;
    for (; i < n1; i++) {
        L.push_back(A[p + i]);
    }
    for (; j < n2; j++) {
        R.push_back(A[q + j]);
    }
    L.push_back(INT_MAX); // L[n1]
    R.push_back(INT_MAX); // R[n2]
    i = j = 0;
    for (size_t k = p; k < r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        }
        else {
            A[k] = R[j];
            ++j;
        }
    }
    return A;
}

std::vector<int>        &MergeSort(std::vector<int> &A, size_t p, size_t r)
{
    if (p<r) {
        size_t q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        return _Merge(A, p, q, r);
    }
    return A;
}

int main()
{
    std::vector<int> A = {2, 4, 5, 7, 1, 2, 3, 6};
    //std::vector<int> A = {23, 23, 23, 23, 23, 23, 5};
    MergeSort(A, 0, A.size());
    std::cout << A << std::endl;
    return 0;
}