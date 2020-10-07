# Визуализация графа матрицы смежности

## Алгоритм:

- Задание имени файла с описанием графа
- Чтение из файла / чтение из матрицы смежности
- Автоматический ввод нужной команды в терминал 

## Визуализация в программе из ДЗ№2:
``` C
// запись на языке DOT

	char* graph_name = (char*) calloc(40, sizeof(char));

	printf("The name of file .dot (without .dot)\n");
	scanf("%s", graph_name);

	char* graph_name_twin = (char*) calloc(40, sizeof(char));
	strcat(graph_name_twin, graph_name);
	strcat(graph_name, ".dot");

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

	FILE* f = fopen(graph_name, "w");
	fprintf(f, "%s\n", arr);
	fclose(f);

	char* term = (char*) calloc(500, sizeof(char));

	strcat(term, "echo \"");
	strcat(term, arr);

	strcat(term, "\" | dot -Tpng >./");
	strcat(term, graph_name_twin);
	strcat(term, ".png");
	printf("%s\n", term);
	system(term);
	free(term);
	free(arr);
	free(graph_name);
	free(graph_name_twin);

```

![Alt-текст](https://github.com/igorkorobenko/FLITA_3dz/blob/main/terminal_dz2.png "териминал ДЗ2")

## Визуализация вне программы, из файла с расширением .dot:
``` C
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
```
![Alt-текст](https://github.com/igorkorobenko/FLITA_3dz/blob/main/terminal_dz3.png "териминал ДЗ3")

## Результат работы:

![Alt-текст](https://github.com/igorkorobenko/FLITA_3dz/blob/main/graph.png "териминал ДЗ")