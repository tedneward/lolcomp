all: antlr test kotlin csharp java

# ======== ANTLR grammar-based source generation
#
antlr: antlrbuild antlrtest jarbuild clrbuild

antlrbuild: lolcode.g4
	echo ========== Building ANTLR 
	cd antlr; ./build.sh; cd ..

antlrtest: antlrbuild
	echo ========== Testing ANTLR
	cd antlr; ./test.sh; cd ..

jarbuild: lolcode.g4
	echo ========== Building ANTLR JAR
	cd antlr/jar; gradle build; cd ../..

clrbuild: lolcode.g4
	echo ========== Building ANTLR CLR
	cd antlr/clr; dotnet build; cd ../..


# ========== Kotlin Interpreter
#
kotlin: kotlinbuild kotlintest

kotlinbuild: jarbuild
	cd kotlin; gradle build; cd ..

kotlintest: kotlinbuild
	cd kotlin; gradle test; cd ..

# ========== C# Interpreter
#
csharp: csharpbuild csharptest

csharpbuild: clrbuild
	cd csharp; dotnet build; cd ..

csharptest: csharpbuild
	cd csharp; dotnet test; cd ..

# ========== Java Interpreter
#
java:

# ========== F# Interpreter
#
fsharp:

# ========== C++ Interpreter
#
cpp:
