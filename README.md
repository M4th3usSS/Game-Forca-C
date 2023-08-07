# Projeto de introdu��o a C

Esse � o meu segundo projeto de introdu��o a linguagem C. Apesar de simples, aqui explorei mais recursos da linguagem, como la�os encadeados, ponteiros, fun��es e 
manipul��o de arquivos. Eu n�o priorizei o uso de vari�veis globais, usei ponteiros e passagem por c�pia para desenvolver mais habilidades;


## T�picos das anota��es.:

- Fun��o sprintf();
- Fun��o strlen();
- Fun��o scanf() e Buffer de mem�ria;
- Varredura de um array;
- Loops encadeados;
- Criar Fun��es;
- Par�metros;
- Passagem de par�metros por c�pia;
- Passagem de par�metros por ponteiro;
- Vari�veis globais;
- Retorno de Fun��es;
- Header files;
- Leitura e escrita em um arquivo;
- Fun��es fopen(), fclose(), fscanf() , fprintf() , fseek();
- if tern�rio;


## OBS.:

Os la�os encadeados assim como a estrutura��o de c�digos pode gerar d�vidas, a crit�rio de conhecimento � uma boa pr�tica debuggar o c�digo para entender melhor o que eles est�o fazendo;
No trabalho com arrays, tenha cuidado com os dados e sua tipagem;

## FUN��O sprintf(char[],string)

A fun��o sprintf recebe no primeiro par�metro um array de char, no segundo par�metro voc� deve entrar com a string que deseja armazenar nesse array;
Essa fun��o ir� percorrer toda a string que voc� colocou no segundo argumento, armazenando cada char da string em sua respectiva posi��o no array de char;
Se a string � menor que o tamanho do vetor de char, ser� atribuido um '\0' no char sucessor ao �ltimo, isso garante que ela ir� armazenar no array somente os char necess�rios;
Para imprimir o array de char voc� deve usar o %s, passando como argumento o array de char que deseja imprimir.

Exemplo: 

```C
char palavra_secreta[10];
sprintf(palavra_secreta,"MELANCIA");
printf("%s",palavra_secreta);

/*Temos o seguinte array: char palavra_secreta[10], nele ser� armazenado a palavra "MELANCIA", os valores de cada posic�o desse array ser�o:

palavra_secreta[0] = 'M'
palavra_secreta[1] = 'E'
palavra_secreta[2] = 'L'
palavra_secreta[3] = 'A'
palavra_secreta[4] = 'M'
palavra_secreta[5] = 'C'
palavra_secreta[6] = 'I'
palavra_secreta[7] = 'A'
palavra_secreta[8] = '\0'
palavra_secreta[9 ... 19] // = LIXO DE MEM�RIA ou VALOR DE INICIALIZA��O
*/

```

Para mais informa��es sobre a fun��o sprintf() consulte a [documenta��o do C](https://learn.microsoft.com/pt-br/cpp/c-language/?view=msvc-170).

## FUN��O strlen(char[])**

A fun��o strlen(char[]) recebe como par�metro um array de char e retorna seu tamanho.

Exemplo:

```C
char palavra_secreta[50];
sprintf(palavra_secreta,"MELANCIA");
int tamanho_palavra_secreta = strlen(palavra_secreta);
printf("%d", tamanho_palavra_secreta);

// Resultado:
//8
```

OBS.: Lembre-se que os �ndices de um array sempre come�am em 0, ent�o para um array exemplo[N], seus �ndices s�o:

```C
exemplo[0]
exemplo[1]
exemplo[2]
exemplo[3]
...
exemplo[N-1]
```
Para mais informa��es sobre a fun��o strlen() consulte a [documenta��o do C](https://learn.microsoft.com/pt-br/cpp/c-language/?view=msvc-170).


## Criar fun��es

    - Passagens por c�pia.
    - Passagem por endere�o de mem�ria - Ponteiros.

    Uma outra alternativa para esse c�digo seria usar vari�veis globais, por�m, a crit�rio de conhecimento e consulta vou deixar da forma que est�.

## Fun��o fopen, fclose,fscanf

    Essas s�o fun��es de manipula��o de arquivos.

    fopen - Abre um arquivo do diret�rio atual.
    fclose - Fecha o arquivo.
    fscanf - Faz a leitura sequencial do arquivo(linha a linha).
