//�� 1 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//������������������������ȷ���ǣ�A��
//
//int main()
//{
//	int arr[10] = { 0 };
//	return 0;
//}
//��Ŀ���ݣ�
//A.������arr��& arr��һ����
//B .sizeof(arr)��arr��ʾ��������
//C .& arr��arr��ʾ��������
//D.����sizeof(arr)��& arr�е��������������ط����ֵ�������arr������������Ԫ�صĵ�ַ��
// 
//�� 2 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�����ĸ������Ǵ���ģ�(D)
//
//#include <stdio.h>
//int main()
//{
//	int* p = NULL;
//	int arr[10] = { 0 };
//	return 0;
//}
//��Ŀ���ݣ�
//A.p = arr;
//B .int(*ptr)[10] = &arr;
//C.p = &arr[0];
//D.p = &arr;
//
//�� 5 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//���ڶ���ָ������������ȷ���ǣ���B��
//
//��Ŀ���ݣ�
//A.����ָ��Ҳ��ָ�룬ֻ������һ��ָ�����
//B.����ָ��Ҳ��ָ�룬����������һ��ָ��ĵ�ַ
//C.����ָ���������������ĵ�ַ
//D.����ָ��Ĵ�С��4���ֽ�
// 
//�� 6 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//��ζ���һ��int���͵�ָ�����飬����Ԫ�ظ���Ϊ10����(C)
//
//��Ŀ���ݣ�
//A .int a[10]
//B .int(*a)[10]
//C .int* a[10];
//D .int (*a[10])(int);
// 
//�� 7 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�����ĸ���ָ�����飺��A��
//
//��Ŀ���ݣ�
//A . int* arr[10];
//B .int* arr[];
//C .int** arr;
//D .int(*arr)[10];
// 
//�� 8 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������"ָ��"����������ȷ���ǣ��� A ��
//
//��Ŀ���ݣ�
//A.��ʹ��free�ͷŵ�һ��ָ�����ݺ�, ָ�������ֵ����ΪNULL
//B .32λϵͳ���κ�����ָ��ĳ��ȶ���4���ֽ�
//C.ָ�������������������ָ��ʵ��ָ�����ݵ���������
//D.Ұָ����ָ��δ��������Ѿ��ͷŵ��ڴ��ַ
// 
//�� 9 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�����������������ȷ���ǣ���C��
//
//char* p = "hello bit";
//
//��Ŀ���ݣ�
//A.���ַ���hello bit�����p������
//B.���ַ���hello bit�ĵ�һ���ַ������p������
//C.���ַ���hello bit�ĵ�һ���ַ��ĵ�ַ�����p������
//D.*p�ȼ���hello bit
// 
//�� 10 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//��������ִ�н���ǣ�C��
//
//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	char* str3 = "hello bit.";
//	char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}
//��Ŀ���ݣ�
//A.str1 and str2 are same str3 and str4 are same
//B.str1 and str2 are same str3 and str4 are not same
//C.str1 and str2 are not same str3 and str4 are same
//D.str1 and str2 are not same str3 and str4 are not same
