#include <stdio.h>
#include <stdlib.h>

void accept(int arr[20][20],int row,int col);
void display(int arr[20][20],int row,int col);
int create_compact(int arr[20][20],int row,int col,int sp[20][20]);
void simpletranspose(int sp[20][20],int tp[20][20]);
void fast_transpose(int sp[20][20],int tp[20][20]);
void sparseaddition(int cp1[20][20],int cp2[20][20],int cp3[20][20]);

void accept(int arr[20][20],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("\nEnter element of row %d column %d:-",i,j);
			scanf(" %d",&arr[i][j]);
		}
	}
}


void display(int arr[20][20],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf(" %d",arr[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}


int create_compact(int arr[20][20],int row,int col,int sp[20][20]){
	int i,j,k=1;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(arr[i][j]!=0){
				sp[k][2]=arr[i][j];
				sp[k][1]=j;
				sp[k][0]=i;
				k++;
			}
		}
	}
	sp[0][0]=row;
	sp[0][1]=col;
	sp[0][2]=k-1;
	return k;
}


void simpletranspose(int sp[20][20],int tp[20][20]){
	int i,j,k=1;
	tp[0][0]=sp[0][1];
	tp[0][1]=sp[0][0];
	tp[0][2]=sp[0][2];
	for(i=0;i<sp[0][1];i++){
		for(j=1;j<=sp[0][2];j++){
			if(sp[j][1]==i){
				tp[k][0]=sp[j][1];
				tp[k][1]=sp[j][0];
				tp[k][2]=sp[j][2];
				k++;
			}
		}
	}
}


void fast_transpose(int sp[20][20],int tp[20][20]){
	int rterm[10];
	int rpos[10];
	int i,j;
	tp[0][0]=sp[0][1];
	tp[0][1]=sp[0][0];
	tp[0][2]=sp[0][2];
	for(i=0;i<sp[0][1];i++){
		rterm[i]=0;
	}
	for(i=1;i<=sp[0][2];i++){
		rterm[sp[i][1]]++;
	}
	rpos[0]=1;
	for(i=1;i<sp[0][1];i++){
		rpos[i]=rpos[i-1]+rterm[i-1];
	}
	for(j=1;j<=sp[0][2];j++){
		int loc=rpos[sp[j][1]];
		tp[loc][0]=sp[j][1];
		tp[loc][1]=sp[j][0];
		tp[loc][2]=sp[j][2];
		rpos[sp[j][1]]++;
	}
}

