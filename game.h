// game.h
#ifndef GAME_H
#define GAME_H

#include "piece.h"

#define BOARD_SIZE 8

// ���� ����: ü�� ���� �迭
extern Piece board[BOARD_SIZE][BOARD_SIZE];

// ���� ���¸� �����ϱ� ���� ����ü
typedef struct {
    int turn;         // ���� ���� (0 = ���, 1 = ���)
    int game_over;    // ���� ���� ���� (0 = ���� ��, 1 = ����)
} GameState;

extern GameState gameState;

// �Լ� ����
void initBoard();
void printBoard();
int select_move_Piece(char select_piece[3], char move_piece[3]);

#endif
#pragma once
