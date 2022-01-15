#include <stdio.h>
#include <stdlib.h>
#include "h.h"


/*
    Solving this proved to be a bit tricky.
    The way I want to do it is the following:

    - Each sentence needs a 2D-Array, representing what each segment might represent.
      For example:
      The first sentence contains the lenght 2 word "BE". This means, B and E
      must represent the one and are the vertical-right segments.

      Therefore, we know that the length 3 word "EDB", which also contains them, must
      be a seven, since that is the only alternative.

    - Once reducing every segment to its minimal possibilities, it should be possible
      to calculate what number is hiding behind the 4-letter code.

    - Repeat for every sentence in the input.


    The 2D-Array for the first sentence after reading the first word should look like
    this. (" " = false, X = true): 

        a   b   c   d   e   f   g  
    0   
    1       X           X
    2
    3
    4
    5
    6
    7
    8
    9
    
    And after reading all letters could look something like this:

        a   b   c   d   e   f   g
    0   X   X       X   X   X   X
    1       X           X
    2       X   X       X   X   X
    3       X   X   X   X       X
    4   X   X   X       X
    5   ...
    6   ...
    7       X       X   X   
    8   X   X   X   X   X   X   X
    9   ...

    So we could interpret the 4-letter code by checking what letters are in each codeword.
    For example:
        eb abdefg bcefg abce -> 1024
*/


int main() 
{   

}


void toggleSegmentToUniqueNumber(SevenSegmentDisplay *ssd, char segment, int number)
{
    // make segment small case
    if(segment >= 'A' && segment <= 'G') {
        segment += 32;    
    }
    
    // throw error if out of bounds
    if(segment < 'a' || segment > 'g') {
        perror("Passed bad arg [segment]");
        exit(EXIT_FAILURE);
    }
    
    // toggle the appropriate segments based on the number and letter
    int letter = segment - 97;

    ssd->
    
    ssd->segments[segment - 

   } 
}
