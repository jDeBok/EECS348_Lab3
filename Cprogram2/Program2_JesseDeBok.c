#include <stdio.h>  //standard input/output needed
#include <stdbool.h>    //I like using while(true), so imported bool library
void nflScore(int score) {//input: score to consider, output: prints each combination when found
    int s8 = score; //declare my 5 variables I use to find how many of each score can be used
    int s7; //I imagined it like I was converting to a different base
    int s6; //I start with the biggest one, and loop through how many of them I can fit in my score
    int s3; //Each time I do a loop, I test out another valid combination that is either less than score or equal to score
    int s2; //I compare my total of scoring plays added and my input score to only print the correct outputs
    int total;  //end declaration of needed variables
    for (int eight = 0; eight <= score / 8; eight++) {  //for loop which runs for how many times I can fit 8 into my score
        if (s8 - eight*8 == 1) {    //I use s8 instead of score for consistency between for loops, as all the loops are the same
            continue;   //means there's only 1 point of difference between s and this many 8 point scores, which is impossible to make up
        }   //end if
        s7 = s8 - eight*8;  //new score to consider is previous minus how many 8 I use
        for (int seven = 0; seven <= s7 / 7; seven++) { //runs for how many times I can fit 7 into my score, after taking away the number of 8's I am using
            if (s7 - seven*7 == 1) {    //only one point of difference, so don't consider this many
                continue;   //skip this iteration
            }   //end if
            s6 = s7 - seven*7;  //new score to consider is previous minus how many 7 I use
            for (int six = 0; six <= s6 / 6; six++) {   //how many times I can fit 6 into score, after taking away the number of 7's and 8's I'm using
                if (s6 - six*6 == 1) {    //only one point of difference, so don't consider this many
                    continue;   //skip this iteration
                }   //end if
                s3 = s6 - six*6;    //new score to consider is previous minus how many 6 I use
                for (int three = 0; three <= s3 / 3; three++) { //how many times I can fit 3 into score, after taking away 6, 7, 8
                    if (s3 - three*3 == 1) {    //only one point of difference, so don't consider this many
                        continue;    //skip this iteration
                    }   //end if
                    s2 = s3 - three*3;  //new score to consider is previous minus how many 3 I use
                    for (int two = 0; two <= s2 / 2; two++) {   //how many 2's I can fit into my remaining score, after taking away 3, 6, 7, 8
                        if (s2 - two*2 == 1) {    //only one point of difference, so don't consider this many
                            continue;   //skip this iteration
                        }   //end if
                        total = eight*8 + seven*7 + six*6 + three*3 + two*2;    //take total out of if statement for readability, this is what my scoring plays add up towards
                        if (total == score) {   //These loops find combinations which are <= score that fit the scoring rules, so I need to filter one last times only those that are equal to score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eight,seven,six,three,two);    //print out per instructions
                        }   //end if
                    }   //end two for loop
                }   //end three for loop
            }   //end six for loop
        }   //end seven for loop
    }   //end eight for loop
}   //end nflScore
int main() {    //start main
	while (true) {  //keep prompting until user inputs a number less than or equal to 1
	    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");  //prompt
	    int score;  //declare score
	    scanf("%d", &score);    //scan my score in from user
	    if (score > 1) {    //valid NFL scores are greater than 1
	        printf("Possible combinations of Scoring Plays: \n");   //header
	        nflScore(score);    //returns nothing, print statement in function
	    }   //end if
	    else {  //ending input
	        printf("Thanks for the input.\n");  //Ending program
	        return 0;   //succesful exiting is 0
	    }   //end else
	}   //end while loop
}   //end main
