//
//  public.h
//  DS
//
//  Created by mac on 13-9-8.
//  Copyright (c) 2013年 xiaoran. All rights reserved.
//

#ifndef DS_public_h
#define DS_public_h

//#include <malloc.h>
#include "stdlib.h"  // 后来，换到mac环境下,#include <malloc.h> 应该为<malloc/malloc.h> 或 #include "stdlib.h"
#include <stdio.h>
#include <string.h>  // for memset


typedef char ElemType ; // 也可能是一个复杂的复合类型
typedef int Status;



#define OK 1
#define ERROR 0

typedef int bool;
#define YES 1
#define NO 0

#define DEFAULT_SIZE 10
#define OUT_OF_BOUND -1


#endif
