#include <iostream>
#include "ch02/sec1/insertion_sorter.h"

using namespace std;

int main() {
    vector<int> A = {6, 5, 4, 3, 2, 1};
    InsertionSorter::sort(A);
    cout << "Sorted array is: ";
    for (auto a: A) {
        cout << a << " ";
    }
    cout << endl;
}
