#include"stdio.h"
#include"string.h"


void reverse(char *lhs, char *rhs) {
	char temp;
	while (lhs < rhs) {
		temp = *lhs;
		*lhs++ = *rhs;
		*rhs-- = temp;
	}
}


void reverseWords(char *str)
{
	char *previousPtr = str;
	char *temp = str;

	while(*temp) {
		temp++;
		if (*temp == '\0') {
			reverse(previousPtr, temp-1);	
		} else if (*temp == ' ') {
			reverse(previousPtr, temp - 1);
			while(*(++temp) == ' ');
			previousPtr = temp; 
		}
	}
	reverse(str,str+strlen(str) - 1);
}

int main(void)
{
	char testStr[]="I love this world ";
	reverseWords(testStr);
	printf("after the reverse the str is  \n %s\n", testStr);
}
