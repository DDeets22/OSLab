# OSLab PLEASE READ THIS
operating systems lab for KSU fall semester 2023, i actually got this working in the end. allthough for some reason you have to hit controll C to exit after it is done producing 98 numbers

these files are c++

so use this instead:

$ g++ producer.c -pthread -lrt -o producer

$ g++ consumer.c -pthread -lrt -o consumer

$ ./producer & ./consumer &
