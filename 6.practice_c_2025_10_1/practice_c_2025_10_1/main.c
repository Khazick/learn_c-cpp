#include "arr01.h" //���ļ���ʹ���Զ���ͷ�ļ�����˫���Ŷ����Ǽ�����

//�� 6 �⣨����⣩
//��Ŀ���ƣ�
//���ֲ��� - ����ʵ��
//��Ŀ���ݣ�
//дһ�����ֲ��Һ���
//���ܣ���һ�����������в���ָ������ֵ���ҵ��˾ͷ����±꣬�Ҳ����ͷ��� - 1.
//int bin_search(int arr[], int left, int right, int key)
//// arr �ǲ��ҵ�����
////left ��������±�
////right ��������±�
////key Ҫ���ҵ�����
int bin_search(int arr[], int left, int right, int key) {//�β���ʵ�ε���ʱ����
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main1() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 0;
	scanf("%d", &key);
	int ret = bin_search(arr, left, right, key);
	printf("%d\n", ret);
	return 0;
}
//
//�� 7 �⣨����⣩
//��Ŀ���ƣ�
//�˷��ھ���
//��Ŀ���ݣ�
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
void multiplication_table(int input) {
	for (int i = 1;i <= input;i++) {
		for (int j = 1;j <= i;j++)
			printf("%3d*%-3d=%3d ", j, i, i * j);
		printf("\n");
	}
}
int main2() {
	int input = 0;
	scanf("%d", &input);
	multiplication_table(input);
	return 0;
}

//�� 8 �⣨����⣩
//��Ŀ���ƣ�
//�����ж�����
//��Ŀ���ݣ�
//ʵ�ֺ����ж�year�ǲ������ꡣ
int leap_year(int y) {
	return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) ? 1 : 0;//return����Ը���ֵ��Ҳ���Ը����ʽ��ֻ����void����ʱ������ʲô������
}
void is_leap_year(int x,int y) {
	if (x > 0)
		printf("%d�������ꡣ\n", y);
	else
		printf("%d�겻�����ꡣ\n", y);
}
int main3() {
	int year = 0;
	scanf("%d", &year);
	is_leap_year(leap_year(year),year);//��ʽ���ʣ���һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
	return 0;
}

//�� 9 �⣨����⣩
//��Ŀ���ƣ�
//�����ж�����
//��Ŀ���ݣ�
//ʵ��һ������is_prime���ж�һ�����ǲ���������
//
//��������ʵ�ֵ�is_prime��������ӡ100��200֮���������
bool is_prime(int x) {
	int flag = 1;
	for (int i = 2;i < x;i++) {
		if (x % i == 0) {
			flag = 0;
			break;
		}
	}
	if(flag == 1)
		return true;//return ִ�к� ���������׷��أ��������벻��ִ��
	return false;//return����if����У���Ҫ��ÿ�����������һ������ֵ������ᱨ��
}
int main4() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = n;i <= m;i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}
	return 0;
}
//�𰸲ο���ע�⣺ʹ��sqrt������1-10�������޷��ж�
int is_prime1(int n){
	int i = 0;
	for (i = 2; i <= sqrt(n); i++){
		if (0 == n % i){
			return 0;
		}
	}
	return 1;
}
int main04()
{
	int i = 0;
	for (i = 100; i <= 200; i++) {
		if (is_prime1(i) == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}

//�� 10 �⣨����⣩
//��Ŀ���ƣ�
//ʹ�ú���ʵ���������
//��Ŀ���ݣ�
//����һ���������飬��ɶ�����Ĳ���
//
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��

void init(int arr[], int n) {//�β���һά���飬�����С���Բ������Ƕ�ά���飬�п���ʡ���в�����ʡ
	for (int i = 0;i < n; i++)
		arr[i] = 0;//�βκ�ʵ�ε�������ͬһ�����飬�β������޸Ļ�Ӱ��ʵ������
}
void print(int arr[],int n) {//�������������壬�������main���潫�ᱨ��
	for (int i = 0;i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void scan(int arr[], int n);//��������֮ǰ��һ�������������Ķ�����һ�����������

void reverse(int arr[],int n) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main05() {
	arr_01();//���ļ�ʹ��
	return 0;
}

void scan(int arr[], int n) {//����������˵���ᱨ��
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
}

//static �� extern
extern void printMessage();// �����ⲿ����/����

int main() {
	static int a = 0;//�������ξֲ�/ȫ�ֱ���/������ʹ���Ϊ��̬
	// �����ⲿ����
	printMessage();
	return 0;
}