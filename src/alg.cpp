// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int i =  len - 1;
    while (arr[i] > value) {
        i--;
    }
    len = i + 1;
    count += countPairs1(arr, len, value);
    return count;
}

int binarySearch(int *arr, int size, int value) {
    int l = 0;
    int h = size - 1;
    int count = 0;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] < value) {
            l = mid + 1;
        } else if (arr[mid] > value) {
            h = mid - 1;
        } else {
            count ++;
            int i = mid - 1;
            mid++;
            while(arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[i] == value){
                count++;
                i--;
            }
            break;
        }
        return count;
    }
}

int countPairs3(int *arr, int len, int value) {
    int j = 0;
    int count = 0;
    while (arr[j] <= (value / 2) - 1) {
        int b = value - arr[j];
        count += binarySearch(arr, len, b);
        j++;
    }
    int mid = binarySearch(arr, len, value / 2);
    count += mid * (mid - 1) / 2;
    return count;
}
