#include <stdio.h>
#include <string.h>

int main(){
	int array;
	int isi[1001];
	int turn;
	int sisa;
	int i=0;
	int jumlah=0;
	int left=0;
	scanf("%d %d", &array, &turn);getchar();
	
	for(int i=0;i<array;i++){
		scanf("%d", &isi[i]);
			//printf("%d ", isi[i]);
	}getchar();//printf("\n");
	
	do{
		
		jumlah=0;
		
		for(int a=0+i;a<turn+i;a++){
			jumlah += isi[a];
		
		}//printf("%d \n", jumlah);
		if(i==0){
			sisa=isi[array-1];
		//	printf("%d \n", sisa);
		}
		else{
			sisa=isi[0];
		//	printf("%d \n", sisa);
		}
		
		i++;
		
	}while(((jumlah^sisa)%2==0) && (i+turn <= array));
	
	if((jumlah^sisa)%2==0){
		printf("Preston\n");
	}
	else{
		printf("John\n");
	}
}
