import sys
import time
def sprint(str):
   for c in str + '\n':
     sys.stdout.write(c)
     sys.stdout.flush()
     time.sleep(3./90)
