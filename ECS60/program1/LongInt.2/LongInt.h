#ifndef LongInt_H
#define LongInt_H
#include "LinkedList.h"

class LongInt{
friend ostream& operator<<(ostream &, LongInt &);
friend istream& operator>>(istream &, LongInt &);
friend LongInt operator+(LongInt &, LongInt &);

 public:
 LongInt();
 List<int> sumLongInt(LongInt &, LongInt &);
 LongInt& operator=(const LongInt& rhs);
 List<int> num1;
};//end class Long Int

#endif
