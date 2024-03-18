// Copyright 2021 NNTU-CS
#include <iostream>
#include <unordered_map>
#include <vector>

int countPairs1(int *arr, int len, int value) {
    std::unordered_map<int, int> numCount;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (numCount.find(value - arr[i]) != numCount.end()) {
            count++;
        }
        numCount[arr[i]]++;
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    std::unordered_map<int, int> numCount;
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += numCount[value - arr[i]];
        numCount[arr[i]]++;
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int value) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        int idx = binarySearch(arr, i + 1, len - 1, complement);
        if (idx != -1) {
            count++;
        }
    }
    return count;
}
