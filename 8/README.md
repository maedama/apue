#8. Process Controll
##8-2. Process Identifiers 
### process id
ある特定の時間に動いているprocessの中であればunique. 多くのシステムでuniqueなファイルを生成するロジックで用いられたりする(workerとか)がこれは必ずしも正しい使い方ではない。プロセスが終了したら、そのidは再利用対象になるからである。一方で、多くのUNIXシステムでは一度使ったidはしばらく再利用されないようなhueristicsが実装されており、厳密には正しくなくても、あまり問題にはならない。

その他もid
 1. pid_t getpid(void) : process idを取得
 2. pid_t getppid(void) : 親プロセスのidを取得a
 3. uid_t getuid(void) : 実行者のreal userId
 4. gid_t geteuid(void) : effective user_id (rootで実行するけど、apacheユーザーとして実行するケース等)
 5. gid_t getgid(void): real groupId


##8-3. fork Function
### fork()
親プロセスでは子のid、子のプロセスでは0を返す。子は自分の親がしりたければgetppidを呼べばよい。text segmentは共有される。既存の実装ではheap領域とかもCOWでforkした時点ではコピーされない。

### clone()
forkをより一般化したmethod。親プロセスと子プロセスで何を共有するかより明確にcontrolできる(linux限定?)

### IO BUFFER
stdioを使ってwriteするときは、基本的にcのレイヤーでbufferingが行われている。
これを意識せずにforkすると、意図せず二回同じものをwriteしてしまうことがある。
これは、block typeのfileであれば、同じところに二回同じものをかくだけかもしれないが、character typeのfile(stdoutとか)だと、二回おなじものをかくので意味不明。
forkする前にfsyncする必要が有る

### FD
forkするとfdは今日有される。加えてfdがさすfiletableも共有される。これはdup(fd)を呼び出したときと同じ挙動である。filetableを共有するとfileのoffsetも共有されるので、ファイルにredirectして親プロセスが何かかいてoffsetが進んだとき、子プロセス側のoffsetも進むので正しくappendできる

### 主な用途

 1. コードとして分岐したいケース : tcpサーバーとか (親はacceptして、子がacceptしたsocketをつかってごにょごにょ)
 1. プロセスが別のprogramを実行したいケース。shell(親がUserからの入力うけつけと評価をし、子がexec)

##8-4. vfork Function
 forkと以下の点で異なる
 1. address空間をコピーしない。かわりに子が親のaddress空間を直に参照する(heap含め)
 1. 子が親よりも先に実行される。(exec or exitするまで。子が親プロセスをまったりするとdeadlock)

 これは基本的に、子が別のプログラムをすぐに実行する(like in shell)用途専用
##8-5. exit Function
##8-6. wait and waitpid Functions
##8-7. waitid Function
##8-8. wait3 and wait4 Functions
##8-9. Race Conditions
##8-10. exec Functions
##8-11. Changing User Ids and Group Ids
##8-12. Interpreter Files
##8-13. system Functions
##8-14. Process Accountings
##8-15. User Identitication
##8-16. Process times
##8-17. Summary
