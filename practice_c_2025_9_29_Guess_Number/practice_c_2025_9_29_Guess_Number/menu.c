#include"game.h"
//�˵�
void menu() {

	printf(" ------------------------ \n");
	printf(" |   Guess Number Game  | \n");
	printf(" |~~~~~~~~~~~~~~~~~~~~~~| \n");
	printf(" |     1.    play       | \n");
	printf(" |     2.    exit       | \n");
	printf(" ------------------------ \n");
}
//�Ѷ�
void difficulty() {
	system("cls");
	printf(" ------------------------ \n");
	printf(" |   Guess Number Game  | \n");
	printf(" |~~~~~~~~~~~~~~~~~~~~~~| \n");
	printf(" |     1.    easy       | \n");
	printf(" |     2.   normal      | \n");
	printf(" |     3.    hard       | \n");
	printf(" ------------------------ \n");
}
//ʤ��
void win_interface(int r) {
	system("cls");
	printf(" ------------------------ \n");
	printf(" |    ��ϲ��¶���!     |\n");
	printf(" |   ��ȷ�Ĵ�Ϊ:%3d   |\n", r);
	printf(" |      ��Ϸ����!       |\n");
	printf(" ------------------------ \n");
}
//ʧ��
void lose_interface(int r) {
	system("cls");
	printf(" ------------------------ \n");
	printf(" |   �����ľ��������ˣ� |\n");
	printf(" |   ��ȷ�Ĵ�Ϊ:%3d   |\n", r);
	printf(" |      ��Ϸ����!       |\n");
	printf(" ------------------------ \n");
}