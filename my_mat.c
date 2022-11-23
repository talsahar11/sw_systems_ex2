#include <limits.h>
#include <stdio.h>
#define n 5

int mat[n][n] = {0} ;
int i, j ;

void floyd_warshall(int mat[n][n]){
	int k ; 
	
	//Initializing all of the cells with value 0 (no path) with the maximum int value, exept the diagonal of the matrix.
	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			if(mat[i][j] == 0 && i != j){
				mat[i][j] = INT_MAX ;
			}
		}	
	}
	
	//The floyd warshall algorithm implementation
	for(k = 0 ; k < n ; k++){
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < n ; j++){
				if(i != k && j != k){
					//This if statement prevent bits overlapping while adding cells with value of INT_MAX, which can cause the value to be
					//negative.
					if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX){
						if(mat[i][j] > mat[i][k] + mat[k][j]){
							mat[i][j] = mat[i][k] + mat[k][j] ;
						}
					}
				}
			}
		}
	}
}

void scan_matrix(){
	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			scanf("%d", &mat[i][j]) ;
		}
	}	
	
	//After the materix was scanned to the system, apply the floyd warshall algorithm on it.
	floyd_warshall(mat) ;
}

char * is_path_exists(int i, int j){
	if(mat[i][j] == INT_MAX){
		return "False" ;
	}else{
		return "True" ;
	}
}

int shortest_path(int i, int j){
	if(mat[i][j] != INT_MAX){
		return mat[i][j] ;
	}else{
		return -1 ;
	}
}
