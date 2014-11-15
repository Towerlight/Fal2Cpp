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
	if(FalCompile()) printf("Compiling succeed\n");
	else printf("Compiling failed!\n");
	return 0;
}