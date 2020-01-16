/* Day One */
#include <cmath>
#include <stdio.h>
#include <fstream>

int calc_fuel (int mass)
{
	return (floor(mass/3)-2);
}

int main ()
{
	// Process the input file
	std::ifstream in("input.txt");

	int n = 0;
	int tot_fuel = 0;
	int fuel_req = 0;

	while(in >> n)
	{
		do 
		{
			fuel_req = calc_fuel(n);
			
			if (fuel_req > 0)
			{
				tot_fuel += fuel_req;
				n = fuel_req;
			}
		} while (fuel_req > 0);
	}

	printf("Total Required Fuel: %u", tot_fuel);
    return 0;
}
