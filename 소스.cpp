#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<urlmon.h>
#include<Windows.h>
#include<time.h>
#define de "\t"
#define la "<>"
#define la1 ","
#pragma comment(lib, "urlmon.lib")
int select_num(char* data);
int main() {



	

	FILE* fp1 = fopen("write.txt", "w");
	char *pt;
	int count = 0, number = 0, ex_number = 0;
	printf("1\n");
	while (1) {
		URLDownloadToFile(0, "https://www1.president.go.kr/petitions/584936", "out.txt", 0, 0);
		FILE* fp = fopen("out.txt", "r");
		if (fp != NULL) {
			printf("2\n");
			char data[255];
			char n_data[255];
			char f_data[255];
			while (!feof(fp)) {
				if (count == 1034) {
					pt = fgets(data, sizeof(data), fp);
					count = 0;
					fclose(fp);
					remove("out.txt");
					break;
				}
				else {
					pt = fgets(f_data, sizeof(f_data), fp);
					//printf("%s", f_data);
					count++;
				}
			}
			//printf("%s\n", data);
			char* tok;
			tok = strtok(data, de);
			char ti[20];
			char n[20];
			char e_n[20];
			strcpy(data, tok);
			strcpy(n_data, data);
			number = select_num(n_data);
			if (ex_number == 0) {
				time_t nowTime = time(NULL);
				struct tm* pTmNow = localtime(&nowTime);
				if (pTmNow)
					printf("%d년 %d월 %02d일 %02d시 %02d분 %02d초\t", pTmNow->tm_year + 1900, pTmNow->tm_mon + 1, pTmNow->tm_mday, pTmNow->tm_hour, pTmNow->tm_min, pTmNow->tm_sec);
				printf("%s\n", data);
				sprintf(ti, "%d-%d-%02d %02d:%02d:%02d", pTmNow->tm_year + 1900, pTmNow->tm_mon + 1, pTmNow->tm_mday, pTmNow->tm_hour, pTmNow->tm_min, pTmNow->tm_sec);
				sprintf(n, "%d", number);
				printf("%s\n", ti);
				strcat(ti, "\t");
				strcat(ti, n);
				strcat(ti, "\n");

				printf("%s", ti);
				//fprintf(fp1, "sdsds");
				//fputs(ti, fp1);
				printf("%d\n", fputs(ti, fp1));
				ex_number = number;
			}
			else {
				int number_ex = number - ex_number;
				time_t nowTime = time(NULL);
				struct tm* pTmNow = localtime(&nowTime);
				if (pTmNow)
					printf("%d년 %d월 %02d일 %02d시 %02d분 %02d초\t", pTmNow->tm_year + 1900, pTmNow->tm_mon + 1, pTmNow->tm_mday, pTmNow->tm_hour, pTmNow->tm_min, pTmNow->tm_sec);
				printf("%s\n", data);
				sprintf(ti, "%d-%d-%02d %02d:%02d:%02d", pTmNow->tm_year + 1900, pTmNow->tm_mon + 1, pTmNow->tm_mday, pTmNow->tm_hour, pTmNow->tm_min, pTmNow->tm_sec);
				printf("%s\n", ti);
				sprintf(n, "%d", number);
				strcat(ti, "\t");
				strcat(ti, n);
				strcat(ti, " ");
				sprintf(e_n, "%d", number_ex);
				strcat(ti, "(");
				strcat(ti, e_n);

				strcat(ti, ")");
				strcat(ti, "\n");

				printf("%s", ti);
				//fprintf(fp1, "sdsds");
				//fputs(ti, fp1);
				printf("%d\n", fputs(ti, fp1));
				ex_number = number;
			}

		}
		else {
			printf("error\n");
		}
		Sleep(20000);
	}
	
	
	system("PAUSE>NUL");

	return 0;

}
int select_num(char* data) {
	//printf("select %s\n", data);
	//printf("%d", atoi(data));
	char* token;
	char token1[255];
	token = strtok(data, la);
	token = strtok(NULL, la);
	token = strtok(NULL, la);
	token = strtok(NULL, la);
	printf("%s\n", token);
	printf("%d\n", strlen(token));

	char* tok1;
	int aa, co = 0;
	char num[14];
	strcpy(data, token);
	//printf("%c\n", data[9]);
	tok1 = strtok(data, la1);

	while (tok1 != NULL) {
		if (co == 0) {
			strcpy(num, tok1);
			//printf("%s\n", num);
			tok1 = strtok(NULL, la1);
			co++;
		}
		else {
			strcat(num, tok1);
			//printf("%s\n", num);
			tok1 = strtok(NULL, la1);

		}
		//printf("%s\n", tok1);
		////sscanf(tok1, "%d", &aa);
		//sprintf(num, "%s", tok1);
		//tok1 = strtok(NULL, la1);
	}
	//num[13] = '\0';
	//printf("%s\n", num);
	int a = atoi(num);
	//printf("%s\n", (int)data);

	//printf("%d\n", a);
	return a;
}