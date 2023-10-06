#include <cstring>

void removeConsecutiveDuplicates(char *input) {
	int n = strlen(input);
	if(n < 2) return;

	if(input[0]==input[1])
	{
		for(int i=1;i<=n;++i) input[i-1] = input[i];  // copying with the incl
		removeConsecutiveDuplicates(input);
	}else{
		removeConsecutiveDuplicates(input+1);
	}
}
