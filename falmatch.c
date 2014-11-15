int MatchVar(int &st)
{
	int ed;
	for(; codeInput[st] == ' ' && st < len; st ++) ;
	for(ed = st + 1; codeInput[ed] != ',' && codeInput[ed] != '\0' && codeInput[ed] != '\n' && codeInput[ed] != ':' && ed < len; ed ++) ;
	return ed;
}
int MatchFOR(int type, int st)
{
	int cur, bg, ed, bgf, edf;
	bg = st;
	ed = MatchVar(bg);
	bgf = ed + 1;
	edf = MatchVar(bgf);
	if(argAmount[type] == 3)
	{
		bgs = edf + 1;
		eds = MatchVar(bgs);
	}
	else bgs = -1, eds = -1;
	if(bg == len || ed == len || bgf == len || edf == len || bgs == len || eds == len)
		printf("(Error) Line %d: for format error!\n", linecnt);
	fprintf(fout, "for(int "), Print(bg, ed), 
		fputc(';', fout), Print(bg, ed), fprintf(fout, "<=" );
	for()
}
int Match(int type, int st)
{
	switch(type)
	{
		case FORTYPE: return MatchFOR(type, st);
		case IFTYPE: return MatchIF(st);
		case IOTYPE: return MatchIO(type, st);
		case RESETTYPE: return MatchRST(type, st);
		case OPENTYPE: return MatchOPEN(st);
	}
}