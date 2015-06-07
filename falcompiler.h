#include "falcompile.c"
#include "falmatch.c"

const int COMPILESUCCESS = 1, COMPILEFAIL = 0;
const int codeLength = 1000;
const int keywordAmount = 11;
char codeInput[codeLength];
// Unfinished Part
char keyword[200][20] = 
{
	"print",
	"scan", 
	"fopen", 
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
	// To be completed
};
int argAmount[] = 
{
	// To be completed
};
FILE *fin, *fout;
int len, linecnt;
int FalCompile ();
int Match(int type, int st);