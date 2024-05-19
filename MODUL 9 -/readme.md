# <h1 align="center">Laporan Praktikum Modul 9 Priority Queue and Heaps </h1>
<p align="center">Rifka Annisa Swasthi</p>

## Dasar Teori
1. Priority Queue

Priority queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan priorotas tertentu.

Priority Queue berdasarkan
aturan elemen yang prioritasnya lebih tinggi, diproses lebih dahulu dibandingkan dengan elemen yang prioritasnya lebih
rendah dan dua elemen dengan prioritas yang sama, diproses sesuai dengan urutan mereka sewaktu dimasukkan ke dalam
priority queue [1]

Penggunaaan Algoritma priority queue antara lain dalam Algoritma Dijkstra digunakan untuk menemukan jalur terpendek dalam graf berbobot positif, Algoritma A star digunakan untuk menemukan permasalahan pencarian jarak terpendek dengan heuristik, Algoritma Huffman digunakan untuk kompresi data dan Penjadwalan tugas. [2]

2. Heaps

Heaps adalah struktur data pohon khusus. Heaps terdiri dari tiga simpul yang berurutan diisi dari kiri ke kanan. simpul atau node pertama disebut root induk, simpul kedua adalah anak kiri dari akar dan simpul ketiga adalah anak kanan dari akar.

Kelebihan menggunakan struktur data heaps adalah struktur data ini memungkinkan penghapusan dan penyidipan dalam waktu logaritmik -O (log2N), data dipohon dibentuk dalam urutan tertentu. selain memperbarui atau menanyakan maksimum dan minimun, pemrogram dapat menemukan hubungan antara induk dan keturunanya.

Struktur data heaps memiliki dua cara yaitu min heap dan max heap. pada tumpukan minimum atau min heap node akar memiliki nilai yang sama atau lebih kecil dari nilai anak pada node tersebut. struktur min heap lengkap di pohon biner. Tumpukan maks, node induk atau roor memiliki nilai sama atau lebih besar dari anaknya di node tersebut, pohon biner lengkap sehingga dapat membuat tumpukan maksimal dari kumpulan nilai dan menjalankannya dalam waktu O n. [3]

![Screenshot 2024-05-20 002317](https://github.com/RifkaASwasthi/Praktikum-Struktru-Data-Assignment-9-Queue-and-Heaps./assets/162097297/054a09d0-2d46-4ae5-85a9-910c55bf173c)



## Guided 

### 1. Contoh kode

```C++
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



```
Kode di atas digunakan adalah contoh dari heaps maks yang menggunakana array dengan operasi penyisipan, ekstraksi elemen maksimum, perrubahan elemen dan penghapusan elemen. dengan mengguanakna operasi heaps shiftup untuk memastikan properti heap terjaga, shiftdown, insert int p, extractmax utnuk menghapus elemen maksimum, getmax untk mengembalikan elemen maksimun tanpa menghapus dan remove untuk menghapus elemen. dengan emnyisiplan elemen ke heap berupa insert 45, insert 20 dst, kemudian menampilakan heap setelah penyisispan dengan std cout priority queue kemudian menhapus elemen maksimum dengan std cout node with maximum priority nanti ditampilan dan std tampilan priority queue after extracting maximum, mengubah prioritas elemen indeks 2 menjadi 49 dan menampilkan heap setelah perubahan, menghapus di indeks 3 dan ditampilkan priority queue after removing the element.

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user

```C++
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

```
#### Output:
![Screenshot 2024-05-19 234804](https://github.com/RifkaASwasthi/Praktikum-Struktru-Data-Assignment-9-Queue-and-Heaps./assets/162097297/a95cedb4-ec3d-40d9-a913-6f3f47c5cf67)


Kode di atas digunakan adalah modivikasi dari kode guided yaitu heaps maks menggunakan array,H50 untuk array yang menyimpan elemen sejumlah 50 heapoperasi pertama void shiftup untuk memeastikan heap terjaga dari sebuah node ke root while node i lebih nesar dari node awal maka node ditukar dengan node awal proses berlanjut sampai properti heap terjaga. operasi kedua void shiftdown utnuk memastikan heap terjaga dari node ke daun, dari masing masing if dugunakan ntuk mencari elemen terbesar di antara node dan menukar sampai heap terjaga, operasi ke tiga insert int p untuk menyisipkan elemn baru p ke dalam heap yang ditempatkan di akhir heap kemudian memeanggil shift up utnuk menjaga heap, proprerti selanjtunya extrac max untuk menghapus dan mengambalikan elemen maksimum , change priority untuk mengubah prioritas nilai setiap elemen akan dicheck dari indeks ke 1 dan menjadi p, get max untuk mengmabalikan elemen maksimum roor, remove untuk menghapuselemen p dan print mencetak heap, di outpus memasukkan elemen sebanyak 5 di masukkan masing maasing angka 1,2,3,4,5 kemudian dapat mangubah dengan change dna menghapus dengan remove di setiap elemen yang diinginkan.

#### Full code Screenshot:
![Screenshot 2024-05-19 234903](https://github.com/RifkaASwasthi/Praktikum-Struktru-Data-Assignment-9-Queue-and-Heaps./assets/162097297/32f23547-58ee-4a6f-b24a-5d812c9d81dd)



## Kesimpulan
Priority queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan priorotas tertentu.
Priority Queue berdasarkan
aturan elemen yang prioritasnya lebih tinggi, diproses lebih dahulu dibandingkan dengan elemen yang prioritasnya lebih
rendah dan dua elemen dengan prioritas yang sama, diproses sesuai dengan urutan mereka sewaktu dimasukkan ke dalam
priority queue 
Heaps adalah struktur data pohon khusus. Heaps terdiri dari tiga simpul yang berurutan diisi dari kiri ke kanan. simpul atau node pertama disebut root induk, simpul kedua adalah anak kiri dari akar dan simpul ketiga adalah anak kanan dari akar.Struktur data heaps memiliki dua cara yaitu min heap dan max heap. 

## Referensi
[1] Jorgha Akam Aryandi1, Muhammad Azmi Nugraha2, Yahya Aliman Aidil Basith3,Muhammad Azmi Nugraha4 Deden Pradeka5, dan Dian Anggraini6. 2023, IMPLEMENTASI ALGORITMA QUEUE UNTUK MENENTUKAN PRIORITAS PELAYANAN UMUM DIRUMAH SAKIT,[Jurnal] Program Studi Teknik Komputer, Universitas Pendidikan Indonesia, Indonesia, JIKO (Jurnal Informatika dan Komputer).

[2] Ricky Pratama. 2023, Priority Queue: Konsep dan Penggunaan dalam Algoritma, [Artikel] Medium.

[3] Alyssa Walker. 2024, Struktur Data Heap: Apa itu Heap? Tumpukan Min & Maks (Contoh), [Artikel] Guru99.
