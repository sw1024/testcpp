#!/usr/bin/python

from xml.dom import minidom

'''
domtree = minidom.parse("movie.xml")
collection = domtree.documentElement
'''
'''example 1
for i in range(1, 5):
    for j in range(1, 5):
        if i == j:
            continue;
        for k in range(1, 5):
            if k != i and k != j and i != j :
                print i,j,k
'''
i = int(raw_input("lirun:"))
arr=[1000000,600000,400000,200000,100000, 0]
rate=[0.01,0.015,0,03,0,05,0,075,0,1]
r = 0
for idx in range(0, 6):
    print idx
    if (i > arr[idx]):
        val = (i - arr[idx]) * rate[idx]
        r += val
        i = arr[idx]
print r

