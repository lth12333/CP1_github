// func.c
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game.h"

// ���� ���� ����
Piece board[BOARD_SIZE][BOARD_SIZE];
GameState gameState = { 0, 0 };

// ü���� �ʱ�ȭ �Լ�
void initBoard() {
    // �⺻���� �ʱ�ȭ (��: �� ��ġ)
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = (Piece){ 'P', 'B' }; // ��� ��
        board[6][i] = (Piece){ 'P', 'W' }; // ��� ��
    }
    board[0][0] = board[0][7] = (Piece){ 'R', 'B' }; // ��� ��
    board[0][1] = board[0][6] = (Piece){ 'N', 'B' }; // ��� ����Ʈ
    board[0][2] = board[0][5] = (Piece){ 'B', 'B' }; // ��� ���
    board[0][3] = (Piece){ 'Q', 'B' }; // ��� ��
    board[0][4] = (Piece){ 'K', 'B' }; // ��� ŷ
    board[7][0] = board[7][7] = (Piece){ 'R', 'W' }; // ��� ��
    board[7][1] = board[7][6] = (Piece){ 'N', 'W' }; // ��� ����Ʈ
    board[7][2] = board[7][5] = (Piece){ 'B', 'W' }; // ��� ���
    board[7][3] = (Piece){ 'Q', 'W' }; // ��� ��
    board[7][4] = (Piece){ 'K', 'W' }; // ��� ŷ
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (Piece){ ' ', ' ' }; // ������
        }
    }
    
    // �ٸ� �⹰ �ʱ�ȭ �ڵ� �߰� ����
}

// ü���� ��� �Լ�
void printBoard() {
    for (int i = 0; i < BOARD_SIZE + 1; i++) {
        if (i == 8) {
            printf("---|---|---|---|---|---|---|---|---|\n   | a | b | c | d | e | f | g | h |\n");
        }
        else {
            printf("---|---|---|---|---|---|---|---|---|\n %c |", 56 - i);
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c%c |", board[i][j].color, board[i][j].type);
            }
        }
        printf("\n");
    }
}

//�⹰ ��ġ ���� �Լ�
int move_piece(Piece* start, Piece* arrival) {
    arrival->color = start->color;
    arrival->type = start->type;
    start->type = ' ';
    start->color = ' ';
    return 1;
}

//�� �⹰ �̵� �Լ�
int pawn(int s_y, int s_x, int a_y, int a_x) {
    if (board[s_y][s_x].color == 'B') {
        if (a_y - s_y == 1) {
            if (abs(a_x - s_x) == 1 && board[a_y][a_x].color == 'W') {
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
            else if (a_x == s_x && board[a_y][a_x].color == ' ') {
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
        }
    }
    if (a_y - s_y == -1) {
        if (abs(a_x - s_x) == 1 && board[a_y][a_x].color == 'B') {
            return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
        }
        else if (a_x == s_x && board[a_y][a_x].color == ' ') {
            return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
        }
    }
    return 0;
}
int rook(int s_y, int s_x, int a_y, int a_x) {
    if (board[s_y][s_x].color != board[a_y][a_x].color) {
        if (s_y == a_y) {
            if (s_x > a_x) {
                for (int i = s_x - 1; i > a_x; i--) {
                    if (board[a_y][i].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
            else {
                for (int i = s_x + 1; i < a_x; i++) {
                    if (board[a_y][i].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
        }
        else if (s_x == a_x) {
            if (s_y > a_y) {
                for (int i = s_y - 1; i > a_y; i--) {
                    if (board[i][a_x].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
            else {
                for (int i = s_y + 1; i < a_y; i++) {
                    if (board[i][a_x].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
        }
    }
    return 0;
}
int knight(int s_y, int s_x, int a_y, int a_x) {
    if (board[s_y][s_x].color != board[a_y][a_x].color) {
        if ((abs(a_y - s_y) == 2 && abs(a_x - s_x) == 1) || 
            (abs(a_y - s_y) == 1 && abs(a_x - s_x) == 2)) {
            return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
        }
    }
    return 0;
}
int bishop(int s_y, int s_x, int a_y, int a_x) {
    if (board[s_y][s_x].color != board[a_y][a_x].color && abs(a_y - s_y) == abs(a_x - s_x)) {
        if (a_y > s_y) {
            if (a_x > s_x) {
                for (int i = 1; i < a_y - s_y; i++) {
                    if (board[s_y + i][s_x + i].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
            else {
                for (int i = 1; i < a_y - s_y; i++) {
                    if (board[s_y + i][s_x - i].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);                
            }
        }
        else {
            if (a_x > s_x) {
                for (int i = 1; i < s_y - a_y; i++) {
                    if (board[s_y - i][s_x + i].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
            else {
                for (int i = 1; i < s_y - a_y; i++) {
                    if (board[s_y - i][s_x - i].color != ' ') {
                        return 0;
                    }
                }
                return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
            }
        }
    }        
    return 0;
}
int queen(int s_y, int s_x, int a_y, int a_x) {
    if (rook(s_y, s_x, a_y, a_x) || bishop(s_y, s_x, a_y, a_x)) {
        return 1;
    }
    return 0;
}
int king(int s_y, int s_x, int a_y, int a_x) {
    if (board[s_y][s_x].color != board[a_y][a_x].color && (abs(a_y - s_y) == 1 || abs(a_x - s_x) == 1)) {
        return move_piece(&board[s_y][s_x], &board[a_y][a_x]);
    }
    return 0;
}


// �⹰ �̵� ���� �Լ�
int select_move_Piece(char select_piece[3], char arrival_point[3]) {
    // ���� üũ �� �⺻ �̵� ����  s = start, a = arrival
    int s_y = 56 - (int)select_piece[1], s_x = (int)select_piece[0] - 97; //start���� 0~7�� ��ȯ
    int a_y = 56 - (int)arrival_point[1], a_x = (int)arrival_point[0] - 97; //arrival���� 0~7�� ��ȯ
    int len = strlen(select_piece); //���� ����
    char color[2] = { 'W', 'B' };
    if (len == 2 && -1 < s_x && s_x < 8 && -1 < s_y && s_y < 8 && (s_x != a_x || s_y != a_y) &&
        -1 < a_x && a_x < 8 && -1 < a_y && a_y < 8 && color[gameState.turn] == board[s_y][s_x].color) 
    {
        switch (board[s_y][s_x].type) {
        case 'P':
            return pawn(s_y, s_x, a_y, a_x);
        case 'R':
            return rook(s_y, s_x, a_y, a_x);
        case 'N':
            return knight(s_y, s_x, a_y, a_x);
        case 'B':
            return bishop(s_y, s_x, a_y, a_x);
        case 'Q':
            return queen(s_y, s_x, a_y, a_x);
        case 'K':
            return king(s_y, s_x, a_y, a_x);
        default:
            return 0;
        };
    }
    else {
        return 0;
    }
}



