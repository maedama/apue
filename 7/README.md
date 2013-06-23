# 7.Process Environenment
## 7.1 Introduction
## 7.2 main Function
 1. 実行するのはkernel。execというシステムコールが定義されてる
  1. startup routinesがmainの前に実行される
   1. 環境変数とコマンドライン引数などをkernelからうけとって(多分)、mainを実行する

## 7.3 Process Termination
### termination condition
 1. 5 normal termination process
  1. return from main
  1. exit called
  1. _exit or _Exit called
  1. Return of the last thread
  1. pthread_exit called from the last thread
 1. 3 abnormal termination process
  1. Calling abort
  1. Receipt of a signal
  1. Response of last thread to cancelleation request(?)

### atexit
exitの際によばれるhandlerの登録(_exitではよばれない)。
LIFOで最後に登録されたhandlerから順番によばれる

_exit系のfunctionはbufferingされたIOの書き出し等の処理を一切せずにkernelにreturnする。(多分stdioがatexitでfsyncするような実装になっている)

## 7.4 Command Line Arguments
特にいうべきことはなし。cのstartup routineがわたしてくれる。
## 7.5 Environement List
 1. extern char **environ

## 7.6 Memory Layout of a C Program
 1. Cのメモリの構成
  1. Text Segement(マシン語の命令。多分頻繁に使われるやつは、共有になってる。*.so?)
  1. initialized data: compile時に初期化されてるもの (long max = 99とか)
  1. uninitialized data(bss):compile時には初期化されてないもの (long sum([100])とか
  1. stack (関数のコールスタック): 変数の現在値、どこまで実行したか等が保存されてる。これにより同じ関数をrecursiveに実行しても変数の値が混ざったりする事はない.関数内で使うlocal変数とかもこの領域を使う。関数の実行が終了すると勝手に解放される
  1. heap: 動的に確保する領域。関数の実行が終了しても明示的にfreeを呼ばない限りは解放されない

## 7.7 Shared Libraries
 多くの関数で共有できるコードをデータとして共有する仕組み。これにより以下のような利点が有る
  1. 個々の実行可能ファイルのサイズが小さくなる
  1. updateが簡単
 compile時のオプションでshared libraryを使うか使わないかは選べる

## 7.8 Memory Allocation 
 1. void *malloc(size_t size) : 指定したメモリを確保する(確保した領域はindetermined)
 2. void *calloc(size_t nobj, size_t size) : 指定したサイズのオブジェクトを指定した個数分
 3. void *realloc: (void *ptr, size_t newsize) : メモリをふやしたり減らしたり(新たに確保した領域はindeterminde)

 reallocもmallocも連続した領域としてメモリの確保を試みる。そのため、realloc時は現在確保している領域をこれ以上拡大できない場合はデータのコピーが走る。
 メモリの確保の際はsbrkというシステムコールを使う。
 freeで解放したからといってkernelにメモリ空間をかえすとは限らない。領域をstockしておいて、次にmallocが呼ばれた際に再利用する。
 
 memory allocation algorithm
  1. best-fit (malloc)
  1. first-fit (malloc)
  1. quick-fit (quick-fit)

メモリをallocateする際はどこの領域にallocateするのか強く意識する必要が有る。
 1. char[BUFSIZE] : これはstack領域にallocateする。関数がreturnした段階ではもう使われては行けない領域。freeしなくてもメモリが解放される
 1. malloc : これはheap領域にallocateする。なので関数がreturnされたあとに参照されてもかまわない。一方でfreeしないとメモリが解放されないので注意。
 1. static char[BUFSIZE]: これcompile phaseで初期化されて、(多分)かなり上位の空間にallocateされるのではないか?

## 7.9 Environment Variables
 1. getenv:(const char *name): 特定の環境変数の値を取得
 1. setenv(const char *name, const char *value, intrewrite): overwrideするかしないか選べる
 1. putenv(char *str): name=valueを引数にとり、environment listに加える or overwride
 1. unsetenv(const char *name): remove env

## 7.10 setjmp and loginmp Functions
 関数をこえたgotoはcでは許可されてない。でもこれをどうしてもやりたい場合にsetjmpをlongjmpを使う事が可能。
 longjmpをすると、それまでの関数のstackは全て捨てされられる。また、setjmpすると、どのstackまで戻ってくればいいか、情報を保存しておくことができ、これをlongjmpの際にわたすことで
 戻ってくる場所を明示できる(おそらく)。関数のcallstackはどんなに複雑な呼び出しになっていてもstackなので、巻き戻しのロジックは簡単という事だと思われる。
 一方で、変数の値はかわってしまってるので特にcompile optionを指定しないと最後に評価された値になり、ここは直感的ではない。でもcompile optionを指定すると、inline展開されるので、このへんはの値もrollbackされる。

## 7.11 getrlimit and setrlimit Functions

## 7.12 Summary
 関数のcallstackの挙動についてはもう少しきちっと理解したい。今のところの想像は下記
 1 : 関数を実行するためのbyteコード。static変数、global変数は一番topのメモリ領域に確保される。
 2 : mainから関数を実行していくと、それぞれ下位のstackにつまれていく。保存される情報は、auto変数とどこまで実行しているかとかの内容。新しく関数を実行したらこれらの情報をstackにのこしたまま新しく呼び出した関数の情報がstackにつまれる
 3 : 特定の関数がreturnしたらstackから情報をpopして、auto変数等のために確保していた領域はすぐさまfreeされる
 4 : mallocはこれらのstackとは別のheap領域にメモリを確保するので、明示的にfreeしないとだめだし、逆にかんすうがreturnsしても使える。
