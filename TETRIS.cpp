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
int WINAPI WinMain(HINSTANCE hInstance,  //프로그램 진입점, 윈도우 생성, 메시지 루프
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	srand(time(NULL));
	MSG mSg;
	WCHAR szTitle[] = L"테트리스";  // 윈도우 타이틀 바에 표시될 문자열
	WCHAR szClass[] = L"Class";     // 윈도우 클래스 이름
	HICON hIcon1; // 아이콘 핸들 변수 (NULL로 로드되는 아이콘)
	HICON hIcon2; // 아이콘 핸들 변수 (리소스에서 로드되는 아이콘)
	hIcon1 = LoadIcon(NULL, IDI_QUESTION);
	hIcon2 = LoadIcon(hInstance, MAKEINTRESOURCE(101));
	WNDCLASSEX WndEx; // 윈도우 클래스 정보를 담을 구조체 선언 (Ex는 확장 버전)
	WndEx.cbSize = sizeof(WndEx); // 구조체의 크기를 설정 (필수)
	WndEx.style = NULL;           // 윈도우 클래스 스타일 (여기서는 기본값, 필요시 CS_HREDRAW | CS_VREDRAW 등 사용)
	WndEx.lpfnWndProc = WndProc;  // 이 클래스의 윈도우 메시지를 처리할 콜백 함수 포인터
	WndEx.cbClsExtra = 0;         // 여분의 클래스 메모리 (사용하지 않음)
	WndEx.cbWndExtra = 0;         // 여분의 윈도우 메모리 (사용하지 않음)
	WndEx.hInstance = hInstance;  // 이 클래스를 등록하는 애플리케이션 인스턴스 핸들
	WndEx.hIcon = LoadIcon(NULL, L"IDI_ICON"); // 큰 아이콘 (Alt+Tab 등에서 사용) 로드 (사용자 정의 리소스 아이콘)
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW); // 마우스 커서 모양 로드 (표준 화살표 커서)
	WndEx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // 윈도우 배경 브러시 (검은색 브러시 사용)
	WndEx.lpszMenuName = /*L"IDR_MENU"*/MAKEINTRESOURCE(IDR_MENU); // 윈도우에 사용할 메뉴 리소스 이름 (MAKEINTRESOURCE는 리소스 ID를 문자열로 변환)
	WndEx.lpszClassName = szClass; // 등록할 윈도우 클래스 이름 (위에서 정의한 "Class")
	WndEx.hIconSm = LoadIcon(hInstance, /*L"IDI_ICON"*/MAKEINTRESOURCE(IDI_ICON)); // 작은 아이콘 (제목 표시줄 등에 사용) 로드

	RegisterClassEx(&WndEx); // 위에서 설정한 정보로 윈도우 클래스를 시스템에 등록

	g_hWnd = CreateWindowEx(NULL,         // 확장 윈도우 스타일 (여기서는 없음)
		szClass,                  // 사용할 윈도우 클래스 이름 (위에서 등록한 "Class")
		szTitle,                  // 윈도우 타이틀 바에 표시될 텍스트
		WS_OVERLAPPEDWINDOW,      // 윈도우 스타일 (겹쳐진 창, 제목 표시줄, 크기 조절 등 일반적인 창 스타일)
		0,                        // 윈도우 시작 X 좌표 (CW_USEDEFAULT 사용 시 시스템이 결정)
		0,                        // 윈도우 시작 Y 좌표 (CW_USEDEFAULT 사용 시 시스템이 결정)
		700,                      // 윈도우 너비
		600,                      // 윈도우 높이
		NULL,                     // 부모 윈도우 핸들 (여기서는 없음)
		NULL,                     // 메뉴 핸들 또는 자식 윈도우 ID (클래스에 메뉴가 지정되어 있으므로 NULL)
		hInstance,                // 윈도우를 생성하는 애플리케이션 인스턴스 핸들
		NULL);                    // 생성 매개변수 (WM_CREATE 메시지로 전달될 포인터, 여기서는 없음)

	ShowWindow(g_hWnd, nShowCmd); // 윈도우를 화면에 표시 (nShowCmd 값에 따라 초기 상태 결정)
	UpdateWindow(g_hWnd);        // WM_PAINT 메시지를 강제로 발생시켜 윈도우의 클라이언트 영역을 그림

	// --- 메시지 루프 시작 ---
	// 애플리케이션이 메시지를 기다리고 처리하는 핵심 부분
	while (TRUE) // 무한 루프: 프로그램이 종료될 때까지 계속 실행
	{
		// PeekMessage: 메시지 큐에 메시지가 있는지 확인 (PM_NOREMOVE: 메시지를 큐에서 제거하지 않음)
		// 메시지가 없어도 즉시 반환되므로, 게임 루프처럼 지속적인 작업에 적합 (CPU를 독점하지 않음)
		if (PeekMessage(&mSg, NULL, 0, 0, PM_NOREMOVE))
		{
			// GetMessage: 메시지 큐에 메시지가 있을 때까지 대기하다가 메시지를 가져옴
			// WM_QUIT 메시지를 받으면 FALSE를 반환하며 루프 종료
			if (!GetMessage(&mSg, NULL, 0, 0))
				break; // WM_QUIT 메시지를 받으면 루프를 빠져나감

			TranslateMessage(&mSg); // 키보드 입력 메시지를 처리 (예: VK_RETURN을 WM_CHAR로 변환)
			DispatchMessage(&mSg);  // 메시지를 해당 윈도우의 WndProc 함수로 전달
		}
		// 만약 메시지 큐가 비어 있다면 (PeekMessage가 FALSE를 반환),
		// 이 else 블록이나 while 루프의 다른 부분에서 게임 로직(예: 프레임 업데이트, 그리기)을 처리할 수 있습니다.
		// 현재 코드에서는 메시지가 없을 때 아무것도 하지 않고 다시 PeekMessage를 기다립니다.
	}
	// --- 메시지 루프 종료 ---

	return mSg.wParam; // WM_QUIT 메시지의 wParam 값을 반환하며 프로그램 종료
}

