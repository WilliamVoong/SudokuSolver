#include <stdio.h> 


int calculate_row( int[][9], int);
int calculate_col( int[][9], int);
int calculate_box( int[][9], int, int);
int check_col(int[][9], int); 
int check_row(int[][9], int); 
int check_box(int[][9], int, int); 
void test_function_calculate_col(int[][9]);



int main(){

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

	test_function_calculate_col(problem); 
	

				
;}		



void test_function_calculate_col(int problem[9][9]){
	int test_sucess=1;
	if (calculate_col(problem, 0)==13){}
	else if (calculate_col(problem, 5)==7){}
	else if (calculate_col(problem, 7)==14){}
	else{test_sucess=0;};
	
	if(test_sucess){
		printf("test_function_calculate_row succeeded");
	}	
		
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
	for (int i =0; i < index_col*3+3; i++){
			for(int j =0; j < index_col*3+3; j++){
				sum+=problem[i][j]; 
			}	
				
	}
	return sum;
}

int check_row(int(*problem)[9], int row){
	if( calculate_row(problem,row) > 45){return 0;}
	else		 {return 1; }
	
}



int check_col( int(*problem)[9], int col){
	if( calculate_row(problem,col) > 45){return 0;}
	else		 {return 1;}
	
}			

int check_box( int(*problem)[9], int row, int col){
	if( calculate_box(problem,col,row) > 45){ return 0;}
	else		 {return 1;}
	
}		