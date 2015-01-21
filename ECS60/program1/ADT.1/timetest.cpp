#include <iostream>
#include "CPUTimer.h"
#include "CursorList.h"
#include "LinkedList.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "vector.h"
#include "dsexceptions.h"
#include <fstream>
#include <stdexcept>
#include <iomanip>

vector<CursorNode <int> > cursorSpace (250000);
int getChoice(){
	int choice;
	std::cout << std::setw(10) << "ADT Menu" << endl;
	std::cout << "0. Quit" << endl; 
	std::cout << "1. LinkedList" << endl;
	std::cout << "2. CursorList" << endl;
	std::cout << "3. StackAr" << endl;
	std::cout << "4. StackLi" << endl;
	std::cout << "5. QueueAr" << endl;
	std::cout << "6. SkipList" << endl;
	std::cout << "Your choice >> ";
	std::cin >> choice;
	return choice;
}//end getChoice

void RunList(char filename[]){
	char operation;
	int value;
	ifstream inf(filename);
	inf.ignore(1000, '\n');	
	//std::cout << "filename is: " << filename << endl;
	List<int> list;
	ListItr <int> listItr = list.zeroth();
	while (inf >> operation >> value){
		if (operation == 'i'){
			list.insert(value, listItr);
			//std::cout << "inserting: " << value << endl; 
		}else if (operation == 'd'){
			list.remove(value);
			//std::cout << "removing" << value << endl;
		}//end else if			
	}//end while
}//end RunList

void RunCursorList(char filename[]){
	char operation;
	int value;
	ifstream inf (filename);
	inf.ignore(1000, '\n');
	//vector<CursorNode <int> > cursorSpace(250000);
	//std::cout << "filename is: " << filename << endl;
	CursorList<int> cList(cursorSpace);
	CursorListItr<int> cListItr = cList.zeroth();
	while (inf >> operation >> value){
		if (operation == 'i'){
			cList.insert(value, cListItr);
		}else if (operation == 'd'){
			cList.remove(value);
		}//end else if
	}//end while
}//end RunCursorList

void RunStackAr(char filename[]){
	char operation;
	int value;
	ifstream inf(filename);
	inf.ignore(1000, '\n');
	StackAr<int> stackList (250000);
	while (inf >> operation >> value){
		if (operation == 'i'){
			stackList.push (value);
		}else if (operation == 'd'){
			stackList.pop();
		}//end else if
	}//end while
}//end RunStackAr


void RunSkipList(char filename[])
{
    ifstream inf(filename);
    inf.ignore(1000, '\n');
  
    SkipList<int> list(-1, 250000);
    char operation;
    int value;
    
    while(inf>>operation>>value)
    {
        if(operation == 'i') 
	  list.insert(value);
        if(operation == 'd') 
	  list.deleteNode(value);
    }
}

void RunStackLi(char filename[])
{
    ifstream inf(filename);
    inf.ignore(1000, '\n');
    
    StackLi<int> list;

    char operation;    
    int value;
    
    while(inf>>operation>>value)
    {
        if(operation == 'i') 
	  list.push(value);
        else if(operation == 'd')
	  list.pop();
    }
}

void RunQueueAr(char filename[])
{
    ifstream inf(filename);
    inf.ignore(1000, '\n');
    
    Queue<int> array(250000);
    char operation;
    int value;
    
    while(inf>>operation>>value)
    {
        if(operation == 'i') 
	  array.enqueue(value);
        if(operation == 'd') 
	  array.dequeue();
    }
}

int main(){
	char filename[90];
	int choice;
	CPUTimer ct;
	std::cout << "Filename >> ";
	std::cin >> filename;
	do {
		choice = getChoice();
		ct.reset();
		switch (choice){
			case 1: RunList(filename); break;
			case 2: RunCursorList(filename); break;
			case 3: RunStackAr(filename); break;
			case 4: RunStackLi(filename); break;
			case 5: RunQueueAr(filename); break;
			case 6: RunSkipList(filename); break;
		}//end switch
		std::cout << "CPU time: " << ct.cur_CPUTime() << endl;
	} while(choice > 0);
}//end main

