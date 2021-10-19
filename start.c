#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

float add_1 (float *pp_p1_tab, int i)
{
	//printf("ici dans la fonction nous avont i = %d et p1_tab[nominal] = %f p1_tab[i] = %f, p1_tab[i-1] = %f\n", i , *pp_p1_tab, pp_p1_tab[i], pp_p1_tab[i+1]);
	//printf("resultat = %f\n", pp_p1_tab[0]);
        //printf("resultat = %f\n",pp_p1_tab[1]);
        //printf("resultat = %f\n", pp_p1_tab[2]);
        //printf("resultat = %f\n", pp_p1_tab[3]);
        //printf("resultat = %f\n", pp_p1_tab[4]);
        //printf("resultat = %f\n", pp_p1_tab[5]);
	return pp_p1_tab[i] + pp_p1_tab[i+1];
}

float add_2 (float *pp_p1_tab, int i, int j, char **argv)

{
	//printf("ICI pp_p1_tab[i] = %f + atofargv[j+2] = %f et j = %d et i = %d", pp_p1_tab[i], atof(argv[j+1]), j, i);
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

		//printf("argv a la posision i = %c alors que i vaut = %d\n", argv[i][0], i );
		switch(argv[i][0])
		{
			case '/':	
				
				//printf("i = %d arg = %d et *p_pi_tab = %f *p_tour = %d\n", i, arg, *p_p1_tab, *p_tour);
				if(*p_tour == 1)
				{
					//puts("on a bien fait le calcule dans la premiere partie ");
					*p_p1_tab += atof(argv[i-1]) / atof(argv[i+1]);
				}
				else if (arg == 1 && *p_tour != 1)
				{
					//puts("la on rentre dans la deuxieme partie");
					*p_p1_tab /= atof(argv[i+1]);
				}
				*p_tour += 1;
				break;
			
			case 'x':
			case '*':
				
				//printf("i = %d arg = %d et *p_pi_tab = %f *p_tour = %d\n", i, arg, *p_p1_tab, *p_tour);
				if(*p_tour == 1)
				{
					//puts("on a bien fait le calcule dans la premiere partie ");
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
					//puts("la on rentre dans la deuxieme partie");
					*p_p1_tab *= atof(argv[i+1]);
				}
				
				*p_tour += 1;
				break;
		}
		/*	case '%':
				reste = fmodf( result, atof(argv[i+2]));
				result /= atof(argv[i+2]);
				modulo_bool = 1;
				break; */
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
	//printf("arg == %d\n", arg[i]);
	compteur++;
	}
	

	//printf("la taille de arg est de : %d ehhh", arg_size);
	//printf("%s\n", tri);
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
	//printf("P1_tab de 0 vaut = %f et p2_tab de 0 = %c\n", p1_tab[0], p2_tab[0]);
	
	i=0;
	j=0;
		
		do{
			for (j = 2; i != compteur ;)
			{	
				//printf("arg de i = %d\n", arg[i]);
				if (arg[i] == 1)
				{
					do//while (arg[i+1] == 1)
					{
						//printf("\nj = %d et i = %d\n", j,i);
						calculator(j, argv, &tour, arg[i], &p1_tab[u_i], p2_tab);
						//printf("tableau posision %d et le resultat est  = %f\n", u_i, p1_tab[u_i]);
						i++;
						j+=2;
						tour = 2;
						//printf("arg de i%d ICI vaut : %d\n",i, arg[i]);
					}while(arg[i] == 1);
				//printf("argv j - 2 = %d\n", arg[i]);
				
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
			
			//printf("t = %d\n", t);
		for(j = 2 ; t != compteur ; j+=2)
		{
			//printf("j = %d\n", j);
				
			if (argv[j][0] == '+' && arg[t+1] == 1 )
			{	
				//puts("ON EST RENTRée\n");
				//printf("i = %d et le tableau p1_tab %f= argv = %c\n", i, p1_tab[i], argv[j][0]);
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
