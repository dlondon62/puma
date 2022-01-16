#/bin/sh!
CSV_DIR=/Users/dima/Downloads/shuffleF_inputs
CMD_DIR=/Users/dima/Dennis/shuffleF
CMD_NAME=shuffleF_sample
CMD="$CMD_DIR/$CMD_NAME -X $CSV_DIR/X.csv -Y $CSV_DIR/y.csv -I $CSV_DIR/ind.csv -N $CSV_DIR/leastNansCol.csv -r 100"
echo "running CMD=$CMD" 
$CMD
