#include <stdio.h> 
#include <stdlib.h>
typedef struct sudoku{
	int row;
	int col;
	int *Valid_numbers;
	int size;
	int count;
	int checked_all;
	struct sudoku *prev;
	struct sudoku *next;
} *PSUDOKU,SUDOKU;  




int calculate_row( int[][9], int);
int calculate_col( int[][9], int);
int calculate_box( int[][9], int, int);
int check_col(int[][9], int,int); 
int check_row(int[][9], int,int); 
int check_box(int[][9], int, int,int); 
int check_no_duplicate_row(int[][9], int,int); 
int check_no_duplicate_col(int[][9], int,int); 
int check_no_duplicate_box(int[][9], int,int,int); 
int Valid_Number(int [][9],int,int,int);

int get_size_valid_num(int[][9],int,int);
int *get_valid_num(int[][9],int,int,int); 
int Is_changeable(int[][9],int,int);
SUDOKU *create_linked_list(int[][9], struct sudoku *); 


void test_function_calculate_col(int[][9]);
void test_function_calculate_row(int[][9]);
void test_function_calculate_box(int[][9]);
void test_function_check_no_duplicate_row(int [][9]);
void test_function_check_no_duplicate_col(int [][9]);
void test_function_check_no_duplicate_box(int [][9]);
void test_function_Valid_number(int [][9]);
void test_get_size_valid_num(int[][9]);

int main(){
struct sudoku *head=( (struct sudoku *) malloc(sizeof(SUDOKU)));;
struct sudoku *end= ((struct sudoku *) malloc(sizeof(SUDOKU)) );;
PSUDOKU linkedlist= head;
linkedlist->prev=NULL; 



  int problem[9][9]= { 	{ 0, 0, 4,   0, 0, 0,   0, 6, 7 },
                        { 3, 0, 0,   4, 7, 0,   0, 0, 5 },
                        { 1, 5, 0,   8, 2, 0,   0, 0, 3 },
                            
                        { 0, 0, 6,   0, 0, 0,   0, 3, 1 },
                        { 8, 0, 2,   1, 0, 5,   6, 0, 4 },
                        { 4, 1, 0,   0, 0, 0,   9, 0, 0 },
                            
                        { 7, 0, 0,   0, 8, 0,   0, 4, 6 },
                        { 6, 0, 0,   0, 1, 2,   0, 0, 0 },
                        { 9, 3, 0,   0, 0, 0,   7, 1, 0 } 
						
					};
linkedlist=create_linked_list(problem,linkedlist); 

	test_function_calculate_col(problem); 
	test_function_calculate_row(problem);
	test_function_calculate_box(problem); 
	test_function_check_no_duplicate_row(problem);
	test_function_check_no_duplicate_col(problem);
	test_function_check_no_duplicate_box(problem);
	test_function_Valid_number(problem); 
	test_get_size_valid_num(problem);
	int size= get_size_valid_num(problem,0,1);
	int *ptr=get_valid_num(problem,0,1,size);
	printf("  hej ");  
	linkedlist= head;
	linkedlist=linkedlist->next;
	linkedlist=linkedlist->next;
	printf("  %d ", linkedlist->Valid_numbers[2]); 
	printf("  %d ", linkedlist->size); 
	
	
				
;}		



void test_function_calculate_col(int problem[9][9]){
	int test_sucess=1;
	if (calculate_col(problem, 0)==13){}
	else if (calculate_col(problem, 5)==7){}
	else if (calculate_col(problem, 7)==14){}
	else{test_sucess=0;};
	
	if(test_sucess){
		printf("test_function_calculate_col succeeded \n");
	}
	else{
		printf("* ERROR * test_function_calculate_col FAILED ");
	}
		
		
}
void test_function_calculate_row(int problem[9][9]){
	int test_sucess=1;
	if (calculate_row(problem, 0)==17){}
	else if (calculate_row(problem, 5)==14){}
	else if (calculate_row(problem, 7)==9){}
	else{test_sucess=0;};
	
	
	if(test_sucess){
		printf("test_function_calculate_row succeeded \n");
	}
	else{
		printf("* ERROR * test_function_calculate_box FAILED \n");
	}
		
		
}
void test_function_calculate_box(int problem[9][9]){

	int test_sucess=1;
	
	if (calculate_box(problem, 0,4)==21){}
	else if (calculate_box(problem, 5,3)==6){}
	else if (calculate_box(problem, 7,1)==27){}
	else{test_sucess=0;};
	
	
	if(test_sucess){
		printf("test_function_calculate_box succeeded \n");
	}
	else{
		printf("* ERROR * test_function_calculate_box FAILED \n");
	}
		
		
}
void test_function_check_no_duplicate_row(int problem[9][9]){
	int test_sucess=1;
	if( check_no_duplicate_row(problem, 1,3)==0){}
	else{test_sucess=0;}
	
	if( check_no_duplicate_row (problem, 7,3)){
		test_sucess=1;
	}else{
	test_sucess=0;}
	
	if( check_no_duplicate_row (problem, 8,3)){
		test_sucess=0;
	}
	else{test_sucess=1;}
	
	if(test_sucess){
		printf("test_function_check_no_duplicates_row succeeded \n");
	}
	else{
		printf("* ERROR * test_function_check_no_duplicates_row  FAILED \n");
	}
		
	
}
void test_function_check_no_duplicate_col(int problem[9][9]){
	int test_sucess=1;
	if( check_no_duplicate_col(problem, 1,3)==0){}
	else{test_sucess=0;}
	
	if( check_no_duplicate_col(problem, 7,3)==0){
	}else{
	test_sucess=0;}
	
	if( check_no_duplicate_col(problem, 8,3)==0){
	}
	else{test_sucess=0;}
	
	if(test_sucess){
		printf("test_function_check_no_duplicates_col succeeded \n");
	}
	else{
		printf("* ERROR * test_function_check_no_duplicates_col  FAILED \n");
	}
		
	
}
void test_function_check_no_duplicate_box(int problem[9][9]){
	int test_sucess=1;
	if(check_no_duplicate_box(problem, 0,0,2))
	{}
	else{test_sucess=0;}

	if(test_sucess){
		printf("test_function_check_no_duplicates_box succeeded \n");
	}
	else{
		printf("* ERROR * test_function_check_no_duplicates_box  FAILED \n");
	}
		
	
	
}
void test_function_Valid_number(int problem[9][9]){
	int test_sucess=1;
	if(Valid_Number(problem,8,8,9)){}
	else{test_sucess=0;}
	
	if(test_sucess){
		printf("Is_Valid succeeded \n");
	}
	else{
		printf("* ERROR * Is_Valid  FAILED \n");
	}
		
	
	
}	
void test_get_size_valid_num(int problem[9][9]){
	if(get_size_valid_num(problem,0,0)==1){
		printf("test_get_size_valid_num succeeded");
	}
	else{ printf(" * ERROR * test_get_size_valid_num FAILED");}
}

