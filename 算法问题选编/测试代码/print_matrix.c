#include "stdio.h"

// a[i*rows+j]
void print_matrix_incircle(int *matrix,int rows,int cols,int start){
	int endX = cols-start-1;
	int endY = rows-start-1;

	//然后依次打印 上，右，下，左
	for(int i=start;i<=endX;i++){
		printf("%d ",matrix[start*rows+i]);
	}

	for(int i=start+1;i<=endY;i++){
		printf("%d ",matrix[i*rows+endX]);
	}

	for(int i=endX-1;i>=start;i--){
		printf("%d ",matrix[endY*rows+i]);
	}

	for(int i=endY-1;i>start;i--){
		printf("%d ",matrix[i*rows+start]);
	}
}

void print_matrix(int *matrix,int rows,int cols){
	if(matrix==NULL) return ;
	if(rows<=0 || cols<=0) return;

	int start = 0;
	while(start*2<cols && start*2<rows){
		print_matrix_incircle(matrix,rows,cols,start);
		start++;
	}
}


int main(int argc, char const *argv[])
{
	int matrix[] = {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16};
	print_matrix(matrix,4,4);
	return 0;
}
