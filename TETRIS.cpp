#include "resource.h"
#include <windows.h>
#include <stdio.h>
#include<ctime>
#include<stdlib.h>
#define WM_NewBlock WM_USER + 1
#define YES 1
#define NO 0
#define SUCCESS 1
#define FAIL 0
#define ON 1
#define OFF 0
#define ALIVE 1
#define DEAD 0
int Block[7][4][4][4] = { 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,

						 0, 0, 0, 0,
						 1, 1, 1, 1,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,

						 0, 0, 0, 0,
						 1, 1, 1, 1,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 1, 0,
						 0, 0, 1, 0,
						 0, 1, 1, 0,
						 0, 0, 0, 0,

						 1, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 0, 0,
						 1, 0, 0, 0,
						 1, 1, 1, 0,
						 0, 0, 0, 0,

						 1, 0, 0, 0,
						 1, 0, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 0, 0,
						 0, 0, 1, 0,
						 1, 1, 1, 0,
						 0, 0, 0, 0,

						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 1, 1, 1, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 0, 0,
						 0, 1, 0, 0,
						 1, 1, 1, 0,
						 0, 0, 0, 0,

						 0, 0, 1, 0,
						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 1, 1, 1, 0,
						 0, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 0, 0, 0,
						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 0, 1, 1, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 0, 1, 1, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0 };
int BackGround[21][12];
BOOL bTime = OFF;
int BlockNum;
int RotateNum;
int NowX, NowY;
int NextBlockNum;
int FullLineNum;
int PlayerState;
int HoldBlock = -1;
HWND g_hWnd;
int GX, GY;
int BlockPocket[7] = { 0,1,2,3,4,5,6 };
int cnt = 0;
int eraseCnt = 0;
BOOL check = TRUE;
int expCnt;
int level;
BOOL isFirstLevelUp = TRUE;

void InitBackGround(void);
void DrawBackGround(void);
void DrawBlock(void);
void EraseBlock(void);
void DrawNextBlock(void);
BOOL BlockCanMove(int x, int y);
void LeftMove(void);
void RightMove(void);
void Rotate(void);
BOOL DownMove(void);
void UpdateBackGround(void);
void CheckFullLine(void);
void EraseFullLine(int);
void Hold(void);
void DrawHoldBlock(void);
void DrawGhostBlock(void);
void EraseGhostBlock(void);
void UpBlock(void);
void EraseBottomblock(void);
void ReInitBackGround(void);
void DrawNewBackGround(void);
void MakeBlockPocket(void);
void LevelUp(void);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	srand(time(NULL));
	MSG mSg;
	WCHAR szTitle[] = L"테트리스";
	WCHAR szClass[] = L"Class";
	HICON hIcon1;
	HICON hIcon2;
	hIcon1 = LoadIcon(NULL, IDI_QUESTION);
	hIcon2 = LoadIcon(hInstance, MAKEINTRESOURCE(101));
	WNDCLASSEX WndEx;
	WndEx.cbSize = sizeof(WndEx);
	WndEx.style = NULL;
	WndEx.lpfnWndProc = WndProc;
	WndEx.cbClsExtra = 0;
	WndEx.cbWndExtra = 0;
	WndEx.hInstance = hInstance;
	WndEx.hIcon = LoadIcon(NULL, L"IDI_ICON");
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndEx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndEx.lpszMenuName = /*L"IDR_MENU"*/MAKEINTRESOURCE(IDR_MENU);
	WndEx.lpszClassName = szClass;
	WndEx.hIconSm = LoadIcon(hInstance, /*L"IDI_ICON"*/MAKEINTRESOURCE(IDI_ICON));

	RegisterClassEx(&WndEx);
	g_hWnd = CreateWindowEx(NULL,
		szClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		700,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(g_hWnd, nShowCmd);
	UpdateWindow(g_hWnd);
	while (TRUE)
	{
		if (PeekMessage(&mSg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&mSg, NULL, 0, 0))
				break;
			TranslateMessage(&mSg);
			DispatchMessage(&mSg);
		}
	}
	return mSg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case FILE_START:
			if (PlayerState == DEAD)
			{
				expCnt = 0;
				level = 0;
				eraseCnt = 0;
				MakeBlockPocket();
				InitBackGround();
				DrawBackGround();
				PlayerState = ALIVE;
				NextBlockNum = BlockPocket[cnt++];
				FullLineNum = 0;
				SendMessage(hWnd, WM_NewBlock, 0, 0);
			}
			if (bTime == ON)
			{
				KillTimer(hWnd, 3);
				KillTimer(hWnd, 4);
				bTime = OFF;
			}
			else
			{
				SetTimer(hWnd, 3, 1000, NULL);
				SetTimer(hWnd, 4, 15000, NULL);
				bTime = ON;
			}
			break;
		case FILE_EXIT:
			DestroyWindow(hWnd);
			break;
		}
		return FALSE;
	case WM_NewBlock:
		NowX = 3;
		NowY = 0;
		RotateNum = 0;
		BlockNum = NextBlockNum;
		if (cnt >= 7)
		{
			MakeBlockPocket();
			cnt = 0;
		}
		NextBlockNum = BlockPocket[cnt++];
		DrawGhostBlock();
		DrawBlock();
		DrawNextBlock();
		if (!BlockCanMove(NowX, NowY))
		{
			HoldBlock = -1;
			PlayerState = DEAD;
		}
		return FALSE;
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_LEFT:
			LeftMove();
			break;
		case VK_RIGHT:
			RightMove();
			break;
		case VK_UP:
			Rotate();
			break;
		case VK_DOWN:
			DownMove();
			break;
		case VK_SPACE:
			while (DownMove());
			break;
		case 'C':
			Hold();
			break;
		}
		return FALSE;
	case WM_TIMER:
		if (PlayerState == ALIVE)
		{
			if (wParam == 3)
				DownMove();
		}
		if (PlayerState == ALIVE)
		{
			if (wParam == 4)
			{
				EraseBlock();
				EraseGhostBlock();
				UpBlock();
				EraseBottomblock();
				ReInitBackGround();
				DrawNewBackGround();
				DrawGhostBlock();
				DrawBlock();
			}
		}
		else
		{
			if (bTime == ON)
			{
				bTime = OFF;
				KillTimer(hWnd, 3);
				KillTimer(hWnd, 4);
			}
		}

		return FALSE;
	case WM_DESTROY:
		if (bTime == ON)
		{
			KillTimer(hWnd, 3);
			KillTimer(hWnd, 4);
		}
		PostQuitMessage(0);

		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void InitBackGround()
{
	InvalidateRect(g_hWnd, NULL, TRUE);
	UpdateWindow(g_hWnd);
	for (int row = 0; row < 21; row++)
		for (int col = 0; col < 12; col++)
		{
			BackGround[row][col] = 0;
		}
	for (int row = 0; row < 21; row++)
		for (int col = 0; col < 12; col++)
		{
			if (row == 20)
				BackGround[row][col] = 1;
			else if (col == 0)
				BackGround[row][col] = 1;
			else if (col == 11)
				BackGround[row][col] = 1;
			else
				BackGround[row][col] = 0;
		}
}

