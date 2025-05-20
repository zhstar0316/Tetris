// 리소스를 사용하기 위해서 resource.h 파일을 include해 주어야 한다.
#include "resource.h"
// API 함수들을 사용하려면 windows.h 파일을 include해 주어야 한다.
#include <windows.h>
//배경의 배열
int Background[21][12];

//테트리스 블록을 위한 3차원배열
//이 배열에는 블록의 모양이 저장되어 있다.
int Block[7][4][4][4] =		{ 0, 1, 0, 0,
							  0, 1, 0, 0,
							  0, 1, 0, 0,
							  0, 1, 0, 0,	//ㅣ모양

							  0, 0, 0, 0,
							  1, 1, 1, 1,
							  0, 0, 0, 0,
							  0, 0, 0, 0,	//ㅡ모양

							  0, 1, 0, 0,
							  0, 1, 0, 0,
							  0, 1, 0, 0,
							  0, 1, 0, 0,	//ㅣ모양

							  0, 0, 0, 0,
							  1, 1, 1, 1,
							  0, 0, 0, 0,
							  0, 0, 0, 0,	//ㅡ모양

							  0, 0, 1, 0,
							  0, 0, 1, 0,
							  0, 1, 1, 0,
							  0, 0, 0, 0,	//역ㄴ모양

							  1, 1, 1, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 0,
							  0, 0, 0, 0,	//ㄱ모양

							  1, 1, 0, 0,
							  1, 0, 0, 0,
							  1, 0, 0, 0,
							  0, 0, 0, 0,	//역 ㄱ모양

							  0, 0, 0, 0,
							  1, 0, 0, 0,
							  1, 1, 1, 0,
							  0, 0, 0, 0,	//ㄴ모양

							  1, 0, 0, 0,	//	ㅣ
							  1, 0, 0, 0,	//	ㅣ
							  1, 1, 0, 0,	//	ㅣ
							  0, 0, 0, 0,	//	ㅣㅡ 모양

							  0, 0, 0, 0,	//
							  0, 0, 1, 0,	//
							  1, 1, 1, 0,	//	ㅣ
							  0, 0, 0, 0,	//	ㅣㅡㅡㅡ모양

							  0, 1, 1, 0,	//	ㅡㅡ
							  0, 0, 1, 0,	//	   ㅣ
							  0, 0, 1, 0,	//	   ㅣ
							  0, 0, 0, 0,	//	   ㅣ 모양

							  1, 1, 1, 0,	//	ㅣㅡㅡㅡ
							  1, 0, 0, 0,	//	ㅣ
							  0, 0, 0, 0,	//	
							  0, 0, 0, 0,	//	모양

							  0, 0, 0, 0,
							  0, 1, 0, 0,
							  1, 1, 1, 0,
							  0, 0, 0, 0,  // 'ㅗ'자 모양

							  0, 0, 1, 0,
							  0, 1, 1, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 0,  // 'ㅓ'자 모양

							  1, 1, 1, 0,
							  0, 1, 0, 0,
							  0, 0, 0, 0,
							  0, 0, 0, 0,  // 'ㅜ'자 모양

							  1, 0, 0, 0,
							  1, 1, 0, 0,
							  1, 0, 0, 0,
							  0, 0, 0, 0,  // 'ㅏ'자 모양

							  0, 1, 0, 0,  // ㅣ
							  0, 1, 1, 0,  //  ㅡ
							  0, 0, 1, 0,  //   ㅣ  모양
							  0, 0, 0, 0,  //

							  0, 1, 1, 0,  //     __
							  1, 1, 0, 0,  //  __ㅣ	  모양
							  0, 0, 0, 0,  //
							  0, 0, 0, 0,  //

							  0, 1, 0, 0,  //   ㅣ
							  0, 1, 1, 0,  //    ㅡ
							  0, 0, 1, 0,  //     ㅣ 모양
							  0, 0, 0, 0,  //

							  0, 1, 1, 0,  //     __
							  1, 1, 0, 0,  //  __ㅣ	  모양
							  0, 0, 0, 0,  //
							  0, 0, 0, 0,  //

							  0, 1, 0, 0,  //
							  1, 1, 0, 0,  //     ㅣ
							  1, 0, 0, 0,  //	 ㅡ
							  0, 0, 0, 0,  //	ㅣ	모양

							  1, 1, 0, 0,  //	__
							  0, 1, 1, 0,  //	 ㅣ__ 모양
							  0, 0, 0, 0,  //
							  0, 0, 0, 0,  //

							  0, 1, 0, 0,  //
							  1, 1, 0, 0,  //     ㅣ
							  1, 0, 0, 0,  //	 ㅡ
							  0, 0, 0, 0,  //	ㅣ	모양

							  1, 1, 0, 0,  //	__
							  0, 1, 1, 0,  //	 ㅣ__ 모양
							  0, 0, 0, 0,  //
							  0, 0, 0, 0,  //

							  1, 1, 0, 0,  //
							  1, 1, 0, 0,  //		
							  0, 0, 0, 0,  //	ㅁ모양
							  0, 0, 0, 0,  //

							  1, 1, 0, 0,  //
							  1, 1, 0, 0,  //		
							  0, 0, 0, 0,  //	ㅁ모양
							  0, 0, 0, 0,  //

							  1, 1, 0, 0,  //
							  1, 1, 0, 0,  //		
							  0, 0, 0, 0,  //	ㅁ모양
							  0, 0, 0, 0,  //

							  1, 1, 0, 0,  //
							  1, 1, 0, 0,  //		
							  0, 0, 0, 0,  //	ㅁ모양
							  0, 0, 0, 0 };  //

