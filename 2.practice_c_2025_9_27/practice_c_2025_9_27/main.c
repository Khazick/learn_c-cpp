#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int x = 100;

int main()
{
	//1.ע��
	//����
	/* �����ã���ǰ����žͽ�ƥ�� */

	//2.�������� ���䳤��
	printf("%zd\n", sizeof(char));
	printf("%zd\n", sizeof(bool));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(long));
	printf("%zd\n", sizeof(long long));
	int a = 0;
	printf("%zd\n", sizeof(a += 3));//sizeof�ڲ�������
	printf("\n");

	//3. signed/unsigned
	//signed int = int
	int b = 1;
	unsigned c = 1;
	printf("%d\n", b);
	printf("%u\n", c);//unsigned��ӡ��%u
	printf("%d\n", c);
	b = -1;
	c = -1;
	printf("%d\n", b);
	printf("%u\n", c);
	printf("%d\n", c);

	//4.ȫ�ֱ������ֲ�����
	printf("\n");
	int x = 1;
	printf("%d\n", x);//ȫ�ֺ;ֲ�ͬ��ʱ�������þֲ�

	//5.�ӡ������ˡ�����ȡģ
	printf("\n");
	int q = 1;
	int w = 2;
	int e = 0;
	float r = 0.5;
	int t = -2;
	e = q + w;
	printf("%d\n", e);
	printf("%d\n", q+w);
	e = q - w;
	printf("%d\n", e);
	printf("%d\n", q - w);
	e = q * w;
	printf("%d\n", e);
	printf("%d\n", q * w);
	e = q / w;
	printf("%d\n", e);
	printf("%d\n", q / w);
	e = q / r;
	printf("q / r = %d\n", e);//e��int����
	printf("%f\n", q / r);//�� ���� ��������֮һ��һ��������
	e = q % w;//ȡģֻ����������
	printf("%d\n", e);
	printf("%d\n", q % w);
	//printf("%f\n", q % r);������ȡģ�ᱨ��
	printf("%d\n", 3 % t);
	printf("%d\n", -3 % t);//����ȡģ���������ȡ����ȡģ��ߵ����ķ���
	printf("%d\n", 3 % -t);

	//6.��ֵ
	printf("\n");
	e = q + 1;//��ֵ
	e = a = q + 1;//������ֵ
	e = e + a;//���ϸ�ֵ
	e += a;
	e++;//��Ŀ������++��--
	int y = 0;
	printf("%d\n", y++);//����++ ���ú��
	y = 0;
	printf("%d\n", ++y);//ǰ��++ �ȼӺ���

	//7.ǿ������ת��
	int d = (int)3.14;
	printf("%d\n", d);

	return 0;
}
