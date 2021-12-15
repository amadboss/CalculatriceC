#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

float add_1 (float *pp_p1_tab, int i)
{
	
	return pp_p1_tab[i] + pp_p1_tab[i+1];
}

float add_2 (float *pp_p1_tab, int i, int j, char **argv)

{
	return pp_p1_tab[i] + atof(argv[j+1]);
}

float sous_1 (float *pp_p1_tab, int i)
{
	return pp_p1_tab[i] - pp_p1_tab[i+1];
}

float sous_2(float *pp_p1_tab, int i, int j, char **argv)
{
	return pp_p1_tab[i] - atof(argv[j+1]);
}

void calculator (int i, char **argv, int *p_tour, int arg, float *p_p1_tab, char *p_p2_tab)
{	

		switch(argv[i][0])
		{
			case '/':	
				
				if(*p_tour == 1)
				{
					*p_p1_tab += atof(argv[i-1]) / atof(argv[i+1]);
				}
				else if (arg == 1 && *p_tour != 1)
				{
					*p_p1_tab /= atof(argv[i+1]);
				}
				*p_tour += 1;
				break;
			
			case 'x':
			case '*':
				
				if(*p_tour == 1)
				{
					if(p_p2_tab[0] == '+')
					{
						*p_p1_tab += p_p1_tab[0] + atof(argv[i-1]) * atof(argv[i+1]);
					}
					else if (p_p2_tab[0] == '-')
					{
						*p_p1_tab += p_p1_tab[0] - atof(argv[i-1]) * atof(argv[i+1]);
					}
					else
					{
						*p_p1_tab += atof(argv[i-1]) * atof(argv[i+1]);
					}
				}
				else if (arg == 1 && *p_tour != 1)
				{
					*p_p1_tab *= atof(argv[i+1]);
				}
				
				*p_tour += 1;
				break;
		}

}


int main(int argc, char **argv )
{
	char p2_tab[50] = {0};
	int i, j, t, valide = 0;
	int u_i = 0;
	int compteur = 0;//, modulo_bool = 0; 
	int tour = 1;
	int  arg[50] ;
	float p1_tab[50];
	

	j = 2;
	for (i = 0; j <= argc - 1 ; i++)
	{
	
		switch(argv[j][0])
		{
			case '+':
			case '-':
				arg[i] = 2;
			break;
			case '*':
			case 'x':
			case '/':
				arg[i] = 1;
			break;
		}
	
	j+=2;

	compteur++;
	}
	
	if (argc == 1)
	{
		puts("probleme de parametre");
		return 1;
	}
	
	i = 0;
	j = 0;
	
	if(argv[2][0] == '+' || argv[2][0] == '-')
	{
		p1_tab[0] = atof(argv[1]);
	}
	
	for (j = 2; valide ; j+=2)
	{
		for(i = 0; valide ; i++ )
		{
			if (arg[i] == 1)
			{
				valide = 1;
			}
			else if (argv[j][0] == '+' && arg[i+1] != 1)
			{
				//puts("entrée dans le premier else if");
				p1_tab[0] += atof(argv[j+1]);
			}
			else if (argv[j][0] == '-' && arg[i+1] != 1)
			{
				//puts("entrée dans le deuxieme else if");
				p1_tab[0] -= atof(argv[j+1]); 
			}
			else if (arg[i+1] == 1)
			{
				//puts("entrée dans le troixieme else if");
				valide = 1;
				p2_tab[0] = argv[j+2][0];
			}
		}
	}	
	i=0;
	j=0;
		
		do{
			for (j = 2; i != compteur ;)
			{	

				if (arg[i] == 1)
				{
					do//while (arg[i+1] == 1)
					{
						calculator(j, argv, &tour, arg[i], &p1_tab[u_i], p2_tab);
						i++;
						j+=2;
						tour = 2;
					}while(arg[i] == 1);
				
				}	
			
			else if (arg[i] == 2)
			{
				//printf("p2 vaut %s\n", p2_tab);		
				tour = 1;
				u_i++;
				i++;
				j+=2;
			}
		
			}
		}while(arg[i] == 1 || arg[i] == 2);
		
		tour = 1;
		i = 0;
		t = 0;
			
		for(j = 2 ; t != compteur ; j+=2)
		{
			//printf("j = %d\n", j);
				
			if (argv[j][0] == '+' && arg[t+1] == 1 )
			{	
				p1_tab[i+1] = add_1( p1_tab, i);
				//i++;
			}
				
			else if ( argv[j][0] == '+' && arg[t+1] != 1)
			{
				p1_tab[i+1] = add_2(p1_tab, i, j, argv);
			}
			else if (argv[j][0] == '-' && arg[t+1] == 1)
			{	
				p1_tab[i+1] = sous_1(p1_tab, i);
			}
			else if	(argv[j][0] == '-' && arg[t+1] != 1)
			{
				p1_tab[i+1] = sous_2(p1_tab, i, j, argv);
			}
			if (arg[t] == 2)
			{
				i++;
			}
				t++;	
			}
	
		printf("résultat = %f\n", p1_tab[i]);
		return 0;
}
