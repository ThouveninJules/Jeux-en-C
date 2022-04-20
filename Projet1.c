#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void UJ(int);
void DJ(int);
void Deb(int, int, char*, char*);
void ShiUJ(int, char*);
void MorUJ(int, int, char*);
void ShiDJ(int, char*, char*);
void MorDJ(int, int, char*, char*);

int main()
{
    int nb;
    printf("Selectionnez le nombre de joueur :\n\n1-Un joueur\n2-Deux joueurs\n\n");
    do
    {
        scanf("%d", &nb);
    }while(nb<1 || nb>2);
    if(nb==1)
    {
        UJ(nb);
    }else
    {
        DJ(nb);
    }
    return 0;
}


void UJ(int nb)
{
    int i, jeu;
    char psd[10], null[1];
    printf("\nEntrez votre pseudo (10 caracteres max) : ");
    scanf("%s", psd);
    printf("\nBonjour %s, a quel jeu voulez-vous jouer ?\n\n1-Pierre_feuille_Puits_ciseaux\n2-Morpion\n3-Annuler\n\n", psd);
    do
    {
        scanf("%d", &jeu);
    }while(jeu<1 || jeu>3);
    if(jeu==1 || jeu==2)
    {
        Deb(jeu, nb, psd, null);
    }
}

void DJ(int nb)
{
    int i, jeu;
    char psd1[10], psd2[10];
    printf("\nJoueur 1, entrez votre pseudo (10 caracteres max) : ");
    scanf("%s", psd1);
    printf("\nJoueur 2, entrez votre pseudo (10 caracteres max) : ");
    scanf("%s", psd2);
    printf("\nBonjour %s et %s, a quel jeu voulez-vous jouer ?\n\n1-Pierre_feuille_Puits_ciseaux\n2-Morpion\n3-Annuler\n\n", psd1 , psd2);
    do
    {
        scanf("%d", &jeu);
    }while(jeu<1 || jeu>3);
    if(jeu==1 || jeu==2)
    {
        Deb(jeu, nb, psd1, psd2);
    }
}

void Deb(int j, int nb, char* psd1, char* psd2)
{
    int chx;
    do
    {
    printf("\n1-Jouer\n2-Regles\n3-Quitter\n\n");
    scanf("%d", &chx);
    if(chx==2)
    {
        if(j==1)
        {
            printf("\nCiseaux>Feuille>Pierre>Ciseaux\nFeuille>Puits>Ciseaux/Pierre\n\nA la fin de la premiere manche, une revanche est possible avec les meme regles.\nCependant les signes de la manche precedente ne sont plus utilisables.\n");
        }else if(j==2)
        {
            printf("\nVous placerez lors de votre tour un symbole qui vous sera assigne dans une des cases d'un tableau de 3x3 cases.\nAlignez verticalement, horizontalement ou diagonalement 3 symboles pour gagner.\n");
        }
    }
    }while(chx<1 || chx==2 || chx>3);
    if(chx==1)
    {
        if(nb==1)
        {
            if(j==1)
            {
                ShiUJ(nb, psd1);
            }else if(j==2)
            {
                int ini=0;
                MorUJ(nb, ini, psd1);
            }
        }
        if(nb==2)
        {
            if(j==1)
            {
                ShiDJ(nb, psd1, psd2);
            }else if(j==2)
            {
                int ini=0;
                MorDJ(nb, ini, psd1, psd2);
            }
        }
    }
}

