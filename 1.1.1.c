#include<stdio.h>
void main() {
		
	int len , pos = 0, flag = 0;
	
	scanf("%d" , &len);
	int arr[len];
	for(int i = 0; i<len; i++ ){
		scanf("%d " , &arr[i]);
	}
	int key;
	scanf("%d" , &key);
	for(int j = 0;j<len;j++){
		if(arr[j] == key){
			pos = j;
			flag = 1;
		}
	
	
	//Type your content here
	
	
	
	
	}
	if (flag == 1) {
		printf("found at position %d\n", pos);
	} else {
		printf("%d not found\n", key);
	}
}
