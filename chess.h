#ifndef CHESS_H
#define CHESS_H

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 8
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define BOARD_OFFSET_X 50
#define BOARD_OFFSET_Y 50
#define SQUARE_SIZE 87

#define NAME_LEN 50
#define ROLL_LEN 20
#define MAX_MOVES 500
#define SAVE_FILE "saved_game.txt"
#define HISTORY_FILE "match_history.txt"
#define EMPTY '.'

/* Player Data Structure */
struct player {
    char name[NAME_LEN];
    char roll[ROLL_LEN];
};

/* Move History Record Structure */
struct moveRecord {
    char piece;
    int fromRow, fromCol, toRow, toCol;
    char captured;
    int wasPromotion;
};

/* Piece Animation State */
typedef struct {
    int active;
    char piece;
    Vector2 startPos;
    Vector2 targetPos;
    Vector2 currentPos;
    float progress;
    int toRow, toCol;
} PieceAnimation;

/* Captured Pieces Tracking Structure */
typedef struct {
    char whiteCaptured[16];
    int wCount;
    char blackCaptured[16];
    int bCount;
} CapturedTracker;

/* Shared State Declarations */
extern char board[SIZE][SIZE];
extern char boardBackup[SIZE][SIZE];
extern int turnBackup;
extern int canUndo;
extern struct player p1, p2;
extern int whiteTurn;
extern int wKingMoved, bKingMoved;
extern int wRookAMoved, wRookHMoved;
extern int bRookAMoved, bRookHMoved;
extern struct moveRecord moves[MAX_MOVES];
extern int moveCount;

extern int selectedRow;
extern int selectedCol;
extern int lastFromRow, lastFromCol, lastToRow, lastToCol;
extern char statusMessage[128];
extern CapturedTracker capturedData;

/* Logic Function Declarations */
void setupBoard(void);
int isWhite(char p);
int isBlack(char p);
int isEmpty(char p);
int sameSide(char a, char b);
void backupState(void);
void undoMove(void);
void findKing(int white, int *outRow, int *outCol);
int canMove(int fromRow, int fromCol, int toRow, int toCol, int white, int allowCastle);
int isAttacked(int row, int col, int byWhite);
int inCheck(int white);
int isLegalMove(int fromRow, int fromCol, int toRow, int toCol, int white);
int hasAnyLegalMove(int white);
void makeMove(int fromRow, int fromCol, int toRow, int toCol);
void saveGame(void);
int loadGame(void);
void deleteSavedGame(void);
void logResult(const char *result);

/* Raylib GUI Function Declarations */
void drawVectorPiece(char piece, int x, int y, int size);
void renderGUI(void);
void handleMouseInput(void);
void initGameApp(void);

#endif /* CHESS_H */


