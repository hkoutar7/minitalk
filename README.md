
# Project Title : _Minitalk_ 


### A brief description of what this project does and who it's for

## About
The purpose of this project is to code a small data exchange program using UNIX signals.

#### Mandatory
* Produce server & client executables
* client must communicate a string passed as a parameter to server (referenced by its process ID) which then displays it
* Use SIGUSR1 & SIGUSR2 signals ONLY

#### Bonus
- Add reception acknowledgement system
- Support Unicode characters

| Function Used | Description |
| --- | --- |
| write | This function is used to write data to a file descriptor |
| getpid|This function retrieves the process ID (PID) of the calling process |
| signal| his function allows a process to establish a signal handler for a specific signal|
| sigaction| Similar to signal |
| pause| This function causes the calling process to sleep until a signal is received|
| kill|This function sends a signal to a specified process or group of processes|
| sleep|This function suspends the execution of the calling thread for a specified number of seconds |
| usleep| this function suspends the execution of the calling thread but in microseconds |
| exit| This function is used to terminate the calling process and return an exit status |



## Compilation

To deploy this project run

```bash
  make minitalk
```

```bash
  ./server
```

```bash
  ./cliend pid_server "string to be displayed by the server"
```


## Documentation

[signal Handler](http://www.cs.umsl.edu/~sanjiv/classes/cs2750/lectures/signals.pdf)


## Ressources

Here are some related youtube playist to get your head around unistd function

- [Unix Signals](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUYe)
- [siguser1 & siguser2](https://www.youtube.com/watch?v=83M5-NPDeWs)
- [bitwise operator](https://www.youtube.com/watch?v=jlQmeyce65Q&t=41s)
## Authors

- [@hkoutar-](https://www.github.com/hkoutar7)

