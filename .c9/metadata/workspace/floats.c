{"filter":false,"title":"floats.c","tooltip":"/floats.c","undoManager":{"mark":67,"position":67,"stack":[[{"start":{"row":0,"column":0},"end":{"row":17,"column":0},"action":"insert","lines":["#include <cs50.h>","#include <stdio.h>","","int main(void)","{","    printf(\"x is \");","    int x = get_int();","    ","    printf(\"y is \");","    int y = get_int();","    ","    printf(\"%i plus %i is equal to %i\\n\", x, y, x+y);","    printf(\"%i minus %i is equal to %i\\n\", x, y, x-y);","    printf(\"%i times %i is equal to %i\\n\", x, y, x*y);","    printf(\"%i divided by %i is equal to %i\\n\", x, y, x/y);","    printf(\"remainder of %i divided by %i is %i\\n\", x, y, x%y);","}",""],"id":1}],[{"start":{"row":6,"column":6},"end":{"row":6,"column":7},"action":"remove","lines":["t"],"id":2}],[{"start":{"row":6,"column":5},"end":{"row":6,"column":6},"action":"remove","lines":["n"],"id":3}],[{"start":{"row":6,"column":4},"end":{"row":6,"column":5},"action":"remove","lines":["i"],"id":4}],[{"start":{"row":6,"column":4},"end":{"row":6,"column":5},"action":"insert","lines":["f"],"id":5}],[{"start":{"row":6,"column":5},"end":{"row":6,"column":6},"action":"insert","lines":["l"],"id":6}],[{"start":{"row":6,"column":6},"end":{"row":6,"column":7},"action":"insert","lines":["o"],"id":7}],[{"start":{"row":6,"column":7},"end":{"row":6,"column":8},"action":"insert","lines":["a"],"id":8}],[{"start":{"row":6,"column":8},"end":{"row":6,"column":9},"action":"insert","lines":["t"],"id":9}],[{"start":{"row":6,"column":20},"end":{"row":6,"column":21},"action":"remove","lines":["t"],"id":10}],[{"start":{"row":6,"column":19},"end":{"row":6,"column":20},"action":"remove","lines":["n"],"id":11}],[{"start":{"row":6,"column":18},"end":{"row":6,"column":19},"action":"remove","lines":["i"],"id":12}],[{"start":{"row":6,"column":18},"end":{"row":6,"column":19},"action":"insert","lines":["f"],"id":13}],[{"start":{"row":6,"column":19},"end":{"row":6,"column":20},"action":"insert","lines":["l"],"id":14}],[{"start":{"row":6,"column":20},"end":{"row":6,"column":21},"action":"insert","lines":["o"],"id":15}],[{"start":{"row":6,"column":21},"end":{"row":6,"column":22},"action":"insert","lines":["a"],"id":16}],[{"start":{"row":6,"column":22},"end":{"row":6,"column":23},"action":"insert","lines":["t"],"id":17}],[{"start":{"row":9,"column":6},"end":{"row":9,"column":7},"action":"remove","lines":["t"],"id":18}],[{"start":{"row":9,"column":5},"end":{"row":9,"column":6},"action":"remove","lines":["n"],"id":19}],[{"start":{"row":9,"column":4},"end":{"row":9,"column":5},"action":"remove","lines":["i"],"id":20}],[{"start":{"row":9,"column":4},"end":{"row":9,"column":5},"action":"insert","lines":["d"],"id":21}],[{"start":{"row":9,"column":4},"end":{"row":9,"column":5},"action":"remove","lines":["d"],"id":22}],[{"start":{"row":9,"column":4},"end":{"row":9,"column":5},"action":"insert","lines":["f"],"id":23}],[{"start":{"row":9,"column":5},"end":{"row":9,"column":6},"action":"insert","lines":["l"],"id":24}],[{"start":{"row":9,"column":6},"end":{"row":9,"column":7},"action":"insert","lines":["o"],"id":25}],[{"start":{"row":9,"column":7},"end":{"row":9,"column":8},"action":"insert","lines":["a"],"id":26}],[{"start":{"row":9,"column":8},"end":{"row":9,"column":9},"action":"insert","lines":["t"],"id":27}],[{"start":{"row":9,"column":20},"end":{"row":9,"column":21},"action":"remove","lines":["t"],"id":28}],[{"start":{"row":9,"column":19},"end":{"row":9,"column":20},"action":"remove","lines":["n"],"id":29}],[{"start":{"row":9,"column":18},"end":{"row":9,"column":19},"action":"remove","lines":["i"],"id":30}],[{"start":{"row":9,"column":18},"end":{"row":9,"column":19},"action":"insert","lines":["f"],"id":31}],[{"start":{"row":9,"column":19},"end":{"row":9,"column":20},"action":"insert","lines":["l"],"id":32}],[{"start":{"row":9,"column":20},"end":{"row":9,"column":21},"action":"insert","lines":["o"],"id":33}],[{"start":{"row":9,"column":21},"end":{"row":9,"column":22},"action":"insert","lines":["a"],"id":34}],[{"start":{"row":9,"column":22},"end":{"row":9,"column":23},"action":"insert","lines":["t"],"id":35}],[{"start":{"row":11,"column":13},"end":{"row":11,"column":14},"action":"remove","lines":["i"],"id":36}],[{"start":{"row":11,"column":13},"end":{"row":11,"column":14},"action":"insert","lines":["f"],"id":37}],[{"start":{"row":12,"column":13},"end":{"row":12,"column":14},"action":"remove","lines":["i"],"id":38}],[{"start":{"row":12,"column":13},"end":{"row":12,"column":14},"action":"insert","lines":["f"],"id":39}],[{"start":{"row":13,"column":13},"end":{"row":13,"column":14},"action":"remove","lines":["i"],"id":40}],[{"start":{"row":13,"column":13},"end":{"row":13,"column":14},"action":"insert","lines":["f"],"id":41}],[{"start":{"row":14,"column":13},"end":{"row":14,"column":14},"action":"remove","lines":["i"],"id":42}],[{"start":{"row":14,"column":13},"end":{"row":14,"column":14},"action":"insert","lines":["f"],"id":43}],[{"start":{"row":13,"column":22},"end":{"row":13,"column":23},"action":"remove","lines":["i"],"id":44}],[{"start":{"row":13,"column":22},"end":{"row":13,"column":23},"action":"insert","lines":["f"],"id":45}],[{"start":{"row":12,"column":22},"end":{"row":12,"column":23},"action":"remove","lines":["i"],"id":46}],[{"start":{"row":12,"column":22},"end":{"row":12,"column":23},"action":"insert","lines":["f"],"id":47}],[{"start":{"row":11,"column":21},"end":{"row":11,"column":22},"action":"remove","lines":["i"],"id":48}],[{"start":{"row":11,"column":21},"end":{"row":11,"column":22},"action":"insert","lines":["f"],"id":49}],[{"start":{"row":11,"column":36},"end":{"row":11,"column":37},"action":"remove","lines":["i"],"id":50}],[{"start":{"row":11,"column":36},"end":{"row":11,"column":37},"action":"insert","lines":["f"],"id":51}],[{"start":{"row":12,"column":37},"end":{"row":12,"column":38},"action":"remove","lines":["i"],"id":52}],[{"start":{"row":12,"column":37},"end":{"row":12,"column":38},"action":"insert","lines":["f"],"id":53}],[{"start":{"row":13,"column":37},"end":{"row":13,"column":38},"action":"remove","lines":["i"],"id":54}],[{"start":{"row":13,"column":37},"end":{"row":13,"column":38},"action":"insert","lines":["f"],"id":55}],[{"start":{"row":14,"column":42},"end":{"row":14,"column":43},"action":"remove","lines":["i"],"id":56}],[{"start":{"row":14,"column":42},"end":{"row":14,"column":43},"action":"insert","lines":["f"],"id":57}],[{"start":{"row":15,"column":40},"end":{"row":15,"column":41},"action":"remove","lines":["i"],"id":58}],[{"start":{"row":15,"column":40},"end":{"row":15,"column":41},"action":"insert","lines":["f"],"id":59}],[{"start":{"row":15,"column":46},"end":{"row":15,"column":47},"action":"remove","lines":["i"],"id":60}],[{"start":{"row":15,"column":46},"end":{"row":15,"column":47},"action":"insert","lines":["f"],"id":61}],[{"start":{"row":14,"column":27},"end":{"row":14,"column":28},"action":"remove","lines":["i"],"id":62}],[{"start":{"row":14,"column":27},"end":{"row":14,"column":28},"action":"insert","lines":["f"],"id":63}],[{"start":{"row":15,"column":26},"end":{"row":15,"column":27},"action":"remove","lines":["i"],"id":64}],[{"start":{"row":15,"column":26},"end":{"row":15,"column":27},"action":"insert","lines":["f"],"id":65}],[{"start":{"row":15,"column":4},"end":{"row":15,"column":63},"action":"remove","lines":["printf(\"remainder of %f divided by %f is %f\\n\", x, y, x%y);"],"id":66}],[{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"remove","lines":["    "],"id":67}],[{"start":{"row":14,"column":59},"end":{"row":15,"column":0},"action":"remove","lines":["",""],"id":68}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":14,"column":59},"end":{"row":14,"column":59},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1498646016039,"hash":"eb2eae9b2f9bd5bbb94032c1a485b1b658f27134"}