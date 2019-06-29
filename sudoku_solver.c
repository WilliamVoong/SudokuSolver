#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
typedef struct sudoku{
	int row;
	int col;
	int *Valid_numbers;
	int size;
	int count;
	struct sudoku *prev;
	struct sudoku *next;
} *PSUDOKU,SUDOKU;  


void solve_sudoku(int[][9],struct sudoku *);
int check_no_duplicate_row(int[][9], int,int); 
int check_no_duplicate_col(int[][9], int,int); 
int check_no_duplicate_box(int[][9], int,int,int); 
int Valid_Number(int[][9],int,int,int);

int get_size_valid_num(int[][9],int,int);
int *get_valid_num(int[][9],int,int,int); 
int Is_changeable_coord(int[][9],int,int);
SUDOKU *create_linked_list(int[][9]); 
int tried_all_valid_numbers(struct sudoku *); 

void test_get_size_valid_num(int[][9]);
void print_sudoku(int problem[][9]);
void test_function_check_no_duplicate_row(int [][9]);
void test_function_check_no_duplicate_col(int [][9]);
void test_function_check_no_duplicate_box(int [][9]);
void test_function_Valid_number(int [][9]);

int main(){
	struct sudoku *head=( (struct sudoku *) malloc(sizeof(SUDOKU)));
	PSUDOKU current_node= head;
	current_node->prev=NULL; 
	clock_t start, end;
    double cpu_time_used;
	
	int test_problem[9][9]=	{
							{ 0, 0, 4,   0, 0, 0,   0, 6, 7 },
							{ 3, 0, 0,   4, 7, 0,   0, 0, 5 },
							{ 1, 5, 0,   8, 2, 0,   0, 0, 3 },
                            
							{ 0, 0, 6,   0, 0, 0,   0, 3, 1 },
							{ 8, 0, 2,   1, 0, 5,   6, 0, 4 },
							{ 4, 1, 0,   0, 0, 0,   9, 0, 0 },
								
							{ 7, 0, 0,   0, 8, 0,   0, 4, 6 },
							{ 6, 0, 0,   0, 1, 2,   0, 0, 0 },
							{ 9, 3, 0,   0, 0, 0,   7, 1, 0 } 
						
						};
	/*int problem[9][9]= { { 0, 0, 0,   0, 0, 0,   0, 0, 0 }, // this sudoku problem is designed to work agaisnt
                        { 0, 0, 0,   0, 0, 3,   0, 8, 5 },	// the bruteforce algorithm and therefore slow. 
                        { 0, 0, 1,   0, 2, 0,   0, 0, 0 }, // However the puzzle is still solved in a timely matter (on my machine)
                            
                        { 0, 0, 0,   5, 0, 7,   0, 0, 0 },
                        { 0, 0, 4,   0, 0, 0,   1, 0, 0 },
                        { 0, 9, 0,   0, 0, 0,   0, 0, 0 },
                            
                        { 5, 0, 0,   0, 0, 0,   0, 7, 3 },
                        { 0, 0, 2,   0, 1, 0,   0, 0, 0 },
                        { 0, 0, 0,   0, 4, 0,   0, 0, 9 } 
						
					};
*/			
					
	int problem[9][9]= {{ 8, 0, 0,   0, 0, 0,   0, 0, 0 }, 
                        { 0, 0, 3,   6, 0, 0,   0, 0, 0 },	
                        { 0, 7, 0,   0, 9, 0,   2, 0, 0 }, 
                            
                        { 0, 5, 0,   0, 0, 7,   0, 0, 0 },
                        { 0, 0, 0,   0, 4, 5,   7, 0, 0 },
                        { 0, 0, 0,   1, 0, 0,   0, 3, 0 },
                            
                        { 0, 0, 1,   0, 0, 0,   0, 6, 8 },
                        { 0, 0, 8,   5, 0, 0,   0, 1, 0 },
                        { 0, 9, 0,   0, 0, 0,   4, 0, 0 } 
	
					};
	 

	printf("\n sudoku to be solved : \n");
	print_sudoku(problem);
	
	start = clock();
	current_node=create_linked_list(problem); 

	
	while(current_node){
		if(tried_all_valid_numbers(current_node)){  
			//  printf(" \n *** BACK TRACK*** \n");
			current_node->count=0;
			problem[current_node->row][current_node->col]=0;
			current_node=current_node->prev;
			
		}
		
		else if( Valid_Number(problem, current_node->row, current_node->col , current_node->Valid_numbers[current_node->count]) )
		{	
			problem[current_node->row][current_node->col]= current_node->Valid_numbers[current_node->count];
			current_node->count+=1; 
			current_node=current_node->next; 
			
		}
		else{ 
			current_node->count+=1;
		}
			
		
		
	}
	end= clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n    	**** Solved  *****  \n");
	print_sudoku(problem);
	printf("it took %f seconds to solve the puzzle\n", cpu_time_used); 
				
	printf("Press ENTER key to Continue\n");  
	getchar(); 			
}		
void print_sudoku(int problem[9][9]){
	printf("\n+___________+___________+___________+\n");
	for (int row=0; row<9; row++){ 
		
		for(int columns=0; columns<9; columns++){
			
		 if(columns==0){
			 printf("|"); 
		 }
		 printf(" %d |", problem[row][columns]);
		 
		
        }
		if( (row+1) % 3 ){
			printf("\n+           +           +           +\n");
		}
		else{
			printf("\n+___________+___________+___________+\n");
		}
	 
	}
}
void solve_sudoku(int sudoku[][9],PSUDOKU current_node){
	
	int value_to_try; 
	
	while(current_node){
		
		value_to_try = current_node->Valid_numbers[current_node->count];
		
		if( tried_all_valid_numbers(current_node) ){  
		
			current_node->count=0;
			sudoku[current_node->row][current_node->col]=0;
			current_node=current_node->prev;
			//  printf(" \n *** BACK TRACK*** \n");
			
		}
		
		else if(  Valid_Number(sudoku, current_node->row, current_node->col , value_to_try) )
		{	
			sudoku[current_node->row][current_node->col]= value_to_try;
			current_node->count+=1; 
			current_node=current_node->next; 
			
		}
		else{ 
			current_node->count+=1;
		}
			
		
		
	}
	
}
// tests
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

