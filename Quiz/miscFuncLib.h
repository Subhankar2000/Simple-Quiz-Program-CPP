

// Custom string function to find first position of given character c in string str
// c - the character that is to be searched in the string
// str - The input string which is to be searched
int indexOf(char c, char *str)
{
    int i = 0;
    while(*(str+i) != '\0')
    {
        if(*(str+i) == c)
           return i;
        i++;
    }
    return -1;
}

// Custom string function to find the character at position p in string str
// p - Position at which the character has to be shown
// str - The input string that is to be searched
char charAt(int p, char *str)
{
    int i = 0;
    while(*(str+i) != '\0')
    {
        if(p == i)
           return *(str+i);
        i++;
    }
    return '\0';
}

// Custom string function to extract a part of string
// dest - Destination string variable 
// source - Source string variable 
// sp - Start position
// ep - End position
void stringExtract(char *dest, char *source, int sp, int ep)
{
    int s=0,i;
    for(i=sp ; i<=ep; i++)
    {
        *(dest+s) = *(source+i);
        s++;
    }
    *(dest+s) = '\0';
}

// Get password with masking effect - The input characters are maked with the specified character
// mask - The character that should mask the input
std::string getPassword(const char mask = '\0')
{
	std::string password;

	char input = getch();
	while (input != '\r')
	{
		std::cout << mask;
		password += input;
		input = getch();
	}

	std::cout << std::endl;

	return password;
}

// Add specific numbers of spaces at the end of a string
// st - String to pack with space
// l  - Number of spaces to add
char * packSpace(char * st, int l)
{
	int i;
	int len = strlen(st);
	for(i = len; i < l; i++)
	{
		*(st + i) = ' ';
	}
	*(st+i) = '\0';
	
	return st;
}



