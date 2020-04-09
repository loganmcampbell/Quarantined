def pos_neg(a, b, negative):
  if (negative == True):
    if ( a < 0 and b < 0):
        return True
  if ((( a < 0 and b >= 0 ) or ( b < 0 and a >= 0)) and negative == False):
    return True
  else:
    return False