void ShiUJ(int nb, char* psd)
{
    int t1, t2, bot1, bot2, score1=0, score2=0, rev, scoreFinal=0;
    system("cls");
    printf("%s, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n", psd);
    do
    {
        scanf("%d", &t1);
    }while(t1<1 || t1>4);
    srand(time(NULL));
    bot1=rand()%3;
    system("cls");
    switch(t1)
    {
    case 1 : printf("Vous avez joue : Pierre\n");
            switch (bot1)
        {
            case 0 : score1=0;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nEgalite !");
            break;
            case 1 : score1=1;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nGagne !");
            break;
            case 2 : score1=-1;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nPerdu !");
            break;
            case 3 : score1=-1;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nPerdu !");
            break;
        };
        break;
    case 2 : printf("Vous avez joue : Ciseaux\n");
            switch (bot1)
        {
            case 0 : score1=-1;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nPerdu !");
            break;
            case 1 : score1=0;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nEgalite !");
            break;
            case 2 : score1=-1;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nPerdu !");
            break;
            case 3 : score1=1;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nGagne !");
            break;
        };
        break;
    case 3 : printf("Vous avez joue : Puits\n");
            switch (bot1)
        {
            case 0 : score1=1;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nGagne !");
            break;
            case 1 : score1=1;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nGagne !");
            break;
            case 2 : score1=0;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nEgalite !");
            break;
            case 3 : score1=-1;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nPerdu !");
            break;
        };
        break;
    case 4 : printf("Vous avez joue : Feuille\n");
            switch (bot1)
        {
            case 0 : score1=1;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nGagne !");
            break;
            case 1 : score1=-1;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nPerdu !");
            break;
            case 2 : score1=1;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nGagne !");
            break;
            case 3 : score1=0;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nEgalite !");
            break;
        };
        break;
    }
    printf("\n\n%s, voulez-vous faire une revanche ?\n\n1-Oui\n2-Non\n\n", psd);
    do
    {
        scanf("%d", &rev);
    }while(rev<1 || rev>2);
    system("cls");
    if(rev==1)
    {
        if(score1==0)
        {
            printf("%s, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n", psd);
            do
            {
                printf("\n\n%d est interdit\n\n", t1);
                scanf("%d", &t2);
            }while(t2<1 || t2>4 || t2==t1);
        }else
        {
            printf("%s, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n", psd);
            do
            {
                printf("\n\n%d et %d sont interdits\n\n", t1, bot1+1);
                scanf("%d", &t2);
            }while(t2<1 || t2>4 || t2==t1 || t2==bot1+1);
        }
        do
        {
            bot2=rand()%3;
        }while(bot2==t1-1 || bot2==bot1);
        system("cls");
        switch(t2)
    {
    case 1 : printf("Vous avez joue : Pierre\n");
            switch (bot2)
        {
            case 0 : score2=0;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nEgalite !");
            break;
            case 1 : score2=1;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nGagne !");
            break;
            case 2 : score2=-1;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nPerdu !");
            break;
            case 3 : score2=-1;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nPerdu !");
            break;
        };
        break;
    case 2 : printf("Vous avez joue : Ciseaux\n");
            switch (bot2)
        {
            case 0 : score2=-1;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nPerdu !");
            break;
            case 1 : score2=0;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nEgalite !");
            break;
            case 2 : score2=-1;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nPerdu !");
            break;
            case 3 : score2=1;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nGagne !");
            break;
        };
        break;
    case 3 : printf("Vous avez joue : Puits\n");
            switch (bot2)
        {
            case 0 : score2=1;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nGagne !");
            break;
            case 1 : score2=1;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nGagne !");
            break;
            case 2 : score2=0;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nEgalite !");
            break;
            case 3 : score2=-1;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nPerdu !");
            break;
        };
        break;
    case 4 : printf("Vous avez joue : Feuille\n");
            switch (bot2)
        {
            case 0 : score2=1;
            printf("Votre adversaire a joue : Pierre");
            printf("\n\nGagne !");
            break;
            case 1 : score2=-1;
            printf("Votre adversaire a joue : Ciseaux");
            printf("\n\nPerdu !");
            break;
            case 2 : score2=1;
            printf("Votre adversaire a joue : Puits");
            printf("\n\nGagne !");
            break;
            case 3 : score2=0;
            printf("Votre adversaire a joue : Feuille");
            printf("\n\nEgalite !");
            break;
        };
        break;
    }
    }
        scoreFinal=score1+score2;
        if(scoreFinal>0)
        {
            printf("\n\nVous avez gagne ! Felicitation %s!\n", psd);
        }else if(scoreFinal==0)
        {
            printf("\n\nEgalite !\n");
        }else if(scoreFinal<0)
        {
            printf("\n\nPerdu, dommage %s...\n", psd);
        }
        UJ(nb);
    }

