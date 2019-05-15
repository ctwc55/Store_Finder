#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int position;	 
	char url[100];	 
	char name[100];  
	int price;	     
	int type;        
	int type_eat;    
	//----------------
	int near_point_dist;
} Node;

Node store[1000];
int graph[100][100];

int main()
{

	system("pause");
	return 0;
}