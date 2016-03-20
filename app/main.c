#include "hello.h"
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/********库里面的测试函数*********/
	char *s = "Hello World";
	print_hello(s);

	/********cjson测试部分*******************/
	cJSON_InitHooks(NULL);

	cJSON *pjsonroot = NULL;
	pjsonroot = cJSON_CreateObject();	//生成一个json
	if(pjsonroot == NULL)
	{
		printf("createjson error\n");
		exit(-1);
	}
	cJSON_AddFalseToObject(pjsonroot,"MDetectClose");

	cJSON *pjsonsub = NULL;
	pjsonsub = cJSON_CreateObject();	//生成一个子json
	if(pjsonsub == NULL)
	{
		printf("createjson error\n");
		exit(-1);
	}
	cJSON_AddNumberToObject(pjsonsub,"Channel",123);
	cJSON_AddTrueToObject(pjsonsub,"ChannelOpen");
	cJSON_AddTrueToObject(pjsonsub,"EnablePush");
	cJSON_AddNumberToObject(pjsonsub,"Sendsitivity",5);
	cJSON_AddNumberToObject(pjsonsub,"PhotoNum",7);
	cJSON_AddNumberToObject(pjsonsub,"PhotoIrvMs",8);
	cJSON_AddNumberToObject(pjsonsub,"PreRecVideoSec",9);
	cJSON_AddNumberToObject(pjsonsub,"RecVideoDurSec",10);
	cJSON_AddTrueToObject(pjsonsub,"AudioAlarm");

	cJSON *arry = cJSON_CreateArray();	//生成一个json数组
	if(arry == NULL)
	{
		printf("createjson error\n");
		exit(-1);
	}
	cJSON *p1 = cJSON_CreateObject();	//生成一个子子json
	cJSON_AddStringToObject(p1,"WeekDay","Mon");
	cJSON_AddTrueToObject(p1,"IsEnable");
	cJSON_AddStringToObject(p1,"StartTime","000000");
	cJSON_AddStringToObject(p1,"EndTime","235959");

	cJSON *p2 = cJSON_CreateObject();	//生成一个子子json
	cJSON_AddStringToObject(p2,"WeekDay","Teu");
	cJSON_AddTrueToObject(p2,"IsEnable");
	cJSON_AddStringToObject(p2,"StartTime","111111");
	cJSON_AddStringToObject(p2,"EndTime","222222");
	cJSON_AddItemReferenceToArray(arry,p1);	//把p1加入json数组
	cJSON_AddItemReferenceToArray(arry,p2);	//把p2加入json数组

	cJSON_AddItemReferenceToObject(pjsonsub,"ArmTime",arry);	//把json数组加入pjsonsub
	cJSON_AddItemReferenceToObject(pjsonroot,"MotionDetectList",pjsonsub);
	//解析json
	char *p = cJSON_Print(pjsonroot);
	char *q = cJSON_PrintUnformatted(pjsonroot);
	printf("cJSON_Print = %s\nlen = %d\n",p,strlen(p));
	printf("cJSON_PrintUnformatted = %s\nlen = %d\n",q,strlen(q));

	//正式解析cJSON_Print
	cJSON *root = cJSON_Parse(p);
	cJSON *sub = cJSON_GetObjectItem(root,root->child->string);
	printf("%s = %d\n",sub->string,sub->valueint);

	sub = cJSON_GetObjectItem(cJSON_GetObjectItem(root,"MotionDetectList"),"Channel");
	printf("Channel = %d\n",sub->valueint);

	sub = cJSON_GetObjectItem(cJSON_GetObjectItem(root,"MotionDetectList"),"AudioAlarm");
	printf("AudioAlarm = %d\n",sub->valueint);

	//sub = cJSON_GetObjectItem(cJSON_GetObjectItem(cJSON_GetArrayItem(cJSON_GetObjectItem(root,"MotionDetectList"),1),"ArmTime"),"WeekDay");
	sub = cJSON_GetObjectItem(cJSON_GetArrayItem(cJSON_GetObjectItem(cJSON_GetObjectItem(root,"MotionDetectList"),"ArmTime"),1),"WeekDay");
	printf("%s = %s\n",sub->string,sub->valuestring);

	cJSON_Delete(root);
	cJSON_Delete(pjsonroot);
	free(p);
	free(q);
	exit(0);
}