void sparseaddition(int cp1[20][20],int cp2[20][20],int cp3[20][20]){
	int i=1,j=1,k=1;
	if(cp1[0][0]==cp2[0][0] && cp1[0][1]==cp2[0][1]){
		while(i<=cp1[0][2] && j<=cp2[0][2]){
			if(cp1[i][0]==cp2[j][0]){
				if(cp1[i][1]==cp2[j][1]){
					cp3[k][0]=cp1[i][0];
					cp3[k][1]=cp1[i][1];
					cp3[k][2]=cp1[i][2]+cp2[j][2];
					i++;
					j++;
					k++;
				}
				else if(cp1[i][1]<cp2[j][1]){
					cp3[k][0]=cp1[i][0];
					cp3[k][1]=cp1[i][1];
					cp3[k][2]=cp1[i][2];
					i++;
					k++;
				}
				else{
					cp3[k][0]=cp2[j][0];
					cp3[k][1]=cp2[j][1];
					cp3[k][2]=cp2[j][2];
					j++;
					k++;
				}
			}
			else if(cp1[i][0]<cp2[j][0]){
				cp3[k][0]=cp1[i][0];
				cp3[k][1]=cp1[i][1];
				cp3[k][2]=cp1[i][2];
				i++;
				k++;
			}
			else{
				cp3[k][0]=cp2[j][0];
				cp3[k][1]=cp2[j][1];
				cp3[k][2]=cp2[j][2];
				j++;
				k++;
			}		
		}
		while(i<=cp1[0][2]){
			cp3[k][0]=cp1[i][0];
			cp3[k][1]=cp1[i][1];
			cp3[k][2]=cp1[i][2];
			i++;
			k++;
		}
		while(j<=cp2[0][2]){
			cp3[k][0]=cp2[j][0];
			cp3[k][1]=cp2[j][1];
			cp3[k][2]=cp2[j][2];
			j++;
			k++;
		}
	}
	cp3[0][0]=cp1[0][0];
	cp3[0][1]=cp1[0][1];
	cp3[0][2]=k-1;
	
	for(i=0;i<k;i++){
		for(j=0;j<3;j++){
			printf(" %d",cp3[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
}


int main(){
	int mat[20][20],sp[20][20],tp[20][20],sp1[20][20],sp2[20][20],mat1[20][20];
	int row,col,spsize,sp1size,tpsize,ch;
	char c;
	printf("\nEnter no. of rows");
	scanf(" %d",&row);
	printf("\nEnter no. of columns");
	scanf(" %d",&col);


	do{
		printf("\nEnter your choice\n1.Accept\n2.Display\n3.Compact\n4.Simple Transpose\n5.Fast Transpose\n6.Sparse Addition");
		scanf(" %d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the elements of the array:\n");
				accept(mat,row,col);
				break;

			case 2:
				printf("\nElements of the Array:\n");
				display(mat,row,col);
				break;

			case 3:
				printf("\nCompact of matrix is:\n");
				spsize=create_compact(mat,row,col,sp);
				display(sp,spsize,3);
				break;

			case 4:
				printf("\nSimple Transpose of matrix:\n");
				simpletranspose(sp,tp);
				spsize=create_compact(mat,row,col,sp);
				display(tp,spsize,3);
				break;

			case 5:
				printf("\nFast Transpose of matrix is:\n");
				fast_transpose(sp,tp);
				spsize=create_compact(mat,row,col,sp);
				display(tp,spsize,3);
				break;
				
			case 6:
				printf("\nEnter Second Matrix:\n");
				accept(mat1,row,col);
				sp1size=create_compact(mat1,row,col,sp1);
				printf("\nCompact form of second matrix:\n");
				display(sp1,sp1size,3);
				printf("\nSparse adiition of matrices is:\n");
				sparseaddition(sp,sp1,sp2);
				break;

			default:
				printf("\nEnter correct choice");
		}
		printf("Do you want to continue?YorN");
		scanf(" %c",&c);
	}
	while(c=='y'||c=='Y');
	return 0;
}

/*OUTPUT:-
apr@c04l0117-dx2480-MT:~$ gcc sp.c
apr@c04l0117-dx2480-MT:~$ ./a.out

Enter no. of rows3

Enter no. of columns3

Enter your choice
1.Accept
2.Display
3.Compact
4.Simple Transpose
5.Fast Transpose
6.Sparse Addition1

Enter the elements of the array:

Enter element of row 0 column 0:-1

Enter element of row 0 column 1:-0

Enter element of row 0 column 2:-0

Enter element of row 1 column 0:-0

Enter element of row 1 column 1:-1

Enter element of row 1 column 2:-0

Enter element of row 2 column 0:-0

Enter element of row 2 column 1:-0

Enter element of row 2 column 2:-1
Do you want to continue?YorNy

Enter your choice
1.Accept
2.Display
3.Compact
4.Simple Transpose
5.Fast Transpose
6.Sparse Addition2

Elements of the Array:
 1	 0	 0	
 0	 1	 0	
 0	 0	 1	
Do you want to continue?YorNy

Enter your choice
1.Accept
2.Display
3.Compact
4.Simple Transpose
5.Fast Transpose
6.Sparse Addition3

Compact of matrix is:
 3	 3	 3	
 0	 0	 1	
 1	 1	 1	
 2	 2	 1	
Do you want to continue?YorNy

Enter your choice
1.Accept
2.Display
3.Compact
4.Simple Transpose
5.Fast Transpose
6.Sparse Addition4

Simple Transpose of matrix:
 3	 3	 3	
 0	 0	 1	
 1	 1	 1	
 2	 2	 1	
Do you want to continue?YorNy

Enter your choice
1.Accept
2.Display
3.Compact
4.Simple Transpose
5.Fast Transpose
6.Sparse Addition5

Fast Transpose of matrix is:
 3	 3	 3	
 0	 0	 1	
 1	 1	 1	
 2	 2	 1	
Do you want to continue?YorNy

Enter your choice
1.Accept
2.Display
3.Compact
4.Simple Transpose
5.Fast Transpose
6.Sparse Addition6

Enter Second Matrix:

Enter element of row 0 column 0:-1

Enter element of row 0 column 1:-4

Enter element of row 0 column 2:-0

Enter element of row 1 column 0:-0

Enter element of row 1 column 1:-0

Enter element of row 1 column 2:-3

Enter element of row 2 column 0:-6

Enter element of row 2 column 1:-0

Enter element of row 2 column 2:-4

Compact form of second matrix:
 3	 3	 5	
 0	 0	 1	
 0	 1	 4	
 1	 2	 3	
 2	 0	 6	
 2	 2	 4	

Sparse adiition of matrices is:
 3	 3	 6	
 0	 0	 2	
 0	 1	 4	
 1	 1	 1	
 1	 2	 3	
 2	 0	 6	
 2	 2	 5	
 */