void DrawBackGround()
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(70, 130, 180));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 21; row++)
		for (int col = 0; col < 12; col++)
			if (BackGround[row][col] == 1)
			{
				x = 100 + col * 20;
				y = row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void DrawBlock()
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 191, 255));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	SetTextColor(hDC, RGB(70, 130, 180));
	SetBkColor(hDC, RGB(0, 0, 0));
	SetBkMode(hDC, OPAQUE);
	wchar_t buffer1[100] = { 0 };
	wchar_t buffer2[100] = { 0 };
	swprintf(buffer1, 50, L"SCORE : %d", eraseCnt * 1000);
	swprintf(buffer2, 50, L"LEVEL : %d", level);
	TextOutW(hDC, 430, 380, buffer1, lstrlenW(buffer1));
	TextOutW(hDC, 430, 400, buffer2, lstrlenW(buffer2));
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (Block[BlockNum][RotateNum][row][col] == 1)
			{
				x = 120 + NowX * 20 + col * 20;
				y = NowY * 20 + row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void EraseBlock()
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (Block[BlockNum][RotateNum][row][col])
			{
				x = 120 + NowX * 20 + col * 20;
				y = NowY * 20 + row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void DrawNextBlock()
{
	HDC hDC;
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 2, RGB(70, 130, 180));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hDC = GetDC(g_hWnd);
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	Rectangle(hDC, 430, 40, 530, 140);
	SetTextColor(hDC, RGB(70, 130, 180));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 430, 20, L"NEXT BLOCK", 10);
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 191, 255));
	hDC = GetDC(g_hWnd);
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
		{
			if (Block[NextBlockNum][RotateNum][row][col])
			{
				x = 450 + col * 20;
				y = 50 + row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
		}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
	DrawHoldBlock();
}

BOOL BlockCanMove(int x, int y)
{
	int check = 0;
	int row, col;
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			if (Block[BlockNum][RotateNum][row][col])
				check += BackGround[y + row][x + col + 1];
	if (check == 0)
		return YES;
	else
		return NO;
}

