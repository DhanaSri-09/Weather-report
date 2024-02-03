#include <stdio.h>
#include <string.h>
#define LENGTH 50

void main()
{
	char city_name[LENGTH];
	char Url[200], final_url[200];
	char weather_data[600];
	printf("Enter city name: ");
	scanf("%s", city_name);
	char *url_1 = "curl \"https://api.openweathermap.org/data/2.5/weather?q=";
	char *url_2 = "&appid=abe3a0f4d0b6cebfbe7393b4b4e3aa28&units=metric\"";
	sprintf(Url, "%s%s%s", url_1, city_name, url_2);
	sprintf(final_url, "%s>weather_data.txt",Url);
	printf("%s", Url);
	system(final_url);

	FILE *fpweather = fopen("weather_data.txt", "r");
	fgets(weather_data, sizeof(weather_data), fpweather);
	char *token = (char*)strtok(weather_data, ":");
	while (token != NULL)
	{
		if (strcmp(token, "{\"temp\"") == 0) 
		{

            token = (char*)strtok(NULL, ",");
            printf("Temperature: %s\n", token);
            break;
        }
        else
        {
        	token = (char*)strtok(NULL, ":");
        }

	}

}