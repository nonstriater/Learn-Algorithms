## const 修饰符
### 成员函数尽量使用const
const 前置，表示返回值不能被修改
const 后置，表示该函数不会修改成员变量
函数参数使用const修饰，可以防止手误 无意义赋值:
if ( a*b = c )

### 使用const enum inline替换#define，便于调试。因为使用#define定义的变量不进入符号表。

## 构造函数，析构函数
声明virtual析构函数的前提是：类中至少有一个virtual描述的成员函数，否则没有必要
一定要在在析构函数中处理掉异常
不在类成员的构造和析构期间调用虚函数。在派生类构造期间，virtual停留在基类阶层；在基类构造期间，virtual函数还不具有virtual属性。

## 补充:C语言代码规范
这里面的算法代码均使用C语言完成，养成良好的代码规范习惯，不但可以写出优质的代码，也可以更快的阅读其他优秀开源代码。代码规范主要有：

### 符号命名

**局部变量** 尽量短，能表达清楚意思即可，能简写就简写，比如"err" 表示 "error"; "fd" 表示文件描述符 ，循环变量可以使用i,j,k ;结构体成员变量不需要"m_"前缀;全局变量"g_"开头

**常量名** 全大写，单词之间"_"分割，如 "MAX_NUMBER_OF_SLAB_CLASSES" ;

**宏定义** 对于options 宏定义，适当使用前缀 ，比如：
```
/* Client classes for client limits, currently used only for
 * the max-client-output-buffer limit implementation. */
#define CLIENT_TYPE_NORMAL 0 /* Normal req-reply clients + MONITORs */
#define CLIENT_TYPE_SLAVE 1  /* Slaves. */
#define CLIENT_TYPE_PUBSUB 2 /* Clients subscribed to PubSub channels. */
#define CLIENT_TYPE_MASTER 3 /* Master. */
#define CLIENT_TYPE_OBUF_COUNT 3 
```

**枚举** 使用前缀:
```
enum conn_states {
    conn_listening,  /**< the socket which listens for connections */
    conn_new_cmd,    /**< Prepare connection for next command */
    conn_waiting,    /**< waiting for a readable socket */
    conn_read,       /**< reading in a command line */
    conn_parse_cmd,  /**< try to parse a command from the input buffer */
    conn_write,      /**< writing out a simple response */
    conn_nread,      /**< reading in a fixed number of bytes */
    conn_swallow,    /**< swallowing unnecessary bytes w/o storing */
    conn_closing,    /**< closing this connection */
    conn_mwrite,     /**< writing out many items sequentially */
    conn_closed,     /**< connection is closed */
    conn_max_state   /**< Max state value (used for assertion) */
};
```

**函数命名** 全小写，单词之间"_"分割。如"split_cmdline_strerror()"  

### 注释

所有注释使用 "/* 这里是注释 */ "


### 其他

合理使用数据类型：rel_time_t,uint8_t,uint32_t,uint64_t,size_t,off_t
