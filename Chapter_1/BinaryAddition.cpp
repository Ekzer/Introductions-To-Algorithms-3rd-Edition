//
// Created by Julian Vives on 14/05/2017.
//

#include <vector>
#include <list>
#include <iostream>

int     *BinaryAdd(const std::vector<int> &nb1, const std::vector<int> &nb2)
{
    int*     result = new int[nb1.size()+1];
    int      carry = 0, res;
    for (int j = (int)nb1.size() - 1; j >= -1; j--) {
        if (carry && j == -1) {
            result[j+1] = carry;
            break;
        }
        res = nb1[j] + nb2[j] + carry;
        carry = 0;
        if (res > 1) {
            carry = 1;
            res %= 2;
        }
        result[j+1] = res;
    }
    return result;
}

std::ostream        &operator<<(std::ostream &os, const int *tab) {
    int size = (sizeof(tab) / sizeof(tab[0]));
    for (int i = 0; i< size; i++) {
        os << tab[i];
    }
    return os;
}
int main() {
    const std::vector<int> nb1 = {1,1,0,0,1,1,1}; // 103
    const std::vector<int> nb2 = {1,1,0,0,1,0,0}; // 100
    std::cout << BinaryAdd(nb1, nb2) << std::endl;
}

