//
// Created by Julian Vives on 06/05/2017.
//

#include <iostream>
#include "SortingAlgorithm.hpp"

std::ostream    &operator<<(std::ostream &os, const std::vector<int> &array) {
    for (auto &item: array) {
        os << item;
    }
    return os;
}

/**
 * @param _toSort
 */
SortingAlgorithm::SortingAlgorithm(const std::vector<int> &_toSort) : _toSort(_toSort) {}

SortingAlgorithm::~SortingAlgorithm() {}

std::vector<int> &SortingAlgorithm::InsertionByNonDecreasingOrder() {
    const ssize_t size = _toSort.size();
    for (size_t j = 1; j < size; j++) {
        int key = _toSort[j];
        ssize_t i = j - 1;
        while (i > -1 && _toSort[i] > key) {
            _toSort[i + 1] = _toSort[i];
            --i;
        }
        _toSort[i + 1] = key;
    }
    return _toSort;
}

std::vector<int> &SortingAlgorithm::InsertionByNonIncreasingOrder() {
    const ssize_t size = _toSort.size();
    for (size_t j = 1; j < size; j++) {
        int key = _toSort[j];
        ssize_t i = j - 1;
        while (i > -1 && _toSort[i] < key) {
            _toSort[i + 1] = _toSort[i];
            --i;
        }
        _toSort[i + 1] = key;
    }
    return _toSort;
}

const std::vector<int> &SortingAlgorithm::getToSort() const {
    return _toSort;
}

void SortingAlgorithm::setToSort(const std::vector<int> &_toSort) {
    this->_toSort = _toSort;
}

int main(int ac, const char** av) {
    const std::vector<int> toSort = {5, 2, 4, 6, 1, 3};
    SortingAlgorithm *test = new SortingAlgorithm(toSort);
    std::vector<int> sorted = test->InsertionByNonDecreasingOrder();
    std::cout << "NON DECREASING ORDER" << std::endl;
    std::cout << sorted << std::endl;
    test->setToSort(toSort);
    sorted = test->InsertionByNonIncreasingOrder();
    std::cout << "NON INCREASING ORDER" << std::endl;
    std::cout << sorted << std::endl;
    delete test;
}