

/*这段程序在什么情况下会引发线程死锁*/
/*From Dawn*/
void Thelove(List *me, List *you) {
  List *result;
  EnterCriticalSection(me->heart);
  EnterCriticalSection(you->heart);
  result->love = me->heart;
  me->heart = you->heart;
  you->heart = result->love;
  LeaveCriticalSection(me->heart);
  LeaveCriticalSection(you->heart);
}
/*两次调用发生在不同线程的同一个时间点：
线程ＡThelove(1, 2);线程ＢThelove(2, 1);
而在线程Ａ的Thelove()的第一次EnterCriticalSection()之后发生了context switch，
然后线程Ｂ执行了它的 Thelove() 操作，两个线程于是会落入“我等你,你等我”的轮回。
线程Ａ需要 2->heart，线程Ｂ需要
1->heart，而双方都掌握有对方所要的东西。发生线程死锁.*/
