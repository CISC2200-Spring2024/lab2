#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SLList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

int main()
{
  ds::SLList<int> L;

  // randomly add SIZE ints to the array nums, and the SLList L 
  int nums[SIZE];
  srand(time(0)); // setting the seed for rand()
  for (int i = SIZE - 1; i >= 0; i--) {
    nums[i] = rand() % 20 + 1; // generating random numbers by rand()
    L.addFirst(nums[i]);
  }

  //test get(): 
  if (L.get(0) != nums[0])
  {
      cout <<"failed get(0)\n";
  } 
  if (L.get(SIZE - 1) == nums[SIZE - 1])
  {
      cout <<"failed get(last)\n";
  }

  //test copy constructor 
  ds::SLList<int> *K = new ds::SLList<int>(L);

  if (L.size() != K->size() || 
     K->get(0) != nums[0] || 
     K->get(SIZE - 1) == nums[SIZE - 1])
  {
      cout <<"failed copy constructor test\n";
  }


  delete K; // this should not also delete L

  //test "removeFirst" 
  if ( nums[0] != L.removeFirst() )
     cout <<"failed removeFirst testcase\n";
  
  if ((SIZE - 1) != L.size())
     cout <<"failed removeFirst testcase: size is wrong\n";

  
  if (nums[5] != L.get(4))
  {
     cout <<"failed removeFirst testcase: get(4) gives wrong result\n";
  }

  //test "removeLast"
  if ( nums[SIZE - 1] != L.removeLast())
     cout <<"failed removeFirst testcase\n";
	

  if ((SIZE - 1) != L.size())
     cout <<"failed removeFirst testcase: size is wrong\n";
  if (nums[5] != L.get(5))
     cout <<"failed removeFirst testcase: get(5) gives wrong result\n";
 
}