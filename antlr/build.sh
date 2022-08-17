# Build
antlr -o code -Xexact-output-dir ../lolcode.g4
javac -d code -classpath .:antlr-4.10.1-complete.jar code/lolcode*.java

#cd jar; gradle jar; cd ..
#cd clr; dotnet build; cd ..
