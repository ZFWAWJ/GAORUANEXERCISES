/**************************************************************************************************/
/* Copyright (C) SA614296, ruanjiansheji, 2014-2015                                               */
/*                                                                                                */
/*  FILE NAME             :  menu1.c                                                              */
/*  PRINCIPAL AUTHOR      :  ZhangFang                                                            */
/*  SUBSYSTEM NAME        :  menu1                                                                */
/*  MODULE NAME           :  menu1                                                                */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/12                                                           */
/*  DESCRIPTION           :  This is a menu1 program                                              */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangFang, 2014/09/12
 *
 */

#include <stdio.h>
#include <stdlib.h>

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* menu program */

typedef struct DataNode
{
    char*    cmd;
    char*    desc;
    int      (* headler)();
    struct   DataNode * next;
}tDataNode;

static tDataNode head[] = 
{
    {"help", "this is help cmd!", Help,&head[1]},
    {"version", "menu program v1.0", NULL, NULL}
};


main()
{
    while(1)
    {
        tDataNode *p = head;
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        while(p != NULL)
        {
            if(strcmp(p -> cmd,cmd) == 0)
            {
                printf("%s - %s\n",p -> cmd, p -> desc);
                if(p -> headler != 0)
                {
                    p -> headler();
                 }
                break;
            }
            	p = p -> next;
            if(p == NULL)
            {
                printf("This is a wrong cmd!\n");
            }
        }
    }
}

int Help()
{
    tDataNode *p;
    p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p -> cmd, p -> desc);
        p = p -> next;
    }
    return 0;
}
