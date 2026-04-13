## Simple Program Lifetime Stages  

The process of compiling is performed by the program called the **compiler**.  

The input for the compiler is a **translation unit**. A typical translation unit is a text file containing the source code.  

The output of the compilation is a collection of binary **object files**, one for each of the input translation units.  

In order to become suitable for execution, the object files need to be processed through another stage of program building called **linking**.   

**Compilation** is the process of translating the code of a higher-level language to the code of a lower-level language (typically, assembler or machine code).  

**Cross-compilation** is the process of compiling source on one platform to be run on another platform.  

**Decompilation** (disassembling) is the process of converting the source code of a lower-level language to the higher-level language.  

**Language translation** is the process of transforming source code of one programming language to another of the same level of complexity.  

**Language rewriting** is the process of rewriting the language expressions into a form more suitable for certain tasks (such as optimization).  


## The Stages of Compiling  

### Preprocessing  

The standard first step is running the source file through the special text processing program called the **preprocessor**.  The output of the preprocessor is the code in its final shape, which will be passed to the stage of **syntax analysis**.  

The gcc compiler provides the mode in which only the preprocessing is performed on the input source file:  

```  
gcc -E -P <input file> -o <output preprocedded file>.i  
```   
-E = preprocess only   
-P = remove linemakers  


