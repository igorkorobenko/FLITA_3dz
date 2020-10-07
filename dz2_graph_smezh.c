#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

	int bg = -1;
	while ((bg != 1) && (bg != 0)){
		printf("0 - for graph\n");
		printf("1 - for digraph\n");
		scanf("%d", &bg);
	}

	int n;
	printf("Num of elements: ");
	scanf("%d", &n);

	while (n < 0){
        printf("Num > 0 !\n");
        scanf("%d",&n);
        printf("\n");
    }

	int mtx[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mtx[i][j] = 0;
		}
	}

	char* names[n];

	printf("Fill the names of elements\n");

	for (int i = 0; i < n; i++){
		printf("#%d ", i + 1);
		char *s = (char*) malloc(20 * sizeof(char));
		scanf("%s", s);
		names[i] = s;
	}

	putchar('\n');

	printf("Connections\n");

	printf("Example:\n");
	printf("lol\n");
	printf(";\n\n");

	for (int i = 0; i < n; i++){
		printf("#%d: %s\n", i + 1, names[i]);
		_Bool flag = 1;

		while (flag){
			char* cmp_sting = (char*) malloc(20 * sizeof(char));
			scanf("%s", cmp_sting);

			for (int j = 0; j < n; j++){
				if (strcmp(names[j], cmp_sting) == 0){
					mtx[i][j]++;
					if (bg == 0){
						mtx[j][i]++;
					}
				}
			}
			if (strcmp(cmp_sting, ";") == 0){
				flag = 0;
			}
			free(cmp_sting);
		}	
	}


	// проверка на связанность графа (крест)

	_Bool goriz = 1;
	for (int i = 0; i < n; i++){
		_Bool vertic = 0;
		for (int j = 0; j < n; j++){
			if (mtx[i][j] > 0)
				vertic = 1;

			if (mtx[j][i] > 0)
				vertic = 1;
		}
		if (vertic == 0)
			goriz = 0;
	}
	if (!goriz){
		printf("Unrelated graph\n");
	}
	else {
		printf("Related graph\n");
	}

	for (int i = 0; i < n; i++){
		printf("#%d %10s: ", i + 1, names[i]);
			for (int k = 0; k < n; k++){
				printf("%d ", mtx[i][k]);
			}
			printf("\n");
	}

// запись на языке DOT

	char* arr = (char*) calloc(500, sizeof(char));

	if(bg == 1){
		strcat(arr, "digraph G {");
		for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (mtx[i][j] > 0){
				for (int a = 0; a < mtx[i][j]; a++){
					strcat(arr, names[i]);
					strcat(arr, "->");
					strcat(arr, names[j]);
					strcat(arr, ";");
				}
			}
		}
	}
	}
	else {
		strcat(arr, "graph G {");
		for (int i = 0; i < n; i++){
			strcat(arr, names[i]);
			strcat(arr, ";");
		}
		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++){
				if (mtx[i][j] > 0){
					for (int a = 0; a < mtx[i][j]; a++){
						strcat(arr, names[i]);
						strcat(arr, "--");
						strcat(arr, names[j]);
						strcat(arr, ";");
					}
				}
			}
		}
		}

	strcat(arr, "}");

	FILE* f = fopen("graph.dot", "w");
	fprintf(f, "%s\n", arr);
	fclose(f);

	char* term = (char*) calloc(500, sizeof(char));

	strcat(term, "echo \"");
	strcat(term, arr);

	strcat(term, "\" | dot -Tpng >./graph_pikcha.png");
	printf("%s\n", term);
	system(term);
	free(term);
	free(arr);

	return 0;
}