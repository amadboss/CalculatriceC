#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void calculator (int i, float *p_result, char **argv, int *p_tour, int arg, float *p_p1_tab)
{

                printf("argv a la posision i = %c alors que i vaut = %d\n", argv[i][0], i );
                switch(argv[i][0])
                {
                        case '+':
                                if(*p_tour == 1)
                                {
                                        *p_result += atof(argv[i-1]) + atof(argv[i+1]);
                                        *p_tour += 1;
                                }
                                else
                                {
                                        *p_p1_tab += atof(argv[i+1]);
                                }
                                break;
                        case '-':
                                *p_result += atof(argv[i-1]) - atof(argv[i+1]);
                                break;
                        case '/':
                                break;
                        case 'x':
                        case '*':
                                printf("i = %d arg = %d et *p_pi_tab = %f *p_tour = %d\n", i, arg, *p_p1_tab, *p_tour);
                                if(*p_tour == 1)
                                {
                                        puts("on a bien fait le calcule dans la premiere partie ");
                                        *p_p1_tab += atof(argv[i-1]) * atof(argv[i+1]);
                                        //*p_tour = 1;
                                }
                                else if (arg == 1 && *p_tour != 1)
                                {
                                        puts("la on rentre dans la deuxieme partie");
                                        *p_p1_tab *= atof(argv[i+1]);
                                }
                                *p_tour += 1;
                                break;
                        }
                /*      case '%':
                                reste = fmodf( result, atof(argv[i+2]));
                                result /= atof(argv[i+2]);
                                modulo_bool = 1;
                                break; */
        }


int main(int argc, char **argv )
{
        float result;//, reste;
        //float *p_result;
        int i, j;
        int u_i = 0;
        int compteur = 0;//, modulo_bool = 0;
        int tour = 1;
        //int arg_size = 0;
        int  arg[50] ;
        float p1_tab[50];
        //char *tri = arg;
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
        j += 2;
        printf("arg == %d", arg[i]);
        compteur++;
        }
        //compteur--;
        //arg_size = sizeof arg / sizeof arg[0];
        //printf("la taille de arg est de : %d ehhh", arg_size);
        //printf("%s\n", tri);
        if (argc == 1)
        {
                puts("probleme de parametre");
                return 1;
        }
        i = 0;
        j = 0;
        //result = atof(argv[1]);
        //while (arg[i] != 2) {
                //for (i = 0; i != compteur ;)
                //{
                do{
                for (j = 2; i != compteur ;){
                        //for (j = 2; j != 50; j+=2 )
                        //{
                        //printf("arg de i = %d\n", arg[i]);
                        //printf("arg de i = %d\n", arg[i]);
                        if (arg[i] == 1)
                        {
                                do//while (arg[i+1] == 1)
                                {
                                //if (arg[i] == 1)
                                //{
                                        printf("\nj = %d et i = %d\n", j,i);
                                        calculator(j, &result, argv, &tour, arg[i], &p1_tab[u_i]);
                                        //printf("arg a la posision j = %d`\n", arg[i]);
                                        //tour = 1;
                                        printf("resultat  = %f\n", p1_tab[u_i]);
                                        i++;
                                        //compteur--;
                                //}
                                        j+=2;
                                        tour = 2;
                                        printf("arg de i%d ICI vaut : %d\n",i, arg[i]);
                                }while(arg[i] == 1);
                        }
                        else if (arg[i] == 2)
                        {
                                tour = 1;
                                u_i++;
                                i++;
                                j+=2;
                        }
                puts("Sortie de la premiere boucle");
                //}
                }
                }while(arg[i] == 1 || arg[i] == 2);
                puts("on est sortie de la deuxieme boucle");
                //}
        //tour = 1;
/*tour = 1;
                        else if (arg[i] == 2)
                        {
                                if (arg[i+1] == 2)
                                {
                                        tour = 2;
                                        calculator(j, &result, argv, &tour, arg[i], &p1_tab[u_i]);

*/

        //      }

        /*
        for (i = 0; i < 20; i++)
        {
        if (arg[i] == 2)
        {
        //printf("%d", i);
        calculator(i, &result, argv, &tour, arg[i]);
        }
        }

        if (modulo_bool == 0)
        {
                printf("Le tab est : %f\n", p1_tab[2]);
        }
        else
        {
        //              printf("resultat = %f et reste de la division est = %f ", result, reste);
        }*/
                return 0;
}
