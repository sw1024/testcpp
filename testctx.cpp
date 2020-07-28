/**
 * @file	testctx.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-07-19
 */

#include <stdlib.h>
#include <ucontext.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define	 CO_DEFAULT_STACK_SIZE 2*1024*1024

void task()
{
	printf("hello world\n");
}

int main()
{
	int i;
	char* co_stack;
	ucontext_t ctx;
	ucontext_t ctx_main;

	co_stack = (char*) malloc(CO_DEFAULT_STACK_SIZE);
	if (co_stack == nullptr)
		return -1;

	memset(co_stack, 0, CO_DEFAULT_STACK_SIZE);

	getcontext(&ctx);
	ctx.uc_stack.ss_sp = co_stack;
	ctx.uc_stack.ss_size = CO_DEFAULT_STACK_SIZE;
	ctx.uc_link = &ctx_main;
	makecontext(&ctx, &task, 0);

	for (i = 0; i < 10; i++) {
		swapcontext(&ctx_main, &ctx);
		std::cout<<"start change"<<std::endl;
		makecontext(&ctx, &task, 0);
	}

	free(co_stack);

	return 0;
}



