#include<stdio.h>
#include<string.h> //hint

struct dict{
	char value[100];
	char key[100];
};

void editdict(){ //for editing the dictionary
	//write your code here
}

void printdict(struct dict *dic, int size){ //for printing the output
	for(int i=0; i<size ; i++){
		printf("%s : %s\n",dic[i].key,dic[i].value);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	struct dict dic[size]; //you can do this to declare structure in the array

	//write your code here
}