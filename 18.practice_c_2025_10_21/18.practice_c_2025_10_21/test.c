//�� 1 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//���������print_arr������������ĸ�����ȷ�ģ���C��
//
//int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//print_arr(arr, 3, 5);
//��Ŀ���ݣ�
//A .void print_arr(int arr[][], int row, int col);
//B .void print_arr(int* arr, int row, int col);
//C .void print_arr(int(*arr)[5], int row, int col);
//D .void print_arr(int(*arr)[3], int row, int col);
// 
//�� 2 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//����test���������ȷ���ǣ��� BD ��
//
//char* arr[5] = { "hello", "bit" };
//
//test(arr);
//
//��Ŀ���ݣ�
//A .void test(char* arr);
//B .void test(char** arr);
//C .void test(char arr[5]);
//D .void test(char* arr[5]);
//�� 3 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������Ľ���ǣ���B��
//
//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//��Ŀ���ݣ�
//A .5, 1
//B .4, 1
//C .4, 2
//D .5, 2
//�� 4 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������Ľ���ǣ���A��
//
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//��Ŀ���ݣ�
//A .1, 6
//B .10, 5
//C .10, 1
//D .1, 5