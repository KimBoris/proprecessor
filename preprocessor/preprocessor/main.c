#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Test.h"



//<전처리기>

//컴파일러가 소스코드를 컴파일하기에 앞서 선행처리하는 구문
// ->모든 C언어 컴파일러들은 전처리기로 정의된 것들을 소스코드에 반영한 후 컴파일

//전처리기란?
//'컴파일 전'처리
//무엇을 처리하나? > 코드를 변형(변경)시킨다.
//1. User가 작성한 코드,2. 편집기 찾기+바꾸기 

//즉, 컴파일전 처리 = 코드를 변형(변경)하는 것을 말한다. 

//->CPU의 연산과는 아무런 관련이 없다.
//오직, 컴파일러에 의해서만 일어나는 로직
//따라서, 컴파일타임에만 작동

//<헤더 '~.h'> ->선언이 들어있다.
// '<>' = 브라켓 
//ex) #include <~.h>   ->컴파일러 설정의 시스템 디렉토리에서 파일을 찾는다.
//ex) #include "~.h"   ->현재 폴더에서 찾는다.

//헤더 파일은 무조건 말머리에 #pragma once를 적어줘야 한다.

//ex)

//main.c 파일에는 
// main()실행함수
//#include "Test.h" 를 선언해줘야한다. printf()함수를 사용하기 위해
//#include <stdio.h>도 선언.


//Test.h 파일 - 선언
//void TestFunc(int nParam);

//Test.c 파일 - 정의
//void TestFunc(int nParam)
//printf("Test"); 


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//<매크로>
// 실제로는 함수가 아니라 한 행 혹은 여러행으로 기술할 수 있는 구문 (혹은 항)
// 코드 중 불연속적으로 반복되는 것을 함수로 만든다.


//매크로는 왜 사용하는가?
// 함수가 함수를 호출하게 되면
//스택이 쌓이는는데 ( 매개변수가 있다면 또 써줘야 하겠지) )

//Call Overhead = 함수를 호출하는데 드는 비용


//*비용의 증가 = 
//1. 스택의 증가 = 제어(흐름)와 관련된 어떤 내용도 변화가 온다.
//2. 매개변수의 복사양이 많아진다면 = 복사할 때 코드도 많이 증가한다.
//따라서, 함수 설계시 덩치 큰 구조체를 매개변수로 주는것은 그리 좋은 방법이 아니다.


//코드조각 -> 함수
// 함수 -> 1. 유지보수와
//      -> 2. 구조를 해서 만든다.
// 함수를 만드는 이유 = 코드 조각의 내용이 너무 작고 자주 호출될 때 = 매크로를 사용한다. 
// 매크로는 최대한 사용을 자제한다. 

//So, 매크로가 아닌 대안 = __inline함수를 사용 > __inline함수로 불가능한 것들만 매크로를 사용한다.




//예시)
//macro01.c

#include <stdio.h>

//캐므로 함수 정의. 단, 실제 함수는 아니다.
#define ADD(a,b) (a+b)   

//사용자 정의 함수 선언 및 정의
int Add(int a, int b)
{
	return a + b;
}

int main(void)
{
	//Add()함수를 호출하고 반환 결과를 출력한다.
	printf("%d\n", Add(3, 4));

	//ADD()배크로를 '실행'하고 결과를 출력한다.
	printf("%d\n", ADD(3, 4));
	return 0;
}
/*(ex)
#define Add(a,b) (a+b)

int main(void)
{
printf("%d", ADD(3,4)); -> 이게 함수라면 함수를 넘겨받아서 결과를 찍어넣는다.
						-> 함수처럼 생겼지만 실제로는 함수가 전혀 아니다.
						-> 함수 호출에 대한 overhead가 전혀 없는 코드가 된다.

printf("%d", a+b);
					->함수가 아니라면 결과를 바로 찍어낸다.
*/





