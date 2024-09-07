#include <stdio.h>

void celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

void celsiusToKelvin(double celsius) {
    double kelvin = celsius + 273.15;
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
}

void fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
}

void fahrenheitToKelvin(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5/9;
    double kelvin = celsius + 273.15;
    printf("%.2f Fahrenheit = %.2f Kelvin\n", fahrenheit, kelvin);
}

void kelvinToCelsius(double kelvin) {
    double celsius = kelvin - 273.15;
    printf("%.2f Kelvin = %.2f Celsius\n", kelvin, celsius);
}

void kelvinToFahrenheit(double kelvin) {
    double celsius = kelvin - 273.15;
    double fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Kelvin = %.2f Fahrenheit\n", kelvin, fahrenheit);
}

int main() {
    int choice;
    double temperature;

    printf("Temperature Converter\n");
    printf("Select the input scale:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    switch (choice) {
        case 1:
            // Celsius
            printf("Select the output scale:\n");
            printf("1. Fahrenheit\n");
            printf("2. Kelvin\n");
            printf("Enter your choice (1/2): ");
            scanf("%d", &choice);
            if (choice == 1) {
                celsiusToFahrenheit(temperature);
            } else if (choice == 2) {
                celsiusToKelvin(temperature);
            } else {
                printf("Invalid choice.\n");
            }
            break;

        case 2:
            // Fahrenheit
            printf("Select the output scale:\n");
            printf("1. Celsius\n");
            printf("2. Kelvin\n");
            printf("Enter your choice (1/2): ");
            scanf("%d", &choice);
            if (choice == 1) {
                fahrenheitToCelsius(temperature);
            } else if (choice == 2) {
                fahrenheitToKelvin(temperature);
            } else {
                printf("Invalid choice.\n");
            }
            break;

        case 3:
            //Kelvin
            printf("Select the output scale:\n");
            printf("1. Celsius\n");
            printf("2. Fahrenheit\n");
            printf("Enter your choice (1/2): ");
            scanf("%d", &choice);
            if (choice == 1) {
                kelvinToCelsius(temperature);
            } else if (choice == 2) {
                kelvinToFahrenheit(temperature);
            } else {
                printf("Invalid choice.\n");
            }
            break;
    }

    return 0;
}
