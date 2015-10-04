//
//  main.cpp
//  Heap-Sort
//
//  Created by Desislava Stoyanova on 10/3/15.
//  Copyright © 2015 Desislava Stoyanova. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void Swap(int& a,int& b) {
    int temp = a;
    a = b;
    b = temp;
}

unsigned long Left(unsigned long index) {
    return index * 2 + 1;
}

unsigned long Right(unsigned long index) {
    return index * 2 + 2;
}

void MaxHeapify(vector<int>& vec,unsigned long index) {
    unsigned long left = Left(index);
    unsigned long right = Right(index);
    unsigned long largest = index;
    if (left < vec.size() && vec[left] > vec[largest]) {
        largest = left;
    }
    if (right < vec.size() && vec[right] > vec[largest]) {
        largest = right;
    }
    if (largest != index) {
        Swap(vec[index], vec[largest]);
        MaxHeapify(vec, largest);
    }
}

void BuildMaxHeap(vector<int>& vec) {
    for (long i = vec.size() / 2 - 1; i >= 0; i--) {
        MaxHeapify(vec, i);
    }
}

void HeapSort(vector<int>& vec) {
    // Additional vector to store the result in descending order
    vector<int> result;
    BuildMaxHeap(vec);
    while (!vec.empty()) {
        unsigned long last = vec.size() - 1;
        Swap(vec[0], vec[last]);
        result.push_back(vec[last]);
        vec.pop_back();
        MaxHeapify(vec, 0);
    }
    vec = result;
    reverse(vec.begin(), vec.end());
}

int main(int argc, const char * argv[]) {
    vector<int> vec;
    int number;
    // Open the file to read numbers
    ifstream file_read;
    file_read.open("nums.txt");
    while (file_read >> number) {
        vec.push_back(number);
    }
    file_read.close();
    // Heap sort
    HeapSort(vec);
    // Open file to write numbers in sorted order
    ofstream file_write;
    file_write.open("nums_sorted.txt");
    for (int i = 0; i < vec.size(); i++) {
        file_write << vec[i];
        file_write << "\n";
    }
    file_write.close();
    return 0;
}