//int main(void)
//{
//
//
//
//
//
//
//	TestFunc(10);
//	/*
//	$(VC_IncludePath); - Visual Studio - ProgramFiles\microsoft\vc\include 에 있다.
//	stdio.h 등 헤더파일들을 메모리로 열어볼 수 있다. 
//
//
//	$(WindowsSDK_IncludePath);
//	*/
//	
//
//
//	//__inline 함수
//	 
//
//	return 0;
//}





//<매크로 특수 연산자>

/*
1. #
//a를 "a"(문자열)로 변경하는 매크로 정의
#define STRING(a) #a

2. a와 b를 합쳐 하나로 붙여주는 매크로 정의
#define PASTER(a, b) a##b

ex)
int main(void)
{
int nData = 10;

//PASTER(nDa, ta) 는 그냥 'nData'라고 쓴것과 같다.
printf("%d\n", PASTER(nDa,ta));  = 10
printf("%d\n", nData);  = 10

//"nData"로 처리된다.
printf("%s\n", STRING(nData));   = "nData"
return 0;



2. ##


*/



//<조건부 컴파일>

//상수 정의에 따라 실제로 번역되는 소스코드가 달라지도록 구성하는 것
//#if XXX, #else, #endif 이렇게 3가지가 있다.


//(ex)
//conditional01.c

/*
_MSGTEST_ 상수 정의가 됐는가 그렇지 않은가에 따라
MYMESSAGE 정의는 달라진다!


#ifdef _MSGTEST_    >> #define _MSGTEST_라고 기술하면  참 값이 나온다.
#define MYMESSAGE "I am a boy"
#else
#define MYMESSAGE "You are a girl"
#endif

int main(void)
{
_MSGTEST_상수가 정의 된 경우와 그렇지 않은 경우 출력되는 문자열이 달라진다.

puts(MYMESSAGE);
return 0;


*/


//PreCondition03.c

/*
#define MYUNICODE // 선언  > 1. MYUNICODE상수 정의, 실제 값을 정의할 목적이 아니라
							단지 상수가 정의되었음을 컴파일러에 알리기 위한것




#ifdef MYUNICODE		//상수가 정의되었는지 비교하는 전처리기
	typedef wchar_t TCHAR;	//TCHAR = wchar_t형이 된다.
	#define _T(string) L##string //_T() 매크로 정의, 인자로 전달된 문자열 상수를 유니코드 문자열 상수로 만든다.
	#define PRINT wprintf		 //wprintf = PRINT로 정의


#else				//전처리기 조건에 만족하지 못했을 경우
								//MYUNICODE 상수가 정의되지 않은 경우 컴파일될 소스코드, 위의 행과 달리
								//MBCS형식에 맞춘 정보들을 정의한다.
	typedef char TCHAR;
	#define _T(string) string
	#define PRINT printf
#endif

void main()
{
	TCHAR szData[16] = _t("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%d, %d\n"), sizeof(TCHAR), sizeof(szData));
}

 >>실행 결과
 Test string
 2, 32
*/





//<빌드 모드 선택>
/*
1. 디버그 모드
2. 릴리즈 모드 

<예시> = 실제 개발자들이 프로그램을 디버깅 할 때 많이 사용하는 코드이다.
이런 조건부 컴파일 전처리기를 구성하여 두가지 코드를 작성하여ㅍ
디버그 모드일 땐 개발자용 메세지
릴리즈 모드일 땐 일반 사용자가 보는 메세지를 출력할 수 있다.

빌드 모드를 판별하여 상수 정의가 달라지도록 조건부 컴파일을 시도한 프로그램
'_DEBUG' 상수가 정의되었는지 확인하는 방법으로 빌드모드 판단할 수 있다.


#include <stdio.h>

#ifdef _DEBUG
	#define MODEMESSAGE "Debug mode"
#else 
	#define MODEMESSAGE "Release mode"
#endif

int main(void)
{
	puts(MODEMESSAGE);
	return 0;
}


*/
//__inline 함수 
//함수와 매크로의 장점을 모아놓은것 
//매크로는 특수한 연산자 #, ##등을 사용할 때
//즉, 함수처럼 생긴것을 한 구문으로 만드는 것
ㄴ