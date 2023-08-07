#include "../include/main.h"

// ========= Codificação =========
// Use a codificação ISO 8859-15
// Adicione a biblioteca locale.h
// Adicione na main :
// setlocale(LC_ALL,"portuguese");
// ===============================

// ======== Buscar ===============
// @scan-array
// @ponteiro
// @if-ternário
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
            // @ponteiro | Aqui usamos o & para passar o endereço de memória das variáveis delcaradas na main, com isso, o que acontecer com seus valores na função capturaChute também irá alterar na main, pois agora estamos lidando com o endereço de mémoria da variável, e não criando uma nova variável como acontece na passagem por cópia.

        } while (!acertou(palavra_secreta, chutes, chutes_dados) && !enforcou(&chutes_dados, chutes, palavra_secreta));
        exibir_artes(acertou(palavra_secreta, chutes, chutes_dados), palavra_secreta);
        adicionaPalavra();
        repetir = repetirJogo(repetir);

    } while (repetir == 'S');

    return 0;
}

void chuta(char aux_chutes[], int *chutes_dados)
{ // @ponteiro | Usamos o * para dizer que essa variável receberá um endereço de memória, ou seja, o ponteiro dos parâmetros inseridos na main
    char chute;
    scanf(" %c", &chute);
    aux_chutes[(*chutes_dados)] = chute;
    (*chutes_dados)++;
    // @ponteiro Usamos (*chutes_dados) para pegar o valor contido no endereço de memória da variável chutes_dados, que por sua vez é o mesmo da variável chutes_dados presente na main; se não usarmos dessa forma ele irá retornar o próprio endereço de memória da variável chutes_dados;
}

int jaChutou(char letra, char chutes[], int chutes_dados)
{

    int achou = 0;

    for (int j = 0; j < chutes_dados; j++) // @scan-array | Percorre o array de char chutes[ALFABETO_ESTENDIDO] para avaliar se algum char chutado é igual ao char na posição palavra_secreta[i];
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
    (erros >= 1 ? '(' : ' '),  // @if-ternário
    (erros >= 1 ? '_' : ' '),  // @if-ternário
    (erros >= 1 ? ')' : ' ')); // @if-ternário

    printf(" |      %c%c%c   \n", 
    (erros >= 3 ? '\\' : ' '), // @if-ternário
    (erros >= 2 ? '|' : ' '),  // @if-ternário
    (erros >= 3 ? '/' : ' ')); // @if-ternário

    printf(" |       %c     \n", 
    (erros >= 2 ? '|' : ' ')); // @if-ternário

    printf(" |      %c %c   \n", 
    (erros >= 4 ? '/' : ' '),   // @if-ternário
    (erros >= 4 ? '\\' : ' ')); // @if-ternário

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

    f = fopen("palavras.txt", "r"); // @read-arquivo | O primeiro argumento é o nome do arquivo, o segundo "r" define que será somente leitura.
    
    if (f == 0) // Se o arquivo não existir, informa uma mensagem de erro e fecha o programa.
    {
        printf("Desculpe, banco de dados não disponivel\n\n");
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

    printf("Você deseje adicionar uma nova palavra no jogo? (S/N)");
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
            printf("Desculpe, banco de dados não disponivel\n\n");
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
