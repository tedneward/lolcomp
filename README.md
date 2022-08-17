# lolcomp
A practice harness for building a language (LOLCODE, in this case)

Requires `antlr` tool to be installed and on the PATH someplace. Easiest way to do this: `brew install antlr`.

# Generate LOLCode grammars
Since I don't anticipate adding anything to the existing LOLCode language (he said, knowing he probably would given half a chance and any reasonable chance of success), I'm not hooking the grammar-generation into the various build steps (yet).

To build the ANTLR-generated source from the .g4 file, go into `antlr` and execute `build.sh`. Test the results with `test.sh`, which will execute the generated source against the examples in `examples` and print out the tree and tokens.

When that seems correct, deploy the generated library artifacts to the right places in the implementation directories by running `deploy.sh`. (It'll be in a "lib" directory in the right places according to Gradle or MSBuild, depending on which is in use for that implementation.)

## CLR

`dotnet build` should be sufficient to generate the ANTLR sources and compile them into an assembly (lolcodeparser.dll).

## JVM

`gradle jar` should be sufficient to generate the ANTLR sources and compile them into a jar file (lolcodeparser.jar).

# LOLCODE implementations

## C# (csharp) -- CLR

## Kotlin -- JVM

## F# (fsharp) -- CLR

## Java -- JVM

# Test against examples
The `examples` dir has some LOLCODE programs in it for testing.

# TODOs

* Desperately need more examples to work against.
    * Someday, vary up the versions and respect them (somehow).
    
