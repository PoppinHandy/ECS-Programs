
#include "LinkedList.h"
#include "StackLi.h"
#include "LongInt.h"
#include <iostream>
#include <stdexcept>
#include <cctype> //for isdigit


LongInt::LongInt(){
  num1.makeEmpty();
}//end constructor

LongInt& LongInt::operator=(const LongInt& rhs){
  if(&rhs == this){
    return *this;
  }
  num1 = rhs.num1;
  return *this;
}//end operator= 

std::istream& operator>>(std::istream &input, LongInt &n1){
  //Take in the character and split each digit, putting each digit
  //into a list
  ListItr <int> itr = n1.num1.zeroth();
  int convertChar = 0;
  char digit;
  while(input && input.peek() != '\n'){
    if(std::isdigit(input.peek())){
      input >> digit;
      convertChar = digit - '0';
      n1.num1.insert(convertChar, itr);
      //std::cout<< "inserting " << digit << endl;
    }//end if
  }//end while
  input.ignore(1, '\n');
  itr = n1.num1.first();
  return input;
}//end operator>>

/*
Input: 2 lists containing the long int numbers
Output: List containing the solution
Initiate two stacks to do the operation, take the first
value of linked list, put it in a stack, increment iterator,
do the same for the second stack. Add top stacks together.
If s1.top + s2.top > 9, add 1 to carry stack. Loop through the rest
of the lists, adding 1 to resulting number and popping stack.
Execeptions: if itr.isPastEnd() for any list, then print the 
remaining numbers of the other list out
 */
List<int> LongInt::sumLongInt(LongInt &n1, LongInt &n2){
  static StackLi<int> carryStack;
  List <int> soln;
  int sum = 0;
  ListItr <int> itr1 = n1.num1.first();
  ListItr <int> itr2 = n2.num1.first();
  ListItr <int> solnItr = soln.zeroth();
  while(!itr1.isPastEnd() && !itr2.isPastEnd()){
    sum = itr1.retrieve() + itr2.retrieve();
    //std::cout << "Sum is " << sum << endl;
    //mainly for first two numbers, and with no carrying of 1
    if (sum > 9 && carryStack.isEmpty()){
      soln.insert(sum - 10, solnItr);
      //std::cout << "adding (empty Stack): " << solnItr.retrieve() << endl;
      carryStack.push(1);
      itr1.advance();
      itr2.advance();
    }
    //there is a one carry and sum is greater than nine
    else if(sum > 9 && !carryStack.isEmpty()){
      soln.insert(sum - 10 + carryStack.topAndPop(), solnItr); //stack now empty
      //std::cout << "adding (with Stack): " << solnItr.retrieve()<< endl;
      carryStack.push(1);
      itr1.advance();
      itr2.advance();
    }
    //sum doesnt carry over, but there's still a 1 from last calculation
    else if (sum <= 9 && !carryStack.isEmpty()){
      soln.insert(sum + carryStack.topAndPop(), solnItr); //stack now empty
      //std::cout << "adding (sum less than 9 and stack not empty): " << solnItr.retrieve()<< endl;
      itr1.advance();
      itr2.advance();
    }//end if else
    //sum doesn't carry over and there's no 1 to carry over from
    else{
      soln.insert(sum, solnItr); 
      //std::cout << "adding (no carry over and sum less than 9): " << solnItr.retrieve()<< endl;
      itr1.advance();
      itr2.advance();
    }//end else
  }//end while
      
  /*At this point either both int lists have already gone through, or one 
    of them has so this next part is for the latter condition where
    either list still has numbers to input
  */
  if (!itr2.isPastEnd() && itr1.isPastEnd()){
    //std::cout << "Not finished yet!" << endl;
    while(!itr2.isPastEnd()){
      if(!carryStack.isEmpty()){
	//if number still sums over 10 after adding 1
	if((itr2.retrieve() + carryStack.top()) > 9){
	  soln.insert((itr2.retrieve() + carryStack.top()) - 10, solnItr);
	  itr2.advance();
	}else{
	  soln.insert(itr2.retrieve() + carryStack.topAndPop(), solnItr);
	  //std::cout << "itr2 not empty adding: " << solnItr.retrieve()<< endl;
	  itr2.advance();
	}//end else
      }else{
	soln.insert(itr2.retrieve(), solnItr);
	//std::cout << "itr2 not empty adding: " << solnItr.retrieve()<< endl;
	itr2.advance();
      }//end else
    }//end while
  }else if(!itr1.isPastEnd() && itr2.isPastEnd()){
    //std::cout << "Not finished yet! " << endl;
    while(!itr1.isPastEnd()){
      if(!carryStack.isEmpty()){
	//if the number still sums over 10 after adding 1
	if((itr1.retrieve() + carryStack.top()) > 9){
	  soln.insert((itr1.retrieve() + carryStack.top()) - 10, solnItr);
	  itr1.advance();
	}else{
	  soln.insert(itr1.retrieve() + carryStack.topAndPop(), solnItr);
	  //std::cout << "NOTFINISHEDYETadding: " << solnItr.retrieve()<< endl;
	  itr1.advance();
	}
      }else{
	soln.insert(itr1.retrieve(), solnItr);
	//std::cout << "NOTFINISHEDYETadding: " << solnItr.retrieve()<< endl;
	itr1.advance();
      }//end else
    }//end while
  }//end else if
  else if (itr1.isPastEnd() && itr2.isPastEnd() && !carryStack.isEmpty()){
    soln.insert(carryStack.topAndPop(), solnItr);
  }//end else if
  
  return soln;
}//end sumLongInt

LongInt operator+(LongInt &n1, LongInt &n2){
  LongInt intTmp;
  intTmp.num1 = n1.sumLongInt(n1,n2);
  return intTmp;
}//end operator+

std::ostream& operator<<(std::ostream &out, LongInt &n1){
  ListItr <int> itr = n1.num1.first();
  while(!itr.isPastEnd()){
    out << itr.retrieve();
    itr.advance();
  }//end while
  return out;
}//end operator <<
  
