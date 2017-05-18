//
// Created by Julian Vives on 11/05/2017.
//

#include <vector>
#include <iostream>

/**
 * Returns index position or -1 if not found.
 *
 * idx : Loop invariant
 * - Initialization : before the first loop iteration. Holds special "NIL" value by default.
 * - Maintenance : Before iteration : NIL || idx < sequence.size
 *                 After iteration : NIL || idx < sequence.size
 * - Termination : NIL || idx < sequence.size
 * @param sequence
 * @param valueToFind
 * @return idx
 */
int     LinearSearch(const std::vector<int> &sequence, int valueToFind)
{
    int idx = -1, size = static_cast<int>(sequence.size());
    for (int i = 0; i<size; i++) {
        if (sequence[i] == valueToFind) {
            idx = i;
            break;
        }
    }
    return idx;
}

int main()
{
    const std::vector<int> sequence = {25, 34, 34, 1, 12, 35, 6};
    std::cout << LinearSearch(sequence, 1) << std::endl;
    std::cout << LinearSearch(sequence, 0) << std::endl;
}