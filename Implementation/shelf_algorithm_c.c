#include <stdio.h>
#include <opencv2/opencv.hpp>


// opencv를 이용하여 그림그리는 작업 시행
// 자세한 알고리즘은 Python파일 참조


typedef enum { FALSE, TRUE } TF;

struct box {
	int width;
	int height;
	TF rotation;
};

struct current_point {
	int width;
	int height;
};

void setitem(int * item, int num, struct box * box_list);
void setitem_sort(struct box * box_list, int num, TF up);
void setitem_rotation(struct box * box_list, int num);
void simplefit(struct box* box_list, int num);
void fit(struct box* box_list, int num);

void func_1(void);
void func_2(void);
void func_3(void);
void func_4(void);
void func_5(void);
void func_6(void);

int main() {

	int sel;
	printf("1. nextfit\n");
	printf("2. smaller height first\n");
	printf("3. larger height first_1 \n");
	printf("4. larger height first_2 \n");
	printf("5. rotate\n");
	printf("6. final\n\n");
	printf("1부터 6까지 원하는 연산을 선택하세요 : ");

	scanf_s("%d", &sel, sizeof(int));

	switch (sel) {
	case 1: 
		func_1();
		break;
	case 2:
		func_2();
		break;
	case 3:
		func_3();
		break;
	case 4:
		func_4();
		break;
	case 5:
		func_5();
		break;
	case 6:
		func_6();
		break;
	}


	//int item[] = { 11, 21, 43, 39, 13, 52, 35, 25, 28, 20, 66, 55, 54, 62, 50, 61, 49, 16, 60, 51, 39, 27, 54, 62, 65, 13, 34, 50, 48, 63, 19, 41, 18, 61, 23, 51, 39, 58, 35, 14, 35, 31, 67, 58, 25, 24, 58, 63, 59, 57, 69, 57, 34, 28, 61, 30, 18, 57, 10, 26, 42, 66, 31, 50, 63, 13, 42, 10, 57, 63, 61, 54, 50, 53, 20, 54, 66, 31, 48, 35, 28, 25, 37, 54, 32, 50, 42, 49, 62, 37, 31, 24, 63, 44, 66, 29, 25, 51, 52, 17, 67, 55, 27, 48, 23, 39, 38, 41, 46, 15, 46, 68, 24, 41, 38, 20, 33, 42, 12, 12, 51, 31, 53, 41, 25, 28, 39, 69, 61, 12, 55, 59, 35, 60, 13, 60, 22, 41, 60, 68, 28, 33, 31, 60, 27, 48, 38, 60, 19, 63, 28, 50, 24, 31, 42, 38, 11, 17, 50, 36, 27, 59, 42, 25, 16, 61, 35, 19, 32, 67, 40, 53, 33, 42, 15, 40, 62, 23, 42, 19, 57, 42, 43, 59, 12, 10, 45, 68, 16, 15, 15, 34, 67, 33, 27, 54, 53, 64, 18, 22 };
	//int item[] = {20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6};
	//int item[] = {10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11, 10, 20, 22, 11 };
	//int item[] = { 160, 160, 80, 80, 80, 80, 60, 60, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	//int item[] = {67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11};	

	return 0;
}


void func_1(void) {
	int item[] = { 11, 21, 43, 39, 13, 52, 35, 25, 28, 20, 66, 55, 54, 62, 50, 61, 49, 16, 60, 51, 39, 27, 54, 62, 65, 13, 34, 50, 48, 63, 19, 41, 18, 61, 23, 51, 39, 58, 35, 14, 35, 31, 67, 58, 25, 24, 58, 63, 59, 57, 69, 57, 34, 28, 61, 30, 18, 57, 10, 26, 42, 66, 31, 50, 63, 13, 42, 10, 57, 63, 61, 54, 50, 53, 20, 54, 66, 31, 48, 35, 28, 25, 37, 54, 32, 50, 42, 49, 62, 37, 31, 24, 63, 44, 66, 29, 25, 51, 52, 17, 67, 55, 27, 48, 23, 39, 38, 41, 46, 15, 46, 68, 24, 41, 38, 20, 33, 42, 12, 12, 51, 31, 53, 41, 25, 28, 39, 69, 61, 12, 55, 59, 35, 60, 13, 60, 22, 41, 60, 68, 28, 33, 31, 60, 27, 48, 38, 60, 19, 63, 28, 50, 24, 31, 42, 38, 11, 17, 50, 36, 27, 59, 42, 25, 16, 61, 35, 19, 32, 67, 40, 53, 33, 42, 15, 40, 62, 23, 42, 19, 57, 42, 43, 59, 12, 10, 45, 68, 16, 15, 15, 34, 67, 33, 27, 54, 53, 64, 18, 22 };
	int num = (sizeof(item) / sizeof(int)) / 2;
	struct box * box_list;
	box_list = (struct box *)malloc(num * sizeof(box));
	if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
		printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
		exit(1);     // 프로그램 종료
	}
	setitem(item, num, box_list);
	simplefit(box_list, num);
	free(box_list);
}

