# Deploy to JVM-based 
cp jar/build/libs/antlrcalc.jar ../java/lib/libs
cp jar/build/libs/antlrcalc.jar ../kotlin/lib/libs

# Deploy to CLR-based
cp clr/bin/Debug/net6.0/ANTLRCalcParser.dll ../csharp/lib
#cp clr/bin/Debug/net6.0/ANTLRCalcParser.dll ../fsharp/.....

