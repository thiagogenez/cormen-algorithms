#! /usr/bin/python
# coding: utf-8

import random

def get_array(qtd = 10, max = 100):
	s = set()
	while len(s) != qtd:
		s.add(random.randint(1, max))
	return list(s)

