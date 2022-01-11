/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 3

void stock (char lineName[][256], int lineStock[]);
void emission (char *lineName, int *lineStock);

int main()
{
    char command[256] = {}; /* 入力コマンドバッファ */
    int i = 0; // ループカウンタ
    int lineStock[] = {0, 0, 0};
    char lineName[][256] = {"コカコーラ", "Qoo グレープ", "ファンタオレンジ"};

    printf("********* 自動販売機プログラム：このプログラムは自動販売機の商品排出を管理します **********\n\n");
    printf("初期設定をします >> 各商品を入庫してください\n\n");

    /* 商品の補充 */
    for (i=0; i<LINE_MAX; i++) {
        printf("%s の入庫数を入力してください: ", lineName[i]);
        scanf("%s", command);
        if (atoi(command) < 1 || atoi(command) > 10) {
            printf("入庫可能数は1本〜10本までです\n");
            i--;
            continue;
        }
        lineStock[i] = atoi(command);
        printf(">> %sが%d本補充されました\n\n", lineName[i], lineStock[i]);
    }

    /* 在庫表示 */
    stock(lineName, lineStock);

    for (;;) {
        /* メニュー入力表示 */
        printf("いらっしゃいませ😃\n");
        for (i=0; i<LINE_MAX; i++) {
            /* 課題②：在庫のない商品は表示しない */
            printf("  %d: %s\n", i+1, lineName[i]);
        }
        printf("欲しいジュースを選んでください🥤: ");
        scanf("%s", command);

        /* 入力値に Q か q が入力されたら for ループを抜ける */
        if(strcmp(command, "Q") == 0 || strcmp(command, "q") == 0) {
            printf("プログラムを終了します...");
            break;
        }

        if (atoi(command) < 1 || atoi(command) > LINE_MAX) {
            /* 課題③：在庫のない商品はエラー表示する */
            printf("そんな商品はありまへん😤\n");
            continue;
        }

        /* 商品排出処理 */
        emission(lineName[atoi(command)-1], &lineStock[atoi(command)-1]);

        /* 在庫表示 */
        stock(lineName, lineStock);
    }

    return 0;
}

void stock (char lineName[][256], int lineStock[]) {
    int i = 0;
    printf("\n最新在庫状況 >>\n");
    for (i=0; i<LINE_MAX; i++) {
        printf("%s: %d\n", lineName[i], lineStock[i]);
    }
    printf("\n");
}

/* 課題①：選ばれた商品を排出する（在庫を減らす） */
void emission (char *lineName, int *lineStock) {
    /* lineName -> 商品名の参照渡し */
    /* lineStock -> 差在庫数の参照渡し */
    /* ヒント①： 在庫数が0以下なら何もしない*/
    /* ヒント②： 在庫数が1以上なら在庫数を-1する*/
    printf("\n%s: %d\n", lineName, *lineStock);
}
