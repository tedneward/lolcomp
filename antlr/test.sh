for TEST in ../examples/*.lol
do
    echo Testing ${TEST}
    java -classpath antlr-4.10.1-complete.jar:code org.antlr.v4.gui.TestRig lolcode program -tree -tokens ${TEST}
done
