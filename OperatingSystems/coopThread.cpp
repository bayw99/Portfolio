#include <iostream>

using namespace std;

typedef void (*Ptr)(int);

int numThr=0;

long r0[10],r1[10],r2[10]; // struct with all registered named
long *stack0,*stack1,*stack2;

void save(long *rLocation) {
    asm("mov %rax, (%rdi)\n"
        "mov %rbx, 8(%rdi)\n"
        "mov %rcx, 16(%rdi)\n"
        "mov %rdx, 24(%rdi)\n"
        "mov %rsi, 32(%rdi)\n"
        "mov %r8, 40(%rdi)\n"
        "mov %rbp, 48(%rdi)\n");
}

void load(long *rLocation) {  // similar to the book
    asm("mov (%rdi), %rax\n"
        "mov 48(%rdi), %rbp\n"
        "mov 40(%rdi), %r8\n"
        "mov 32(%rdi), %rsi\n"
        "mov 24(%rdi), %rdx\n"
        "mov 16(%rdi), %rcx\n"
        "mov 8(%rdi), %rbx\n");
}

int currentThr;

void setStack(long *s) {
    asm("mov %rdi,%rsp\n");
}

void setStackAndRun(long *s,Ptr ptr) {
    asm("mov %rdi,%rsp\n");
    ptr(currentThr);
}

void getStack(long **s) {
    asm("mov %rsp,(%rdi)");
}
 
void startThr(Ptr ptr) {
    numThr++;
    currentThr=numThr;
    if (numThr==1) {
        stack1=((long *)malloc(sizeof(long)*64000))+64000;
        save(r0);
        getStack(&stack0);
        load(r1);
        setStackAndRun(stack1,ptr);
    }
    else if (numThr==2) {
        stack2=((long *)malloc(sizeof(long)*64000))+64000;
        save(r0);
        getStack(&stack0);
        load(r2);
        setStackAndRun(stack2,ptr);
    }
   numThr = 0;
}

void shareCPU(int thread) {
  if (numThr== 1) {
      save(r1); // Save out created thread registers
      load(r0); // Load the main thread registers
      setStack(stack0);
  }
  else if (numThr == 2) {
      save(r2);
      load(r0);
      setStack(stack0);
  }
  // Switch stacks back and swap registers
}

void main1(int whoami) {
    while(true) {
        cout << "Main 1 says Hello" << endl;
        shareCPU(whoami);
    }
}

void main2(int whoami) {
    while(true) {
        cout << "Main 2 says Hello" << endl;
        shareCPU(whoami);
    }
}

int main() {
    startThr(main1);
    startThr(main2);
    startThr(main1);
    while(true) {
        shareCPU(0);
    };
    return 0;
}

