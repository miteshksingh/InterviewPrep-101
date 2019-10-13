* Amdahl's law describes the maximum theoretical speed up a program can achieve by using additional computing resources.

S(n) = 1/((1-P) + (P/n))

S(n) is the speedup achieved by using n cores or threads
P is the fraction of the program that is parallelizable
(1-P) is the fraction of the program that must be executed serially

* As n approaches infinity,
S(n) = 1/1-P = 1/fraction of program that is serially executed

So if fraction of program that is serially executed is 0.1,
maximum speedup will be 10 (even when using infinite processors).

* Utilization = Speedup/no of processors
As we add more processors, teh utilization of processor decreases.