void func_2(void) {
	int item[] = { 11, 21, 43, 39, 13, 52, 35, 25, 28, 20, 66, 55, 54, 62, 50, 61, 49, 16, 60, 51, 39, 27, 54, 62, 65, 13, 34, 50, 48, 63, 19, 41, 18, 61, 23, 51, 39, 58, 35, 14, 35, 31, 67, 58, 25, 24, 58, 63, 59, 57, 69, 57, 34, 28, 61, 30, 18, 57, 10, 26, 42, 66, 31, 50, 63, 13, 42, 10, 57, 63, 61, 54, 50, 53, 20, 54, 66, 31, 48, 35, 28, 25, 37, 54, 32, 50, 42, 49, 62, 37, 31, 24, 63, 44, 66, 29, 25, 51, 52, 17, 67, 55, 27, 48, 23, 39, 38, 41, 46, 15, 46, 68, 24, 41, 38, 20, 33, 42, 12, 12, 51, 31, 53, 41, 25, 28, 39, 69, 61, 12, 55, 59, 35, 60, 13, 60, 22, 41, 60, 68, 28, 33, 31, 60, 27, 48, 38, 60, 19, 63, 28, 50, 24, 31, 42, 38, 11, 17, 50, 36, 27, 59, 42, 25, 16, 61, 35, 19, 32, 67, 40, 53, 33, 42, 15, 40, 62, 23, 42, 19, 57, 42, 43, 59, 12, 10, 45, 68, 16, 15, 15, 34, 67, 33, 27, 54, 53, 64, 18, 22 };
	int num = (sizeof(item) / sizeof(int)) / 2;
	struct box * box_list;
	box_list = (struct box *)malloc(num * sizeof(box));
	if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
		printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
		exit(1);     // 프로그램 종료
	}
	setitem(item, num, box_list);
	setitem_sort(box_list, num, FALSE);
	simplefit(box_list, num);
	free(box_list);
}

void func_3(void) {
	int item[] = { 11, 21, 43, 39, 13, 52, 35, 25, 28, 20, 66, 55, 54, 62, 50, 61, 49, 16, 60, 51, 39, 27, 54, 62, 65, 13, 34, 50, 48, 63, 19, 41, 18, 61, 23, 51, 39, 58, 35, 14, 35, 31, 67, 58, 25, 24, 58, 63, 59, 57, 69, 57, 34, 28, 61, 30, 18, 57, 10, 26, 42, 66, 31, 50, 63, 13, 42, 10, 57, 63, 61, 54, 50, 53, 20, 54, 66, 31, 48, 35, 28, 25, 37, 54, 32, 50, 42, 49, 62, 37, 31, 24, 63, 44, 66, 29, 25, 51, 52, 17, 67, 55, 27, 48, 23, 39, 38, 41, 46, 15, 46, 68, 24, 41, 38, 20, 33, 42, 12, 12, 51, 31, 53, 41, 25, 28, 39, 69, 61, 12, 55, 59, 35, 60, 13, 60, 22, 41, 60, 68, 28, 33, 31, 60, 27, 48, 38, 60, 19, 63, 28, 50, 24, 31, 42, 38, 11, 17, 50, 36, 27, 59, 42, 25, 16, 61, 35, 19, 32, 67, 40, 53, 33, 42, 15, 40, 62, 23, 42, 19, 57, 42, 43, 59, 12, 10, 45, 68, 16, 15, 15, 34, 67, 33, 27, 54, 53, 64, 18, 22 };
	int num = (sizeof(item) / sizeof(int)) / 2;
	struct box * box_list;
	box_list = (struct box *)malloc(num * sizeof(box));
	if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
		printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
		exit(1);     // 프로그램 종료
	}
	setitem(item, num, box_list);
	setitem_sort(box_list, num, TRUE);
	simplefit(box_list, num);
	free(box_list);
}

