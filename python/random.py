#!/usr/bin/env python

def num_steps(k):
    if k in [1, 2]:
        return k
    if k == 3:
        return 4
    return num_steps(k-1) + num_steps(k-2) + num_steps(k-3)

n = input()
print "Num for %s: %s" % (n, num_steps(n))