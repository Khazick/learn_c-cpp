#include"game.h"
//��������
void guess_game(int r, int level) {
	int guess = 0;
	int count = level;
	while (count >= 0) {
		scanf("%d", &guess);
		if (guess < r) {
			printf("��С��,�㻹��%d�λ���\n", count);
		}
		else if (guess > r) {
			printf("�´���,�㻹��%d�λ���\n", count);
		}
		else {
			win_interface(r);
			break;
		}
		count--;
	}
	if (count < 0) {
		lose_interface(r);
	}
}
//��Ϸ
void game() {
	int input = 0;
	int input2 = 0;
	int a = 1;
	int level = 0;
	do {
	start:
		//��Ϸ�˵�			
		a = 1;
		menu();
		//�����
		int r = rand() % 100 + 1;
		printf("����ѡ���ţ�");
		scanf("%d", &input);
		//�˵�ѡ��
		switch (input) {
		case 1:
		level_start:
			difficulty();
			printf("��ѡ���Ѷȣ�\n");
			scanf("%d", &input2);
			switch (input2) {
			case 1:
				level = 30;
				break;
			case 2:
				level = 15;
				break;
			case 3:
				level = 7;
				break;
			default:
				system("cls");
				printf("�������\n");
				goto level_start;
			}
			printf("��ʼ��������Ϸ\n�����ַ�Χ��0~100��\n���������֣�\n");
			guess_game(r, level);
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			system("cls");
			printf("�������\n");
			goto start;
		}
	} while (input - 2);
}