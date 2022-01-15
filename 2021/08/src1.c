#include <stdio.h>
#include <stdlib.h>
#include "input_test.h"

int main()
{
	/*  #  segments         count
		0: a b c   e f g => 6
		1:     c     f   => 2
		2: a   c d e   g => 5
		3: a   c d   f g => 5
		4:   b c d   f   => 4
		5: a b   d   f g => 5
		6: a b   d e f g => 6
		7: a   c     f   => 3
		8: a b c d e f g => 7
		9: a b c d   f g => 6
		
		f not on   => 2
		count is 2 => 1
		count is 4 => 4
		count is 3 => 7
		count is 7 => 8
		a not on   => 1 4
		c not on   => 5 6
		d not on   => 0 1 7
		g not on   => 1 4 7
		b not on   => 1 2 3 7
		e on       => 0 2 6 8
	*/
	int superPosition = 'a' + 'b' + 'c' + 'd' + 'e' + 'f' + 'g';
	int encoding[7];
	
	
    for(int sentence = 0; sentence < SENTENCES / 2; sentence++) {
        char *_sentence = input[sentence];

		// reset encoding
		for(int i = 0; i < 7; i++) {
			encoding[i] = superPosition;
		}
        printf("Set encoding array to super position %d\n", superPosition);
		
        // split words on the left into an array
        int words = countWords(_sentence);
        int lastpos = 0;
               
        char *words[10];
        int curWord = 0;
        for(pos = 0; _sentence[pos] != 0; pos++) {
            if(_sentence[pos] == ' ') {
                int length = pos - lastpos;
                char *word = malloc(length * sizeof(char) + 1);
                for(int i = 0; i < length; i++) {
                    word[i] = _sentence[lastpos + i];
                }
                word[length] = 0;
                words[curWord++] = word; 
            }    
        }
        
        
        
  
        printf("Counted words on left (%d) and right(%d)\n", wordsLeft, wordsRight);
        
        
        // loop over each word until the encoding has been discovered
        int stop = 0;
        while(!stop) {
            
        }
		// count letters in word
		
	}
}

