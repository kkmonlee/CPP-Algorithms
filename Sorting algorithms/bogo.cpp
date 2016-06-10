/**
 * Bogo Sort C++ source file
 * @author kkmonlee
 *
 * ABOUT:
 * Bogo Sort checks if the list is already sorted. If yes, algorithm ends.
 * Otherwise it randomly shuffles the list and repeats the procedure
 *
 * PSEUDOCODE:
 * function bogosort(array)
 *      while !ordered(array)
 *          shuffle(array)
 * COMPLEXITY:
 * O(n*n!), because there are n! possible permutations of the input list
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

template <typename RandomAccessIterator, typename Predicate>
void bogoSort(RandomAccessIterator begin, RandomAccessIterator end, Predicate p) {

    std::random_device rd;
    std::mt19937 generator(rd());
    while (!std::is_sorted(begin, end, p)) {
        std::shuffle(begin, end, generator);
    }
};

template <typename RandomAccessIterator>
void bogoSort(RandomAccessIterator begin, RandomAccessIterator end) {
    bogoSort(begin, end, std::less < typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

int main() {
    int a[] = {23, 23, 3254, 12, 1, 5, 47, 467, 69, -23, -393};
    bogoSort(std::begin(a), std::end(a));
    copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}