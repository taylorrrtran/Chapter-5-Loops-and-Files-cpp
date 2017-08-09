#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include "chapter5Problems.h"

int main()
{
	chapter5Problems *p1 = new chapter5Problems;
	p1->studentLineUpMod();
	system("pause");
	return 0;
}

void chapter5Problems::sumOfNumbers()
{
	//This program will have a running total starting from 1 to the number entered

	int num, total = 0;

	//Gather input
	std::cout << "Enter an integer: ";
	std::cin >> num;

	//Input validation: Positive numbers only
	while (num < 0)
	{
		std::cout << "Number can only be positive. Try again: ";
		std::cin >> num;
	}

	//Running total and display it
	for (int i = 1; i <= num; i++)
		total += i;

	std::cout << "Total from 1 to " << num << ": " << total << std::endl;
}

void chapter5Problems::ASCIIcodes()
{
	//This program will print ASCII codes from 0 to 127

	std::cout << "ASCII Codes from 0 to 127: " << std::endl;
	for (int i = 0; i <= 127; i++)
	{
		char letter = i;
		std::cout << letter << " ";
		if ((i % 16) == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

void chapter5Problems::oceanLevels()
{
	/* This program will display a table showing how much the ocean will have
	   risen for each year for the next 25 years by 1.5 mm a year */

	double total = 0.0;
	std::cout << "Ocean rising levels by 1.5 mm per year: " << std::endl;

	for (int i = 1; i <= 25; i++)
	{
		//Running total
		total += 1.5;

		//Display yearly amount that the ocean has risen
		std::cout << "Year " << i << ": " << total << std::endl;
	}
}

void chapter5Problems::caloriesBurned()
{
	//This program will display the number of calories burned from 5-30 minutes by 5's

	std::cout << "For burning 3.6 calories per minute, you get...." << std::endl;

	for (int i = 5; i <= 30; i += 5)
	{
		//Running total
		double calories = (3.6 * i);

		//Display the number of calories for every 5 minutes
		std::cout << "Calories burned at " << i << " minutes: " << calories << std::endl;
	}
}

void chapter5Problems::membershipFees()
{
	//This program will show projected rates of a membership after increasing 4% every year from $2500

	double total = 2500;

	for (int i = 1; i <= 6; i++)
	{
		//Running total
		total += (total * 0.04);

		//Display the yearly rates
		std::cout << std::setprecision(2) << std::showpoint << std::fixed;
		std::cout << "Yearly rates for membership after a 4% increase every year: $" << total << std::endl;
	}
}

void chapter5Problems::distanceTraveled()
{
	//This program will display the distance a vehicle has traveled for each hour

	double mph, hours;

	//Gather miles per hour of car
	std::cout << "What is the speed of the vehicle in mph? ";
	std::cin >> mph;

	//Input validation: mph cannot be negative
	while (mph < 0)
	{
		std::cout << "The miles per hour cannot be negative. Try again: ";
		std::cin >> mph;
	}

	//Gather hours traveled
	std::cout << "How many hours has it traveled? ";
	std::cin >> hours;

	//Input validation: Hours cannot be less than one
	while (hours < 1)
	{
		std::cout << "Hours cannot be less than one. Try again: ";
		std::cin >> hours;
	}

	//Display the distance traveled by the hour
	std::cout << "Hour \t Distance Traveled \n" ;
	std::cout << "--------------------------\n";
	for (int i = 1; i <= hours; i++)
	{
		double distance = i * mph;
		std::cout << i << "\t" << std::setw(13) << std::right << distance << std::endl;
	}
}

void chapter5Problems::penniesForPay()
{
	/* This program will display how much one would earn after his/her salary
	   doubling every day starting from one penny on the first day */

	double days;

	//Gather input
	std::cout << "Enter the amount of days worked: ";
	std::cin >> days;

	//Input validation: days cannot be less than one
	while (days < 1)
	{
		std::cout << "Days cannot be less than one. Try again: ";
		std::cin >> days;
	}

	//Calculate salary
	double salary = 0.01, total = 0.01;
	for (int i = 2; i <= days; i++)
	{
			salary *= 2.0;
			total += salary;
	}

	//Display salary in dollar format
	salary = (salary / 100);
	std::cout << std::setprecision(2) << std::showpoint << std::fixed;
	std::cout << "Total salary: $" << total << std::endl;
}

void chapter5Problems::mathTutor()
{
	//This program will generated random numbers that will be computed and need to be solved by user input

	double answer, total;
	char selection = '0';

	//Get the system time
	unsigned seed = time(0);

	//Seed the random number generator
	srand(seed);

	//Range value from 1 - 999
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 999;

	//Display menu
	while (selection != '5')
	{
		//Generate new numbers as long as the loop is active
		int number1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		int number2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		double numDouble1;
		double numDouble2;

		//Menu
		std::cout << "Please choose one of the following options: \n";
		std::cout << "1. Addition \n";
		std::cout << "2. Subtraction \n";
		std::cout << "3. Multiplication \n";
		std::cout << "4. Division \n";
		std::cout << "5. Quit the program \n";
		std::cout << "Enter the number next to your selection: ";

		//Gather selection
		std::cin >> selection;

		//Switch
		switch (selection)
		{
		case '1' : //Display problem and let user type in answer for addition problem.
			std::cout << std::setw(5) << number1 << std::endl;
			std::cout << "+ " << std::setw(3) << number2 << std::endl;
			std::cout << "------" << std::endl;

			//Gather input
			std::cout << "Type in the correct answer: ";
			std::cin >> answer;

			//If correct, congratulate. Else, show correct answer.
			total = number1 + number2;
			if (answer == total)
				std::cout << "Congratulations! That is the correct answer! \n" << std::endl;
			else
				std::cout << "Correct answer is: " << total << std::endl << std::endl;
			break;

		case '2': //Display problem and let user type in answer for subtraction problem.
			std::cout << std::setw(5) << number1 << std::endl;
			std::cout << "- " << std::setw(3) << number2 << std::endl;
			std::cout << "------" << std::endl;

			//Gather input
			std::cout << "Type in the correct answer: ";
			std::cin >> answer;

			//If correct, congratulate. Else, show correct answer.
			total = number1 - number2;
			if (answer == total)
				std::cout << "Congratulations! That is the correct answer! \n" << std::endl;
			else
				std::cout << "Correct answer is: " << total << std::endl << std::endl;
			break;

		case '3': //Display problem and let user type in answer for multiplication problem.
			std::cout << std::setw(5) << number1 << std::endl;
			std::cout << "* " << std::setw(3) << number2 << std::endl << std::endl;
			std::cout << "------" << std::endl;

			//Gather input
			std::cout << "Type in the correct answer: ";
			std::cin >> answer;

			//If correct, congratulate. Else, show correct answer.
			total = number1 * number2;
			if (answer == total)
				std::cout << "Congratulations! That is the correct answer! \n" << std::endl;
			else
				std::cout << "Correct answer is: " << total << std::endl;
			break;

		case '4': //Display problem and let user type in answer for division
			numDouble1 = (double)rand() / MAX_VALUE;
			numDouble2 = (double)rand() / MAX_VALUE;
			std::cout << std::setw(5) << numDouble1 << std::endl;
			std::cout << "/ " << std::setw(3) << numDouble2 << std::endl;
			std::cout << "------" << std::endl;

			//Gather input
			std::cout << "Type in the correct answer: ";
			std::cin >> answer;

			//If correct, congratulate.Else, show correct answer.
			total = numDouble1 / numDouble2;
			if (answer == total)
				std::cout << "Congratulations! That is the correct answer! \n" << std::endl;
			else
				std::cout << "Correct answer is: " << total << std::endl << std::endl;
			break;

			//Quit the program
		case '5': break;
		}
	}
}

void chapter5Problems::hotelOccupancy()
{
	//This program calculates the occupancy rate for a hotel

	double floors, rooms, roomsOccupied, 
		   totalRooms = 0.0, totalOccupied = 0.0, totalVacant = 0.0, 
		   occupiedPercentage;

	//Gather input
	std::cout << "Enter how many floors are in the hotel: ";
	std::cin >> floors;

	//Input validation: floors cannot be less than one
	while (floors < 1)
	{
		std::cout << "Floors cannot be less than one. Try again: ";
		std::cin >> floors;
	}

	//Ask how many rooms are on each floor
	for (int i = 1; i <= floors; i++)
	{
		//Skip the 13th floor as tradition dictates that hotels don't have a 13th floor
		if (i == 13)
			continue;

		//Gather input
		std::cout << "Enter the amount of rooms on Floor " << i << ": ";
		std::cin >> rooms;

		//Input validation: rooms cannot be less than 10
		while (rooms < 10)
		{
			std::cout << "Rooms cannot be less than 10. Try again: ";
			std::cin >> rooms;
		}

		//How many rooms are occupied
		std::cout << "How many of those rooms are occupied? ";
		std::cin >> roomsOccupied;

		//Input validation: rooms occupied cannot be more than the room total on the fllor
		while (roomsOccupied < 0 || roomsOccupied > rooms)
		{
			std::cout << "Rooms occupied cannot be negative or more than the total amount of rooms on the floor. Try again: ";
			std::cin >> roomsOccupied;
		}

		//Keep running total of the rooms occupied
		totalRooms += rooms;
		totalOccupied += roomsOccupied;
	}

	//Display total rooms, total occupied and percentage of occupation, and total rooms vacant
	totalVacant = totalRooms - totalOccupied;
	occupiedPercentage = (totalOccupied / totalRooms) * 100.0;

	std::cout << std::setprecision(2) << std::showpoint << std::fixed;
	std::cout << "Total rooms in the hotel:              " << std::setw(8) << totalRooms << std::endl;
	std::cout << "Total rooms occupied in the hotel:     " << std::setw(8) << totalOccupied << std::endl;
	std::cout << "Total rooms vacant in the hotel:       " << std::setw(8) << totalVacant << std::endl;
	std::cout << "Percantage of rooms that are occupied: " << std::setw(8) << occupiedPercentage << "% \n";
}

void chapter5Problems::averageRainfall()
{
	//This program will collect data and calculate the average rainfall over a period of years

	double years, rainfall, totalRainfall = 0.0, averageRainfall, totalMonths = 0.0;

	//Gather years
	std::cout << "Enter the amount of years: ";
	std::cin >> years;

	//Input validation: Years cannot be less than 1
	while (years < 1)
	{
		std::cout << "Years cannot be less than one. Try again: ";
		std::cin >> years;
	}

	//Gather rainfall
	for (int i = 1; i <= years; i++)
	{
		std::cout << "For Year " << i << std::endl;
		for (int j = 1; j <= 12; j++)
		{
			std::cout << "Enter the rainfall in inches for Month " << j << ": ";
			std::cin >> rainfall;

			//Input validation: rainfall cannot be negative
			while (rainfall < 0)
			{
				std::cout << "Rainfall cannot be negative. Try again: ";
				std::cin >> rainfall;
			}

			//Running total of rainfall
			totalRainfall += rainfall;
		}

		//Number of months total
		totalMonths = 12 * i;
	}

	//Display average rainfall per month and total rainfall
	averageRainfall = totalRainfall / totalMonths;

	std::cout << std::setprecision(2) << std::showpoint << std::fixed;
	std::cout << "Total rainfall in inches for the period: " << totalRainfall << std::endl;
	std::cout << "Total months in the period:              " << totalMonths << std::endl;
	std::cout << "Average rainfall per month in inches:    " << averageRainfall << std::endl;
}

void chapter5Problems::population()
{
	//This program will predict the size of a population of organisms

	double organisms, increase, daysMultiply;

	//Gather starting number of organisms
	std::cout << "What is the starting number of organisms: ";
	std::cin >> organisms;

	//Input validation: Organisms cannot be less than two
	while (organisms < 2)
	{
		std::cout << "Starting number cannot be less than 2. Try again: ";
		std::cin >> organisms;
	}

	//Gather population increase in percentage
	std::cout << "Enter the average daily population increase (in percentage): ";
	std::cin >> increase;

	//Input cannot be negative
	while (increase < 0)
	{
		std::cout << "Average daily population increase cannot be negative. Try again: ";
		std::cin >> increase;
	}
	
	//Convert input to percentage
	increase /= 100;

	//Gather the number of days they will multiply
	std::cout << "Enter the number of days the organism will multiply: ";
	std::cin >> daysMultiply;

	//Input validation: Days cannot be less than 1
	while (daysMultiply < 1)
	{
		std::cout << "Days multiply cannot be less than 1. Try again: ";
		std::cin >> daysMultiply;
	}

	//Loop to display the population size each day
	for (int i = 1; i <= daysMultiply; i++)
	{
		if (i == 1)
			std::cout << "Day " << i << ": Population is " << organisms << std::endl;
		else
		{
			organisms += (organisms * increase);
			std::cout << "Day " << i << ": Population is " << organisms << std::endl;
		}
	}
}

void chapter5Problems::celsiusToFahrenheitTable()
{
	//This program will print a table of Celsius to Fahrenheit table from temperatures 0 - 20

	double celsiusConversion;
	std::cout << "Celsius to Fahrenheit conversion from 0 to 20 degress: \n";

	for (int i = 0; i <= 20; i++)
	{
		celsiusConversion = ((9.0 / 5.0) * i) + 32.0;
		std::cout << "Celsius: " << i;
		std::cout << "\t Fahrenheit: " << celsiusConversion << std::endl;
	}
}

void chapter5Problems::greatestAndLeastOfThree()
{
	//This program will run a loop and find the greatest and least numbers in the series

	double num, largest = 0.0, smallest = 0.0;
	std::cout << "This program will display the largest and smallest number of a series. \n";

	std::cout << "Enter a number. Type -99 when you would like to quit: ";
	std::cin >> num;

	if (num == -99)
		exit(0);
	else
		largest = num;
	

	//Gather series and figure out the largest and smallest of the series
	while (num != -99)
	{
		std::cout << "Enter a number. Type -99 when you would like to quit: ";
		std::cin >> num;


		//Find the largest and smallest numbers of the series
		if (num == -99)
			break;
		else if (num > largest)
			largest = num;
		else if (num < smallest)
			smallest = num;
	}

	//Display the largest and smallest numbers in the series
	std::cout << "Largest number in the series:  " << largest << std::endl;
	std::cout << "Smallest number in the series: " << smallest << std::endl;
}

void chapter5Problems::studentLineUp()
{
	/* This program will show which student will be in the front and end of the line
	assuming no two student have similar names */

	std::string student;
	double numStudents;

	//Gather num of students
	std::cout << "Enter the number of students: ";
	std::cin >> numStudents;

	//Input validation: Number of students cannot be less than 1 or greater than 25
	while (numStudents < 1 || numStudents > 25)
	{
		std::cout << "Number of students cannot be less than 1 or greater than 25. Try again: ";
		std::cin >> numStudents;
	}

	//Gather student names and alphabetize to see who is first and last
	std::cin.ignore();
	std::string first, last;
	for (int i = 1; i <= numStudents; i++)
	{
		std::cout << "Enter student name: ";
		std::getline(std::cin, student);

		if (i == 1)
		{
			first = student;
			last = student;
		}
		else if (first < student)
			first = student;
		else if (last > student)
			last = student;
	}

	//Display first and last student of the list
	std::cout << "First student: " << last << std::endl;
	std::cout << "Last student:  " << first << std::endl;
}

void chapter5Problems::payrollReport()
{
	//This program will display totals for gross and net pay, state and federal tax, FICA withholdings

	double grossPay, totalGross = 0.0,
		   netPay, totalNet = 0.0,
		   FICA, totalFICA = 0.0,
		   stateTax, totalState = 0.0,
		   federalTax, totalFederal = 0.0;
	std::string employee;

	do
	{
		//Gather employee number
		std::cout << "Enter a employee number or 0 if you would like to terminate the program: ";
		std::getline(std::cin, employee);

		//Gather taxes, pays, and FICA withholdings

		std::cout << "Enter the gross pay for Employee " << employee << ": ";
		std::cin >> grossPay;

		//Input validation: Gross pay cannot be negative
		while (grossPay < 0)
		{
			std::cout << "Gross pay cannot be negative. Try again: ";
			std::cin >> grossPay;
		}

		std::cout << "Enter the net pay for Employee " << employee << ": ";
		std::cin >> netPay;

		//Input validation: Net pay cannot be negative
		while (netPay < 0)
		{
			std::cout << "Net pay cannot be negative. Try again: ";
			std::cin >> netPay;
		}

		std::cout << "Enter the state tax paid by Employee " << employee << ": ";
		std::cin >> stateTax;

		//Input validation: State tax cannot be negative
		while (stateTax < 0)
		{
			std::cout << "State tax cannot be negative. Try again: ";
			std::cin >> stateTax;
		}

		std::cout << "Enter the federal tax paid by Employee " << employee << ": ";
		std::cin >> federalTax;

		//Input validation: Federal tax cannot be negative
		while (federalTax < 0)
		{
			std::cout << "Federal tax cannot be negative. Try again: ";
			std::cin >> federalTax;
		}

		std::cout << "Enter the FICA witholdings by Employee " << employee << ": ";
		std::cin >> FICA;

		//Input validation: FICA cannot be negative
		while (FICA < 0)
		{
			std::cout << "FICA cannot be negative. Try again: ";
			std::cin >> FICA;
		}

		//Total of state tax, federal tax, and FICA withholdings cannot be greater than gross pay
		while ((stateTax + federalTax + FICA) > grossPay)
		{
			std::cout << "Total sum of state and federal tax and FICA withholdings cannot be greater than gross pay. \n";

			std::cout << "Enter the state tax paid by Employee " << employee << ": ";
			std::cin >> stateTax;

			//Input validation: State tax cannot be negative
			while (stateTax < 0)
			{
				std::cout << "State tax cannot be negative. Try again: ";
				std::cin >> stateTax;
			}

			std::cout << "Enter the federal tax paid by Employee " << employee << ": ";
			std::cin >> federalTax;

			//Input validation: Federal tax cannot be negative
			while (federalTax < 0)
			{
				std::cout << "Federal tax cannot be negative. Try again: ";
				std::cin >> federalTax;
			}

			std::cout << "Enter the FICA witholdings by Employee " << employee << ": ";
			std::cin >> FICA;

			//Input validation: FICA cannot be negative
			while (FICA < 0)
			{
				std::cout << "FICA cannot be negative. Try again: ";
				std::cin >> FICA;
			}
		}

		//Running totals
		totalGross += grossPay;
		totalNet += netPay;
		totalState += stateTax;
		totalFederal += federalTax;
		totalFICA += FICA;
	} while (employee != "0");

	//Display totals
	std::cout << std::setprecision(2) << std::showpoint << std::fixed;
	std::cout << "Total gross pay:         $" << totalGross << std::endl;
	std::cout << "Total net pay:           $" << totalNet << std::endl;
	std::cout << "Total state tax:         $" << totalState << std::endl;
	std::cout << "Total federal tax:       $" << totalFederal << std::endl;
	std::cout << "Total FICA withholdings: $" << totalFICA << std::endl;
}

void chapter5Problems::savingsAccountBalanceAndMod()
{
	//This program will calculate the balance of a savings account at the end of a period

	double annualInterest, monthlyInterest, interest, balance, months, deposit, withdraw;
	double totalDeposits = 0, totalWithdraws = 0, totalInterest = 0;

	//Write report to a file
	std::ofstream outputFile;
	std::string filename;

	//Ask user for file name
	std::cout << "Enter a filename to read the report to and including its file extension: ";
	std::cin >> filename;

	//Open file
	outputFile.open(filename);

	//Input validation: Make sure file can be opened
	while (!outputFile)
	{
		std::cout << "There was an error in opening the file. Try again: ";
		std::cin >> filename;
		outputFile.open(filename);
	}

	//Gather input
	std::cout << "Enter the annual interest rate: ";
	std::cin >> annualInterest;

	std::cout << "Enter the starting balance: $";
	std::cin >> balance;

	std::cout << "Enter how many months have passed since the account was established: ";
	std::cin >> months;

	//Monthly interest
	interest = (annualInterest / 100.00) / 12.00;

	//Input valiadtion: Months can't be negative
	while (months < 1)
	{
		std::cout << "Amount of months passed cannot be negative. Try again: ";
		std::cin >> months;
	}
	
	//For loop to ask amount deposited/withdrawn every month
	for (int i = 1; i <= months; i++) 
	{
		std::cout << "Amount to be deposited into Month " << i << ": ";
		std::cin >> deposit;

		//Input valiadtion: Deposit can't be negative
		while (deposit < 0)
		{
			std::cout << "Amount deposited cannot be negative. Try again: ";
			std::cin >> deposit;
		}

		//Keep track of total deposits
		totalDeposits += deposit;

		std::cout << "Amount to be withdrawn from this month: " << i << ": ";
		std::cin >> withdraw;

		//Input valiadtion: Withdraw can't be negative
		while (withdraw < 0)
		{
			std::cout << "Amount withdrawn cannot be negative. Try again: ";
			std::cin >> withdraw;
		}

		//Keep track of total amount of withdraws
		totalWithdraws += withdraw;

		//Keep a total of the balance
		balance += deposit - withdraw;

		//If balance is negative, close the account and loop
		if (balance < 0)
		{
			std::cout << "The account has been closed due to a negative balance. \n";
			break;
		}

		monthlyInterest = balance * interest;
		balance += monthlyInterest;

		//Calculate total monthly interest
		totalInterest += monthlyInterest;
	}

	//Display totals
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	std::cout << "Total balance:             $" << std::setw(8) << balance << std::endl;
	std::cout << "Total amount of deposits:  $" << std::setw(8) << totalDeposits << std::endl;
	std::cout << "Total amount of withdraws: $" << std::setw(8) << totalWithdraws <<std::endl;
	std::cout << "Total interest earned:     $" << std::setw(8) << totalInterest << std::endl;

	//Read report into file
	outputFile << std::setprecision(2) << std::fixed << std::showpoint;
	outputFile << "Total balance:             $" << std::setw(8) << balance << std::endl;
	outputFile << "Total amount of deposits:  $" << std::setw(8) << totalDeposits << std::endl;
	outputFile << "Total amount of withdraws: $" << std::setw(8) << totalWithdraws << std::endl;
	outputFile << "Total interest earned:     $" << std::setw(8) << totalInterest << std::endl;

	//Close file
	outputFile.close();


}

void chapter5Problems::salesBarChart()
{
	//This program will display a graph comparing each store's bar sales

	double sales1, sales2, sales3, sales4, sales5;

	//For loop to gather sales for 5 stores
	for (int i = 1; i <= 5; i++)
	{
		std::cout << "Enter today's sales for Store " << i << ": $";
		if (i == 1)
			std::cin >> sales1;
		else if (i == 2)
			std::cin >> sales2;
		else if (i == 3)
			std::cin >> sales3;
		else if (i == 4)
			std::cin >> sales4;
		else
			std::cin >> sales5;
	}

	sales1 /= 100.00;
	sales2 /= 100.00;
	sales3 /= 100.00;
	sales4 /= 100.00;
	sales5 /= 100.00;

	//Display bar chart for each store
	std::cout << "SALES BAR CHART\n";
	std::cout << "(Each * = $100)\n";

	//Store 1
	std::cout << "Store 1: ";
	for (int i = 1; i <= sales1; i++)
		std::cout << "*";
	std::cout << std::endl;

	//Store 2
	std::cout << "Store 2: ";
	for (int i = 1; i <= sales2; i++)
		std::cout << "*";
	std::cout << std::endl;

	//Store 3
	std::cout << "Store 3: ";
	for (int i = 1; i <= sales3; i++)
		std::cout << "*";
	std::cout << std::endl;

	//Store 4
	std::cout << "Store 4: ";
	for (int i = 1; i <= sales4; i++)
		std::cout << "*";
	std::cout << std::endl;

	//Store 5
	std::cout << "Store 5: ";
	for (int i = 1; i <= sales5; i++)
		std::cout << "*";
	std::cout << std::endl;
		
}

void chapter5Problems::populationBarChart()
{
	//This program will produce a bar chart based on reading population from a file

	std::ifstream inputFile;
	std::string filename1;
	double year, population, numAsterisk;

	//Ask user for file name
	std::cout << "Enter a filename of the Prairieville population including its file extension: ";
	std::cin >> filename1;

	//Open file
	inputFile.open(filename1);

	//Input validation: Make sure file can be opened
	while (!inputFile) {
		std::cout << "There was an error in opening the file. Try again: ";
		std::cin >> filename1;
		inputFile.open(filename1);
	}

	//Display bar graph
	std::cout << "PRAIRIEVILLE POPULATION GROWTH\n";
	std::cout << "(each * represents 1,000 people)\n";

	//Gather data from file
	while (inputFile >> year >> population)
	{
		//Display
		std::cout << year << ' ';

		//Calculate number of asterisks where 1 asterisk = every 1,000 people and display them
		numAsterisk = population / 1000.00;
		for (int i = 1; i <= numAsterisk; i++)
			std::cout << '*';

		std::cout << std::endl;
	}

	//Close the file
	inputFile.close();
	
}

void chapter5Problems::budgetAnalysis()
{
	//This program will display if a user is over or under his/her budget

	double budget, expenses, total = 0;

	//Gather input
	std::cout << "Enter the budget for this month: $";
	std::cin >> budget;

	//Calculate running total to see if user is over/under budget
	std::cout << "Enter 0000 when you are done typing in expenses: ";
	std::cin >> expenses;
	while (expenses != 0000)
	{
		std::cout << "Enter expenses: $";
		std::cin >> expenses;
		total += expenses;
	}

	if (total > budget)
		std::cout << "You are over budget.\n";
	else if (total < budget)
		std::cout << "You are under budget.\n";
	else
		std::cout << "You have just reached your budget.\n";
}

void chapter5Problems::randomNumberGuessingAndMod()
{
	//This program will run until the user guests the correct number

	double number;
	int total = 1;

	//Get the system time
	unsigned seed = time(0);

	//Seed the random number generator
	srand(seed);

	//Range value from 1 - 999
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 999;

	//Generate new numbers as long as the loop is active
	int randomNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	//Display if random number is too high or too low
	std::cout << "Enter a number to correct the guessing number: ";
	std::cin >> number;
	while (number != randomNum)
	{
		if (number < randomNum)
		{
			std::cout << "Too low, try again: ";
			std::cin >> number;
		}
		else if (number > randomNum)
		{
			std::cout << "Too high, try again: ";
			std::cin >> number;
		}

		//Keep running total
		total += 1;
	}

	//Show correct number and total amount of guesses
	std::cout << "Congrats! You have guessed the correct number!\n";
	std::cout << "Total amount of guesses: " << total << std::endl;
}

void chapter5Problems::squareDisplay()
{
	//This program will create a square display based on an integer input

	int square;

	//Gather input
	std::cout << "Enter the length and rows of a square to be displayed: ";
	std::cin >> square;

	//Input validation: The length and row cannot be less than 1 or greater than 15
	while (square < 1 || square > 15)
	{
		std::cout << "The length and row cannot be less than 1 or greater than 15. Try again: ";
		std::cin >> square;
	}

	//Display square
	for (int i = 1; i <= square; i++)
	{
		for (int j = 1; j <= square; j++)
		{
			std::cout << "X";
			//Indent line if the counter modulo square is equal to zero
			if (j % square == 0)
				std::cout << std::endl;
		}
	}
}

void chapter5Problems::patternDisplay()
{
	//This program will display two opposite patterns

	std::cout << "Pattern A: \n";
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << "+";
			if (j % i == 0)
				std::cout << std::endl;
		}
	}

	std::cout << "\nPattern B: \n";
	for (int i = 10; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << "+";
			if (j % i == 0)
				std::cout << std::endl;
		}
	}
}

