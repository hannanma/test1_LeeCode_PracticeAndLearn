#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
#include <iostream>
#include <string>
use namespace std
*/

#define max_word_length		11

struct sentence {
	char * word;
	int wordlength;
	struct sentence * next;
	struct sentence * prev;
};

int main(void)
{
	int cmdCount = 0;
	int cmdERROR=0;
	int i=0;
	char test1;
	struct cmd_stack * stackTMP=NULL;
	struct cmd_stack * stackTMP2=NULL;
	
	
	
	char input_buff=NULL;
	char * temp_string;
	temp_string=(char *)malloc(sizeof(char)*40960000);
	
	struct sentence * sentence_long=(sentence *)malloc(sizeof(struct sentence));
	(*sentence_long).next=NULL;
	(*sentence_long).prev=NULL;
	(*sentence_long).wordlength=0;
	(*sentence_long).word=(char *)malloc(sizeof(char)*max_word_length);
	int temp_idx_1=0;
	int temp_word_overflow=0;
	struct sentence * head = sentence_long;
	struct sentence * tail =NULL;
	struct sentence * sentence_temp = sentence_long;
	

	temp_string[0]='a';
	temp_string[1]='b';
	temp_string[2]='c';
	temp_string[3]='\0';
	printf("it is %s \n", temp_string);


	printf("Please input a sentence, nature sentence (multiple word seperated by space) is preferred: \n");
	for(;;)
	{	
	
	scanf("%c", &input_buff);
	
		if( (input_buff!=' ') && (input_buff!='\n') && temp_word_overflow==0)
		{
			(*sentence_long).word[temp_idx_1]=input_buff;
			temp_idx_1++;
			if(temp_idx_1>max_word_length-2)
			{
				(*sentence_long).word[temp_idx_1]='\0';
				printf("\n\t\t max word length supported is %d, \n\t\t your current word will be truncted as %s\n", max_word_length-1, (*sentence_long).word);
				temp_idx_1=max_word_length-1;
				temp_word_overflow=1;
			}		
		}
		if(input_buff==' ')
		{
			if(temp_idx_1==0)
			{
				continue;
			}
			temp_word_overflow=0;
			(*sentence_long).word[temp_idx_1]='\0';
			printf("\t you inputed word %s \n", (*sentence_long).word);			
			sentence_temp=(sentence *)malloc(sizeof(struct sentence));
			(*sentence_long).next=sentence_temp;
			(*sentence_temp).prev=sentence_long;
			(*sentence_temp).word=(char *)malloc(sizeof(char)*max_word_length);
			(*sentence_temp).wordlength=0;
			(*sentence_long).wordlength=temp_idx_1;
			sentence_long=sentence_temp;
			temp_idx_1=0;
			input_buff=NULL;
		}
		if(input_buff=='\n')
		{
			if(temp_idx_1==0)
			{
				tail = (*sentence_temp).prev;
				break;
			}
			(*sentence_long).word[temp_idx_1]='\0';
			printf("\t you inputed word %s \n", (*sentence_long).word);	
			input_buff = NULL;
			printf("input finished \n");
			tail = sentence_temp;
			break;
		}
/*
		else
		{
			printf("input is %c, why we are trapped here?\n", input_buff);
			return 0;
		}
*/
	}

	printf("printing all list data\n");
	
	sentence_temp=tail;
	temp_idx_1=1;
	for(;;)
	{
		if(sentence_temp==NULL)
		{
			printf("end of list data\n");
			break;
		}
		printf("the %d-st is \t%s\n", temp_idx_1, (*sentence_temp).word);
		temp_idx_1++;
		sentence_temp=(*sentence_temp).prev;
	}
	


	return 0;  


/*	
	for(;;)
	{
		
	input_buff=getchar();
	//fflush(stdin);
	if (input_buff != '\n')
		printf("input is %c \n", input_buff);
	else
		printf("input is <enter> \n");
	}


	for(;;)
	{
		
	input_buff=getchar();
	fflush(stdin);
	if (input_buff != '\n')
		printf("input is %c \n", input_buff);
	else
		printf("input is <enter> \n");
	}


	for(;;)
	{
		
	scanf("%c", &input_buff);
	//fflush(stdin);
	if (input_buff != '\n')
		printf("input is %c \n", input_buff);
	else
		printf("input is <enter> \n");
	}
*/



	
	
	

}




