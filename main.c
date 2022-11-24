#include <stdio.h>
#include "my_mat.h"
int main(){
	int i, j ;
	char option ;
	while(option != 'D'){
		scanf("%c", &option) ;
		switch(option){
			case 'A':
				scan_matrix() ;
				break ;
			case 'B':
				scanf("%d %d", &i, &j) ;
				printf("%s\n", is_path_exists(i,j)) ;
				break ;
			case 'C':
				scanf("%d %d", &i, &j) ;
				printf("%d\n", shortest_path(i,j)) ;
				break ;
		}
	}
	return 0 ;
}
