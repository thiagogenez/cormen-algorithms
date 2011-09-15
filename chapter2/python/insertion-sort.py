#! /usr/bin/python
# coding: utf-8

import utils

def insertion_sort(A):
	for i in range(1,len(A)):
		key = A[i]
		j = i - 1
		while j >= 0 and A[j] > key:
			A[j + 1] = A[j]
			j -= 1
		A[j + 1] = key


if __name__ == "__main__":
	A = utils.get_array()
	print "unsorted(A): " + str(A)
	insertion_sort(A)
	print "sorted(A): "+ str(A)
