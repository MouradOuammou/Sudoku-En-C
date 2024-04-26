#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 

#define TAILLE 9


void InitJeux(void);

void Afficher(void);

bool VerifierLigne(int,int);

bool VerifierColonne(int,int);

bool VerifierCarreau(int,int,int);

bool SetValue(int,int,int);

void Generate(void);

void Color(int);

void EffacerQlqValeurCarreau(int,int);

void Jouer(void);