# Deploy to JVM-based 
echo ====== Deploying JAR...
#cp jar/build/libs/lolcodeParser.jar ../java/lib/libs
#cp jar/build/libs/lolcodeParser.jar ../kotlin/lib/libs

# Deploy to CLR-based
echo ====== Deploying assembly...
cp clr/bin/Debug/net6.0/lolcodeParser.dll ../csharp/lib
ls -lF ../csharp/lib
#cp clr/bin/Debug/net6.0/lolcodeParser.dll ../fsharp/.....