void LeftMove()
{
	if (PlayerState == DEAD)
		return;
	if (BlockCanMove(NowX - 1, NowY))
	{
		EraseGhostBlock();
		EraseBlock();
		NowX--;
		DrawGhostBlock();
		DrawBlock();
	}
}

void RightMove()
{
	if (PlayerState == DEAD)
		return;
	if (BlockCanMove(NowX + 1, NowY))
	{
		EraseGhostBlock();
		EraseBlock();
		NowX++;
		DrawGhostBlock();
		DrawBlock();
	}
}

void Rotate()
{
	if (PlayerState == DEAD)
		return;
	int temp = RotateNum;
	RotateNum++;
	RotateNum %= 4;
	if (BlockCanMove(NowX, NowY))
	{
		RotateNum = temp;
		EraseGhostBlock();
		EraseBlock();
		RotateNum++;
		RotateNum %= 4;
		DrawGhostBlock();
		DrawBlock();
	}
	else if (BlockCanMove(NowX + 1, NowY))
	{
		RotateNum = temp;
		EraseGhostBlock();
		EraseBlock();
		NowX++;
		RotateNum++;
		RotateNum %= 4;
		DrawGhostBlock();
		DrawBlock();
	}
	else if (BlockCanMove(NowX - 1, NowY))
	{
		RotateNum = temp;
		EraseGhostBlock();
		EraseBlock();
		NowX--;
		RotateNum++;
		RotateNum %= 4;
		DrawGhostBlock();
		DrawBlock();
	}
	else if (BlockCanMove(NowX - 2, NowY))
	{
		RotateNum = temp;
		EraseGhostBlock();
		EraseBlock();
		NowX -= 2;
		RotateNum++;
		RotateNum %= 4;
		DrawGhostBlock();
		DrawBlock();
	}
	else if (BlockCanMove(NowX, NowY - 1))
	{
		RotateNum = temp;
		EraseGhostBlock();
		EraseBlock();
		NowY--;
		RotateNum++;
		RotateNum %= 4;
		DrawGhostBlock();
		DrawBlock();
	}
	else if (BlockCanMove(NowX, NowY - 2))
	{
		RotateNum = temp;
		EraseGhostBlock();
		EraseBlock();
		NowY -= 2;
		RotateNum++;
		RotateNum %= 4;
		DrawGhostBlock();
		DrawBlock();
	}
	else
		RotateNum = temp;
}

BOOL DownMove()
{
	if (PlayerState == DEAD) return FAIL;
	if (BlockCanMove(NowX, NowY + 1))
	{
		EraseGhostBlock();
		EraseBlock();
		NowY++;
		DrawGhostBlock();
		DrawBlock();
		return SUCCESS;
	}
	else
	{
		UpdateBackGround();
		CheckFullLine();
		SendMessage(g_hWnd, WM_NewBlock, 0, 0);
		check = TRUE;
		return FAIL;
	}
}

void UpdateBackGround()
{
	int element;
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
		{
			element = Block[BlockNum][RotateNum][row][col];
			if (element)
				BackGround[NowY + row][NowX + col + 1] = element;
		}
}

void CheckFullLine()
{
	int row, col, line;
	int elementNum;
	for (row = 19; row >= 0; row--)
	{
		elementNum = 0;
		for (col = 1; col <= 10; col++)
			elementNum += BackGround[row][col];
		if (elementNum == 10)
		{
			for (line = row; line > 0; line--)
				for (col = 1; col <= 10; col++)
					BackGround[line][col] = BackGround[line - 1][col];
			EraseFullLine(row);
			FullLineNum++;
			row++;
		}
	}
}

void EraseFullLine(int row)
{
	HDC hDC, hMemDC;
	HBITMAP hBmp;
	int Xlen = 220;
	int Ylen = row * 20;
	hDC = GetDC(g_hWnd);
	hMemDC = CreateCompatibleDC(hDC);
	hBmp = CreateCompatibleBitmap(hDC, 400, 500);
	SelectObject(hMemDC, hBmp);
	BitBlt(hMemDC, 0, 0, Xlen, Ylen, hDC, 120, 0, SRCCOPY);
	BitBlt(hDC, 120, 20, Xlen, Ylen, hMemDC, 0, 0, SRCCOPY);
	DeleteDC(hMemDC);
	ReleaseDC(g_hWnd, hDC);
	DeleteObject(hBmp);
	eraseCnt++;
	expCnt++;
	LevelUp();
}

