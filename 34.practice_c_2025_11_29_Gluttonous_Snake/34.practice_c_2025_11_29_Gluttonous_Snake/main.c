#include "snake.h"

//完成游戏的测试逻辑
char readYNInput() {
    char ch;
    int temp;

    while (1) {
        // 步骤1：清空缓冲区所有残留字符（包括输入法的冗余字符、多次回车）
        while ((temp = getchar()) != '\n' && temp != EOF);

        // 步骤2：提示用户输入（明确引导直接按 Y/N，无需拼音）
        SetPos(0, 28);
        printf("重新开始请按 Y/y，退出请按 N/n（建议切换英文输入法直接按键）：");
        fflush(stdout);  // 确保提示语立即显示（避免缓冲）

        // 步骤3：读取一个字符，过滤非字母字符
        ch = getchar();
        // 若读取的是字母，转为大写判断；否则重新读取
        if (isalpha(ch)) {
            ch = toupper(ch);  // 转为大写，统一判断
            if (ch == 'Y' || ch == 'N') {
                // 步骤4：读取后再次清空缓冲区（处理用户可能的额外输入/回车）
                while ((temp = getchar()) != '\n' && temp != EOF);
                return ch;  // 返回有效输入
            }
        }

        // 步骤5：输入无效，提示并重试
        SetPos(0, 29);
        printf("输入无效！请直接按 Y 或 N 键（无需拼音输入），按回车确认...");
        fflush(stdout);
        // 等待用户按回车（避免提示语一闪而过）
        while ((temp = getchar()) != '\n' && temp != EOF);
        SetPos(0, 29);
        printf("                                                              ");  // 清空提示行
    }
}
void test_game() {
	srand((unsigned int)time(NULL));
	char ch;
	do {
		system("cls");
		//设置本地环境
		setlocale(LC_ALL, "");
		//创建贪吃蛇
		Snake snake = { 0 };
		//初始化游戏
		game_start(&snake);
		//运行游戏
		game_run(&snake);
		//结束游戏-善后工作
		game_end(&snake);

		SetPos(0, 28);
		printf("重新开始（Y/N）");
        ch = readYNInput();
	} while (ch == 'Y' );
	system("cls");
}

int main() {
	test_game();
	return 0;
}