#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv )
{
	int result, i;
	if (argc == 1)
	{
		puts("probleme de parametre");
		return 1;
	}
 	
	result = atoi(argv[1]);
	
	for (i = 1; i < argc - 1 ; i+=2)
	{	
	
		switch(argv[i+1][0])
		{
			case '+':
				result += atoi(argv[i+2]);
				break;
			case '-':
				result -= atoi(argv[i+2]);
				break;
			case '/':	
				result /= atoi(argv[i+2]);
				break;
			case 'x':
				result *= atoi(argv[i+2]);
				break;
			case '%':
				result %= atoi(argv[i+2]);
				break;
		}
	}
	printf("Le resultat est : %d\n", result);
	return 0;
}