void func_4(void) {
	int item[] = { 11, 21, 43, 39, 13, 52, 35, 25, 28, 20, 66, 55, 54, 62, 50, 61, 49, 16, 60, 51, 39, 27, 54, 62, 65, 13, 34, 50, 48, 63, 19, 41, 18, 61, 23, 51, 39, 58, 35, 14, 35, 31, 67, 58, 25, 24, 58, 63, 59, 57, 69, 57, 34, 28, 61, 30, 18, 57, 10, 26, 42, 66, 31, 50, 63, 13, 42, 10, 57, 63, 61, 54, 50, 53, 20, 54, 66, 31, 48, 35, 28, 25, 37, 54, 32, 50, 42, 49, 62, 37, 31, 24, 63, 44, 66, 29, 25, 51, 52, 17, 67, 55, 27, 48, 23, 39, 38, 41, 46, 15, 46, 68, 24, 41, 38, 20, 33, 42, 12, 12, 51, 31, 53, 41, 25, 28, 39, 69, 61, 12, 55, 59, 35, 60, 13, 60, 22, 41, 60, 68, 28, 33, 31, 60, 27, 48, 38, 60, 19, 63, 28, 50, 24, 31, 42, 38, 11, 17, 50, 36, 27, 59, 42, 25, 16, 61, 35, 19, 32, 67, 40, 53, 33, 42, 15, 40, 62, 23, 42, 19, 57, 42, 43, 59, 12, 10, 45, 68, 16, 15, 15, 34, 67, 33, 27, 54, 53, 64, 18, 22 };
	int num = (sizeof(item) / sizeof(int)) / 2;
	struct box * box_list;
	box_list = (struct box *)malloc(num * sizeof(box));
	if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
		printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
		exit(1);     // 프로그램 종료
	}
	setitem(item, num, box_list);
	setitem_sort(box_list, num, TRUE);
	fit(box_list, num);
	free(box_list);
}

void func_5(void) {
	int item[] = { 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 67, 75, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11, 50, 11 };
	int num = (sizeof(item) / sizeof(int)) / 2;
	struct box * box_list;
	box_list = (struct box *)malloc(num * sizeof(box));
	if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
		printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
		exit(1);     // 프로그램 종료
	}
	setitem(item, num, box_list);
	setitem_rotation(box_list, num);
	setitem_sort(box_list, num, TRUE);
	fit(box_list, num);
	free(box_list);
}

void func_6(void) {
	int item[] = { 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 20, 40, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 40, 30, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 10, 36, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6, 15, 6 };
	int num = (sizeof(item) / sizeof(int)) / 2;
	struct box * box_list;
	box_list = (struct box *)malloc(num * sizeof(box));
	if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
		printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
		exit(1);     // 프로그램 종료
	}
	setitem(item, num, box_list);
	setitem_rotation(box_list, num);
	setitem_sort(box_list, num, TRUE);
	fit(box_list, num);
	free(box_list);
}


void setitem(int * item, int num, struct box * box_list) {
	
	int i;
	for (i = 0; i < num; i++) {
		box_list[i].width = item[2 * i];
		box_list[i].height = item[2 * i + 1];
		box_list[i].rotation = FALSE; 
	}
}

void setitem_rotation(struct box * box_list, int num) {

	//struct box box_list[100];
	int i;
	int temp;
	for (i = 0; i < num; i++) {
		if (box_list[i].width > box_list[i].height) {
			temp = box_list[i].width;
			box_list[i].width = box_list[i].height;
			box_list[i].height = temp;
			box_list[i].rotation = TRUE;  
		}
	}
}

void setitem_sort(struct box * box_list, int num, TF up) {
	int i;
	int j;
	box temp;
	if (up == TRUE) {
		for (i = 0; i < (num - 1); i++) {
			for (j = 0; j < (num - i - 1); j++) {
				if (box_list[j].height < box_list[j + 1].height) {
					temp = box_list[j + 1];
					box_list[j + 1] = box_list[j];
					box_list[j] = temp;
				}
			}
		}
	}
	else {
		for (i = 0; i < (num - 1); i++) {
			for (j = 0; j < (num - i - 1); j++) {
				if (box_list[j].height > box_list[j + 1].height) {
					temp = box_list[j + 1];
					box_list[j + 1] = box_list[j];
					box_list[j] = temp;
				}
			}
		}
	}
	

}

