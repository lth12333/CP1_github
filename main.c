#include <stdio.h> 

#include<string.h>
#include "game.h"

void gameLoop() {
    char select_piece[3];
    char arrival_point[3];
    int success_check = 0;
    initBoard();
    gameState.turn = 0; // ������� ����
    gameState.game_over = 0; // ������ ���� ������ ����
    printBoard();
    while (!gameState.game_over) {
        // �⹰ ��ġ �Է�
        success_check = 0;
        while (success_check == 0) {
            printf("���� ����: %s\n", gameState.turn == 0 ? "���" : "���");
            printf("�⹰ ��ġ�� �Է��ϼ��� (����:a1): ");
            scanf("%s", select_piece);
            printf("�̵��� ��ġ�� �Է��ϼ��� (����:b2): ");
            scanf("%s", arrival_point);
            success_check = select_move_Piece(select_piece, arrival_point);
            if (success_check == 0) {
                printf("����!\n");
            }
            printBoard();
        }
        
        if (success_check == 1) {
            printf("�⹰�� �̵��߽��ϴ�!\n");
            gameState.turn = !gameState.turn; //�� ����
        }
        

        // ������ ���� ���� ����
        if (gameState.turn > 10) { // 10�� ����
            gameState.game_over = 1;
            printf("���� ����!\n");
        }
    }
}

int main() {
    gameLoop();
    return 0;
}