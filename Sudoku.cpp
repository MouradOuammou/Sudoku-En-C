

#include "stdafx.h"
#include "Sudoku.h"

int M[TAILLE][TAILLE];
int SM[TAILLE][TAILLE];
int SAVE[TAILLE][TAILLE];

int nb_case_vide = 45;

int _tmain(int argc, _TCHAR* argv[])
{
	InitJeux();

	Jouer();

	return 0;
}

void Jouer(void)
{
	int ligne,colonne,valeur;
	while(nb_case_vide > 0)
	{
		Afficher();

		Color(7);
		do
		{

			printf("\nEntrez vos donnees (ligne colonne valeur ) exemple 1 3 9 : ");
			scanf("%d %d %d", &ligne,&colonne,&valeur);

			if(ligne > 0 && ligne < 10 && colonne > 0  && colonne < 10 && valeur > 0 && valeur < 10)
			{
				ligne--;
				colonne--;

				if(SAVE[ligne][colonne] == 0)
				{
					if(VerifierCarreau(ligne,colonne,valeur) && VerifierColonne(colonne,valeur) && VerifierLigne(ligne,valeur))
					{
						M[ligne][colonne] = valeur;
						nb_case_vide--;
						break;
					}
					else
					{
						printf("\nValeur non valide!!");
					}
				}
				else
				{
					printf("\nCase d�j� rempli");
				}
			}
			else
			{
				printf("\nLigne ou Colonne non valide!!");
			}

		}
		while(1);
	}

	printf("Bien Jouer, vous avez Gagn�!!");
	system("pause");
}

void InitJeux(void)
{
	int i,j;

	for(i=0; i<TAILLE; i++ )
	{
		for( j=0; j<TAILLE; j++ )
		{
			M[i][j] = 0;
		}
	}

	Generate();
}

void Generate(void)
{
	int i,j,n;
	srand((unsigned int)time(NULL));
	for(i=0;i<TAILLE;i++)
	{
		while(1)
		{
			n = rand()%TAILLE + 1;
			if(VerifierLigne(0,n))
			{
				M[0][i] = n;
				break;
			}
		}
	}

	for(i=1;i<TAILLE;i++)
	{
		if(SetValue(1,0,i))
		{
			break;
		}
	}

	for(i=0;i<TAILLE;i++)
	{
		for(j=0;j<TAILLE;j++)
		{
			SM[i][j] = M[i][j];
		}
	}

	for(i=0;i<TAILLE;i = i+3)
	{
		for(j=0;j<TAILLE;j = j+3)
		{
			EffacerQlqValeurCarreau(i,j);
		}
	}

	for(i=0;i<TAILLE;i++)
	{
		for(j=0;j<TAILLE;j++)
		{
			SAVE[i][j] = M[i][j];
		}
	}
}

void EffacerQlqValeurCarreau(int ligne, int colonne)
{
	int i,j,n;

	n=0;

	while(n<6)
	{
		for(i=ligne;i<ligne+3;i++)
		{
			for(j=colonne;j<colonne+3;j++)
			{
				if(M[i][j] != 0)
				{
					if(rand()%2 == 0)
					{
						n++;
						M[i][j] = 0;
						if(n==5) return;
					}
				}
			}
		}
	}
}

bool SetValue(int ligne,int colonne,int value)
{
	int L=ligne,C=colonne,i;
	bool ret = false;
	if(VerifierLigne(ligne,value) && VerifierColonne(colonne,value) && VerifierCarreau(ligne,colonne,value))
	{
		M[ligne][colonne] = value;

		C=C+1;
		if(C == TAILLE)
		{
			C = 0;
			L = L+1;
			if(L == TAILLE) return true;
		}

		for(i=0;i<TAILLE;i++)
		{
			if(SetValue(L,C,i+1))
			{
				return true;
			}
		}
	}

	M[ligne][colonne] = 0;
	return false;
}

bool VerifierLigne(int ligne, int valeur)
{
	int i;
	for(i=0;i<TAILLE;i++)
	{
		if(M[ligne][i] == valeur)
		{
			return false;
		}
	}
	return true;
}

bool VerifierColonne(int colonne,int valeur)
{
	int i;
	for(i=0;i<TAILLE;i++)
	{
		if(M[i][colonne] == valeur)
		{
			return false;
		}
	}
	return true;
}

bool VerifierCarreau(int ligne,int colonne,int valeur)
{
	int i,j,L,C;

	L = (int)(ligne/3) * 3;
	C = (int)(colonne/3) * 3;

	for(i=L;i<L+3;i++)
	{
		for(j=C;j<C+3;j++)
		{
			if(M[i][j] == valeur)
			{
				return false;
			}
		}
	}

	return true;
}

void Afficher(void)
{
	int i,j,k;

	printf("\t   1   2   3   4   5   6   7   8   9");
	for(i=0;i<TAILLE;i++)
	{
		printf("\n\t ");
		if(i%3==0)
		{
			Color(12);
			for(k=0;k<37;k++)
			{
				printf("%c",219);
			}
		}
		else
		{
			Color(12);
			printf("%c",219);
			Color(14);
			for(k=1;k<37;k++)
			{
				if(k%12==0) Color(12);
				else Color(14);
				printf("%c",219);
			}
		}

		Color(12);
		printf("\n\t%d%c",i+1,219);

		for(j=0;j<TAILLE;j++)
		{
			if(M[i][j] == 0)
			{
				printf("   ");
			}
			else
			{
				Color(11);
				printf(" %d ",M[i][j]);
			}

			if(j%3<=1)
			{
				Color(14);
			}
			else
			{
				Color(12);
			}

			printf("%c",219);
		}
	}
	printf("\n\t ");
	for(k=0;k<37;k++)
	{
		printf("%c",219);
	}
	printf("\n");
}



void Color(int texteColor)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,texteColor);
}
