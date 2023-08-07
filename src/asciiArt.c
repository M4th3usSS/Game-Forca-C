#include <stdio.h>

void exibir_artes(int acertou, char palavra_secreta[])
{

    if (acertou)
    {

        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }
    else
    {

        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavra_secreta);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n\n");
    }
}

void asciiArt01()
{

    printf("\n\n     _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._\n");
    printf("   ,'_.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._`.\n");
    printf("  ( (                                                         ) )\n");
    printf("   ) )                                                       ( (\n");
    printf("  ( (            Bem vindo ao nosso jogo de forca             ) )\n");
    printf("   ) )                                                       ( (\n");
    printf("  ( (_.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._) )\n");
    printf("   `._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._,'\n\n");
    printf("                                  |>>>\n");
    printf("                                  |\n");
    printf("                    |>>>      _  _|_  _         |>>>\n");
    printf("                    |        |;| |;| |;|        |\n");
    printf("                _  _|_  _    \\\\.    .  /    _  _|_  _\n");
    printf("               |;|_|;|_|;|    \\\\:. ,  /    |;|_|;|_|;|\n");
    printf("               \\\\..      /    ||;   . |    \\\\.    .  /\n");
    printf("                \\\\.  ,  /     ||:  .  |     \\\\:  .  /\n");
    printf("                 ||:   |_   _ ||_ . _ | _   _||:   |\n");
    printf("                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |\n");
    printf("                 ||:   ||.    .     .      . ||:  .|\n");
    printf("                 ||: . || .     . .   .  ,   ||:   |       \\,/\n");
    printf("                 ||:   ||:  ,  _______   .   ||: , |            /`\\\n");
    printf("                 ||:   || .   /+++++++\\    . ||:   |\n");
    printf("                 ||:   ||.    |+++++++| .    ||: . |\n");
    printf("              __ ||: . ||: ,  |+++++++|.  . _||_   |\n");
    printf("     ____--`~    '--~~__|.    |+++++__|----~    ~`---,\n");
    printf("-~--~                   ~---__|,--~'                  ~~----_____-~'\n\n\n");
}