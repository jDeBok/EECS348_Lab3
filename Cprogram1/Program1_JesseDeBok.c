#include <stdio.h>
#include <stdlib.h>



float* read_data_from(char* file_name) {
	const int month = 12;
	float* month_sales_data = (float*) malloc(sizeof(float) * month);
	FILE* fp = fopen(file_name, "r+");
	if (fp == NULL) {
		printf("Please check your file again.\n");
	}
	for (int i = 0; i < month; ++i) {
		fscanf(fp, "%f\n", &month_sales_data[i]);
	}
	return month_sales_data;
}
void min_max_avg(float sales[12],char* months[12]) {
	float min = sales[0];
	int whichMin = 0;
	float max = sales[0];
	int whichMax = 0;
	float sum = sales[0];
	for(int i = 1; i < 12; i++) {
		float check = sales[i];
		if (check < min) {
			min = check;
			whichMin = i;
		}
		else if (check > max) {
			max = check;
			whichMax = i;
		}
		sum += check;
	}
	printf("Minimum sales:\t%.2f\t(%s)\n",min,months[whichMin]);
	printf("Maximum sales:\t%.2f\t(%s)\n",max,months[whichMax]);
	printf("Average sales:\t%.2f\n",sum / 12.0);
}
int main() {
	float* month_sales_data = read_data_from("input.txt");
	char* months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	printf("EECS 348 Lab #3 Jesse DeBok, Problem 1\nMonthly Sales Report for 2022\nMonth\t\tSales\n");
	for(int i = 0; i < 12; i++) {
		printf("%-10s\t%.2f\n",months[i],month_sales_data[i]);
	}
	printf("Sales summary: \n");
	min_max_avg(month_sales_data, months);
	
	return 0;
}
