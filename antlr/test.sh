for TEST in ../examples/*.lol
do
    echo Testing ${TEST}
    java -classpath code:antlr-4.10.1-complete.jar org.antlr.v4.gui.TestRig lolcode program -tree -tokens ${TEST}
done
