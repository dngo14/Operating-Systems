#! /bin/sh
# demonstration of UNIX signals

trap "echo SIGHUP	\(signal 1\)"  1
trap "echo SIGINT	\(signal 2\)"  2
trap "echo SIGQUIT	\(signal 3\)"  3
trap "echo SIGILL	\(signal 4\)"  4
trap "echo SIGTRAP	\(signal 5\)"  5
trap "echo SIGABRT	\(signal 6\)"  6
trap "echo SIGIOT	\(signal 6\)"  6
trap "echo SIGBUS	\(signal 7\)"  7
trap "echo SIGFPE	\(signal 8\)"  8
trap "echo SIGKILL	\(signal 9\)"  9
trap "echo SIGUSR1	\(signal 10\)" 10
trap "echo SIGSEGV	\(signal 11\)" 11
trap "echo SIGUSR2	\(signal 12\)" 12
trap "echo SIGPIPE	\(signal 13\)" 13
trap "echo SIGALRM	\(signal 14\)" 14
trap "echo SIGTERM	\(signal 15\)" 15
trap "echo SIGSTKFLT    \(signal 16\)" 16
trap "echo SIGCHLD	\(signal 17\)" 17
trap "echo SIGCONT	\(signal 18\)" 18
trap "echo SIGSTOP	\(signal 19\)" 19
trap "echo SIGTSTP	\(signal 20\)" 20
trap "echo SIGTTIN	\(signal 21\)" 21
trap "echo SIGTTOU	\(signal 22\)" 22
trap "echo SIGURG	\(signal 23\)" 23
trap "echo SIGXCPU	\(signal 24\)" 24
trap "echo SIGXFSZ	\(signal 25\)" 25
trap "echo SIGVTALRM    \(signal 26\)" 26
trap "echo SIGPROF	\(signal 27\)" 27
trap "echo SIGWINCH	\(signal 28\)" 28
trap "echo SIGIO	\(signal 29\)" 29
trap "echo SIGPWR	\(signal 30\)" 30
trap "echo SIGUNUSED	\(signal 31\)" 31
trap "echo SIG\?\?	\(signal 32\)" 32

echo PID=$$
while true
do  echo -n . 
    sleep 2
done