int calculate_col( int (*problem)[9], int col){
	int sum=0; 
	for (int i =0; i < 9; i++){
	sum+=problem[i][col]; 
	}
	return sum;	
	
}
int calculate_row( int(*problem)[9], int row){ 
	int sum=0; 
	for (int i =0; i < 9; i++){
	sum+=problem[row][i]; 
	}
	return sum;	
}
int calculate_box( int(*problem)[9], int row, int col){
	int sum=0; 
	int index_row=row/3; 
	int index_col=col/3; 
	for (int i =index_row*3; i < index_row*3+3; i++){
			for(int j =index_col*3; j < index_col*3+3; j++){
				sum+=problem[i][j]; 
			}	
				
	}
	return sum;
}

int check_no_duplicate_row(int problem[9][9], int row,int val){
	for (int i =0; i < 9; i++){
		if(problem[row][i]==val){
			return 0;
		}
	}
	return 1;
}
int check_no_duplicate_col(int problem[9][9], int col,int value_to_check){
	for (int i =0; i < 9; i++){
		if(problem[i][col]==value_to_check){
			return 0;
		}
	}
	return 1;
}
int check_no_duplicate_box( int(*problem)[9], int row, int col,int val){
	int index_row=row/3; 
	int index_col=col/3; 
	for (int i =index_row*3; i < index_row*3+3; i++){
			for(int j =index_col*3; j < index_col*3+3; j++){
				if(problem[i][j]==val){
					return 0;
				}
				
				
			}	
				
	}
	return 1;
	
}


int check_row(int(*problem)[9], int row, int val){
	if( calculate_row(problem,row) > 45){return 0;}
	if(!(check_no_duplicate_row(problem,row, val))){return 0;} // if duplicate exsist, return 0
	else	{return 1; }
	
}
int check_col( int(*problem)[9], int col, int val){
	if( calculate_row(problem,col) > 45){return 0;}
	if(!(check_no_duplicate_col(problem,col, val))){return 0;}
	else		 {return 1;}
	
}			
int check_box( int(*problem)[9], int row, int col, int val){
	if( calculate_box(problem,col,row) > 45){ return 0;}
	else if ( !(check_no_duplicate_box(problem,row,col,val)) )
	{return 0;}
	else {return 1;}
	
}		

int Valid_Number(int(*problem)[9], int row, int col,int val){
	int Is_Valid=0;
	if( check_row(problem,row,val) && check_col(problem,col,val) && check_box(problem,row,col,val) ){
		Is_Valid=1;
	}
	return Is_Valid;
	
}
int get_size_valid_num(int(*problem)[9], int row, int col){
	int size=0;
	for(int i=1; i <10; i++){
		if(Valid_Number(problem,row,col,i))
		{
			size++;
		}
		
	}
	return size;  
}	
int *get_valid_num(int(*problem)[9], int row, int col, int size){
	int count=0;
	int *ptr=malloc(size*sizeof(int));
	for(int i=1; i < 10;i++){
		if( Valid_Number(problem,row,col,i) ){
		ptr[count]=i;
		count++; 
		}
			
	}
	return ptr; 
}

int Is_changeable( int(*problem)[9] , int row, int col){
	if( problem[row][col]==0){
		return 1;
	}
	else{return 0;} 
}



struct sudoku *create_linked_list(int (*problem)[9], PSUDOKU linkedlist){ // this 
	PSUDOKU new_ptr; 
	PSUDOKU prev_ptr;
	int size;
	for (int i = 0; i<9; i++){
		for(int j=0; j < 9; j++){
			
			if(Is_changeable(problem,i,j)){
				 prev_ptr=linkedlist; 
				 new_ptr=(struct sudoku *) malloc(sizeof(SUDOKU));
				 linkedlist->next=new_ptr; 
	
				 linkedlist=new_ptr; 
				 linkedlist->prev=prev_ptr; 
				 
				 linkedlist->row=i; 
				 linkedlist->col=j; 
				 size=get_size_valid_num(problem,i,j);
				 
				 linkedlist->size=size; 
				 linkedlist->Valid_numbers=get_valid_num(problem,i,j,size); 
				 
				 
				 
			}
			
		}
	}
	linkedlist->next=NULL; 
	return linkedlist; 
	
}

