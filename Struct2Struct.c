/**********************************************************************
* 版权所有 (C)2015, Zhou Zhaoxiong。
*
* 文件名称：Struct2Struct.c
* 文件标识：无
* 内容摘要：结构体变量之间的赋值
* 其它说明：无
* 当前版本：V1.0
* 作    者：Zhou Zhaoxiong
* 完成日期：20150227
*
**********************************************************************/
#include <stdio.h>
#include <string.h>
 
 
// 重定义数据类型
typedef unsigned char UINT8;
typedef unsigned int  UINT32;
typedef signed   int  INT32;
 
// 定义结构体
typedef struct
{
   UINT8   szName[100];   // 姓名
   UINT32  iAge;          // 年龄
   UINT8   szId[100];     // 工号
} T_EmployeeInfo;
 
 
/**********************************************************************
* 功能描述：主函数
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期      版本号      修改人            修改内容
* -------------------------------------------------------------------
* 20150227       V1.0     Zhou Zhaoxiong        创建
***********************************************************************/
INT32 main()
{
    T_EmployeeInfo tEmployeeInfoSrc    = {0};      // 源消息结构体
    T_EmployeeInfo *ptEmployeeInfoDest = NULL;     // 目的消息结构体
    T_EmployeeInfo *ptEmployeeInfoMid  = NULL;     // 中间消息结构体
 
    // 手动输入源消息
    printf("Please input the source info: \n");
    printf("Name: \n");
    scanf("%s", tEmployeeInfoSrc.szName);
    printf("Age: \n");
    scanf("%d", &(tEmployeeInfoSrc.iAge));
    printf("Id: \n");
    scanf("%s", tEmployeeInfoSrc.szId);
 
    // 将源消息赋给目的消息结构体
    ptEmployeeInfoDest = &tEmployeeInfoSrc;   // 指针 = &变量
    // 打印目的消息结构体中的各个变量的值
    printf("The dest info is: Name=%s, Age=%d, Id=%s\n", ptEmployeeInfoDest->szName, ptEmployeeInfoDest->iAge, ptEmployeeInfoDest->szId);
 
    // 将目的消息赋给中间消息结构体
    ptEmployeeInfoMid = ptEmployeeInfoDest;   // 指针 = 指针
    // 打印中间消息结构体中的各个变量的值
    printf("The mid info is: Name=%s, Age=%d, Id=%s\n", ptEmployeeInfoMid->szName, ptEmployeeInfoMid->iAge, ptEmployeeInfoMid->szId);
 
    // 改变目的消息结构体中的某个变量的值
    ptEmployeeInfoDest->iAge = ptEmployeeInfoDest->iAge + 1;
 
    // 将目的消息赋给源消息结构体
    memcpy(&tEmployeeInfoSrc, ptEmployeeInfoDest, sizeof(T_EmployeeInfo)); // memcpy(&变量, 指针, 长度)
    // 打印源消息结构体中的各个变量的值
    printf("The source info is: Name=%s, Age=%d, Id=%s\n", tEmployeeInfoSrc.szName, tEmployeeInfoSrc.iAge, tEmployeeInfoSrc.szId);
 
    return 0;
}
