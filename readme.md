# How to build
```
mpicc <name_of_the_source_code> -o <name_of_the_executable>
```
for example
```
mpicc is_prime.c -o is_prime
```
will build app from `is_prime.c` source code to an executable named `is_prime`
# How to run
```
mpirun -np <number of processes> ./<name_of_the_executable>
```
for example
```
mpirun -np 4 is_prime
```
will run `is_prime` app in 4 processes. 
# Implementations

## is_prime
Application will check if the number passed as the command line argument is the prime number.

Example:
```
mpirun -np 4 is_prime 97
```
will print on the standard output as follows
```
Number: 97; isPrime: 1
```

