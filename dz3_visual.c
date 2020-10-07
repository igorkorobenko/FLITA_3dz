#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	char* s = (char*) calloc(40, sizeof(char));
	printf("Name of file without .dot\n");
	scanf("%s", s);

	char* s_twin = (char*) calloc(40, sizeof(char));

	strcat(s_twin, s);
	strcat(s, ".dot");

	FILE* f = fopen(s, "r");

	char* file_s = (char*) calloc(500, sizeof(char));
	fgets(file_s, 500, f);

	fclose(f);


	char* term = (char*) calloc(500, sizeof(char));
	strcat(term, "echo \"");
	strcat(term, file_s);
	strcat(term, "\" | dot -Tpng >./");
	strcat(term, s_twin);
	strcat(term, ".png");
	printf("%s\n", term);

	system(term);


	free(s);
	free(s_twin);
	free(file_s);
	free(term);

	return 0;
}