// check no duplicates
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

// getting valid numbers for each cordinate
int Valid_Number(int(*problem)[9], int row, int col,int val){
	int Is_Valid=0;
	if( check_no_duplicate_row(problem,row,val) && check_no_duplicate_col(problem,col,val) && check_no_duplicate_box(problem,row,col,val) ){
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

// create linked list
int Is_changeable_coord( int(*problem)[9] , int row, int col){
	if( problem[row][col]==0){
		return 1;
	}
	else{
		return 0;
	} 
}
struct sudoku *create_linked_list(int (*problem)[9]){ // this 
	
	PSUDOKU head=( (struct sudoku *) malloc(sizeof(SUDOKU)));
	PSUDOKU current_node;
	PSUDOKU new_ptr; 
	PSUDOKU prev_ptr;
	int size;
	
	current_node=head;
	current_node->prev=NULL;
	for (int i = 0; i<9; i++){
		
		for(int j=0; j < 9; j++){
			
			if(Is_changeable_coord(problem,i,j)){
				 prev_ptr=current_node; 
				 new_ptr=(struct sudoku *) malloc(sizeof(SUDOKU));
				 
				 
				 current_node->next=new_ptr; 
				 current_node=new_ptr; 
				 current_node->prev=prev_ptr; 
				 
				 current_node->row=i; 
				 current_node->col=j; 
				 current_node->count=0; 
				 size=get_size_valid_num(problem,i,j);
				 
				 current_node->size=size; 
				 current_node->Valid_numbers=get_valid_num(problem,i,j,size); 
				 
				 
				 
			}
			
		}
	}
	current_node->next=NULL; 
	return head->next; 
}


int tried_all_valid_numbers(PSUDOKU current_node){
	if(current_node->count >= current_node->size){
		return 1;
	}
	else{
		return 0;
	} 
}
