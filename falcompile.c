int FalCompile()
{
	int lsttab;
	lsttab = 0;
	linecnt = 0;
	while(fgets(codeInput, 10000000, fin) != EOF)
	{
		int matching, tabcnt;
		int cur, key, tmp;
		matching = 0;
		tabcnt = 0;
		len = strlen(codeInput);
		for(cur = 0; cur < len && codeInput[cur] == 9; cur ++, tabcnt ++) ;
		for(tmp = 0; tmp < lsttab - tabcnt; tmp ++) fputs("}\n", fout);
		lsttab = tabcnt;
		for(cur ++; cur <= len; cur ++)
		{
			for(key = 0; key < keywordAmount; key ++)
			{
				if(cur < keyLen[key]) continue;
				if(StrEql(keyword[key], codeInput + cur - keyLen[key], keyLen[key]) && codeInput[cur] == ' ')
				{
					if(matching)
					{
						printf("(Error) Line %d: Keyword overlapped!\n", linecnt);
						return 0;
					}
					matching = key;
					break;
				}
			}
			if(matching)
			{
				if (!Match(matching, cur)) return 0;
				break;
			}
		}
		if(!matching)
		{
			codeInput[len] = ';';
			fputs(codeInput, fout);
		}
	}
	return 1;
}