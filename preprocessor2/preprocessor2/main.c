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
////��ũ�� �Լ� ���� ����(��, �Լ��� �ƴϴ�)
//#define ADD(a,b) (a+b)
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	//Add()�Լ��� ȣ���ϰ� ��ȯ ����� ����Ѵ�.
//	printf("%d\n", Add(3, 4));//�Լ��� ����
//
//	//ADD()��ũ�θ� '����'�ϰ� ����� ���
//	printf("%d\n", ADD(3, 4)); //�Լ��� �ƴ� 
//
//	//��ũ�� �Լ��� ��ȣ�� �ִ� ���� (a+b)
//	//���� ��ȣ�� ���ٸ�
//	// printf("%d" , ADD(3,4) * 2); > 11�� ���´�
//	// 3 + 4 * 2 = 11 �̱� ������ ������ ������ �����Ͽ� ��ũ�� �Լ��� ������ �Ѵ�.
//
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////

//a�� ���ڿ� "a"�� �����ϴ� ��ũ�� ����
#define STRING(a) #a

//a�� b�� ���� �ϳ��� �ٿ��ִ� ��ũ�� ����
#define PASTER(a, b) a##b


int main(void)
{
	int nData = 10;

	//PASTER(nDa, ta)�� �׳� nData��� �� �Ͱ� ����.
	printf("%d\n", PASTER(nDa, ta));
	printf("%d\n", nData);

	printf("%s\n", STRING(nData));

}