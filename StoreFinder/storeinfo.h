// 함수의 선언과 변수의 선언만 위치

typedef struct {
	char url[100];
	char name[100];
	int price;
	int type;
	int type_eat;

	int position;
	int store_to_pos_dist;
	int second_near;
	int store_to_sec_dist;
} Node;