void simplefit(struct box* box_list, int num) {
	using namespace cv;

	int usedspace = 0;
	int maxheight = 0;
	int i;
	int mul = 2;// 그림 크기를 키우기 위한 배수
	struct current_point current_point = { 0,0 };

	Mat img(mul *256, mul *256, CV_8UC3, Scalar(255, 255, 255));

	for (i = 0; i < num; i++) {
		if ((box_list[i].width + current_point.width <= 256) && (box_list[i].height + current_point.height <= 256)) {
			rectangle(img, Point(mul * current_point.width, mul * current_point.height),
				Point(mul * (current_point.width + box_list[i].width), mul * (current_point.height + box_list[i].height)), Scalar(189, 103, 255), -1);
			rectangle(img, Point(mul * current_point.width, mul * current_point.height),
				Point(mul * (current_point.width + box_list[i].width), mul * (current_point.height + box_list[i].height)), Scalar(0, 0, 0), 1);

			usedspace += box_list[i].width * box_list[i].height;
			current_point.width += box_list[i].width;
			if (maxheight < box_list[i].height) {
				maxheight = box_list[i].height;
			}
		}
		else {
			current_point.width = 0;
			current_point.height += maxheight;
			maxheight = 0;
			line(img, Point(0, mul * current_point.height), Point(mul * 256, mul * current_point.height), Scalar(100, 100, 100), 1);
			
			if ((box_list[i].width + current_point.width <= 256) && (box_list[i].height + current_point.height <= 256)) {
				rectangle(img, Point(mul * current_point.width, mul * current_point.height),
					Point(mul * (current_point.width + box_list[i].width), mul * (current_point.height + box_list[i].height)), Scalar(189, 103, 255), -1);
				rectangle(img, Point(mul * current_point.width, mul * current_point.height),
					Point(mul * (current_point.width + box_list[i].width), mul * (current_point.height + box_list[i].height)), Scalar(0, 0, 0), 1);

				usedspace += box_list[i].width * box_list[i].height;
				current_point.width += box_list[i].width;

				if (maxheight < box_list[i].height) {
					maxheight = box_list[i].height;
				}
			}
			else {
				break;
			}
		}
	}
	
	printf("적재율 : %.2lf%%", (double(usedspace) / double(256 * 256)) * 100);
	imshow("result", img);
	waitKey(0);
	
	
	
}

void fit(struct box* box_list, int num) {
	using namespace cv;

	int usedspace = 0;
	int maxheight = 0;
	int i, j, k;
	int mul = 2;// 그림 크기를 키우기 위한 배수
	int finish = num;
	struct current_point current_point = { 0,0 };
	int temp;
	Mat img(mul * 256, mul * 256, CV_8UC3, Scalar(255, 255, 255));

	for (i = 0; i < num; i++) {
		for (j = 0; j < finish; j++) {
			if ((box_list[j].width + current_point.width <= 256) && (box_list[j].height + current_point.height <= 256)) {
				if (box_list[j].rotation == TRUE) {
					rectangle(img, Point(mul * current_point.width, mul * current_point.height),
						Point(mul * (current_point.width + box_list[j].width), mul * (current_point.height + box_list[j].height)), Scalar(255, 223, 120), -1);
					rectangle(img, Point(mul * current_point.width, mul * current_point.height),
						Point(mul * (current_point.width + box_list[j].width), mul * (current_point.height + box_list[j].height)), Scalar(0, 0, 0), 1);
				}
				else {
					rectangle(img, Point(mul * current_point.width, mul * current_point.height),
						Point(mul * (current_point.width + box_list[j].width), mul * (current_point.height + box_list[j].height)), Scalar(189, 103, 255), -1);
					rectangle(img, Point(mul * current_point.width, mul * current_point.height),
						Point(mul * (current_point.width + box_list[j].width), mul * (current_point.height + box_list[j].height)), Scalar(0, 0, 0), 1);
				}
				usedspace += box_list[j].width * box_list[j].height;
				current_point.width += box_list[j].width;
				if (maxheight < box_list[j].height) {
					maxheight = box_list[j].height;
				}
				for (k = j; k < finish - 1; k++) {
					box_list[k] = box_list[k + 1];
				}
				//box_list[finish - 1] = { 0,0,FALSE };
				finish--;
				box_list = (box *)realloc(box_list, finish * sizeof(box));
				
				if (box_list == NULL) {                                // 동적 할당에서 실패하면 NULL 포인터 반환
					printf("# 메모리가 부족합니다.\n"); // 예외 상황 메시지 출력
					exit(1);     // 프로그램 종료
				}
				
				break;

			}
			else {
				if (box_list[j].height + current_point.height <= 256) {
					if (j == finish - 1) {
						current_point.width = 0;
						current_point.height += maxheight;
						maxheight = 0;
						line(img, Point(0, mul * current_point.height), Point(mul * 256, mul * current_point.height), Scalar(100, 100, 100), 1);
					}
				}
				else {
					if ((box_list[j].rotation==TRUE) && (box_list[j].width + current_point.height <= 256)) {
						temp = box_list[j].width;
						box_list[j].width = box_list[j].height;
						box_list[j].height = temp;
						box_list[j].rotation = FALSE;
						j--;
					}	
				}
			}
		}
	}
	printf("적재율 : %.2lf%%", (double(usedspace) / double(256 * 256)) * 100);

	imshow("result", img);
	waitKey(0);

}


