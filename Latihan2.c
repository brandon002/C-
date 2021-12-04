#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);getchar();
	int pohon[N][N];
	int bunga[N]={0};
	int lestari[N]={0};
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &pohon[i][j]);
		}getchar();
	}
//	for(int i=0;i<N;i++){
//		for(int j=0;j<N;j++){
//			printf("%d", pohon[i][j]);
//		}printf("\n");
//	}
	for(int a=0;a<N;a++){
		int kolom=0;
		bunga[a]++;
		for(int b=0;b<N;b++){
			if(pohon[kolom][a]<pohon[b][a]){
				bunga[a]++;
				
			}
			if(pohon[kolom][a]>pohon[b][a]){
				kolom++;
			}
		}
	}
	for(int a=0;a<N;a++){
		int baris=0;
		lestari[a]++;
		for(int b=0;b<N;b++){
			if(pohon[a][baris]<pohon[a][b]){
				lestari[a]++;
			}
			if (pohon[a][baris]>pohon[a][b]){
				baris++;
			}
		}
	}
	for(int p=0;p<N;p++){
		if(p==N-1){
			printf("%d\n", bunga[p]);
		}
		else{
			printf("%d ", bunga[p]);
		}
	}
	for(int q=0;q<N;q++){
		printf("%d\n", lestari[q]);
	}
	printf("%d\n", pohon[0][0]);
//	printf("%d\n", pohon[0][1]);
//	printf("%d\n", pohon[0][2]);
//	
	printf("%d\n", pohon[1][0]);
//	printf("%d\n", pohon[1][1]);
//	printf("%d\n", pohon[1][2]);
//	
//	printf("%d\n", pohon[2][0]);
//	printf("%d\n", pohon[2][1]);
//	printf("%d\n", pohon[2][2]);
}
