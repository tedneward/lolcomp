all: antlr test kotlin csharp

# ======== ANTLR grammar-based source generation
#
antlr: antlrbuild antlrtest jarbuild clrbuild

antlrbuild:
	echo ========== Building ANTLR 
	cd antlr; ./build.sh; cd ..

antlrtest: antlrbuild
	echo ========== Testing ANTLR
	cd antlr; ./test.sh; cd ..

jarbuild:
	echo ========== Building ANTLR JAR
	cd antlr/jar; gradle build; cd ../..

clrbuild:
	echo ========== Building ANTLR CLR
	cd antlr/clr; dotnet build; cd ../..

# ========== Test everything
#
test: kotlintest csharptest javatest

# ========== Clean everything
#
clean:
	cd antlr; ./clean.sh; cd ..
	cd kotlin; gradle clean; cd ..
	cd csharp; dotnet clean; cd ..
	cd java; gradle clean; cd ..

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
java: javabuild javatest

javabuild: jarbuild
	cd java; gradle build; cd ..

javatest: javabuild
	cd java; gradle test; cd ..

# ========== F# Interpreter
#
fsharp:

# ========== C++ Interpreter
#
cpp:
