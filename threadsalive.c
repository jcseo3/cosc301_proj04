/*
Names: Junghyun Seo & Cindy Han
Fall 2014
Cosc301 
Project 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <ucontext.h>

#include "threadsalive.h"

/* ***************************** 
     stage 1 library functions
   ***************************** */

#define MEM 128000
//check the number in the size of the array ctx
//did we say we were going to use a linked list or an array...?
//ahhhh is ucontext_t an array or a linked list?!?! wamp wamp wamp...merp..
static ucontext_t ctx[3];
static thread = 0; // a boolean to show if we are in a thread or in the main

//need to initialize a ready queue

//initializes the thread library
void ta_libinit(void) {
   //do we do anything here?
   return;
}

//creates a new thread
void ta_create(void (*func)(void *), void *arg) {
	getcontext(&ctx[1]);
	ctx.uc_stack.ss_sp = malloc(MEM);
	ctx.uc_stack.ss_size = MEM;
	ctx.uc_link = 0; //if we are using a linked list for for ready queue, this needs to be a num other than zero, aka to indicate the next item in the queue. I'm not sure if which number it becomes then...
	//where is this func that prof sommers talks about?
	makecontext(&ctx[1], (void*)&func, 1, &arg);
   return;
}

//yields CPU from the current thread to the next runnable thread
void ta_yield(void) {
	//if in thread, we need to switch out to the main
	if(thread){
		//need to save the context of the current thread
		swapcontext();
	}
	//if we are in main, need to release next thread in the ready queue to start working
	else{
		//before releasing next thread, need to save the context of the current thread
	}
    return;
}

int ta_waitall(void) {
    return -1;
}


/* ***************************** 
     stage 2 library functions
   ***************************** */

void ta_sem_init(tasem_t *sem, int value) {
}

void ta_sem_destroy(tasem_t *sem) {
}

void ta_sem_post(tasem_t *sem) {
}

void ta_sem_wait(tasem_t *sem) {
}

void ta_lock_init(talock_t *mutex) {
}

void ta_lock_destroy(talock_t *mutex) {
}

void ta_lock(talock_t *mutex) {
}

void ta_unlock(talock_t *mutex) {
}


/* ***************************** 
     stage 3 library functions
   ***************************** */

void ta_cond_init(tacond_t *cond) {
}

void ta_cond_destroy(tacond_t *cond) {
}

void ta_wait(talock_t *mutex, tacond_t *cond) {
}

void ta_signal(tacond_t *cond) {
}

