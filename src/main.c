#include "../include/main.h"

// ========= Codifica��o =========
// Use a codifica��o ISO 8859-15
// Adicione a biblioteca locale.h
// Adicione na main :
// setlocale(LC_ALL,"portuguese");
// ===============================

// ======== Buscar ===============
// @scan-array
// @ponteiro
// @if-tern�rio
// @read-arquivo
// @write-arquivo
// ===============================

int main()
{

    char palavra_secreta[TAMANHO_PALAVRA];
    char chutes[ALFABETO_ESTENDIDO];
    char repetir;
    int chutes_dados;
    

    do
    {

        repetir = 'S';
        chutes_dados = 0;

        setlocale(LC_ALL, "portuguese");
        asciiArt01();
        escolhePalavra(palavra_secreta);

        do
        {
            desenhaForca(palavra_secreta, chutes, chutes_dados);
            chuta(chutes, &chutes_dados); 
            // @ponteiro | Aqui usamos o & para passar o endere�o de mem�ria das vari�veis delcaradas na main, com isso, o que acontecer com seus valores na fun��o capturaChute tamb�m ir� alterar na main, pois agora estamos lidando com o endere�o de m�moria da vari�vel, e n�o criando uma nova vari�vel como acontece na passagem por c�pia.

        } while (!acertou(palavra_secreta, chutes, chutes_dados) && !enforcou(&chutes_dados, chutes, palavra_secreta));
        exibir_artes(acertou(palavra_secreta, chutes, chutes_dados), palavra_secreta);
        adicionaPalavra();
        repetir = repetirJogo(repetir);

    } while (repetir == 'S');

    return 0;
}

void chuta(char aux_chutes[], int *chutes_dados)
{ // @ponteiro | Usamos o * para dizer que essa vari�vel receber� um endere�o de mem�ria, ou seja, o ponteiro dos par�metros inseridos na main
    char chute;
    scanf(" %c", &chute);
    aux_chutes[(*chutes_dados)] = chute;
    (*chutes_dados)++;
    // @ponteiro Usamos (*chutes_dados) para pegar o valor contido no endere�o de mem�ria da vari�vel chutes_dados, que por sua vez � o mesmo da vari�vel chutes_dados presente na main; se n�o usarmos dessa forma ele ir� retornar o pr�prio endere�o de mem�ria da vari�vel chutes_dados;
}

int jaChutou(char letra, char chutes[], int chutes_dados)
{

    int achou = 0;

    for (int j = 0; j < chutes_dados; j++) // @scan-array | Percorre o array de char chutes[ALFABETO_ESTENDIDO] para avaliar se algum char chutado � igual ao char na posi��o palavra_secreta[i];
    { 
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca(char palavra_secreta[], char chutes[], int chutes_dados)
{

    int erros = chuteErros(&chutes_dados, chutes, palavra_secreta);

    printf("  _______      \n");

    printf(" |/      |     \n");

    printf(" |      %c%c%c    \n", 
    (erros >= 1 ? '(' : ' '),  // @if-tern�rio
    (erros >= 1 ? '_' : ' '),  // @if-tern�rio
    (erros >= 1 ? ')' : ' ')); // @if-tern�rio

    printf(" |      %c%c%c   \n", 
    (erros >= 3 ? '\\' : ' '), // @if-tern�rio
    (erros >= 2 ? '|' : ' '),  // @if-tern�rio
    (erros >= 3 ? '/' : ' ')); // @if-tern�rio

    printf(" |       %c     \n", 
    (erros >= 2 ? '|' : ' ')); // @if-tern�rio

    printf(" |      %c %c   \n", 
    (erros >= 4 ? '/' : ' '),   // @if-tern�rio
    (erros >= 4 ? '\\' : ' ')); // @if-tern�rio

    printf(" |             \n");

    printf("_|___          \n");

    printf("\n\n");

    for (int i = 0; i < strlen(palavra_secreta); i++) // @scan-array | Percorre o array de char: palavra_secreta[];
    { 

        int achou = jaChutou(palavra_secreta[i], chutes, chutes_dados);

        if (achou)
        {
            printf("%c ", palavra_secreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhePalavra(char palavra_secreta[])
{
    FILE *f;

    f = fopen("palavras.txt", "r"); // @read-arquivo | O primeiro argumento � o nome do arquivo, o segundo "r" define que ser� somente leitura.
    
    if (f == 0) // Se o arquivo n�o existir, informa uma mensagem de erro e fecha o programa.
    {
        printf("Desculpe, banco de dados n�o disponivel\n\n");
        exit(1);
    }

    int qtd_palavras;
    fscanf(f, "%d", &qtd_palavras);

    srand(time(0));
    int randominco = rand() % qtd_palavras;

    for (int i = 0; i <= randominco; i++)
    {
        fscanf(f, "%s", palavra_secreta);
    }

    fclose(f);
}

int enforcou(int *chutes_dados, char chutes[], char palavra_secreta[])
{

    return chuteErros(chutes_dados, chutes, palavra_secreta) >= 5;
}

int acertou(char palavra_secreta[], char chutes[], int chutes_dados)
{
    for (int i = 0; i < strlen(palavra_secreta); i++)
    {
        if (!jaChutou(palavra_secreta[i], chutes, chutes_dados))
        {
            return 0;
        }
    }
    return 1;
}

void adicionaPalavra()
{

    char quer;

    printf("Voc� deseje adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char nova_palavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", &nova_palavra);

        FILE *f;

        f = fopen("palavras.txt", "r+"); // @write-arquivo r+ ===> LEITURA E ESCRTIA NO ARQUIVO
        if (f == 0)
        {
            printf("Desculpe, banco de dados n�o disponivel\n\n");
            exit(1);
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", nova_palavra);

        fclose(f);
    }
}

int chuteErros(int *chutes_dados, char chutes[], char palavra_secreta[])
{

    int erros = 0;

    for (int i = 0; i < (*chutes_dados); i++)
    {
        int existe = 0;

        for (int j = 0; j < strlen(palavra_secreta); j++)
        {
            if (chutes[i] == palavra_secreta[j])
            {

                existe = 1;
                break;
            }
        }
        if (!existe)
            erros++;
    }

    return erros;
}

char repetirJogo(char repetir)
{

    printf("\n\nAutor: Matheus Sousa\n");
    printf("=======================================\n");
    printf("Deseja jogar novamente? (S/N)");
    scanf(" %c", &repetir);

    switch (repetir)
    {
    case 'S':
        system("cls");
        return 'S';
    case 'N':
        return 'N';
        break;
    }
}
