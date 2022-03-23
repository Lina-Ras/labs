**Problems of this version**

1) doesn't return controll to main(all threads are waiting to execute task
. While they're doing so, user can't add new threads. Threads can wait
 infinitely long)

2) doesn't actually working (see scr1.png file to understand)