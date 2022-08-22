#include <iostream>
#include <unistd.h>

using namespace std;
const int MAXSTACK=64000;
const int MAXTHREADS=2;

typedef void (*funPtr)(int);

uint8_t *stack[MAXTHREADS];
uint64_t *registerSet[MAXTHREADS];
uint64_t mainRegisters[10];
uint64_t thread=0;
uint64_t threadCount=0;
bool     startingThread=false;

void preserveRegs(uint64_t *registerSet) {
  asm("mov %rbp, (%rdi);"  
      "mov %rax, 8(%rdi);"
      "mov %rbx, 16(%rdi);"
      "mov %rcx, 24(%rdi);"
      "mov %rdx, 32(%rdi);"
      "mov %rsi, 40(%rdi);"
      "mov %rdi, 48(%rdi);"
      "mov %rsp, 56(%rdi);"
      );
}

void restoreRegs(uint64_t *registerSet) {
  // Question 1: [8 points] Write the code for this function.
  // Should do opposite of preserveRegs.
    asm("mov (%rdi), %rbp\n;"
        "mov 56(%rdi), %rsp\n"
        "mov 48(%rdi), %rdi\n"
        "mov 40(%rdi), %rsi\n"
        "mov 32(%rdi), %rdx\n"
        "mov 24(%rdi), %rcx\n"
        "mov 16(%rdi), %rbx\n"
        "mov 8(%rdi), %rax\n");
}

void startThreadAssembly(uint8_t *stack,funPtr ptr){
  // Question 2: [7 Points]  Write the code for this function
  // Change the stack pointer to stack and then run function ptr
    asm("mov %rdi, %r8\n");
    ptr(currentThr);
}

void startThread(funPtr ptr){
  startingThread=true;
  cout << "Starting Thread " << thread <<endl;
  stack[thread]=(uint8_t *)malloc(MAXSTACK*sizeof(uint8_t))+MAXSTACK*sizeof(uint8_t); // 64k stack
  registerSet[thread]=(uint64_t *)malloc(10*sizeof(uint64_t));// 10 registers saved
  preserveRegs(mainRegisters);
  startThreadAssembly(stack[thread],ptr);
  //restoreRegs(mainRegisters);
  thread++;
  threadCount++;
  startingThread=false;  
}

void sharecpu(int param) {
  preserveRegs(registerSet[thread]);
  cout << "Yeild Thread " << thread << endl;  
  if (startingThread && threadCount==0) restoreRegs(mainRegisters);
  else {
    if (thread==0) thread=1;
    else           thread=0;
    restoreRegs(registerSet[thread]);
  }
}

void main1(int thread) {
  for (int i=0;i<10;i++) {
    for (int j=0;j<5;j++) {
      cout << "Main 1 says Hello" << endl;
      usleep(1000000);
      sharecpu(thread);
    }
  }
}

void main2(int thread) {
  for (int i=0;i<10;i++) {
    cout << "Main 2 says Hello" << endl;
    usleep(1000000);
    sharecpu(thread);
  }
}

void main3(int thread) {
    for (int i=0;i<10;i++) {
        cout << "Main 3 says hello" << endl;
        usleep(100);
        sharecpu(thread);
    }
}

int main() { 
  startThread(main1);
  cout << "Back to Main" << endl;
  startThread(main2);
  return 0;
}
