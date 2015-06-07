int MatchVar(int &st)
{
	int ed;
	for(; codeInput[st] == ' ' && st < len; st ++) ;
	for(ed = st + 1; codeInput[ed] != ',' && codeInput[ed] != '\0' && codeInput[ed] != '\n' && codeInput[ed] != ':' && ed < len; ed ++) ;
	return ed;
}
int MatchFOR(int type, int st)
{
	int cur, bg, ed, bgf, edf, arg, frLen;
	arg = argAmount[type];
	bg = st;
	ed = MatchVar(bg);
	bgf = ed + 1;
	edf = MatchVar(bgf);
	if(arg == 3)
	{
		bgs = edf + 1;
		eds = MatchVar(bgs);
	}
	else bgs = -1, eds = -1;
	if(bg == len || ed == len || bgf == len || edf == len || bgs == len || eds == len)
	{
		printf("(Error) Line %d: for format error!\n", linecnt);
		return COMPILEFAIL;
	}
	frLen = strlen(formstr[type]);
	for(cur = 0; cur < frLen; cur ++)
	{
		if(formstr[cur] == 0) Print(bg, ed);
		else if(formstr[cur] == 1) Print(bgf, edf);
		else if(formstr[cur] == 2) Print(bgs, eds);
		else fputc(formstr[cur], fout);
	}
	fputc('\n', fout);
	return COMPILESUCCESS;
}
int MatchRST(int type, int st)
{
	int cur, bg, ed, bgf, edf, arg, frLen;
	bg = st;
	ed = MatchVar(bg);
	if(arg == 2)
	{
		bgf = ed + 1;
		edf = MatchVar(bgf);
	}
	if(bg == len || ed == len || bgf == len || edf == len)
	{
		printf("(Error) Line %d: reset format error!\n", linecnt);
		return COMPILEFAIL;
	}
	frLen = strlen(formstr[type]);
	for(cur = 0; cur < frLen; cur ++)
	{
		if(formstr[cur] == 0) Print(bg, ed);
		else if(formstr[cur] == 1) Print(bgf, edf);
		else fputc(formstr[cur], fout);
	}
	fputc('\n', fout);
	return COMPILESUCCESS;
}
int Match(int type, int st)
{
	switch(oprTy[type])
	{
		case FORTYPE: return MatchFOR(type, st);
		case IFTYPE: return MatchIF(st);
		case IOTYPE: return MatchIO(type, st);
		case RESETTYPE: return MatchRST(type, st);
		case OPENTYPE: return MatchOPEN(st);
	}
}