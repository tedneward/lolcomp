# lolcomp
A practice harness for building a language (LOLCODE, in this case)

Requires `antlr` tool to be installed and on the PATH someplace. Easiest way to do this: `brew install antlr`.

# Generate LOLCode grammars
Since I don't anticipate adding anything to the existing LOLCode language (he said, knowing he probably would given half a chance and any reasonable chance of success), I'm not hooking the grammar-generation into the various build steps (yet).

To build the ANTLR-generated source from the .g4 file, go into `antlr` and execute `build.sh`. Test the results with `test.sh`, which will execute the generated source against the examples in `examples` and print out the tree and tokens.

When that seems correct, generate the sources from the ANTLR grammer with `generate.sh`, and deploy the generated library artifacts to the right places in the implementation directories by running `deploy.sh`. (It'll be in a "lib" directory in the right places according to Gradle or MSBuild, depending on which is in use for that implementation.)

## CLR

`dotnet build` should be sufficient to generate the ANTLR sources and compile them into an assembly (lolcodeparser.dll).

## JVM

`gradle jar` should be sufficient to generate the ANTLR sources and compile them into a jar file (lolcodeparser.jar).

# LOLCODE implementations

## C# (csharp) -- CLR
Test with `dotnet test -l "console;verbosity=detailed"`.

## Kotlin -- JVM
Test with `gradle test`.

## F# (fsharp) -- CLR

## Java -- JVM

# Test against examples
The `examples` dir has some LOLCODE programs in it for testing. These are invoked by the tests.

# Steps

## Step 0: Core scaffolding
Generate grammar sufficient to parse/run "HAI 1.2/KTHXBYE":

* Parser/g4: program, opening, code_block, closing
* AST: ASTNode, Program, CodeBlock
* Interpreter: Interpreter execute, run

## Step 1: I HAS A

* Parser/g4: Add declarations
* AST: Declaration, Atom, Label
* Interpreter: Variant, Declaration branch (which holds map-of-String-to-Variants for scope)

## Step 2: VISIBLE

* Parser/g4: print_block
* AST: Print
* Interpreter: Add ioOut/ioIn; Print branch (looping through Print children, printing Atoms, looking up Labels)

## Step 3: GIMMEH

* Parser/g4: input_block
* AST: Input
* Interpreter: Input branch (reading from ioIn and storing to Variant-referenced-by-Label)

## Step 4: Assignment

* Parser/g4: assignment
* AST: Assignment
* Interpreter: Assignment

# TODOs

* Desperately need more examples to work against.
* Someday, vary up the versions and respect them (somehow).
    
