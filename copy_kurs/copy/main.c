#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"


int main(){
	printf("Course work for option 4.12, created by Alina Rezyapova.\n");
	char* text = "\0";
	int number;
	scanf("%d", &number);
	getchar();
	/*
	if (number != 0 &&  number != 1 && number != 2 && number != 3 && number != 4 && number != 5){
		printf("Error: There is no function with this number.\n");
		return 0;
	}*/

	switch(number){
		case 0:
			text = function_0();
			break;
		case 1:
			text = function_1();
			break;
		case 2:
			text = function_2();
			break;
		case 3:
			text = function_3();
			break;
		case 4:
			text = function_4();
			break;
		case 5:
			function_5();
			break;
		case 9:
			function_9();
			break;
		case 10:
			function_10();
			break;
		case 11:
			function_11();
			break;
		case 12:
                        function_11();
                        break;
		default:
			printf("Error: There is no function with this number.\n");
			return 0;
	}
	return 0;
}
