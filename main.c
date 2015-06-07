#include <stdio.h>
#include "falcompiler.h"

int main (int argc, char const *argv[])
{
	if(argc != 2)
	{
		printf("Syntax error!\n");
		return 0;
	}
	fin = fopen(argv[0], "r");
	fout = fopen(argv[1], "w");
	if(fin == NULL)
	{
		printf("Read input file error!\n");
		return 0;
	}
	if(fout == NULL)
	{
		printf("Create output file error!\n");
		return 0;
	}
	int succ;
	succ = FalCompile();
	if(succ == COMPILESUCCESS) printf("Compiling succeed\n");
	else if(succ == COMPILEFAIL) printf("Compiling failed!\n");
	else printf("Compiler Error!\n");
	return 0;
}