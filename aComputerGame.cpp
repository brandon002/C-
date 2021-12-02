#include <iostream>

using namespace std;

int main(){
	int Test;
	cin >> Test;
	cin.tie(NULL);
	int Column = 0;
	int Cell[2][101];
	
	for(int i=0;i<Test;i++){
		cin >> Column;	
		for(int j=0;j<2;j++){
			for(int k=0;k<Column;k++){
				cin >> Cell[j][k];
			}
		}
		for(int l=0;l<2;l++){
			for(int m=0;m<Column;m++){
				cout<< Cell[l][m] ;
			}
		}
	}
	
}
