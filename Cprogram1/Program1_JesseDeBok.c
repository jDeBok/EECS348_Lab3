#include <stdio.h>
#include <stdlib.h>
float* read_data_from(char* file_name) {	//input: name of file which has my sales report in it,	output: returns a float array of size 12 that has each month's sales number
	float* month_sales_data = (float*) malloc(sizeof(float) * 12);	//allocate enough memory to hold 12 floats, with a pointer called month_sales_data pointing towards first address
	FILE* fp = fopen(file_name, "r+");  //opens a file, reading
	if (fp == NULL) {   //invalid file or didn't find file
		printf("Please check your file again.\n");  //error catch
	}   //end if
	for (int i = 0; i < 12; ++i) {  //Assuming there is only 12 months worth of data, reads in 12 lines and stores in month_sales_data
		fscanf(fp, "%f\n", &month_sales_data[i]);   //scans in floats, looks for new line characters to signify end of float
	}   //end for loop
	return month_sales_data;    //return my 12 array that has my sales numbers in it
}   //end file read
void min_max_avg(float sales[12],char* months[12]) {    //inputs: sales array and month array,  outputs: prints min/max/avg sales and associated months
	float min = sales[0];   //declare my minimum to be first value, will overwrite in for loop if needed
	int whichMin = 0;       //keeps track of which index has my min month, so I can then print out the name of it
	float max = sales[0];   //declare my maximum to be first value, will overwrite if needed
	int whichMax = 0;       //keeps track of which index is max month
	float sum = sales[0];   //sum is total of all sales
	for(int i = 1; i < 12; i++) {   //start at index 1 and go to index 11, once for each month
		float check = sales[i]; //this is my number to check, prevents from repeatedly calling sales[i]
		if (check < min) {  //finds a new min
			min = check;    //min is new min
			whichMin = i;   //new index for new min
		}   //end if
		else if (check > max) { //finds new max
			max = check;    //max is new max
			whichMax = i;   //new index of new max
		}   //end if
		sum += check;   //add value to sum
	}   //end for loop
	printf("Minimum sales:\t%.2f\t(%s)\n", min, months[whichMin]);    //print min sales in which month, in a nice format
	printf("Maximum sales:\t%.2f\t(%s)\n", max, months[whichMax]);    //print max sales and the month
	printf("Average sales:\t%.2f\n", sum / 12.0);    //takes total and divides by 12 to get average over 12 months
}   //end min/max/avg
void six_month_avg(float sales[12], char* months[12]) { //inputs: sales array and month array, outputs: prints rolling 6 month array 7 times
	for(int i = 0; i < 7; i++) {    //for loop for the starting month, starts at January ends July
		float sum = 0;  //redeclare sum each time 
		for (int k = i; k < 6 + i; k++) {   //add up the 6 months for this rolling average
			sum += sales[k];    //adds to sum
		}   //end for loop
		printf("%s-%s\t%.2f\n",months[i],months[i + 5], sum / 6.0); //prints out rolling sum and over what months
	}   //end for loop
}   //end six_month_avg
void print_sales_descending(float sales[12], char* months[12]) {    //inputs: sales array and month array, outputs: sales report highest to lowest
	float* sorted_sales = (float*) malloc(sizeof(float) * 12);  //create a new array to hold my sorted values, won't use input array as I need that to get my month index
	for(int i = 0; i < 12; i++) {   //copy sales to sorted_sales
		sorted_sales[i] = sales[i]; //copies values
	}   //end for loop
	float temp; //declare temp for bubble sort
	for (int i = 0; i < 11; i++) {  //simple bubble sort for this, since it's only 12 values don't need to implement a merge-sort or faster sort
		for (int k = 0; k < 11 - i; k++) {  //goes over the 12 values to complete bubble sort
			if (sorted_sales[k] > sorted_sales[k+1]) {  //puts the greatest value at the end of the array
				temp = sorted_sales[k+1];   //classic bubble sort
				sorted_sales[k+1] = sorted_sales[k];    //use temp to swap the values without losing one of them
				sorted_sales[k] = temp; //could've also done insertion or selection sort for code simplicity
			}   //end if
		}   //end for loop
	}   //end for loop
	for (int i = 11; i >= 0; i--) { //printing out my sorted_sales array.  Since I want highest to lowest I go backwards
		int whichMonth = 0; //keeps track of my month index
		for (int k = 0; k < 12; k++) {  //this for loop finds which month I need to display
			if (sales[k] == sorted_sales[i]){   //goes over my sales array, and when it finds the sales value it sets whichMonth to that index
				whichMonth = k; //my own version of indexOf
			}   //end if
		}   //end for loop
		printf("%-10s\t$%.2f\n", months[whichMonth], sorted_sales[i]);  //display the month and its associated sales number
	}   //end for loop
}   //end descending sales
int main() {    //start main function
	float* month_sales_data = read_data_from("input.txt");  //read my input file, called "input.txt", assuming valid file exists to complete lab
	char* months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; //month array, used in functions to display month names
	printf("EECS 348 Lab #3 Jesse DeBok, Problem 1\nMonthly Sales Report for 2022\n\nMonth\t\tSales\n");    //Header text
	for(int i = 0; i < 12; i++) {   //prints out the simple sales report, sorted by month
		printf("%-10s\t%.2f\n",months[i],month_sales_data[i]);  //month tab sales data
	}   //end for loop
	printf("\nSales summary: \n\n");    //header text
	min_max_avg(month_sales_data, months);  //call min/max/avg, prints from function so no return
	printf("\nSix-Month moving average report:\n\n");   //header text
	six_month_avg(month_sales_data, months);    //prints from function rolling average
	printf("\nSales report (highest to lowest):\n\n");  //header text
	printf("Month\t\tSales\n"); //more header, use tabs and newlines for clarity
	print_sales_descending(month_sales_data, months);   //prints from function
	return 0;   //succesful execution is return 0
}   //end main
