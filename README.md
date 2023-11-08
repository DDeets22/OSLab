# OSLab
operating systems lab for KSU fall semester 2023

these files are c++

so use this instead:

$ g++ producer.c -pthread -lrt -o producer
$ g++ consumer.c -pthread -lrt -o consumer
$ ./producer & ./consumer &
