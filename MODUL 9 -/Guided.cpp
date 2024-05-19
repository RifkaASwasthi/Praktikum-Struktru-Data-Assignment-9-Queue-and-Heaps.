#include <iostream>
#include<algorithm>

int H[50];
int heapsize = -1;

int parent(int i) {
    return (i-1) /2;
}

int leftchild(int i) {
    return ((2 * i) +1);
}

int rightchild(int i){
    return ((2*i) + 2);
}

void shiftup (int i) {
    while (i > 0 && H[parent(i)] < H[i]){
        std :: swap(H[parent(i)], H[i]);
        i= parent(i);
    }
}

void shiftdown (int i) {
    int mmaxindex = i;
    int l = leftchild(i);
    if (l <= heapsize && H[l] > H [mmaxindex]) {
        mmaxindex = l;
    }
    int r = rightchild(i);
    if (r <= heapsize && H[r] > H[mmaxindex]){
        mmaxindex = r;
    }
    if (i != mmaxindex){
        std :: swap (H[i], H[mmaxindex]);
        shiftdown(mmaxindex);
    }
}

void insert( int p){
    heapsize = heapsize +1;
    H[heapsize] = p;
    shiftup(heapsize);
}

int extractmax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize -1;
    shiftdown(0);
    return result;
}
 void changepriority (int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftup (i);
    } else {
        shiftdown (i);
    }
 }

int getmax(){
    return H[0];
}

void remove(int i){
    H[i] = getmax() +1;
    shiftup(i);
    extractmax();
}

int main(){
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std :: cout << "priority queue :";
    for ( int i =0; i<= heapsize; ++i){
        std :: cout << H[i] << "";
    }
    std :: cout << "\n";
    std :: cout << "node with maximum priority :" << extractmax() << "\n";
    std :: cout << "priority queue after estracting maximum:";
    for ( int i = 0; i <= heapsize; i++){
        std :: cout << H[i] << " ";
    }
    std :: cout << "\n";

    changepriority(2, 49);
    std :: cout << "priority queue after priority change:";
    for ( int i = 0; i <= heapsize; i++){
        std :: cout << H[i] << " ";
    }
    std:: cout <<"\n";

    remove(3);
    std :: cout << "priority queue after removing teh element:";
    for ( int i = 0; i <= heapsize; i++){
        std :: cout << H[i] << " ";
    }
    return 0;
}


