//
// Created by Julian Vives on 14/05/2017.
//

#include <vector>
#include <list>
#include <iostream>

std::list<int>  BinaryAdd(const std::vector<int> &nb1, const std::vector<int> &nb2)
{
    std::list<int>      result;
    int                 carry = 0;
    for (int j = (int)nb1.size() - 1; j > -1; j--) {
        result.push_front((nb1[j] + nb2[j] + carry) % 2);
        carry = (nb1[j] + nb2[j] + carry) / 2;
    }
    result.push_front(carry);
    return result;
}

std::ostream    &operator<<(std::ostream &os, const std::list<int> &list) {
    for (auto &item: list) {
        os << item;
    }
    return os;
}

int main() {
    const std::vector<int> nb1 = {1,1,0,0,1,1,1}; // 103
    const std::vector<int> nb2 = {1,1,0,0,1,0,0}; // 100
    std::cout << BinaryAdd(nb1, nb2) << std::endl;
}

