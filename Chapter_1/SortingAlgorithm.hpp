//
// Created by Julian Vives on 06/05/2017.
//

#ifndef INTRODUCTIONS_TO_ALGORITHMS_3RD_EDITION_SORTINGALGORITHM_HPP
#define INTRODUCTIONS_TO_ALGORITHMS_3RD_EDITION_SORTINGALGORITHM_HPP

#include <vector>

class SortingAlgorithm {
private:
    std::vector<int>    _toSort;
public:
    SortingAlgorithm(const std::vector<int> &_toSort);
    ~SortingAlgorithm();

    const std::vector<int, std::allocator<int>> &getToSort() const;

    void setToSort(const std::vector<int, std::allocator<int>> &_toSort);

    std::vector<int>  &InsertionByNonDecreasingOrder();

    std::vector<int> &InsertionByNonIncreasingOrder();
};


#endif //INTRODUCTIONS_TO_ALGORITHMS_3RD_EDITION_SORTINGALGORITHM_HPP
