# Projeto de introdução a C

Esse é o meu segundo projeto de introdução a linguagem C. Apesar de simples, aqui explorei mais recursos da linguagem, como laços encadeados, ponteiros, funções e 
manipulção de arquivos. Eu não priorizei o uso de variáveis globais, usei ponteiros e passagem por cópia para desenvolver mais habilidades;


## Tópicos das anotações.:

- Função sprintf();
- Função strlen();
- Função scanf() e Buffer de memória;
- Varredura de um array;
- Loops encadeados;
- Criar Funções;
- Parâmetros;
- Passagem de parâmetros por cópia;
- Passagem de parâmetros por ponteiro;
- Variáveis globais;
- Retorno de Funções;
- Header files;
- Leitura e escrita em um arquivo;
- Funções fopen(), fclose(), fscanf() , fprintf() , fseek();
- if ternário;


## OBS.:

Os laços encadeados assim como a estruturação de códigos pode gerar dúvidas, a critério de conhecimento é uma boa prática debuggar o código para entender melhor o que eles estão fazendo;
No trabalho com arrays, tenha cuidado com os dados e sua tipagem;

## FUNÇÃO sprintf(char[],string)

A função sprintf recebe no primeiro parâmetro um array de char, no segundo parâmetro você deve entrar com a string que deseja armazenar nesse array;
Essa função irá percorrer toda a string que você colocou no segundo argumento, armazenando cada char da string em sua respectiva posição no array de char;
Se a string é menor que o tamanho do vetor de char, será atribuido um '\0' no char sucessor ao último, isso garante que ela irá armazenar no array somente os char necessários;
Para imprimir o array de char você deve usar o %s, passando como argumento o array de char que deseja imprimir.

Exemplo: 

```C
char palavra_secreta[10];
sprintf(palavra_secreta,"MELANCIA");
printf("%s",palavra_secreta);

/*Temos o seguinte array: char palavra_secreta[10], nele será armazenado a palavra "MELANCIA", os valores de cada posicão desse array serão:

palavra_secreta[0] = 'M'
palavra_secreta[1] = 'E'
palavra_secreta[2] = 'L'
palavra_secreta[3] = 'A'
palavra_secreta[4] = 'M'
palavra_secreta[5] = 'C'
palavra_secreta[6] = 'I'
palavra_secreta[7] = 'A'
palavra_secreta[8] = '\0'
palavra_secreta[9 ... 19] // = LIXO DE MEMÓRIA ou VALOR DE INICIALIZAÇÃO
*/

```

Para mais informações sobre a função sprintf() consulte a [documentação do C](https://learn.microsoft.com/pt-br/cpp/c-language/?view=msvc-170).

## FUNÇÃO strlen(char[])**

A função strlen(char[]) recebe como parâmetro um array de char e retorna seu tamanho.

Exemplo:

```C
char palavra_secreta[50];
sprintf(palavra_secreta,"MELANCIA");
int tamanho_palavra_secreta = strlen(palavra_secreta);
printf("%d", tamanho_palavra_secreta);

// Resultado:
//8
```

OBS.: Lembre-se que os índices de um array sempre começam em 0, então para um array exemplo[N], seus índices são:

```C
exemplo[0]
exemplo[1]
exemplo[2]
exemplo[3]
...
exemplo[N-1]
```
Para mais informações sobre a função strlen() consulte a [documentação do C](https://learn.microsoft.com/pt-br/cpp/c-language/?view=msvc-170).


## Criar funções

    - Passagens por cópia.
    - Passagem por endereço de memória - Ponteiros.

    Uma outra alternativa para esse código seria usar variáveis globais, porém, a critério de conhecimento e consulta vou deixar da forma que está.

## Função fopen, fclose,fscanf

    Essas são funções de manipulação de arquivos.

    fopen - Abre um arquivo do diretório atual.
    fclose - Fecha o arquivo.
    fscanf - Faz a leitura sequencial do arquivo(linha a linha).
