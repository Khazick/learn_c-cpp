#include "game.h"


//��ʼ��ɨ������
void init_mine(char mine[99][99], int rows, int cols,char set) {
	for (int i = 0;i < rows;i++){
		for (int j = 0;j < cols;j++) {
			mine[i][j] = set;
		}
	}
}

void mine_number(int d) {
	printf("|--------------------------|\n");
	printf("|     ****************     |\n");
	printf("|     * һ����%d���� *     |\n", d);
	printf("|     ****************     |\n");
	printf("|--------------------------|\n");
}
//��ӡɨ������
void print_mine(char mine[99][99],int row,int col) {
	for (int i = 0;i <= 4 + col * 6;i++) {
		printf("-");
	}
	printf("\n| 0 | ");
	for (int i = 1;i <= col;i++) {
		printf("|%2d | ", i);
	}
	printf("\n");
	for (int i = 0;i <= 4 + col * 6;i++) {
		printf("-");
	}
	for (int i = 1;i <= row;i++) {	
		printf("\n");
		for (int j = 0;j <= col;j++) {
			if(j==0)
				printf("|%2d | ", i);
			else
				printf("|%2c | ", mine[i][j]);
		}
		printf("\n");
		for (int j = 0;j <= 4 + col * 6;j++) {
			printf("-");
		}
	}
	printf("\n");
}

void set_mine(char mine[99][99], int row, int col,int d) {
	int count = d;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] != '1'){
			mine[x][y] = '1';
			count--;
		}		
	}
}

//ɨ��3*3��Χ�ڵĵ�������
int get_mine_number(char mine[99][99], int x, int y) {
	int count = 0;
	for (int i = -1;i <= 1;i++) {
		for (int j = -1;j <= 1;j++) {
			if (mine[x + i][y + j] == '1')
				count += mine[x + i][y + j] - '0';
		}
	}
	return count;
}
void find_mine(char mine[99][99], char board[99][99],int row, int col,int d) {	
	int x = 0;
	int y = 0;
	int z = 0;
	int flag = 1;
	int find = 0;//�����
	int win = row * col - d;

	//��¼��ʼʱ��
	clock_t st = clock();
	while (win) {
	up:
		system("cls");
		print_mine(board, row, col);
		//print_mine(mine, row, col);	
		mine_number(d);
		printf("|--------------------------|\n");
		printf("|     ( x , y , ���� )     |\n");
		printf("|     ��������1���ų�      |\n|     ��������2�����      |\n|     ��������3��ȡ�����  |\n");
		printf("|     ����������ɨ�ף�     |\n");

		scanf("%d%*c%d%*c%d", &x, &y, &z);
		switch (z) {
		case 1:
			if (mine[x][y] == '1')
			{
				system("cls");
				print_mine(mine, row, col);
				printf("��Ϸʧ�ܣ�\n");
				flag = 0;
				break;
			}
			else {
				win--;
				board[x][y] = get_mine_number(mine, x, y) + '0';
				system("cls");			
			}
			break;
		//ʵ�ֱ�Ǻ�ȡ�����
		case 2:
			board[x][y] = '#';
			if (mine[x][y] == '1')
				find++;
			if (find == d)
				flag = 0;
			break;
		case 3:
			board[x][y] = '*';
			if (mine[x][y] == '1')
				find--;
			break;
		default:
			goto up;
			break;
		}

		if (flag == 0)
			break;
	}
	if (win == 0||find == d) {
		system("cls");
		print_mine(mine, row, col,d);
		printf("��Ϸʤ����\n");
		//��¼����ʱ��
		clock_t ed = clock();
		//��ӡ����ʱ��
		printf("��ʱ��%d��\n", ((int)(ed - st)) / CLOCKS_PER_SEC);
	}
}

void game(int d) {
	system("cls");
	srand((signed int)time(NULL));
	//����ɨ������
	char mine_outside[99][99];
	char mine_inside[99][99];

	//��ʼ��ɨ������
	init_mine(mine_outside,99,99,'*');
	init_mine(mine_inside,99,99,'0');

	int ROW = 0;
	int COL = 0;
	if (d == EAZY)
		ROW = COL = 9;
	else if (d == NORMAL)
		ROW = COL = 16;
	else {
		ROW = 30;
		COL = 16;
	}
	//��ӡ���ױ�����
	print_mine(mine_outside, ROW, COL);

	//���õ���
	set_mine(mine_inside, ROW, COL, d);

	//��ӡ����������
	//print_mine(mine_inside, ROW, COL);

	//�Ų����
	find_mine(mine_inside, mine_outside, ROW, COL, d);

}