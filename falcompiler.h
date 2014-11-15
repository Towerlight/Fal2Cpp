#include "falcompile.c"
#include "falmatch.c"

const int codeLength = 1000;
const int keywordAmount = 11;
char codeInput[codeLength];
// Unfinished Part
char keyword[200][20] = 
{
	"print",
	"scan", 
	"fopen", 
	"int", 
	"char", 
	"double",
	"short",  
	"LL",
	"LB",
	"REP", 
	"REP_0", 
	"REP_G", 
	"REP_0N", 
	"FOR", 
	"DWN", 
	"RST", 
	"CLR", 
	"return"
};
int keyLen[] = 
{
	5, 
	4, 
	5, 
	3, 
	5, 
	5, 
	6, 
	3, 
	3, 
	3, 
	3
};
int argAmount[] = 
{
	-1, 
	-1, 
	1, 
	2, 
	2, 
	2, 
	2, 
	3, 
	3, 
	1, 
	2
};
FILE *fin, *fout;
int len, linecnt;
int FalCompile ();
int Match(int type, int st);