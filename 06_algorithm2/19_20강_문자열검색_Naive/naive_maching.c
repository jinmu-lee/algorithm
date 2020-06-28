#include<stdio.h>
#include<string.h>
#define MAX_LENGTH (10000)
int naiveMatching(char *originalStr, char *searchStr);
int main()
{
	char sentence[] = "ABACABABABACABABACABABACABABABACABABACABABACA";
	char word[] = "ABACABA";
	int count;
	count = naiveMatching(sentence, word);
	printf("%d번 검색완료!!!\n", count);
	return 0;
}
int naiveMatching(char *originalStr, char *searchStr)
{
	size_t i, j;
	size_t originalStrLen, searchStrLen;
	int matchFlag;
	int matchCnt=0;
	
	// TO DO
	int slen = strlen(searchStr);
	int olen = strlen(originalStr);
	for(int i=0;i<=olen-slen;i++){
		if( strncmp(originalStr+i,searchStr,slen) == 0 ){
			matchCnt++;
		}
	}
	return matchCnt;
}

