# Build
echo ====== Building ANTLR code for immediate testing....
antlr -o code -Xexact-output-dir lolcode.g4
javac -d code -classpath .:antlr-4.10.1-complete.jar code/lolcode*.java

