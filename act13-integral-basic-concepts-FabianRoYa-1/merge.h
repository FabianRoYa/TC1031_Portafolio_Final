// =================================================================
//
// File: insertion.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				merge sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef MERGE_H
#define MERGE_H

#include "header.h"
#include <vector>
#include <iostream>
#include <cstring>
#include "header.h"

// =================================================================
// MERGE SORT - VECTOR VERSION
// =================================================================

// =================================================================
// Copy the range [low, high] from array B to array A.
//
// @param A, the destination vector.
// @param B, the source vector.
// @param low, lower index.
// @param high, higher index.
// =================================================================
template <class T>
void copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

// =================================================================
// Merge both halves of A, using B array as temporary storage.
//
// @param A, the source vector.
// @param B, the destination vector.
// @param low, lower index.
// @param mid, middle index.
// @param high, higher index.
// =================================================================
template <class T>
void merge(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while(i <= mid && j <= high){
		if(A[i].get_fecha < A[j].get_fecha){
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}

	for(; j <= high; j++){
		B[k++] = A[j];
	}

	for(; i <= mid; i++){
		B[k++] = A[i];
	}
}

// =================================================================
// If the minimum unit has not been reached (a single array
// position), separate the range [low, high] into two halves,
// invoking the split process again. When no more separations can be
// made, mix both halves of the arrangement.
//
// @param A, the source array.
// @param B, the temporal array.
// @param low, lower index.
// @param high, higher index.
// =================================================================
template<class T>
void split(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int  mid, size, i, j;

	if (high - low == 0) return;

	mid = low + ((high - low) / 2);
	split(A, B, low, mid);
	split(A, B, mid + 1, high);
	merge(A, B,low, mid, high);
	copyArray(A, B, low, high);
}

// =================================================================
// Performs the merge sort algorithm.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================

// =================================================================
// Modificaciones de las funciones para el porgrama
template <class T>
void mergeSort(std::vector<T> &A) {
	std::vector<T> B(A.size());
	split(A, B, 0, A.size() - 1);
}

// =================================================================
// Modificaciones de las funciones para el porgrama
// =================================================================

//Funcion para buscar por dia
template <class T>
int mergeSortDay(std::vector<T> &v) {
  int counter = 0; 
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].day > v[j + 1].day){
				swap(v, j, j + 1);
        counter+=1; 
			}
		}
	}
  return counter; 
}

// Funcion para buscar por mes
template <class T>
int mergeSortMonth(std::vector<T> &v) {
  int counter = 0; 
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].month > v[j + 1].month){
        counter+=1; 
				swap(v, j, j + 1);
			}
		}
	}
  return counter; 
}

#endif /* MERGE_H */
