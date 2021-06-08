// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (i != j and arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count / 2;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i + 1 < len; ++i) {
        for (int j = len - 1; j > i; --j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
            if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }

    return count;
}


int UpperBound(int* nums, int left, int right, int value) {
    int mid = (left + right) / 2;
    while (left < right) {
        if (nums[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return left;
}

int LowerBound(int* nums, int left, int right, int value) {
    int mid = (left + right) / 2;
    while (left < right) {
        if (nums[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return left;
}

int countPairs3(int* nums, int len, int value) {
    int count = 0;
    for (int i = 0; i + 1 < len; ++i) {
        int upper = UpperBound(nums, i + 1, len, value - nums[i]);
        int lower = LowerBound(nums, i + 1, len, value - nums[i]);
        if (lower < len and nums[lower] == value - nums[i]) {
            count += (upper - lower);
        }
    }
    return count;
}
