// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int k) {
    int t = 0;
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == k) {
                t++;
            }
        }
    }
    return t;
}

int countPairs2(int* arr, int len, int k) {
    int t = 0;
    int left = 0;
    int right = len - 1;
    
    while(left != right) {
      if(arr[left] + arr[right] > k) {
        right = right - 1;
      }
      else if(arr[left] + arr[right] < k) {
        left = left + 1;
      }
      else if(arr[left] + arr[right] == k) {
        t++;
        if(arr[right - 1] == arr[right]) {
            right = right - 1;
        } else if (arr[left + 1] == arr[left]) {
            left = left + 1;
        } else {
            left = left + 1;
        }
      }
    }
    return t;
}

int countPairs3(int *arr, int len, int value) {
    int t = 0;
    int left = 0;
    int right = len - 1;
    while (left < right - 1) {
        int middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle;
        else
            right = middle;
    }
    len = right - 1;
    for (int i = 0; i <len; i++) {
        left = i + 1;
        right = len - 1;
        int c = 0;
        while (left < right) {
            int m = (left + right) / 2;
            if (arr[m] < (value-arr[i]))
                left = m + 1;
            else
                right = m;
        }
        while (arr[left] == (value - arr[i])) {
            c++;
            left++;
        }
    t += c;
    }
    if (t) {
        return t;
    } else {
        return 0;
    }
}
