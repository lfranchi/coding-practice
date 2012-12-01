#!/usr/bin/env python

def permute(s):
    res = set()
    if len(s) == 1:
        res = res.union(s)
    else:
        for i in xrange(len(s)):
            perm = s[:i] + s[i+1:]
            p = permute(perm)
            for substr in p:
                res = res.union([substr])
                res = res.union([s[i] + substr])
    return res

print "DONE: %s %s" % ("odg", permute("odg"))