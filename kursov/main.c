#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "read_put_text.h"
#include "functions.h"


int main(){
	printf("Course work for option 4.12, created by Alina Rezyapova.\n");
	char* text = "\0";
	int number;
	scanf("%d", &number);
	getchar();
	switch(number){
		case 0:
			text = function_0();
			//printf("%s", text);
		//case 1:
		//	text = function_1();

	}

}
