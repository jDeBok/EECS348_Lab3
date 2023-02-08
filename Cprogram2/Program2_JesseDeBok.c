#include <stdio.h>
#include <stdbool.h>

void nflScore(int score) {//input: score to consider, output: prints each combination when found
    int s8;
    int s7;
    int s6;
    int s3;
    int s2;
    int total;
    for (int eight = 0; eight <= score / 8; eight++) {
        s8 = score;
        if (s8 - eight*8 == 1) {
            continue;   //means there's only 1 point of difference between s and this many 8 pointers, which is impossible to make up
        }
        s7 = s8 - eight*8;
        for (int seven = 0; seven <= s7 / 7; seven++) {
            if (s7 - seven*7 == 1) {
                continue;
            }
            s6 = s7 - seven*7;
            for (int six = 0; six <= s6 / 6; six++) {
                if (s6 - six*6 == 1) {
                    continue;
                }
                s3 = s6 - six*6;
                for (int three = 0; three <= s3 / 3; three++) {
                    if (s3 - three*3 == 1) {
                        continue;
                    }
                    s2 = s3 - three*3;
                    for (int two = 0; two <= s2 / 2; two++) {
                        if (s2 - two*2 == 1) {
                            continue;
                        }
                        total = eight*8 + seven*7 + six*6 + three*3 + two*2;
                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eight,seven,six,three,two);
                        }
                    }
                }
            }
        }
    }
}
int main() {
	while (true) {
	    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
	    int score;
	    scanf("%d", &score);
	    if (score > 1) {
	        printf("Possible combinations of Scoring Plays: \n");
	        nflScore(score);
	    }
	    else {
	        printf("Thanks for the input.\n");
	        return 0;
	    }
	}
}
