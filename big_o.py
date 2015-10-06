#!/usr/bin/python
#
#  This is a comment
#
#  This program is going to validate if some function f(n) is indeed big O of some other 
#  function g(n)
#
#  This looks for witnesses n & c, where T(n) <= cF(n)
#
#
import sys, string, os, math

MaxConstantToTry = 100
MaxNToTry = 10

for c in range(1, MaxConstantToTry):
   for i in range(4, MaxNToTry):
      equation1 = math.pow(4,i)
      equation2 = math.pow(2,i)
      if (equation1 <= (c*equation2)):
         print "Checking 4^",i," & 2^",i,", for constant ",c,", equation 1=",equation1,", equation2=",equation2
         print "*****SUCCESS****"
         a = raw_input("YOUR DONE, PROVEN, Press enter to continue")
         exit()
      print "Checking 4^",i," & 2^",i,", for constant ",c,", equation 1=",equation1,", equation2=",equation2
      #a = raw_input("Press enter to continue")

