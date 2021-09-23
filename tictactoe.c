#include <stdio.h>
#include <unistd.h>
int main()
{
    int winner = 0, count = 0;
    int a[9], number, mark, Player, flag, i, j;
    for (i = 0; i < 9; i++)
        a[i] = ' ';
    printf("\tWelcome To TIC-TAC-TOE\n\n\n");
    printf("\n");
    printf("\t  %c || %c  || %c  \n", a[0], a[1], a[2]);
    printf("\t =============== \n");
    printf("\t  %c || %c  || %c  \n", a[3], a[4], a[5]);
    printf("\t =============== \n");
    printf("\t  %c || %c  || %c  \n", a[6], a[7], a[8]);
    printf("\n\n");
    printf("\tIMPORTANT INSTRUCTIONS\n\n");
    printf("*Must be 2 Players\n\n");
    printf("*Choose numbers from 1 to 9 \n\n ");


    while (count < 9)
    {

        if (count % 2 == 0)
        {

            mark = 'A';
            Player = 1;
        }
        else
        {
            mark = 'B';
            Player = 2;
        }

        printf("Player %d turn:", Player);
        scanf("%d", &number);
        if (number < 1 || number > 9)
        {
            printf("Allowed number is 1 to 9 \n");
            sleep(1);
            continue;
        }
        if (a[number - 1] == 'A' || a[number - 1] == 'B')
        {
            printf("Position Already occupied \n");
            sleep(1);
            continue;
        }
        a[number - 1] = mark;
        count++;

        flag = 0;

        printf("\n");
        printf("\t  %c || %c  || %c  \n", a[0], a[1], a[2]);
        printf("\t =============\n");
        printf("\t  %c || %c  || %c  \n", a[3], a[4], a[5]);
        printf("\t =============\n");
        printf("\t  %c || %c  || %c  \n", a[6], a[7], a[8]);
        printf("\n\n");
        for (i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                flag = 0;

            if (a[i] == mark)
                flag++;

            if (flag == 3)
            {
                winner = 1;
                goto win;
            }
        }

        flag = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = i; j <= i + 6; j = j + 3)
            {
                if (a[j] == mark)
                    flag++;
            }
            if (flag == 3)
            {
                winner = 1;
                goto win;
            }
            flag = 0;
        }
        if ((a[0] == mark && a[4] == mark && a[8] == mark) ||
                (a[2] == mark && a[4] == mark && a[6] == mark))
        {
            winner = 1;
            goto win;
        }
    }
win:

    printf("\n\n");
    printf("\t  %c || %c  || %c  \n", a[0], a[1], a[2]);
    printf("\t ==============\n");
    printf("\t  %c || %c  || %c  \n", a[3], a[4], a[5]);
    printf("\t ==============\n");
    printf("\t  %c || %c  || %c  \n\n", a[6], a[7], a[8]);
    if (winner)
    {
        printf("Player %d is the winner\n", Player);
    }
    else
    {
        printf("Match draw.....");
    }
    return 0;
}