void Hold(void)
{
	if (PlayerState == DEAD)
		return;
	if (check == TRUE)
	{
		EraseGhostBlock();
		EraseBlock();
		if (HoldBlock == -1)
		{
			HoldBlock = BlockNum;
			BlockNum = NextBlockNum;
			NextBlockNum = BlockPocket[cnt++];
		}
		else
		{
			int tempBlock = BlockNum;
			BlockNum = HoldBlock;
			HoldBlock = tempBlock;
		}
		RotateNum = 0;
		NowX = 3, NowY = 0;
		DrawGhostBlock();
		DrawBlock();
		DrawNextBlock();
		check = FALSE;
	}
}

void DrawHoldBlock(void)
{
	HDC hDC;
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 2, RGB(70, 130, 180));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hDC = GetDC(g_hWnd);
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	Rectangle(hDC, 430, 240, 530, 340);
	SetTextColor(hDC, RGB(70, 130, 180));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 430, 220, L"HOLD BLOCK (C)", 14);
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 191, 255));
	hDC = GetDC(g_hWnd);
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
		{
			if (Block[HoldBlock][RotateNum][row][col])
			{
				x = 450 + col * 20;
				y = 250 + row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
		}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void DrawGhostBlock(void)
{
	int x, y;
	GX = NowX;
	GY = NowY;
	while (BlockCanMove(GX, GY + 1))
	{
		GY++;
	}
	HDC hDC;
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	hDC = GetDC(g_hWnd);
	hPen = CreatePen(PS_DOT, 0, RGB(0, 191, 255));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (Block[BlockNum][RotateNum][row][col])
			{
				x = 120 + GX * 20 + col * 20;
				y = GY * 20 + row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void EraseGhostBlock(void)
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	GX = NowX;
	GY = NowY;
	while (BlockCanMove(GX, GY + 1))
	{
		GY++;
	}
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (Block[BlockNum][RotateNum][row][col])
			{
				x = 120 + GX * 20 + col * 20;
				y = GY * 20 + row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void UpBlock(void)
{
	HDC hDC, hMemDC;
	HBITMAP hBmp;
	int Xlen = 220;
	int Ylen = 380;
	hDC = GetDC(g_hWnd);
	hMemDC = CreateCompatibleDC(hDC);
	hBmp = CreateCompatibleBitmap(hDC, 400, 500);
	SelectObject(hMemDC, hBmp);
	BitBlt(hMemDC, 0, 0, Xlen, Ylen, hDC, 120, 20, SRCCOPY);
	BitBlt(hDC, 120, 0, Xlen, Ylen, hMemDC, 0, 0, SRCCOPY);
	DeleteDC(hMemDC);
	ReleaseDC(g_hWnd, hDC);
	DeleteObject(hBmp);
}

void EraseBottomblock(void)
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int i = 0; i < 10; i++)
	{
		x = 120 + i * 20;
		y = 380;
		Rectangle(hDC, x, y, x + 20, y + 20);
	}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void ReInitBackGround(void)
{
	for (int row = 0; row < 19; row++)
		for (int col = 1; col < 11; col++)
		{
			BackGround[row][col] = BackGround[row + 1][col];
		}
	for (int i = 1; i < 11; i++)
	{
		BackGround[19][i] = 1;
	}
	BackGround[19][rand() % 10 + 1] = 0;
}

void DrawNewBackGround(void)
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 191, 255));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	for (int row = 0; row < 20; row++)
		for (int col = 1; col < 11; col++)
			if (BackGround[row][col] == 1)
			{
				x = 100 + col * 20;
				y = row * 20;
				Rectangle(hDC, x, y, x + 20, y + 20);
			}
	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(g_hWnd, hDC);
}

void MakeBlockPocket(void)
{
	int temp, randnum;
	for (int i = 6; i > 0; i--)
	{
		randnum = rand() % (i + 1);
		temp = BlockPocket[i];
		BlockPocket[i] = BlockPocket[randnum];
		BlockPocket[randnum] = temp;
	}
}

void LevelUp(void)
{
	if (isFirstLevelUp && eraseCnt >= 20)
	{
		expCnt = 0;          
		level++;           
		isFirstLevelUp = FALSE; 
		KillTimer(g_hWnd, 3);
		SetTimer(g_hWnd, 3, 1000-30, NULL);
	}
	else if (!isFirstLevelUp && expCnt >= 8)
	{
		expCnt = 0;         
		level++;        
		KillTimer(g_hWnd, 3);
		SetTimer(g_hWnd, 3, 1000 - 30*level, NULL);
	}
}