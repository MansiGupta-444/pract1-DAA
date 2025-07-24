#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 100
#define N2 10000
#define N3 1000000

float randomnumber(float min, float max) {
return min + ((float)rand() / RAND_MAX) * (max - min);
}

void generatedata(float temp[], float pressure[], int n) {
for (int i = 0; i < n; i++) {
temp[i] = randomnumber(-20, 50);
pressure[i] = randomnumber(950, 1050);
}
}
void generatetemp(float arr[], int n) {
float step = (50 - 20) / (float)n;
for (int i = 0; i < n; i++) {
arr[i] = 20 + step * i;
}
}
// Task A Linear search to find min temp & max press
void TaskA(float temp[], float pressure[], int n) {
float minTemp = temp[0];
float maxPressure = pressure[0];

for (int i = 1; i < n; i++) {

if (temp[i] < minTemp) minTemp = temp[i];
if (pressure[i] > maxPressure) maxPressure = pressure[i];
}
printf("Task A for n = %d\n", n);
printf("Min Temp: %.2f\n", minTemp);
printf("Max Pressure: %.2f\n", maxPressure);
}
// Task B : navie pairwise comparision
void TaskB(float temp[], float pressure[], int n) {
float minTemp, maxPressure;
for (int i = 0; i < n; i++) {
int isMin = 1;
for (int j = 0; j < n; j++) {
if (temp[i] > temp[j]) {
isMin = 0;
break;
}
}
if (isMin) {
minTemp = temp[i];
break;}
}
for (int i = 0; i < n; i++) {
int isMax = 1;
for (int j = 0; j < n; j++) {
if (pressure[i] < pressure[j]) {
isMax = 0;
break;}
}
if (isMax) {
maxPressure = pressure[i];
break;

}
}
printf("Task B for n = %d\n", n);
printf("Min Temp: %.2f\n", minTemp);
printf("Max Pressure: %.2f\n\n", maxPressure);
}
// Task c : linear searchh
int linearSearch(float arr[], int n, float key) {
for (int i = 0; i < n; i++) {
if (arr[i] >= key)
return i;
}
return -1;
}
// Bineary search
int binarySearch(float arr[], int n, float key) {
int low = 0, high = n - 1, result = -1;
while (low <= high) {
int mid = (low + high) / 2;
if (arr[mid] >= key) {
result = mid;
high = mid - 1;
} else {
low = mid + 1;}
}
return result;}

void TaskC(int n) {
float *temp = (float *)malloc(n * sizeof(float));
generatetemp(temp, n);
printf("Task C for n = %d:\n", n);

int linear = linearSearch(temp, n, 30);
int bineary = binarySearch(temp, n, 30);
printf("Linear Search %d, Value: %.2f\n", linear,
temp[linear]);
printf("Binary Search : %d, Value: %.2f\n\n", bineary,
temp[bineary]);
free(temp);
}

// main
int main() {
clock_t start, end;
double time_spent;
int sizes[] = {N1, N2, N3};
for (int s = 0; s < 3; s++) {
int n = sizes[s];
float *temp = (float *)malloc(n * sizeof(float));
float *pressure = (float *)malloc(n * sizeof(float));
generatedata(temp, pressure, n);
// Task A
start = clock();
TaskA(temp, pressure, n);
end = clock();
time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time taken by Task A: %.6f sec\n", time_spent);
// Task B
if (n <= 1000000) {
start = clock();

TaskB(temp, pressure, n);
end = clock();
time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time taken by Task B: %.6f sec\n",
time_spent);
}
// Task c
start = clock();
TaskC(n);
end = clock();
time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time taken by Task C: %.6f sec\n", time_spent);
free(temp);
free(pressure);
}
return 0;
}