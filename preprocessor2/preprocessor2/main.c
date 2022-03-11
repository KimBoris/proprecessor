#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//#include "Test.h"
//
////int main()
////{
////	TestFunc(10);
////
////	return 0;
////}
////매크로 함수 실제 정의(단, 함수는 아니다)
//#define ADD(a,b) (a+b)
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	//Add()함수를 호출하고 반환 결과를 출력한다.
//	printf("%d\n", Add(3, 4));//함수가 맞음
//
//	//ADD()매크로를 '실행'하고 결과를 출력
//	printf("%d\n", ADD(3, 4)); //함수가 아님 
//
//	//매크로 함수에 괄호가 있는 이유 (a+b)
//	//만약 괄호가 없다면
//	// printf("%d" , ADD(3,4) * 2); > 11이 나온다
//	// 3 + 4 * 2 = 11 이기 때문에 연산자 오류를 생각하여 매크로 함수를 만들어야 한다.
//
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////

//a를 문자열 "a"로 변경하는 매크로 정의
#define STRING(a) #a

//a와 b를 합쳐 하나로 붙여주는 매크로 정의
#define PASTER(a, b) a##b


int main(void)
{
	int nData = 10;

	//PASTER(nDa, ta)는 그냥 nData라고 쓴 것과 같다.
	printf("%d\n", PASTER(nDa, ta));
	printf("%d\n", nData);

	printf("%s\n", STRING(nData));

}