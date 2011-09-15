#! /usr/bin/python
# coding: utf-8

import utils

def merge(left, right):
	A = []
        i ,j = 0, 0
	while i < len(left) and j < len(right):
		if left[i] <= right[j]:
			A.append(left[i])
			i += 1
		else:
			A.append(right[j])
			j += 1
	A += left[i:]
	A += right[j:]
	return A


def mergesort(A):
	if len(A) > 1:
		q = len(A) // 2
		left = mergesort(A[:q])
		right = mergesort(A[q:])
		return merge(left, right)
	return A

if __name__ == "__main__":
	A = utils.get_array()
	print "unsorted(A): " + str(A)
	print "mergesort(A): " + str(mergesort(A))