void MorUJ(int nb, int ini, char* psd)
{
    int i, j, v[9], nom=1, chx,score=0, bot;
    char c[3][3];
    srand(time(NULL));
    if(ini==0)
    {
       for(i=0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {
            c[i][j]='*';
        }
    }
    for(i=0; i<=8; i++)
    {
        v[i]=0;
    }
    }
    system("cls");
    printf("\n\n\n");
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[0][0], c[0][1], c[0][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[1][0], c[1][1], c[1][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[2][0], c[2][1], c[2][2]);
    printf("+-----+\n");
    printf("\n\n\n");
    do
    {
    nom=1;
    printf("%s, que voulez-vous jouer ?\n\n", psd);
    for(i=0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {
            printf("%d-Case %d/%d\n", nom, i+1, j+1);
            if(c[i][j]!='*')
            {
                printf("%d est deja pris\n", nom);
            }
            nom++;
        }
    }
    do
    {
        printf("\n");
        scanf("%d", &chx);
    }while(chx<1 || chx>9 || v[chx-1]==1);
    switch(chx)
    {
        case 1 : c[0][0]='X';
        v[0]=1;
        break;
        case 2 : c[0][1]='X';
        v[1]=1;
        break;
        case 3 : c[0][2]='X';
        v[2]=1;
        break;
        case 4 : c[1][0]='X';
        v[3]=1;
        break;
        case 5 : c[1][1]='X';
        v[4]=1;
        break;
        case 6 : c[1][2]='X';
        v[5]=1;
        break;
        case 7 : c[2][0]='X';
        v[6]=1;
        break;
        case 8 : c[2][1]='X';
        v[7]=1;
        break;
        case 9 : c[2][2]='X';
        v[8]=1;
        break;
    }
    system("cls");
    printf("\n\n\n");
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[0][0], c[0][1], c[0][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[1][0], c[1][1], c[1][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[2][0], c[2][1], c[2][2]);
    printf("+-----+\n");
    printf("\n\n\n");
    if(c[0][0]=='X' && c[0][1]=='X' && c[0][2]=='X')
    {   score=1;
        break;
    }else if(c[1][0]=='X' && c[1][1]=='X' && c[1][2]=='X')
    {   score=1;
        break;
    }else if(c[2][0]=='X' && c[2][1]=='X' && c[2][2]=='X')
    {   score=1;
        break;
    }else if(c[0][0]=='X' && c[1][0]=='X' && c[2][0]=='X')
    {   score=1;
        break;
    }else if(c[0][1]=='X' && c[1][1]=='X' && c[2][1]=='X')
    {   score=1;
        break;
    }else if(c[0][2]=='X' && c[1][2]=='X' && c[2][2]=='X')
    {   score=1;
        break;
    }else if(c[0][0]=='X' && c[1][1]=='X' && c[2][2]=='X')
    {   score=1;
        break;
    }else if(c[2][0]=='X' && c[1][1]=='X' && c[0][2]=='X')
    {   score=1;
        break;
    }
    printf("Votre adversaire joue...");
    if(score!=1)
    {
    if(v[0]==0 || v[1]==0 || v[2]==0 || v[3]==0 || v[4]==0 || v[5]==0 || v[6]==0 || v[7]==0 || v[8]==0)
    {
    do
    {
      bot=rand()%9;
    }while(bot<0 || bot>8 || v[bot]==1);
    }
    }else{break;}
    switch(bot)
    {
        case 0 : c[0][0]='O';
        v[0]=1;
        break;
        case 1 : c[0][1]='O';
        v[1]=1;
        break;
        case 2 : c[0][2]='O';
        v[2]=1;
        break;
        case 3 : c[1][0]='O';
        v[3]=1;
        break;
        case 4 : c[1][1]='O';
        v[4]=1;
        break;
        case 5 : c[1][2]='O';
        v[5]=1;
        break;
        case 6 : c[2][0]='O';
        v[6]=1;
        break;
        case 7 : c[2][1]='O';
        v[7]=1;
        break;
        case 8 : c[2][2]='O';
        v[8]=1;
        break;
    }
    system("cls");
    printf("\n\n\n");
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[0][0], c[0][1], c[0][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[1][0], c[1][1], c[1][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[2][0], c[2][1], c[2][2]);
    printf("+-----+\n");
    printf("\n\n\n");
    if(c[0][0]=='O' && c[0][1]=='O' && c[0][2]=='O')
    {   score=-1;
        break;
    }else if(c[1][0]=='O' && c[1][1]=='O' && c[1][2]=='O')
    {   score=-1;
        break;
    }else if(c[2][0]=='O' && c[2][1]=='O' && c[2][2]=='O')
    {   score=-1;
        break;
    }else if(c[0][0]=='O' && c[1][0]=='O' && c[2][0]=='O')
    {   score=-1;
        break;
    }else if(c[0][1]=='O' && c[1][1]=='O' && c[2][1]=='O')
    {   score=-1;
        break;
    }else if(c[0][2]=='O' && c[1][2]=='O' && c[2][2]=='O')
    {   score=-1;
        break;
    }else if(c[0][0]=='O' && c[1][1]=='O' && c[2][2]=='O')
    {   score=-1;
        break;
    }else if(c[2][0]=='O' && c[1][1]=='O' && c[0][2]=='O')
    {   score=-1;
        break;
    }
    }while(v[0]!=1 || v[1]!=1 || v[2]!=1 || v[3]!=1 || v[4]!=1 || v[5]!=1 || v[6]!=1 || v[7]!=1 || v[8]!=1);
    if(score==0)
    {
    if(c[0][0]=='X' && c[0][1]=='X' && c[0][2]=='X')
    {   score=1;
    }else if(c[1][0]=='X' && c[1][1]=='X' && c[1][2]=='X')
    {   score=1;
    }else if(c[2][0]=='X' && c[2][1]=='X' && c[2][2]=='X')
    {   score=1;
    }else if(c[0][0]=='X' && c[1][0]=='X' && c[2][0]=='X')
    {   score=1;
    }else if(c[0][1]=='X' && c[1][1]=='X' && c[2][1]=='X')
    {   score=1;
    }else if(c[0][2]=='X' && c[1][2]=='X' && c[2][2]=='X')
    {   score=1;
    }else if(c[0][0]=='X' && c[1][1]=='X' && c[2][2]=='X')
    {   score=1;
    }else if(c[2][0]=='X' && c[1][1]=='X' && c[0][2]=='X')
    {   score=1;
    }else if(c[0][0]=='O' && c[0][1]=='O' && c[0][2]=='O')
    {   score=-1;
    }else if(c[1][0]=='O' && c[1][1]=='O' && c[1][2]=='O')
    {   score=-1;
    }else if(c[2][0]=='O' && c[2][1]=='O' && c[2][2]=='O')
    {   score=-1;
    }else if(c[0][0]=='O' && c[1][0]=='O' && c[2][0]=='O')
    {   score=-1;
    }else if(c[0][1]=='O' && c[1][1]=='O' && c[2][1]=='O')
    {   score=-1;
    }else if(c[0][2]=='O' && c[1][2]=='O' && c[2][2]=='O')
    {   score=-1;
    }else if(c[0][0]=='O' && c[1][1]=='O' && c[2][2]=='O')
    {   score=-1;
    }else if(c[2][0]=='O' && c[1][1]=='O' && c[0][2]=='O')
    {   score=-1;
    }
    }
    if(score==0)
    {
        printf("Egalite !\n\n");
    }else if(score==1)
    {
        printf("Bravo %s, vous avez gagne !\n\n", psd);
    }else if(score==-1)
    {
        printf("Perdu !\n\n");
    }
    UJ(nb);
}

void ShiDJ(int nb, char* psd1, char* psd2)
{
    int t1, t2, b1, b2, score1=0, score2=0, rev, scoreFinal=0;
    system("cls");
    printf("%s, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n", psd1);
    do
    {
        scanf("%d", &t1);
    }while(t1<1 || t1>4);
    system("cls");
    printf("%s, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n", psd2);
    do
    {
        scanf("%d", &b1);
    }while(b1<1 || b1>4);
    system("cls");
    switch(t1)
    {
    case 1 : printf("%s a joue : Pierre\n", psd1);
            switch (b1)
        {
            case 1 : score1=0;
            printf("%s a joue : Pierre", psd2);
            printf("\n\nEgalite !");
            break;
            case 2 : score1=1;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 3 : score1=-1;
            printf("%s a joue : Puits", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 4 : score1=-1;
            printf("%s a joue : Feuille", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
        };
        break;
    case 2 : printf("%s a joue : Ciseaux\n", psd1);
            switch (b1)
        {
            case 1 : score1=-1;
            printf("%s a joue : Pierre", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 2 : score1=0;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\nEgalite !");
            break;
            case 3 : score1=-1;
            printf("%s a joue : Puits", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 4 : score1=1;
            printf("%s a joue : Feuille", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
        };
        break;
    case 3 : printf("%s a joue : Puits\n", psd1);
            switch (b1)
        {
            case 1 : score1=1;
            printf("%s a joue : Pierre", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 2 : score1=1;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 3 : score1=0;
            printf("%s a joue : Puits", psd2);
            printf("\n\nEgalite !");
            break;
            case 4 : score1=-1;
            printf("%s a joue : Feuille", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
        };
        break;
    case 4 : printf("%s a joue : Feuille\n", psd1);
            switch (b1)
        {
            case 1 : score1=1;
            printf("%s a joue : Pierre", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 2 : score1=-1;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 3 : score1=1;
            printf("%s a joue : Puits", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 4 : score1=0;
            printf("%s a joue : Feuille", psd2);
            printf("\n\nEgalite !");
            break;
        };
        break;
    }
    printf("\n\nVoulez-vous faire une revanche ?\n\n1-Oui\n2-Non\n\n");
    do
    {
        scanf("%d", &rev);
    }while(rev<1 || rev>2);
    system("cls");
    if(rev==1)
    {
        if(score1==0)
        {
            printf("Joueur 2, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n");
            do
            {
                printf("\n\n%d est interdit\n\n", t1);
                scanf("%d", &b2);
            }while(b2<1 || b2>4 || b2==t1);
        }else
        {
            printf("Joueur 2, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n");
            do
            {
                printf("\n\n%d et %d sont interdits\n\n", t1, b1);
                scanf("%d", &b2);
            }while(b2<1 || b2>4 || b2==t1 || b2==b1);
        }
        system("cls");
        if(score1==0)
        {
            printf("Joueur 1, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n");
            do
            {
                printf("\n\n%d est interdit\n\n", t1);
                scanf("%d", &t2);
            }while(t2<1 || t2>4 || t2==t1);
        }else
        {
            printf("Joueur 1, que voulez-vous jouer ?\n\n1-Pierre\n2-Ciseaux\n3-Puits\n4-Feuille\n\n");
            do
            {
                printf("\n\n%d et %d sont interdits\n\n", t1, b1);
                scanf("%d", &t2);
            }while(t2<1 || t2>4 || t2==t1 || t2==b1);
        }
        system("cls");
        switch(t2)
    {
    case 1 : printf("%s a joue : Pierre\n", psd1);
            switch (b2)
        {
            case 1 : score2=0;
            printf("%s a joue : Pierre", psd2);
            printf("\n\nEgalite !");
            break;
            case 2 : score2=1;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 3 : score2=-1;
            printf("%s a joue : Puits", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 4 : score2=-1;
            printf("%s a joue : Feuille", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
        };
        break;
    case 2 : printf("%s a joue : Ciseaux\n", psd1);
            switch (b2)
        {
            case 1 : score2=-1;
            printf("%s a joue : Pierre", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 2 : score2=0;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\nEgalite !");
            break;
            case 3 : score2=-1;
            printf("%s a joue : Puits", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 4 : score2=1;
            printf("%s a joue : Feuille", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
        };
        break;
    case 3 : printf("%s a joue : Puits\n", psd1);
            switch (b2)
        {
            case 1 : score2=1;
            printf("%s a joue : Pierre", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 2 : score2=1;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 3 : score2=0;
            printf("%s a joue : Puits", psd2);
            printf("\n\nEgalite !");
            break;
            case 4 : score2=-1;
            printf("%s a joue : Feuille", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
        };
        break;
    case 4 : printf("%s a joue : Feuille\n", psd1);
            switch (b2)
        {
            case 1 : score2=1;
            printf("%s a joue : Pierre", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 2 : score2=-1;
            printf("%s a joue : Ciseaux", psd2);
            printf("\n\n%s a gagne !", psd2);
            break;
            case 3 : score2=1;
            printf("%s a joue : Puits", psd2);
            printf("\n\n%s a gagne !", psd1);
            break;
            case 4 : score2=0;
            printf("%s a joue : Feuille", psd2);
            printf("\n\nEgalite !");
            break;
        };
        break;
    }
    }
        scoreFinal=score1+score2;
        if(scoreFinal>0)
        {
            printf("\n\n%s a gagne ! Felicitation !\n", psd1);
        }else if(scoreFinal==0)
        {
            printf("\n\nEgalite !\n");
        }else if(scoreFinal<0)
        {
            printf("\n\n%s a gagne ! Felicitation !\n", psd2);
        }
        DJ(nb);
}

void MorDJ(int nb, int ini, char* psd1, char* psd2)
{
    int i, j, v[9], nom=1, chx,score=0, chxb;
    char c[3][3];
    if(ini==0)
    {
       for(i=0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {
            c[i][j]='*';
        }
    }
    for(i=0; i<=8; i++)
    {
        v[i]=0;
    }
    }
    system("cls");
    printf("\n\n\n");
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[0][0], c[0][1], c[0][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[1][0], c[1][1], c[1][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[2][0], c[2][1], c[2][2]);
    printf("+-----+\n");
    printf("\n\n\n");
    do
    {
    nom=1;
    printf("%s, que voulez-vous jouer ?\n\n", psd1);
    for(i=0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {
            printf("%d-Case %d/%d\n", nom, i+1, j+1);
            if(c[i][j]!='*')
            {
                printf("%d est deja pris\n", nom);
            }
            nom++;
        }
    }
    do
    {
        printf("\n");
        scanf("%d", &chx);
    }while(chx<1 || chx>9 || v[chx-1]==1);
    switch(chx)
    {
        case 1 : c[0][0]='X';
        v[0]=1;
        break;
        case 2 : c[0][1]='X';
        v[1]=1;
        break;
        case 3 : c[0][2]='X';
        v[2]=1;
        break;
        case 4 : c[1][0]='X';
        v[3]=1;
        break;
        case 5 : c[1][1]='X';
        v[4]=1;
        break;
        case 6 : c[1][2]='X';
        v[5]=1;
        break;
        case 7 : c[2][0]='X';
        v[6]=1;
        break;
        case 8 : c[2][1]='X';
        v[7]=1;
        break;
        case 9 : c[2][2]='X';
        v[8]=1;
        break;
    }
    system("cls");
    printf("\n\n\n");
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[0][0], c[0][1], c[0][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[1][0], c[1][1], c[1][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[2][0], c[2][1], c[2][2]);
    printf("+-----+\n");
    printf("\n\n\n");
    if(c[0][0]=='X' && c[0][1]=='X' && c[0][2]=='X')
    {   score=1;
        break;
    }else if(c[1][0]=='X' && c[1][1]=='X' && c[1][2]=='X')
    {   score=1;
        break;
    }else if(c[2][0]=='X' && c[2][1]=='X' && c[2][2]=='X')
    {   score=1;
        break;
    }else if(c[0][0]=='X' && c[1][0]=='X' && c[2][0]=='X')
    {   score=1;
        break;
    }else if(c[0][1]=='X' && c[1][1]=='X' && c[2][1]=='X')
    {   score=1;
        break;
    }else if(c[0][2]=='X' && c[1][2]=='X' && c[2][2]=='X')
    {   score=1;
        break;
    }else if(c[0][0]=='X' && c[1][1]=='X' && c[2][2]=='X')
    {   score=1;
        break;
    }else if(c[2][0]=='X' && c[1][1]=='X' && c[0][2]=='X')
    {   score=1;
        break;
    }
    if(score!=1)
    {
    if(v[0]==0 || v[1]==0 || v[2]==0 || v[3]==0 || v[4]==0 || v[5]==0 || v[6]==0 || v[7]==0 || v[8]==0)
    {
    nom=1;
    printf("%s, que voulez-vous jouer ?\n\n", psd2);
    for(i=0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {
            printf("%d-Case %d/%d\n", nom, i+1, j+1);
            if(c[i][j]!='*')
            {
                printf("%d est deja pris\n", nom);
            }
            nom++;
        }
    }
    do
    {
        printf("\n");
        scanf("%d", &chxb);
    }while(chxb<1 || chxb>9 || v[chxb-1]==1);
    }
    }else{break;}
    switch(chxb)
    {
        case 1 : c[0][0]='O';
        v[0]=1;
        break;
        case 2 : c[0][1]='O';
        v[1]=1;
        break;
        case 3 : c[0][2]='O';
        v[2]=1;
        break;
        case 4 : c[1][0]='O';
        v[3]=1;
        break;
        case 5 : c[1][1]='O';
        v[4]=1;
        break;
        case 6 : c[1][2]='O';
        v[5]=1;
        break;
        case 7 : c[2][0]='O';
        v[6]=1;
        break;
        case 8 : c[2][1]='O';
        v[7]=1;
        break;
        case 9 : c[2][2]='O';
        v[8]=1;
        break;
    }
    system("cls");
    printf("\n\n\n");
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[0][0], c[0][1], c[0][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[1][0], c[1][1], c[1][2]);
    printf("+-----+\n");
    printf("|%c|%c|%c|\n", c[2][0], c[2][1], c[2][2]);
    printf("+-----+\n");
    printf("\n\n\n");
    if(c[0][0]=='O' && c[0][1]=='O' && c[0][2]=='O')
    {   score=-1;
        break;
    }else if(c[1][0]=='O' && c[1][1]=='O' && c[1][2]=='O')
    {   score=-1;
        break;
    }else if(c[2][0]=='O' && c[2][1]=='O' && c[2][2]=='O')
    {   score=-1;
        break;
    }else if(c[0][0]=='O' && c[1][0]=='O' && c[2][0]=='O')
    {   score=-1;
        break;
    }else if(c[0][1]=='O' && c[1][1]=='O' && c[2][1]=='O')
    {   score=-1;
        break;
    }else if(c[0][2]=='O' && c[1][2]=='O' && c[2][2]=='O')
    {   score=-1;
        break;
    }else if(c[0][0]=='O' && c[1][1]=='O' && c[2][2]=='O')
    {   score=-1;
        break;
    }else if(c[2][0]=='O' && c[1][1]=='O' && c[0][2]=='O')
    {   score=-1;
        break;
    }
    }while(v[0]==0 || v[1]==0 || v[2]==0 || v[3]==0 || v[4]==0 || v[5]==0 || v[6]==0 || v[7]==0 || v[8]==0);
    if(score==0)
    {
    if(c[0][0]=='X' && c[0][1]=='X' && c[0][2]=='X')
    {   score=1;
    }else if(c[1][0]=='X' && c[1][1]=='X' && c[1][2]=='X')
    {   score=1;
    }else if(c[2][0]=='X' && c[2][1]=='X' && c[2][2]=='X')
    {   score=1;
    }else if(c[0][0]=='X' && c[1][0]=='X' && c[2][0]=='X')
    {   score=1;
    }else if(c[0][1]=='X' && c[1][1]=='X' && c[2][1]=='X')
    {   score=1;
    }else if(c[0][2]=='X' && c[1][2]=='X' && c[2][2]=='X')
    {   score=1;
    }else if(c[0][0]=='X' && c[1][1]=='X' && c[2][2]=='X')
    {   score=1;
    }else if(c[2][0]=='X' && c[1][1]=='X' && c[0][2]=='X')
    {   score=1;
    }else if(c[0][0]=='O' && c[0][1]=='O' && c[0][2]=='O')
    {   score=-1;
    }else if(c[1][0]=='O' && c[1][1]=='O' && c[1][2]=='O')
    {   score=-1;
    }else if(c[2][0]=='O' && c[2][1]=='O' && c[2][2]=='O')
    {   score=-1;
    }else if(c[0][0]=='O' && c[1][0]=='O' && c[2][0]=='O')
    {   score=-1;
    }else if(c[0][1]=='O' && c[1][1]=='O' && c[2][1]=='O')
    {   score=-1;
    }else if(c[0][2]=='O' && c[1][2]=='O' && c[2][2]=='O')
    {   score=-1;
    }else if(c[0][0]=='O' && c[1][1]=='O' && c[2][2]=='O')
    {   score=-1;
    }else if(c[2][0]=='O' && c[1][1]=='O' && c[0][2]=='O')
    {   score=-1;
    }
    }
    if(score==0)
    {
        printf("Egalite !\n\n");
    }else if(score==1)
    {
        printf("Bravo %s, vous avez gagne !\n\n", psd1);
    }else if(score==-1)
    {
        printf("Bravo %s, vous avez gagne !\n\n", psd2);
    }
    DJ(nb);
}
