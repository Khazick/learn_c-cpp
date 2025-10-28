//第 1 题（单选题）
//题目名称：
//如有以下代码：
//
//struct student
//{
//    int num;
//    char name[32];
//    float score;
//}stu;
//则下面的叙述不正确的是：(D)
//
//题目内容：
//A .struct 是结构体类型的关键字
//B .struct student 是用户定义的结构体类型
//C.num, score 都是结构体成员名
//D.stu 是用户定义的结构体类型名
// 
//第 2 题（单选题）
//题目名称：
//下面程序的输出结果是：（C）
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
//题目内容：
//A.zhang
//B.zhao
//C.wang
//D .18
// 
//第 3 题（单选题）
//题目名称：
//结构体访问成员的操作符不包含：（D）
//
//题目内容：
//A ..操作符
//B .->操作符
//C.*解引用操作符
//D .sizeof
// 
//第 4 题（单选题）
//题目名称：
//下面程序要求输出结构体中成员a的数据, 以下不能填入横线处的内容是(B)
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
//题目内容：
//A.a.a
//B.*p.a
//C.p->a
//D .(*p).a

//第 5 题（单选题）
//题目名称：
//在VS2013下，默认对齐数为8字节，这个结构体所占的空间大小是（C）字节
//
//typedef struct {
//    int a;
//    char b;
//    short c;
//    short d;
//}AA_t;
//题目内容：
//A .16
//B .9
//C .12
//D .8

//第 6 题（单选题）
//题目名称：
//在32位系统环境，编译选项为4字节对齐，那么sizeof(A)和sizeof(B)是 ( C )
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
//题目内容：
//A .16, 16
//B .13, 12
//C .16, 12
//D .11, 16
// 
//第 7 题（单选题）
//题目名称：
//下面代码的结果是：（A）
//
//#pragma pack(4)/*编译选项，表示4字节对齐 平台：VS2013。语言：C语言*/
////假设long 是4个字节
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
//题目内容：
//A .12 12 16
//B .11 11 11
//C .12 11 16
//D .11 11 16

//第 8 题（单选题）
//题目名称：
//有如下宏定义和结构定义
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
//当A = 2， B = 3时，pointer分配（ D ）个字节的空间。
//
//题目内容：
//A .20
//B .15
//C .11
//D .9
//解析：sizeof(struct _Record_Struct) * MAX_SIZE这个语句其实是3*2+3

//第 9 题（单选题）
//题目名称：
//下面代码的结果是（ B ）
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
//题目内容：
//A .02 03 04 05
//B .02 29 00 00
//C .02 25 00 00
//D .02 29 04 00
