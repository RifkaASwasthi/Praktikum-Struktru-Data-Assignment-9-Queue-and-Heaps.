#include <iostream>
#include <algorithm>

int H[50];
int heapsize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftchild(int i) {
    return (2 * i) + 1;
}

int rightchild(int i) {
    return (2 * i) + 2;
}

void shiftup(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftdown(int i) {
    int maxindex = i;
    int l = leftchild(i);
    if (l <= heapsize && H[l] > H[maxindex]) {
        maxindex = l;
    }
    int r = rightchild(i);
    if (r <= heapsize && H[r] > H[maxindex]) {
        maxindex = r;
    }
    if (i != maxindex) {
        std::swap(H[i], H[maxindex]);
        shiftdown(maxindex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftup(heapsize);
}

int extractmax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftdown(0);
    return result;
}

void changepriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftup(i);
    } else {
        shiftdown(i);
    }
}

int getmax() {
    return H[0];
}

void remove(int i) {
    H[i] = getmax() + 1;
    shiftup(i);
    extractmax();
}

void printHeap() {
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int n, value;
    std::cout << "Enter the number of elements to insert into the heap: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter value " << (i + 1) << ": ";
        std::cin >> value;
        insert(value);
    }

    std::cout << "Priority queue: ";
    printHeap();

    std::cout << "Node with maximum priority: " << extractmax() << "\n";
    std::cout << "Priority queue after extracting maximum: ";
    printHeap();

    int index, newPriority;
    std::cout << "Enter index to change priority: ";
    std::cin >> index;
    std::cout << "Enter new priority: ";
    std::cin >> newPriority;
    changepriority(index, newPriority);
    std::cout << "Priority queue after priority change: ";
    printHeap();

    std::cout << "Enter index to remove: ";
    std::cin >> index;
    remove(index);
    std::cout << "Priority queue after removing the element: ";
    printHeap();

    return 0;
}
