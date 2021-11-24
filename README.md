# lolcomp
A practice harness for building a language (LOLCODE, in this case)

Requires `antlr` tool to be installed and on the PATH someplace. Easiest way to do this: `brew install antlr`.

# Generate LOLCode grammars
Since I don't anticipate adding anything to the existing LOLCode language (he said, knowing he probably would given half a chance and any reasonable chance of success), I'm not hooking the grammar-generation into the various build steps (yet). Therefore, before doing any build, run the below once from this directory to generate the necessary source to parse the code:

## C#
`antlr -o clr/LOLParser -visitor -package LOLParser -Dlanguage=CSharp antlr/lolcode.g4`

# Test against examples
The `examples` dir has some LOLCODE programs in it for testing.

# TODOs

* Desperately need more examples to work against.
    * Someday, vary up the versions and respect them (somehow).
    
