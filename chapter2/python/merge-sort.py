#! /usr/bin/python
# coding: utf-8


import sys
import utils

def merge(A,p,q,r):
	left = list()
	right = list()

	for i in range(q):
		left.append(A[i])
	for i in range(q,r):
		right.append(A[i])
	
	left.append(sys.maxint)
	right.append(sys.maxint)
	
	a = 0
	b = 0

	for i in range(r):
		if left[a] <= right[b]:
			A[i] = left[a]
			a += 1
		else:
			A[i] = right[b]
			b += 1
	

def merge_sort(A,p,r):
	if p < r:
		q = (p + r) // 2
		merge_sort(A,p,q)
		merge_sort(A,q+1,r)
		merge(A,p,q,r)

if __name__ == "__main__":
	A = utils.get_array()
	print "unsorted(A): " + str(A)
	merge_sort(A,0,len(A))
	print "merge-sort(A): " + str(A)
