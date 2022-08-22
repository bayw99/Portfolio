#include <map>
#include <stdio.h>
#include <malloc.h>

/* Question 3:  5 Points.  Without compiling and running this program
 * hand trace and draw the output of the program
 */

/*
buffer[0] -> malloc(1024)       free
buffer[1] -> malloc(1024) free (deallocated memory)
buffer[2] -> malloc(1024)       free
buffer[3] -> malloc(1024) free
buffer[4] -> malloc(1024)       free
buffer[5] -> malloc(1024) free
buffer[6] -> malloc(1024)       free
buffer[7] -> malloc(1024) free
buffer[8] -> malloc(1024)       free
buffer[9] -> malloc(1024) free
buffer[10] -> malloc(1024)      free
 
 
 print:
 ******************
 6 unfreed locations
 ******************
 
 ******************
 0 unfreed locations
 ******************
 
 
 */

       
using namespace std;
       
map <void *, size_t > allocations;

void report(){
    map<void *, size_t>::iterator it;
    printf("******************\n");
    int count=0;
    for (it=allocations.begin();it!=allocations.end();it++) {
       // printf("location %p (%lu) is still allocated\n",it->first,it->second);
       count++;
    }
    printf("%d unfreed locations",count);
    printf("******************\n");
}       

/* Prototypes for our hooks.  */
static void my_init_hook(void);
static void *my_malloc_hook(size_t, const void *);
static void my_free_hook(void *ptr, const void *caller);

/* Variables to save original hooks. */
static void *(*old_malloc_hook)(size_t, const void *);
static void (*old_free_hook)(void *ptr, const void *caller);

/* Override initializing hook from the C library. */
void (*__malloc_initialize_hook) (void) = my_init_hook;
//  void (*__free_hook)(void *ptr, const void *caller);

static void my_init_hook(void) {
	   old_malloc_hook = __malloc_hook;
	   __malloc_hook = my_malloc_hook;
	   old_free_hook=__free_hook;
	   __free_hook=my_free_hook;
   }

static void * my_malloc_hook(size_t size, const void *caller) {
	   void *result;

	   /* Restore all old hooks */
	   __malloc_hook = old_malloc_hook;

	   /* Call recursively */
	   result = malloc(size);

	   /* Save underlying hooks */
	   old_malloc_hook = __malloc_hook;

	   allocations[result]=size;

	   /* Restore our own hooks */
	   __malloc_hook = my_malloc_hook;

	   return result;
   }
   
static void my_free_hook(void *ptr, const void *caller) {
	   /* Restore all old hooks */
	   __free_hook = old_free_hook;

	   allocations.erase(ptr);

	   /* Call recursively */
	   free(ptr);

	   /* Save underlying hooks */
	   old_free_hook = __free_hook;


	   /* Restore our own hooks */
	   __free_hook = my_free_hook;
}

int main() {
  my_init_hook();
  char *buffer[100];
  for (int i=0;i<=10;i++) {
	  buffer[i]=(char *)malloc(1024);
	  if (i%2==1) free(buffer[i]);
  }
  report();
  for (int i=0;i<10;i++) {
	  if (i%2==0) free(buffer[i]);
  }  
  report();
  return 0;
}

