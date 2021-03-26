# Redis slowlog


redis中的slowlog使用链表来保存


```
struct redisServer {

    // ...


    // 下一条慢查询日志的 ID
    long long slowlog_entry_id;


    // 保存了所有慢查询日志的链表
    list *slowlog;


    // 服务器配置 slowlog-log-slower-than 选项的值
    long long slowlog_log_slower_than;


    // 服务器配置 slowlog-max-len 选项的值
    unsigned long slowlog_max_len;


    // ...

};
```


一条slowlog entry标识

```
typedef struct slowlogEntry {


    // 唯一标识符
    long long id;


    // 命令执行时的时间，格式为 UNIX 时间戳
    time_t time;


    // 执行命令消耗的时间，以微秒为单位
    long long duration;


    // 命令与命令参数
    robj **argv;


    // 命令与命令参数的数量
    int argc;


} slowlogEntry;

```



