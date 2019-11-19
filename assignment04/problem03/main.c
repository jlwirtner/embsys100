#include <assert.h>
#include "stack.h"

int main()
{
  int testValue;
  int testBuffer;
  int result1;
  int result2;
  
  
  // *****************************************************************
  // Test1: Retrieve item from empty stack
  // *****************************************************************
  // Arrange:
  result1 = 444;
  testBuffer = 444;
  stack_init();
  
  // Act:
  result1 = stack_get(&testBuffer);
  
  // Assert:
  assert(-1 == result1);
  assert(444 == testBuffer);
  
  
  
  // *****************************************************************
  // Test2: Successfully retrieve item from stack
  // *****************************************************************
  // Arrange:
  result1 = 444;
  result2 = 444;
  testValue = 4;
  testBuffer = 10;
  stack_init();
  
  // Act:
  result1 = stack_put(testValue);
  result2 = stack_get(&testBuffer);
  
  // Assert:
  assert(0 == result1);
  assert(0 == result2);
  assert(testValue = testBuffer);
  
  
  
  // *****************************************************************
  // Test3: Fill stack, then get all items
  // *****************************************************************
  // Arrange:
  testBuffer = 10;
  stack_init();
  
  // Act:
  stack_put(1);
  stack_put(2);
  stack_put(3);
  
  // Assert:
  assert(0 == stack_get(&testBuffer));
  assert(3 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(2 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(1 == testBuffer);
  
  
  
  // *****************************************************************
  // Test4: Fill stack, fail to put another item in
  // *****************************************************************
  // Arrange:
  testBuffer = 10;
  stack_init();
  
  // Act:
  stack_put(1);
  stack_put(2);
  stack_put(3);
  result1 = stack_put(4);
  
  // Assert:
  assert(-1 == result1);
  
  assert(0 == stack_get(&testBuffer));
  assert(3 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(2 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(1 == testBuffer);
  
  
  
  // *****************************************************************
  // Test5: Fill stack, pop one item, fill again, pop all
  // *****************************************************************
  // Arrange:
  testBuffer = 10;
  stack_init();
  
  // Act:
  stack_put(1);
  stack_put(2);
  stack_put(3);
  
  // Assert:
  assert(0 == stack_get(&testBuffer));
  assert(3 == testBuffer);
  
  assert(0 == stack_put(4));
  
  assert(0 == stack_get(&testBuffer));
  assert(4 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(2 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(1 == testBuffer);
  
  
  
  // *****************************************************************
  // Test6: Fill stack, pop all items twice
  // *****************************************************************
  // Arrange:
  testBuffer = 10;
  stack_init();
  
  // Act:
  stack_put(1);
  stack_put(2);
  stack_put(3);
  
  // Assert:
  assert(0 == stack_get(&testBuffer));
  assert(3 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(2 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(1 == testBuffer);
  
  assert(0 == stack_put(4));
  assert(0 == stack_put(5));
  assert(0 == stack_put(6));
  
  assert(0 == stack_get(&testBuffer));
  assert(6 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(5 == testBuffer);
  
  assert(0 == stack_get(&testBuffer));
  assert(4 == testBuffer);
  
  return 0;
}
