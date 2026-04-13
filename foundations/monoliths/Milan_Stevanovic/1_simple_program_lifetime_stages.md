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

### Lexical Analysis  

**Lexical analysis** takes the raw text of the source file and chops it into **tokens**: the smallest meaningful pieces for the parser.  
  
For example, from:  
  
```    
x = a + 42;  
```  
  
the lexer produces something like:  
  
* identifier: `x`  
* operator: `=`  
* identifier: `a`  
* operator: `+`  
* integer literal: `42`  
* punctuation: `;`  
  
So lexical analysis is mainly about answering:  
  
* “Where does one meaningful piece end and the next begin?”  
* “Is this piece an identifier, keyword, number, string literal, operator, etc.?”  
  
For example, in:  
  
```  
int value = 10;  
```  
  
the lexer sees:  
  
* `int` → keyword  
* `value` → identifier  
* `=` → operator  
* `10` → integer literal  
* `;` → punctuation  
  
What it usually does **not** do is decide whether the whole statement is grammatically valid in the language. That is mostly the job of **parsing**.  
  
So the stages are better thought of like this:  
  
**1. Lexical analysis**  
Raw characters → tokens.  
  
It removes or ignores things that are not important at this stage, such as many whitespaces and comments, and groups characters into tokens.  
  
**2. Parsing / syntax analysis**  
Tokens → grammatical structure.  
  
It checks whether the token sequence fits the language grammar.  
  
For example:  
  
```  
int = x 10;  
```  
  
may be tokenizable just fine, but the parser says the order makes no syntactic sense.  
  
**3. Semantic analysis**  
Syntactically valid structure → meaning/type correctness.  
  
For example:  
  
```  
int x;  
x = "hello";  
```  
  
This may be syntactically fine, but semantically wrong because the types do not match.  
  
So the important distinction is:  
  
* **Lexer**: “What are these pieces?”  
* **Parser**: “Are these pieces arranged legally?”  
* **Semantic analysis**: “Does this legal structure actually make sense?”  
  
> During lexical analysis, the compiler reads the source text, ignores comments and irrelevant whitespace, and converts the character stream into tokens. These tokens are then passed to the parser, which checks whether their arrangement follows the language grammar. After that, semantic analysis checks whether the syntactically correct constructs also make sense.  
  
  
### Compilation  (internal IR + code generation to assembly)  

At this stage, the compiler translates the preprocessed C/C++ source into target-specific assembly code. This means the program is lowered from language-level constructs such as expressions, variables, and function calls into instructions and data representations appropriate for the target architecture. If the source still contains compile-time errors, compilation stops and no assembly file is produced.   

Using GCC, this stage can be observed with:   

```  
gcc -S <iniput file> -o <output file>.s  
```   

This generates a human-readable assembly text file. It is not executable; it is only an intermediate representation that can be inspected by the developer or passed to the assembler in the next stage. On x86, the emitted assembly may be printed in either AT&T or Intel syntax, for example via -masm=att or -masm=intel.   


### Assembling  

At this stage, the assembler translates the assembly source file (`.s`) into an **object file** (`.o`) containing machine code, data, and metadata such as symbols and relocation information. Unlike the previous stage, this is no longer a human-readable representation of the program. The output is usually not yet executable, because references to functions or variables in other object files or libraries may still need to be resolved during linking. In GCC’s stage model, this comes after compilation proper and before linking.   

```  
gcc -c file.s -o file.o  
```   

or, if starting from C/C++ source and stopping after assembly:   

```   
gcc -c file.c -o file.o   
```   

GCC documents `-c` as “compile or assemble … but do not link,” with the ultimate output being an object file. It also documents `.s` as assembler code input.    

> **Assembling:** convert assembly code (`.s`) into an object file (`.o`). The result contains machine-level code but is usually not yet a complete executable.   

https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html "Overall Options (Using the GNU Compiler Collection (GCC))"    

_To inspect the contents of an object file, a tool such as objdump can translate machine instructions back into assembly notation. Be careful with objdump -D: it disassembles all non-empty non-BSS sections, so some output may look like nonsense because those bytes are data, not real code._    


