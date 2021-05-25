// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int a = 0;
for(int i = 0; i < len-1; i++) {
for(int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) a++;
}
}
return a;
}
int countPairs2(int *arr, int len, int value) {
int a = 0, j = 0, r = len - 1;
for (r; arr[r] > value; r--) {}
for (r; r > 0; r--) {
for (j; j < r; j++)
if (arr[j] + arr[r] == value)
a++;
j = 0;
}
return a;
}
int countPairs3(int *arr, int len, int value) {
int a = 0;
for (int i = 0; i < len - 1; i++) {
int j = i + 1, r = len, key = value - arr[i];
for (; j < r;) {
int mid = j + (r - j) / 2;
if (arr[mid] == key) {
for (; arr[mid - 1] == key && mid > j; mid--) {}
for (; arr[mid] == key; mid++, a++) {}
break;
} else if (arr[mid] < key) {
j = mid + 1;
} else {
r = mid;
}
}
}
return a;
}
