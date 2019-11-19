#define MAX_SIZE 3

int* pPut;
int* pGet;

int buffer[MAX_SIZE];

void stack_init(void)
{
    pPut = &buffer[0];
    pGet = &buffer[0];
}

int stack_put(int data)
{
  // stack is full
  if (pPut == &buffer[MAX_SIZE]) {
    return -1;
  }
  
  // put data in stack
  *pPut = data;
  
  // update get pointer
  pGet = pPut;
  
  // increment put pointer
  pPut++;
  
  return 0;
}

int stack_get(int* data)
{
  // Stack is empty
  if (pGet == pPut) {
    return -1;
  }
  
  // get data from stack
  *data = *pGet;
  
  // update put pointer
  pPut--;
  
  // decrement get pointer if not empty
  if (pGet > &buffer[0]) {
    pGet--;
  }
  
  return 0;
}