#include <stdio.h>

struct student 
{
	char *name;
	char *addr;
	unsigned grade;
	unsigned id;
	unsigned class;
};

//static void get_stu_message(struct student *stu);
static void get_stu_message(struct student *);/* 函数声明时，如果参数为结构体类型指针，可以省略后面的变量定义。但是函数定义时不能省略 */

int main(void)
{
	struct student stu = {
		.name = "hds",
		.addr = "xianchina",
		.grade = 2,
		.id = 1903210069,
		.class = 1903
	};

	struct student *ptr = &stu;

	/* 使用指向结构体的指针访问结构体的成员，使用->运算符 */
	get_stu_message(ptr);

	return 0;
}

static void get_stu_message(struct student *stu)
{
	printf("Get name...:%s\n", stu->name);
	printf("Get addr...:%s\n", stu->addr);
	printf("Get grade...:%u\n", stu->grade);
	printf("Get id...:%u\n", stu->id);
	printf("Get class...:%u\n", stu->class);
}
