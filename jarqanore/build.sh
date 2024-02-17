#|/bin/bash

mkdir out 2> /dev/null
rm -rf out/*

echo "Compiling"
cd src
javac -d ../out -cp "../lib/jarqanore.jar" src/*.java
cd ..

echo "Generating jar"
cd out
echo "Main-Class: App" > MANIFEST.mf
echo "Class-Path: jarqanore.jar" >> MANIFEST.mf
echo "" >> MANIFEST.mf

echo "Cleanup"
jar -cfm app.jar MANIFEST.mf *.class
chmod +x app.jar
rm *.class
rm *.mf
