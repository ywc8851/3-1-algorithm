#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int data[6];
double sort_time[2][3];
double random_time[2][3];
double time_result = 0;
clock_t start, end;
long double* tmp = new long double[10000000];
void quicksort(long double* quick_s, int low, int high);
void mergesort(long double* merge_s, int low, int high);
void merge(long double* merge_s, int low, int mid, int high);

int main(){
 int i;
 int num;
    ifstream file;
    file.open("input.txt");
 for (int t = 0; t < 3; t++) {
        file >> num;
        data[t] = num;

 long double* merge_s = new long double[num + 1];
 for (int i = 0; i < num; i++) { merge_s[i] = i; }

 start = clock();
 mergesort(merge_s, 0, num - 1);
 end = clock();
 time_result = (double)(end - start) / CLOCKS_PER_SEC;
 sort_time[0][t] = time_result;

 long double* quick_s = new long double[num + 1];
 for (int i = 0; i < num; i++) { 
 quick_s[i] = i; 
 }

 start = clock();
 quicksort(quick_s, 0, num - 1);
 end = clock();
 time_result = (double)(end - start) / CLOCKS_PER_SEC;
 sort_time[1][t] = time_result;

 delete[] merge_s;
 delete[] quick_s;}
for (int t = 0; t < 3; t++) {
  file >> num;
  data[t + 3] = num;

  long double* merge_s = new long double[num + 1];
  long double* quick_s = new long double[num + 1];

  srand(time(NULL));
  for (int i = 0; i < num; i++) {
   long double num = rand() % RAND_MAX;
   merge_s[i] = num;
   quick_s[i] = num;
  }
  start = clock();
  mergesort(merge_s, 0, num - 1);
  end = clock();
  time_result = (double)(end - start) / CLOCKS_PER_SEC;
  random_time[0][t] = time_result;

  start = clock();
  quicksort(quick_s, 0, num - 1);
  end = clock();
  time_result = (double)(end - start) / CLOCKS_PER_SEC;
  random_time[1][t] = time_result;

  delete[] merge_s;
  delete[] quick_s;

 }
    printf("           |             sorted             ||               random             |\n");
    printf("           |  N=%d |  N=%d |  N=%d ||  N=%d | N=%d |  N=%d |\n", data[0], data[1], data[2], data[3], data[4], data[5]);
    printf(" Merge Sort| %lf | %lf | %lf || %lf  | %lf | %lf  |\n", sort_time[0][0], sort_time[0][1], sort_time[0][2], random_time[0][0], random_time[0][1], random_time[0][2]);
    printf(" Quick Sort| %lf | %lf | %lf || %lf  | %lf | %lf  |\n", sort_time[1][0], sort_time[1][1], sort_time[1][2], random_time[1][0], random_time[1][1], random_time[1][2]);
   return 0; 
}
void merge(long double* merge_s, int start, int middle, int end) {
 int i = start;
 int j = middle + 1;
 int k = start;
 while (i <= middle && j <= end) {
  if (merge_s[i] <= merge_s[j]) {
   tmp[k] = merge_s[i];
   i++;
  }
  else {
   tmp[k] = merge_s[j];
   j++;
  }
  k++;
 }

 if (i > middle) {
  for (int a = j; a <= end; a++) {
   tmp[k] = merge_s[a];
   k++;
  }
 }
 else {
  for (int a = i; a <= middle; a++) {
   tmp[k] = merge_s[a];
   k++;
  }
 }

 for (int a = start; a <= end; a++) {
  merge_s[a] = tmp[a];
 }
}

void mergesort(long double* merge_s, int start, int end) {
 if (start < end) {
  int middle = (start + end) / 2;
  mergesort(merge_s, start, middle);
  mergesort(merge_s, middle + 1, end);
  merge(merge_s, start, middle, end);
 }
}


void quicksort(long double* quick_s, int start, int end) {
 int i = start, j = end;
 long double pivot = quick_s[start];
 do {
  while (quick_s[i] < pivot) { i++; }
  while (quick_s[j] > pivot) { j--; }
  if (i <= j) {
   if (quick_s[i] > quick_s[j]) {
    long double temp = quick_s[i];
    quick_s[i] = quick_s[j];
    quick_s[j] = temp;
   }
   i++;
   j--;
  }
 } while (i <= j);

 if (start < j) { quicksort(quick_s, start, j); }
 if (i < end) { quicksort(quick_s, i, end); }

}
 
