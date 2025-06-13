# QPS Counter

统计各接口QPS计数
使用一个双向循环链表结构




```Java
	static AtomicInteger qpsCount = 100; //线程安全
    static volatile long lastSenconds =  System.currentTimeMillis()/1000;
    
    //1 计数器 
    public static boolean tryAcquire() {

        long current = System.currentTimeMillis()/1000;
        if(current == lastSenconds){
            
            if (qpsCount-- > 0) {//CAS api
                return true;
            } else {
                //限流
                return false;
            }
            
        } else{//下一个时间窗口
            lastSenconds = current;
            qpsCount = 100;
            return true;
        }   
    }
```