//배열의 행과열을 위한 변수
int row, col;

//사각블록 하나의 위치를 위한 변수
int x, y;

//블록의 회전
int Rotate;

//블록의 종류
int Type;

//현재의 블록 좌표
int NowY,NowX;

//블록을 출력하는 함수
void DrawBlock();
//블록을 출력한다
void PrintFourBlock(void);

// 배경의 배열 초기화 하는 함수
void InitBackGround(void);
// 배경을 그리는 함수
void DrawBackGround(void);

// 윈도우의 핸들이 저장될 변수를 만든다. (사용자 정의 함수를 위함)
HWND g_hWnd;

/*
(1) C declaration(__cdecl) : __cdecl 로 함수가 규약이 되어 있으면,
	함수를 호출한 쪽에서 parameter 값들을 함수가 return 되고 난후
	stack 에서 제거함.따라서 호출한 함수가 자신의 parameter 를 알고 있기 때문에
	printf 와 같이 parameter 가 가변적인 함수에서 사용가능.

	__cdecl은 호출자에 의해 가변인자로 받은 스텍 메모리를 해제하는 식이며,
	현재 함수호출규약의 기본형(디폴트)로 돼 있다. 물론, 이 기본형을 [프로젝트] -> [속성] -> [C/C++] -> [고급] -> [호출 규칙] 에서
	수정할 수는 있다. 여기서! 호출자(Caller)라는 꽤나 말이 어색할 수 있는데 호출자는 함수를 부르는 함수이다.
	예를 들면, main()함수에서 A()라는 함수를 실행했다면, A()의 호출자는 main()함수가 되는 것이다.
	더불어 이 상황에서 A()의 함수는 main()으로부터 호출 수신자(Callee)가 되는 것이다.
	스택 메모리를 호출자가 직접 해제를 하다보니 실행파일이 커진다는 설명이 있는데,
	이는 해제하는 코드를 가변 인자 코드를 가진 함수 하나하나 마다 메모리를 해제하는 코드를 넣어야하기 때문이라 설명하고 있다.


(2) standard call(__stdcall) : 이 규약은 함수를 호출 받은 쪽(즉 함수의 내부)에서
	parameter 를 제거하도록 되어 있다.따라서 parameter 의 갯수가 명확한 곳에서
	사용하게 되어 있다.윈도우즈의 API 와 같은 경우 함수에 따른 인자들이 명확히
	정의 되어 있기 때문에 바로 __stdcall 규약을 사용하고 있다.

	WINAPI로 define까지 해놓은 코드이며, 그 특징은 호출자에서 인자 스텍을 넣는 행위만 할뿐 삭제해주지 않는다는 것이다.
	따라서 해당 스텍은 함수 내부에서 직접 삭제를 해야하며, 만약 가변인자로 인자가 들어갈 경우 정확한 인자의 크기를 함수 내에서 알 수 없어
	함수 실행 전으로 회귀하지 못한다. 즉, __stdcall은 가변인자를 사용할 수 없다.

	(참고)stdcall 호출 방식이 cdecl 호출 방식보다 빠르고, 프로그램 용량도 적어짐.
		  stdcall 호출 형식은 호출한 함수 내부에서 파라미터 크기만큼 pop을 해 주기 때문에 가변인자를 사용하는 것이 불가능

*/
// 메시지의 처리를 위해 콜 백 함수를 선언한다.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 프로그램의 시작점을 지정한다.
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	// 메시지 구조체를 선언한다.
	MSG mSg;

	// 윈도우의 캡션을 지정한다.
	WCHAR szTitle[] = L"한 개의 블록 출력하기";
	// 윈도우의 클래스를 지정한다.
	WCHAR szClass[] = L"Class";


	// 추가적인 아이콘 셋팅 법/////////////////////////////////////
	HICON hIcon1;   // icon handle 
	HICON hIcon2;   // icon handle 

	// 기본 아이콘 생성
	hIcon1 = LoadIcon(NULL, IDI_QUESTION);

	// 사용자 정의 아이콘 생성 
	hIcon2 = LoadIcon(hInstance, MAKEINTRESOURCE(101));
	///////////////////////////////////////////////////////////////

	// WNDCLASSEX 구조체를 선언한다. 참고로 창은 하나의 윈도우 클래스를 기반으로 생성된다.
	WNDCLASSEX WndEx;

	// WNDCLASSEX 구조체의 크기를 지정한다.
	WndEx.cbSize = sizeof(WndEx);

	// 윈도우의 스타일을 지정한다.
	WndEx.style = NULL;

	// 메시지를 처리할 함수를 지정한다. 즉 메시지가 발생하면 그 메시지를 WndProc 함수에서 처리한다.
	WndEx.lpfnWndProc = WndProc;

	// 추가 클래스를 지정한다. 추가 클래스가 없기 때문에 NULL 값으로 지정한다.
	WndEx.cbClsExtra = 0;

	// 추가 윈도우를 지정한다. 추가 윈도우가 없기 때문에 NULL 값으로 지정한다.
	WndEx.cbWndExtra = 0;

	// 인스턴스 핸들을 지정한다.
	WndEx.hInstance = hInstance;

	// 실행 파일에 쓰일 아이콘을 지정한다. LoadIcon() 함수는 리소스에서 아이콘을 불러와 반환한다.
	WndEx.hIcon = LoadIcon(NULL, L"IDI_ICON");

	// 윈도우에서 쓰일 커서를 지정한다. LoadCursor() 함수는 미리 예약된 커서 값을 반환한다.
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW);

	// 윈도우의 배경색을 지정한다. GetStockObject() 함수는 흰색을 반환한다.
	WndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	// 윈도우에 사용될 메뉴를 지정한다. 메뉴가 없기 때문에 NULL 값으로 지정하였다.
	WndEx.lpszMenuName = NULL;

	// 클래스를 지정한다. 참고로 이 클래스는 CreateWindowEx() 함수에서 지정될 클래스와 동일해야 한다.
	WndEx.lpszClassName = szClass;

	// 윈도우의 캡션이 쓰일 아이콘을 지정한다. LoadIcon() 함수는 리소스에서 아이콘을 불러와 반환한다.
	WndEx.hIconSm = LoadIcon(hInstance, /*L"IDI_ICON"*/MAKEINTRESOURCE(IDI_ICON));
	//WndEx.hIconSm = hIcon2;

	/*
		리소스란 -> 리소스란 그래픽 요소를 활용하는데 초점이 맞춰진 자원이다.
		리소스 등록 -> 프로젝트- 리소스 파일 마우스 오른쪽 클릭- 추가- 리소스
		리소스 ID란 -> 리소스에는 각각의 ID가 할당되며, 이것을 식별자로 이용한다. 리소스 뷰로 리소스를 한 눈에 볼 수 있다.
		리소스 ID 확인하기 -> 리소스 뷰에서 한눈에 보고 관리할 수 있다.

		아이콘, 커서 제작
		리소스 등록을 통해 아이콘, 커서를 제작하면 직접 그림을 그려서 제작할 수도 있고, 가져오기를 통해 기존 이미지를 불러올 수도 있다.
		커서는 특별히 핫스폿 설정을 통해, 입력받을 커서의 정확한 위치를 설정할 수도 있다. 그리기 도구에 있습니다.


		cf)	리소스 자원 활용을 위한 세팅
			resource 헤더 파일을 인클루드 합니다.
			#include "Resource.h“



		MAKEINTRESOURCE 는 매크로 함수로서 정수를 문자열 변수로 만들어주는 기능을 한다.
		윈도우즈 API 의 리소스 관리 함수들은 그 전달 인자로 문자열을 받는다.
		그러나 리소스 번호는 WORD 즉 정수형이므로 이것을 변환한다.
		아이디는 resource.h 파일에 각각 정수형으로 define 되어 있다.
		소스 파일에서 리소스 아이디를 인식하지 못할 때는 헤더파일에 올바르게 define되어 있는지 확인합니다.

		WndEx.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(커서 아이디));
		WndEx.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(아이콘 아이디));
	*/

	// WNDCLASSEX에 지정된 값들을 레지스터에 등록한다.
	RegisterClassEx(&WndEx);

	// 윈도우를 생성한다.
	g_hWnd = CreateWindowEx(NULL,				// 윈도우의 스타일을 지정한다.
		szClass,					// 윈도우의 클래스를 지정한다.
		szTitle,					// 윈도우의 캡션을 지정한다.
		WS_OVERLAPPEDWINDOW,		// 윈도우의 스타일을 지정한다.
		0,							// 윈도우의 x좌표 위치를 지정한다.
		0,							// 윈도우의 y좌표 위치를 지정한다.
		500,						// 윈도우의 넓이를 320으로 지정하였다.
		500,						// 윈도우의 높이를 250으로 지정하였다.
		NULL,						// 윈도우를 포함하고 있는 다른 윈도우가 없으므로 NULL 값으로 지정하였다.
		NULL,						// 메뉴가 없으므로 NULL 값으로 지정하였다.
		hInstance,					// 인스턴스 핸들을 지정한다.
		NULL);						// 잘 쓰이지 않는다.

	// 윈도우가 실제로 보여질 형태를 지정한다.
	ShowWindow(g_hWnd, nShowCmd);
	// 윈도우를 갱신하고 WM_PAINT 메시지를 호출한다.
	UpdateWindow(g_hWnd);

	// 메시지 처리를 위한 반복문 시작
	while (TRUE)
	{
		// 메시지 큐에 들어온 메시지가 있는지 확인한다.
		if (PeekMessage(&mSg, NULL, 0, 0, PM_NOREMOVE))
		{
			// 만약 메시지가 있으면 MSG 구조체에서 메시지를 읽어온다.
			if (!GetMessage(&mSg, NULL, 0, 0))
				break;	// 메시지 중에 WM_QUIT메시지가 있으면 빠져나간다.
			// 가상키가 발생하면 그 메시지를 받아와서 WM_CHAR에 해당하는 코드를 응용 프로그램의 메시지 큐에 넣어 둔다.
			TranslateMessage(&mSg);
			// 그 메시지들을 처리하기 위해 WndProc() 함수로 보낸다.
			DispatchMessage(&mSg);
		}
	}

	// 기타 부수적인 메시지를 반환한다.
	return mSg.wParam;
}

