#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_PALAVRA 20
#define ALFABETO_ESTENDIDO 26

void asciiArt01();
void asciiArt02(char palavra_secreta[]);
void chuta(char aux_chutes[], int* chutes_dados);
int jaChutou(char letra, char chutes[], int chutes_dados);
void desenhaForca(char palavra_secreta[], char chutes[],int chutes_dados);
void escolhePalavra(char palavra_secreta[]);
int enforcou(int* chutes_dados,char chutes[],char palavra_secreta[]);
int acertou(char palavra_secreta[], char chutes[],int chutes_dados);
void adicionaPalavra();
void exibir_artes(int acertou, char palavra_secreta[]);
int chuteErros(int* chutes_dados,char chutes[],char palavra_secreta[]);
char repetirJogo(char repetir);