LRESULT CALLBACK WndProc(HWND hWnd, // 윈도우 핸들
	UINT uMsg, // 메시지 코드
	WPARAM wParam, // 메시지 추가 정보 (보통 하위 16비트)
	LPARAM lParam) // 메시지 추가 정보 (보통 상위 16비트)
{
	switch (uMsg) // 수신된 메시지에 따라 처리
	{
	case WM_COMMAND: // 메뉴, 액셀러레이터 또는 컨트롤에서 알림 메시지가 발생했을 때
		switch (LOWORD(wParam)) // wParam의 하위 워드(메뉴/컨트롤 ID)를 확인
		{
		case FILE_START: // "게임 시작" 메뉴 항목을 선택했을 때
			if (PlayerState == DEAD) // 플레이어가 죽은 상태일 경우 (새 게임 시작)
			{
				expCnt = 0; // 경험치 초기화
				level = 0; // 레벨 초기화
				eraseCnt = 0; // 지워진 줄 수 초기화
				MakeBlockPocket(); // 블록 주머니 (다음 나올 블록 순서) 생성
				InitBackGround(); // 게임 배경 초기화
				DrawBackGround(); // 게임 배경 그리기
				PlayerState = ALIVE; // 플레이어 상태를 "살아있음"으로 변경
				NextBlockNum = BlockPocket[cnt++]; // 다음 블록을 블록 주머니에서 가져옴
				FullLineNum = 0; // 가득 찬 줄 수 초기화
				SendMessage(hWnd, WM_NewBlock, 0, 0); // 새 블록을 생성하는 메시지 전송
			}
			if (bTime == ON) // 타이머가 작동 중일 경우
			{
				KillTimer(hWnd, 3); // 타이머 3 (자동 하강) 중지
				KillTimer(hWnd, 4); // 타이머 4 (블록 상승) 중지
				bTime = OFF; // 타이머 상태를 "꺼짐"으로 변경
			}
			else // 타이머가 작동 중이 아닐 경우
			{
				SetTimer(hWnd, 3, 1000, NULL); // 1초마다 WM_TIMER 메시지를 보내는 타이머 3 설정 (자동 하강)
				SetTimer(hWnd, 4, 15000, NULL); // 15초마다 WM_TIMER 메시지를 보내는 타이머 4 설정 (블록 상승)
				bTime = ON; // 타이머 상태를 "켜짐"으로 변경
			}
			break;
		case FILE_EXIT: // "게임 종료" 메뉴 항목을 선택했을 때
			DestroyWindow(hWnd); // 윈도우 파괴 (애플리케이션 종료)
			break;
		}
		return FALSE; // 메시지 처리를 완료하고 FALSE 반환
	case WM_NewBlock: // 새 블록을 생성하라는 사용자 정의 메시지
		NowX = 3; // 현재 블록의 X 좌표 초기화
		NowY = 0; // 현재 블록의 Y 좌표 초기화
		RotateNum = 0; // 회전 상태 초기화
		BlockNum = NextBlockNum; // 다음 블록을 현재 블록으로 설정
		if (cnt >= 7) // 블록 주머니의 모든 블록을 사용했을 경우
		{
			MakeBlockPocket(); // 새로운 블록 주머니 생성
			cnt = 0; // 블록 주머니 인덱스 초기화
		}
		NextBlockNum = BlockPocket[cnt++]; // 다음 블록을 블록 주머니에서 가져옴
		DrawGhostBlock(); // 고스트 블록 (떨어질 위치 예측) 그리기
		DrawBlock(); // 현재 블록 그리기
		DrawNextBlock(); // 다음 블록 미리보기 그리기
		if (!BlockCanMove(NowX, NowY)) // 새 블록이 생성되자마자 움직일 수 없다면 (게임 오버)
		{
			HoldBlock = -1; // 홀드 블록 초기화
			PlayerState = DEAD; // 플레이어 상태를 "죽음"으로 변경
		}
		return FALSE; // 메시지 처리를 완료하고 FALSE 반환
	case WM_KEYDOWN: // 키보드 키가 눌렸을 때
		switch (LOWORD(wParam)) // 눌린 키의 가상 키 코드 확인
		{
			case VK_LEFT: // 왼쪽 방향키
				LeftMove(); // 블록 왼쪽으로 이동
				break;
			case VK_RIGHT: // 오른쪽 방향키
				RightMove(); // 블록 오른쪽으로 이동
				break;
			case VK_UP: // 위쪽 방향키
				Rotate(); // 블록 회전
				break;
			case VK_DOWN: // 아래쪽 방향키
				DownMove(); // 블록 한 칸 아래로 이동
				break;
			case VK_SPACE: // 스페이스바
				while (DownMove()); // 블록을 가능한 한 빠르게 바닥까지 내림 (하드 드롭)
				break;
			case 'C': // 'C' 키
				Hold(); // 블록 홀드 기능 (현재 블록을 임시 저장하고 다른 블록 사용)
				break;
		}
		return FALSE; // 메시지 처리를 완료하고 FALSE 반환
	case WM_TIMER: // 타이머 메시지가 발생했을 때
		if (PlayerState == ALIVE) // 플레이어가 살아있는 상태일 경우
		{
			if (wParam == 3) // 타이머 3 (자동 하강 타이머)일 경우
				DownMove(); // 블록 한 칸 아래로 자동 하강
		}
		if (PlayerState == ALIVE) // 플레이어가 살아있는 상태일 경우 (중복 확인)
		{
			if (wParam == 4) // 타이머 4 (블록 상승 타이머)일 경우
			{
				EraseBlock(); // 현재 블록 지우기
				EraseGhostBlock(); // 고스트 블록 지우기
				UpBlock(); // 바닥에서 블록 한 줄 올리기 (테트리스의 가비지 라인)
				EraseBottomblock(); // 하단 블록 지우기 (블록 상승으로 인해 사라지는 부분)
				ReInitBackGround(); // 배경 재초기화
				DrawNewBackGround(); // 새로운 배경 그리기
				DrawGhostBlock(); // 고스트 블록 다시 그리기
				DrawBlock(); // 현재 블록 다시 그리기
			}
		}
		else // 플레이어가 죽은 상태일 경우
		{
			if (bTime == ON) // 타이머가 작동 중이라면
			{
				bTime = OFF; // 타이머 상태를 "꺼짐"으로 변경
				KillTimer(hWnd, 3); // 타이머 3 중지
				KillTimer(hWnd, 4); // 타이머 4 중지
			}
		}

		return FALSE; // 메시지 처리를 완료하고 FALSE 반환
	case WM_DESTROY: // 윈도우가 파괴될 때 (애플리케이션 종료 직전)
		if (bTime == ON) // 타이머가 작동 중이라면
		{
			KillTimer(hWnd, 3); // 타이머 3 중지
			KillTimer(hWnd, 4); // 타이머 4 중지
		}
		PostQuitMessage(0); // 메시지 큐에 WM_QUIT 메시지를 게시하여 애플리케이션 종료
		return FALSE; // 메시지 처리를 완료하고 FALSE 반환
	}
	// 처리되지 않은 메시지는 기본 윈도우 프로시저로 전달하여 처리
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
		SetTimer(g_hWnd, 3, 1000 - 30 * level, NULL);
	}
}