// 메시지를 처리하기 위해서 메시지 처리 함수를 정의한다.
LRESULT CALLBACK WndProc(HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	// uMsg 변수에는 DispatchMessage() 함수에서 보낸 메시지들이 저장되어 있다.
	switch (uMsg)
	{
		// 키보드의 키가 클릭되면
	case WM_KEYDOWN:
		// 엔터 키가 클릭되면 아래의 소스 코드를 처리한다.
		if (LOWORD(wParam) == VK_RETURN)
		{
			// 엔터 키를 누르면 DrawBlock() 함수를 호출한다.
			PrintFourBlock();
			//InitBackGround();
		}

		return FALSE;
		// uMsg 변수에 WM_DESTROY메시지가 있으면
	case WM_DESTROY:
		PostQuitMessage(0);	// 윈도우를 종료한다.
		return FALSE;
	}
	// 미처 처리하지 못한 메시지들을 WndProc함수로 보내어 확실히 처리되어지도록 한다.
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// 아래의 함수는 사용자 정의 함수로서 블록의 모양을 그린다. 이번 예제에서만 아래의 함수는
// 블록을 그리는 동시에 출력하는 함수로 쓰겠지만 다음 예제부턴 아니다...
void DrawBlock()
{
	// 디바이스 컨텍스트를 정의한다.
	HDC hDC;
	// 윈도우 클라이언트 영역의 디스플레이 디바이스 컨텍스트(DC) 핸들을 구해서 반환한다.
	hDC = GetDC(g_hWnd);

	// 아래 두 반복문은 블록의 값을 검사한다.
	for (row = 0; row < 4; row++) // 행
		for (col = 0; col < 4; col++) // 열
			// 만약 배열의 값이 1이면...
			if (Block[Type][Rotate][row][col] == 1)
			{
				// 블록의 위치를 셋팅 (사각블록 하나의 크기가 10이니 *10 해준다)	//row와col의 위치가 2차원 배열내에 있다고 생각 
																					//만약 *10을 안해주면 겹쳐서 네모가 생성될 것
				x = NowX * 10 + col * 10;											//NowX*10 으로 출력하는 블록의 넓이를 설정하여 안 겹치게함			
				y = NowY * 10 + row * 10;											//NowY*10 으로 출력하는 블록의 높이를 설정하여 안 겹치게함
				// 해당 위치에 해당 크기로(10) 사각형을 출력한다.
				Rectangle(hDC, x, y, x + 10, y + 10);
			}
	/*
		즉 간단하게 생각하면 된다. 블록의 모양을 만들기 위해서 배열의 값이 0이면
		아무 것도 출력하지 않고 1이면 사각형을 출력하여 출력결과 같은 블록을 만드는 것이다.
	*/

}


// 아래의 함수는 블록의 모양을 출력한다.
void PrintFourBlock()
{
	Rotate = 0;
	NowY = 0;
	NowX = 0;
	Type = 0;
	for (int j = 0; j < 7; j++)
	{
		// 다음 종류의 블록을 위하여 변수 초기화
		Rotate = 0;
		NowX = 0;
	// 아래의 for 문은 블록의 회전 모양을 출력하기 위해서 사용된다. 블록의 모양이 총 4가지이므로
	// for문을 4번 호출해야 된다.
		for (int i = 0; i < 4; i++)
		{
			// 블록의 모양을 그리는 함수를 호출한다.
			DrawBlock();
			// Rotate값에 1씩 더해서 블록의 회전 모양을 출력하도록 한다.
			Rotate++;            // 블록의 회전을 위한 값 증가
			// 아래의 값은 블록과 블록 사이의 거리를 위해서 사용되었다.
			NowX = NowX + 5;    // 블록이 서로 안 겹치게 하기 위한 넓이 설정
		}
		// 블록의 종류를 변경 (총 7번 변경된다 따라서 총 블록 28개 출력)
		Type++;
		// 아래의 값은 블록과 블록 사이의 아래로 거리를 위해서 사용되었다.
		NowY = NowY + 5;		// 블록이 서로 안 겹치게 하기 위한 높이 설정
	}
}

// 아래의 함수는 사용자 정의 함수로서 배경 블록의 모양을 초기화한다.
// 이 함수는 함수의 블록이 움직이는 공간을 만들어 주는 것으로 매우 중요하다.
void InitBackGround()
{
	// 아래 두 반복문은 배경 블록의 값을 셋팅한다.
	for (int row = 0; row < 21; row++)
		for (int col = 0; col < 12; col++)
		{
			/*
				row값이 20이면 Background[row][col] 값에 1을 넣는다. 즉 배경의 밑줄을 그려준다.
				그리고 또한 블록을 밑줄 밖으로 벗어나지 못하도록 해야 한다.
			*/
			if (row == 20)
				Background[row][col] = 1;
			/*
				col 값이 0이면 Background[row][col] 값에 1을 넣는다. 즉 배경의 왼쪽 줄을 그려준다.
				그리고 또한 블록을 왼쪽 줄밖으로 벗어나지 못하도록 해야 한다.
			*/
			else if (col == 0)
				Background[row][col] = 1;
			/*
				col 값이 11이면 Background[row][col] 값에 1을 넣는다. 즉 배경의 오른쪽 줄을 그려준다.
				그리고 또한 블록을 오른쪽 줄밖으로 벗어나지 못하도록 해야 한다.
			*/
			else if (col == 11)
				Background[row][col] = 1;
			/*
				위의 if문에 해당하지 않으면 모두 0 값을 넣는다. 0 값이 들어간 곳은 블록이 움직일 공간이다.
				그리고 각각의 줄은 블록이 그 0값인 곳에서만 움직일수 있도록 경계 줄 역할을 한다.
			*/
			else
				Background[row][col] = 0;
		}

	// 이 함수를 이용하여 1이 들어간 곳에 사각형을 출력한다. 즉 경계 줄을 그린다.
	DrawBackGround();
}

// 아래의 함수는 배경 블록의 모양을 그린다. 
void DrawBackGround()
{
	// 디바이스 컨텍스트를 선언 및 
	// 윈도우 클라이언트 영역의 디스플레이 디바이스 컨텍스트(DC) 핸들을 구해서 반환해서 대입..
	HDC hDC = GetDC(g_hWnd);
	int x, y;

	// 아래 두 반복문은 배경 블록의 값을 검사한다.
	for (int row = 0; row < 21; row++) // 행
		for (int col = 0; col < 12; col++) // 열    
			// 만약 배열의 값이 1이면...
			if (Background[row][col] == 1)
			{
				// 배경 블록의 위치를 셋팅 (사각블록 하나의 크기가 10이니 *10 해준다)
				x = col * 10;
				y = row * 10;
				// 해당 위치에 해당 크기로(10) 사각형을 출력한다.
				Rectangle(hDC, x, y, x + 10, y + 10);
			}
}