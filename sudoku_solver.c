#include <std.io> 





int main(){
  int[][] problem = { 	{ 0, 0, 4,   0, 0, 0,   0, 6, 7 },
                        { 3, 0, 0,   4, 7, 0,   0, 0, 5 },
                        { 1, 5, 0,   8, 2, 0,   0, 0, 3 },
                            
                        { 0, 0, 6,   0, 0, 0,   0, 3, 1 },
                        { 8, 0, 2,   1, 0, 5,   6, 0, 4 },
                        { 4, 1, 0,   0, 0, 0,   9, 0, 0 },
                            
                        { 7, 0, 0,   0, 8, 0,   0, 4, 6 },
                        { 6, 0, 0,   0, 1, 2,   0, 0, 0 },
                        { 9, 3, 0,   0, 0, 0,   7, 1, 0 } 
						
					}



					
					
		

				
}		


int calculate_row( int[][] problem, int row){
	int sum=0: 
	for (int i =0; i < 9; i++){
	sum+=problem[i][row]; 
	}
	return sum;	
	
}






int calculate_col( int[][] problem, int row){ 
	int sum=0: 
	for (int i =0; i < 9; i++){
	sum+=problem[i][row]; 
	}
	return sum;	
}


int calculate_box( int[][] problem, int row, int col){
	int sum=0: 
	int index_row=row/3; 
	int index_col=col/3; 
	for (int i =0; i < index_col*3; i++){
			for(int j =0; j < index_col*3; j++){
				sum+=problem[i][j]; 
				
	}
}

int check_row(int row){
	if( row > 45){return 0;}
	else		 {return 1; }
	
}



int check_col(int col){
	if( row > 45){return 0;}
	else		 {return 1;}
	
}			

int check_box(int box){
	if( box > 45){ return 0;}
	else		 {return 1;}
	
}			