void chapter5Problems::numericProcessing()
{
	//This program will read integers from a file and output the content's running total

	std::ifstream inputFile;
	std::string filename1;
	double numbers, totalSum = 0, totalNumbers = 0;
	double average;

	//Ask user for file name
	std::cout << "Enter a filename of integers including its file extension: ";
	std::cin >> filename1;

	//Open file
	inputFile.open(filename1);

	//Input validation: Make sure file can be opened
	while (!inputFile) 
	{
		std::cout << "There was an error in opening the file. Try again: ";
		std::cin >> filename1;
		inputFile.open(filename1);
	}

	//Calculate running total and number of numbers in the file
	while (inputFile >> numbers)
	{
		totalSum += numbers;
		totalNumbers += 1;
	}

	//Close the file
	inputFile.close();

	//Calculate average of the numbers in the file
	average = totalSum / totalNumbers;

	//Display variables
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	std::cout << "Total sum of the numbers in the file  : " << totalSum << std::endl;
	std::cout << "Total number of numbers in the file   : " << totalNumbers << std::endl;
	std::cout << "Average of all the numbers in the file: " << average << std::endl;
}

void chapter5Problems::studentLineUpMod()
{
	/* This program will add a modification to the student line up program by reading
	   student names from a file */

	std::ifstream inputFile;
	std::string filename;

	//Gather student file name
	std::cout << "Enter the file with the name of students along with the file extension: ";
	std::cin >> filename;

	//Open file
	inputFile.open(filename);

	//Input validation: Make sure file can be opened
	while (!inputFile)
	{
		std::cout << "There was an error in opening the file. Try again: ";
		std::cin >> filename;
		inputFile.open(filename);
	}

	//Read student names and alphabetisze to see who is first and last
	std::string first, last, student;
	int i = 1;
	while (inputFile >> student)
	{
		//Only the first student will be to be initalized to first and last so following names can be compared to
		if (i == 1)
		{
			first = student;
			last = student;
			i++;
		}
		else if (first < student)
			first = student;
		else if (last > student)
			last = student;
	}

	//Display first and last student of the list
	std::cout << "First student: " << last << std::endl;
	std::cout << "Last student:  " << first << std::endl;
}

chapter5Problems::chapter5Problems()
{
}

