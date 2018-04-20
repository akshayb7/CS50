{"filter":false,"title":"recover1.c","tooltip":"/pset4/recover/recover1.c","undoManager":{"mark":16,"position":16,"stack":[[{"start":{"row":0,"column":0},"end":{"row":24,"column":4},"action":"insert","lines":["#include <stdio.h>","#include <stdlib.h>","","//constant to define the size of a buffer character array for temporary storage","#define BUFFERSIZE 512","","int main(int argc, char *argv[])","{","    //Checking for number of command-line arguments","    if(argc!=2)","    {","        fprintf(stderr, \"Usage: ./recover filename\\n\");","        return 1;","    }","    ","    char* inputfile = argv[1];","    //Open input file","    FILE* inptr = fopen(inputfile, \"r\");","    //Checking if able to open the input file","    if(inptr==NULL)","    {","        fprintf(stderr, \"Unable to open/find the input file\\n\");","        return 2;","    }","    "],"id":1}],[{"start":{"row":2,"column":0},"end":{"row":3,"column":0},"action":"insert","lines":["",""],"id":2}],[{"start":{"row":3,"column":0},"end":{"row":3,"column":1},"action":"insert","lines":["#"],"id":3}],[{"start":{"row":3,"column":1},"end":{"row":3,"column":2},"action":"insert","lines":["i"],"id":4}],[{"start":{"row":3,"column":2},"end":{"row":3,"column":3},"action":"insert","lines":["n"],"id":5}],[{"start":{"row":3,"column":3},"end":{"row":3,"column":4},"action":"insert","lines":["c"],"id":6}],[{"start":{"row":3,"column":4},"end":{"row":3,"column":5},"action":"insert","lines":["l"],"id":7}],[{"start":{"row":3,"column":5},"end":{"row":3,"column":6},"action":"insert","lines":["u"],"id":8}],[{"start":{"row":3,"column":6},"end":{"row":3,"column":7},"action":"insert","lines":["d"],"id":9}],[{"start":{"row":3,"column":7},"end":{"row":3,"column":8},"action":"insert","lines":["e"],"id":10}],[{"start":{"row":3,"column":8},"end":{"row":3,"column":9},"action":"insert","lines":[" "],"id":11}],[{"start":{"row":3,"column":9},"end":{"row":3,"column":11},"action":"insert","lines":["\"\""],"id":12}],[{"start":{"row":3,"column":10},"end":{"row":3,"column":11},"action":"insert","lines":["d"],"id":13}],[{"start":{"row":3,"column":11},"end":{"row":3,"column":12},"action":"insert","lines":["a"],"id":14}],[{"start":{"row":3,"column":12},"end":{"row":3,"column":13},"action":"insert","lines":["t"],"id":15}],[{"start":{"row":3,"column":13},"end":{"row":3,"column":14},"action":"insert","lines":["."],"id":16}],[{"start":{"row":3,"column":14},"end":{"row":3,"column":15},"action":"insert","lines":["h"],"id":17}]]},"ace":{"folds":[],"scrolltop":60,"scrollleft":0,"selection":{"start":{"row":16,"column":27},"end":{"row":16,"column":27},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":1,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1506339291404,"hash":"628131d7819ae3d7bc7ce6dde3e31746402a5f46"}