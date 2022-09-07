# lolcomp
A practice harness for building a language (LOLCODE, in this case)

Requires:

* `antlr` tool to be installed and on the PATH someplace. Easiest way to do this: `brew install antlr`.  
    **Note**: I've included the (as-of-this-writing) latest ANTLR JAR file in the repository, mostly for easier reference when running the `grun` tool, but it will be helpful to have ANTLR installed globally when working with some of the grammars. There is a slight risk to using the command-line tools and my captured JAR file interchangeably (and ANTLR will warn you about it), so my scripts rely on the captured JAR. Used ANTLR 4.10.
* `gradle` and some flavor of build JDK (a la OpenJDK or whatever the JDK-*du-jour* is). Used Gradle 7 and OpenJDK 17. `brew install openjdk; brew install gradle`
* `dotnet`. Used .NET 6.0. `brew install dotnet`
* `make`. Most flavors of make would work. Used GNU make 3.81 (apple-darwin), which is the version that comes with macOS natively. Can also `brew install make` to get `gmake`, which also works (or seems to, anyway). The Makefile at the root is pretty simple--likely any flavor of make would work.

# Quick-and-dirty Build
`make all` from top-level directory.

# Generate LOLCode grammars
Since I don't anticipate adding anything to the existing LOLCode language (he said, knowing he probably would given half a chance and any reasonable chance of success), I'm not hooking the grammar-generation into the various build steps (yet).

To build the ANTLR-generated source from the .g4 file, go into `antlr` and execute `build.sh`. Test the results with `test.sh`, which will execute the generated source against the examples in `examples` and print out the tree and tokens.

When that seems correct, generate the sources from the ANTLR grammer with `generate.sh`, and deploy the generated library artifacts to the right places in the implementation directories by running `deploy.sh`. (It'll be in a "lib" directory in the right places according to Gradle or MSBuild, depending on which is in use for that implementation.)

The `lolcode.g4` grammar comes from the ANTLR project-of-grammars, but I've had to make some adjustments to it to account for some discrepancies between that grammar and various LOLCODE specifications and implementations. I don't promise that this is 100% spec-compliant. (Nor is that really a huge goal of mine.)

## CLR

`dotnet build` should be sufficient to generate the ANTLR sources and compile them into an assembly (`LOLCODEParser.dll`).

## JVM

`gradle jar` should be sufficient to generate the ANTLR sources and compile them into a jar file (`lolcodeparser.jar`).

# LOLCODE implementations

## C# (csharp) -- CLR
Test with `dotnet test -l "console;verbosity=detailed"`.

## Kotlin -- JVM
Test with `gradle test`.

## F# (fsharp) -- CLR
Test with `dotnet test -l "console;verbosity=detailed"`.

## Java -- JVM
Test with `gradle test`.

## JS -- JS

## C++

## Python

## Ruby

## Swift

# Test against examples
The `examples` dir has some LOLCODE programs in it for testing. These are invoked by the tests.

# Steps

## Step 0: Core scaffolding
Generate grammar sufficient to parse/run "HAI 1.2/KTHXBYE":

* Parser/g4: program, opening, code_block, closing
* AST: Node, Program, CodeBlock; ASTBuilder
* Interpreter: Interpreter execute, run

Should be pretty quick, aside from the fact that we're setting up bare-bones infrastructure

## Step 1: I HAS A

* Parser/g4: Add declarations
* AST: Declaration, Atom, Label
* Interpreter: Variant, Declaration branch (which holds map-of-String-to-Variants for scope)

Variant should probably be a predefined class, because that thing is way bigger than I thought it would be when I first started. Whoof.

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

## Step 5: Binary maths

* Parser/g4: maths
* AST: BinaryOp
* Interpreter: BinaryOp

## Step 6: Comparison operations





# TODOs

* Transpiler back-end(s)
* Compiler back-end(s)
* Someday, vary up the versions and respect them (somehow).
    
