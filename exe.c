#include <stdio.h>
#include <string.h>


#pragma warning (disable: 4996)

char* reverseStr(char*);
/*5.  A string(example "I am writing an email") is entered through the keyboard, write a program in C to get its reverse in a column as output i.e.:
email
an
writing
am
i*/
int main()
{
	char str[100];
	printf("Please enter a string: ");
	gets(str);
	printf("%s", reverseStr(str));
	return 0;
}

char* reverseStr(char* str)
{
	char* temp;
	char newStr[100];
	int lenStr = strlen(str);
	int lenTemp;
	temp = strtok(str, " ");
	lenTemp = strlen(temp);
	newStr[lenStr] = 0;
	do
	{
		for (int i = 0; i < lenTemp; i++)
		{
			newStr[lenStr - lenTemp + i] = *temp;
			temp++;
		}
		lenStr -= lenTemp + 1;
		temp = strtok(NULL, " ");

		if (lenStr > 0) {
			newStr[lenStr] = 32; //ascii for space
		}

		lenTemp = temp == NULL ? 0 : strlen(temp);

	} while (temp);
	return newStr;
}