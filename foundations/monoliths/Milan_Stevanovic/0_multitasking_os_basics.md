## Multitasking OS Basics    

The ultimate goal of all the art related to building executables is to establish as much control as possible over the process of program execution.  

The interplay between the operating system kernel and the information embedded inside the executable play significant roles.    

**Moore's law** is the observation that the number of transistors in an integrated circuit doubles about every two years.   

The only way of substantially adapting to the pace of change is to define architecture of computer systems in an abstract/generalized way.  

The overall computer architecture can be represented as a structured set of abstractions.   

Certain aspects of the OS design have a decisive impact on the software architecture in general. The scenario in which the multiple parties try to access the shared resource require thoughtful implementation in which unnecessary code duplication would be avoided - **the factor that directly led to the design of shared libraries.**  

### Memory Hierarchy and Caching Strategy  

The technology seems to be far more efficient in overcoming the performance barriers of processors than memory. This phenomenon is typically referred to as "the processor-memory gap".  

**The memory's access speed is inversely proportional to the storage capacity.** The access times of the largest capacity storage devices are typically several orders of magnitude larger than that of the smallest capacity memory devices.  

The system does not use all the memory all of the time, but only some memory for some of the time.  

All we really need to do is to reserve the fastest memory for running the immediate execution, and to use the slower memory devices for the code/data that is not immediately executed.  

While the CPU fetches from the fast memory the instructions scheduled for the immediate execution, the hardware tries to guess which part of the program will be executed next and supplies that part of the code to the slower memory to await the execution. Shortly before the times comes to execute the instructions stored in the slower memory, they get transferred into the faster memory. This principle is known as **caching.**  

**The more predictable the program execution flows (measured by the lack of jumps, breaks, etc.) the smoother the caching mechanism works.**    

Memory caching hierarchy principle   
(smaller/faster -- larger/slower)  
CPU registers  
L1 Cache  
L2 Cache  
L3 Cache  
Main Memory  
Local Disks  
Remote Storage  

### Virtual Memory   

The running program is represented by the abstraction called **process**.   

**The disproportion between the needs of the memory and the limited memory availability was resolved by the concept of **virtual memory**.   

* Operating systems typically allow the program to use  2^N bytes of memory, where N is either 32 or 64.  
* Physical memory at runtime is divided into small fragments (pages), with each page being used for programs running simultaneously.  
* The complete memory layout of the running program is kept on the slow memory. Only the parts of the memory (code and data) that are about to be currently executed are loaded into the physical memory page.  

### Virtual Addressing  

The runtime placement of the program memory in a concrete address range is performed by the operating system through the mechanism of **address translation**. Its implementation is performed by the hardware module called a **memory management unit (MMU)**, which does not require any involvement of the program itself.  

Regardless of the peculiarities of a given platform's process memory division scheme, the following sections of the memory map must be always supported:   

* **Code section** carrying the machine code instructions for the CPU to execute (**.text** section)  
* **Data sections** carrying the data on which the CPU will operate. Typically, separate sections are kept for initialized data (**.data** section), for uninitialized data (**.bss** section), as well as for constant data (**.rdata** section)   
* The **heap** on which the dynamic memory allocation is run  
* The **stack**, which is used to provide independent space for functions  
* The topmost part belonging to the kernel   

### The Roles of Binaries, Compiler, Linker, and Loader  

* The program binaries carry the details of the blueprint of the running process memory map.  
* The skeleton of a binary file is created by the linker. In order to complete its task, the linker combines the binary files created by the compiler in order to fill out the variety of memoory map sections (code, data, etc).  
* The task of initial creation of the process memory map is performed by the system utility called the program loader. In the simplest sense, the loader opens the binary executable file, reads the information related to the sections, and populates the process memory map structure.  

https://www.youtube.com/watch?v=fGP6VHxqkIM  
https://www.youtube.com/watch?v=B6tJxvYBNrU  
https://www.youtube.com/watch?v=zF4VMombo7U   
https://www.youtube.com/watch?v=5lFnKYCZT5o   
https://www.youtube.com/watch?v=Bz49xnKBH_0   




