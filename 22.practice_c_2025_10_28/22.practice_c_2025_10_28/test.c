//�� 1 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������´��룺
//
//struct student
//{
//    int num;
//    char name[32];
//    float score;
//}stu;
//���������������ȷ���ǣ�(D)
//
//��Ŀ���ݣ�
//A .struct �ǽṹ�����͵Ĺؼ���
//B .struct student ���û�����Ľṹ������
//C.num, score ���ǽṹ���Ա��
//D.stu ���û�����Ľṹ��������
// 
//�� 2 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//���������������ǣ���C��
//
//struct stu
//{
//    int num;
//    char name[10];
//    int age;
//};
//
//void fun(struct stu* p)
//{
//    printf("%s\n", (*p).name);
//    return;
//}
//
//int main()
//{
//    struct stu students[3] = { {9801,"zhang",20},
//                             {9802,"wang",19},
//                    {9803,"zhao",18} };
//    fun(students + 1);
//    return 0;
//}
//��Ŀ���ݣ�
//A.zhang
//B.zhao
//C.wang
//D .18
// 
//�� 3 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�ṹ����ʳ�Ա�Ĳ���������������D��
//
//��Ŀ���ݣ�
//A ..������
//B .->������
//C.*�����ò�����
//D .sizeof
// 
//�� 4 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������Ҫ������ṹ���г�Աa������, ���²���������ߴ���������(B)
//
//#include < stdio.h >
//struct S
//{
//    int a;
//    int b;
//};
//int main()
//{
//    struct S a, * p = &a;
//    a.a = 99;
//    printf("%d\n", __________);
//    return 0;
//}
//��Ŀ���ݣ�
//A.a.a
//B.*p.a
//C.p->a
//D .(*p).a

//�� 5 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//��VS2013�£�Ĭ�϶�����Ϊ8�ֽڣ�����ṹ����ռ�Ŀռ��С�ǣ�C���ֽ�
//
//typedef struct {
//    int a;
//    char b;
//    short c;
//    short d;
//}AA_t;
//��Ŀ���ݣ�
//A .16
//B .9
//C .12
//D .8

//�� 6 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//��32λϵͳ����������ѡ��Ϊ4�ֽڶ��룬��ôsizeof(A)��sizeof(B)�� ( C )
//
//struct A
//{
//    int a;
//    short b;
//    int c;
//    char d;
//};
//
//struct B
//{
//    int a;
//    short b;
//    char c;
//    int d;
//};
//��Ŀ���ݣ�
//A .16, 16
//B .13, 12
//C .16, 12
//D .11, 16
// 
//�� 7 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������Ľ���ǣ���A��
//
//#pragma pack(4)/*����ѡ���ʾ4�ֽڶ��� ƽ̨��VS2013�����ԣ�C����*/
////����long ��4���ֽ�
//int main(int argc, char* argv[])
//{
//    struct tagTest1
//    {
//        short a;
//        char d;
//        long b;
//        long c;
//    };
//    struct tagTest2
//    {
//        long b;
//        short c;
//        char d;
//        long a;
//    };
//    struct tagTest3
//    {
//        short c;
//        long b;
//        char d;
//        long a;
//    };
//    struct tagTest1 stT1;
//    struct tagTest2 stT2;
//    struct tagTest3 stT3;
//
//    printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//    return 0;
//}
//#pragma pack()
//��Ŀ���ݣ�
//A .12 12 16
//B .11 11 11
//C .12 11 16
//D .11 11 16

//�� 8 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�����º궨��ͽṹ����
//
//#define MAX_SIZE A+B
//struct _Record_Struct
//{
//    unsigned char Env_Alarm_ID : 4;
//    unsigned char Para1 : 2;
//    unsigned char state;
//    unsigned char avail : 1;
//}*Env_Alarm_Record;
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc( sizeof(struct _Record_Struct ) * MAX_SIZE);
//��A = 2�� B = 3ʱ��pointer���䣨 D �����ֽڵĿռ䡣
//
//��Ŀ���ݣ�
//A .20
//B .15
//C .11
//D .9
//������sizeof(struct _Record_Struct) * MAX_SIZE��������ʵ��3*2+3

//�� 9 �⣨��ѡ�⣩
//��Ŀ���ƣ�
//�������Ľ���ǣ� B ��
//
//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}
//��Ŀ���ݣ�
//A .02 03 04 05
//B .02 29 00 00
//C .02 25 00 00
//D .02 29 04 00
