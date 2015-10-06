
# Ancient Egyptian Multiplication Algorithm
# Also called Russian Peasant's Algorithm
#
#  This Algorithm is superfast. It is O(:wq
def russian(a,b):
   x = a; y = b;
   z = 0
   while x > 0:
      if x % 2 == 1: 
         z = z + y
         print "Addition"
      y = y << 1
      x = x >> 1
   return z

def naive(a,b):
   x = a; y = b;
   z = 0;
   while x > 0:
      z = z + y
      x = x - 1
   return z


print russian(20,7)
#print "x = %d, z=%d" % (x,z)
