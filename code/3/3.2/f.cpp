#include <stdio.h>
#include "f.h"

int i = 1;
void f()
{
	printf("in f: %d\n", i);
	printf("in f: &i = %ld\n", (long)&i);
}