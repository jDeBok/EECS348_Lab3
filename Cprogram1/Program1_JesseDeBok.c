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
void six_month_avg(float sales[12], char* months[12]) {
	for(int i = 0; i < 7; i++) {
		float sum = 0;
		for (int k = i; k < 6 + i; k++) {
			sum += sales[k];
		}
		printf("%s-%s\t%.2f\n",months[i],months[i + 5], sum / 6.0);
	}
}
void print_sales_descending(float sales[12], char* months[12]) {
	float* sorted_sales = (float*) malloc(sizeof(float) * 12);
	for(int i = 0; i < 12; i++) {
		sorted_sales[i] = sales[i];
	}
	float temp;
	for (int i = 0; i < 11; i++) {
		for (int k = 0; k < 11 - i; k++) {
			if (sorted_sales[k] > sorted_sales[k+1]) {
				temp = sorted_sales[k+1];
				sorted_sales[k+1] = sorted_sales[k];
				sorted_sales[k] = temp;
			}
		}
	}
	for (int i = 11; i >= 0; i--) {
		int whichMonth = 0;
		for (int k = 0; k < 12; k++) {
			if (sales[k] == sorted_sales[i]){
				whichMonth = k;		
			}
		}
		printf("%-10s\t$%.2f\n", months[whichMonth], sorted_sales[i]);
	}
}
int main() {
	float* month_sales_data = read_data_from("input.txt");
	char* months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	printf("EECS 348 Lab #3 Jesse DeBok, Problem 1\nMonthly Sales Report for 2022\n\nMonth\t\tSales\n");
	for(int i = 0; i < 12; i++) {
		printf("%-10s\t%.2f\n",months[i],month_sales_data[i]);
	}
	printf("\nSales summary: \n\n");
	min_max_avg(month_sales_data, months);
	printf("\nSix-Month moving average report:\n\n");
	six_month_avg(month_sales_data, months);
	printf("\nSales report (highest to lowest):\n\n");
	printf("Month\t\tSales\n");
	print_sales_descending(month_sales_data, months);
	return 0;
}
