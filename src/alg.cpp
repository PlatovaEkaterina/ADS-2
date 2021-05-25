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
int sch = 0, j = 0, r = len - 1;
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
int j = i + 1, r = len, k = value - arr[i];
for (; j < r;) {
int mid = j + (r - j) / 2;
if (arr[mid] == k) {
for (; arr[mid - 1] == k && mid > j; mid--) {}
for (; arr[mid] == k; mid++, a++) {}
break;
} else if (arr[mid] < k) {
j = mid + 1;
} else {
r = mid;
}
}
}
return a;
}
