inline void Print(int bg, int ed)
{
	int cur;
	for(cur = bg; cur < ed; cur ++) fputc(codeInput[cur], fout);
}