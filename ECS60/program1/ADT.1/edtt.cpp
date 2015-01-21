#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "SkipList.h"
#include <iostream>
#include <fstream>

using namespace std;
//vector<CursorNode <int> > cursorSpace(250000);

// RunList function
void RunList(char filename[]) {

  //opening ifstream named myfile using filename as a variable
  ifstream myfile(filename);
  char operation;
  int value;
  //initializing list and listitr
  List<int> list;
  ListItr<int> listitr = list.zeroth();
  
  myfile.ignore(1000, '\n');

  //operation loop
  while (myfile>>operation>>value) {
    if (operation == 'i') {
      list.insert(value, listitr);
    }
    else if (operation == 'd') {
      list.remove(value);
    }
  }
}

int getChoice() {
  int choice;
  cout << " ADT Menu " << endl;
  cout << "0. Quit" << endl;
  cout << "1. LinkedList" << endl;
  cout << "2. CursorList" << endl;
  cout << "3. StackAr" << endl;
  cout << "4. StackLi" << endl;
  cout << "5. QueueAr" << endl;
  cout << "6. SkipList" << endl;
  cout << "Your choice >> ";
  cin >> choice;
  return choice;
} 

int main()
{
  char filename[100];
  int choice;
  CPUTimer ct;
  cout << "Filename >> ";
  cin >> filename;

  do
  {
    choice = getChoice();
    ct.reset();
    switch(choice)
    {
      case 1: RunList(filename); break;
              // case 2: RunCursorList(filename); break;
              // case 3: RunStackAr(filename); break;
              // case 4: RunStackLi(filename); break;
              // case 5: RunQueueAr(filename); break;
              // case 6: RunSkipList(filename); break;
    }

    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while(choice > 0);

}
