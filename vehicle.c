#include <stdio.h>

// Define vehicle types and their corresponding fees (if applicable)
enum VehicleType
{
    TRUCK,
    BUS,
    CAR,
    BIKE,
    CYCLE
};
float fees[] = {50.0, 30.0, 20.0, 10.0, 5.0};

int main()
{
    // Initialize vehicle counts and total values
    int vehicleCounts[5] = {0};
    int totalVehicles = 0;
    float totalGain = 0.0;

    while (1)
    {
        // Display menu
        printf("\nVehicle Management System\n");
        printf("1. Vehicle Entry\n");
        printf("2. Show Status\n");
        printf("3. Delete Data\n");
        printf("4. Exit Program\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Vehicle Entry
            enterVehicle(vehicleCounts, &totalVehicles, &totalGain);
            break;
        case 2:
            // Show Status
            showStatus(vehicleCounts, totalVehicles, totalGain);
            break;
        case 3:
            // Delete Data
            resetData(vehicleCounts, &totalVehicles, &totalGain);
            break;
        case 4:
            // Exit Program
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to handle vehicle entry
void enterVehicle(int vehicleCounts[], int *totalVehicles, float *totalGain)
{
    // Get vehicle type
    int vehicleType;
    printf("Enter vehicle type (1-Truck, 2-Bus, 3-Car, 4-Bike, 5-Cycle): ");
    scanf("%d", &vehicleType);

    if (vehicleType < 1 || vehicleType > 5)
    {
        printf("Invalid vehicle type.\n");
        return;
    }

    // Update vehicle count and gain amount
    vehicleCounts[vehicleType - 1]++;
    *totalVehicles += 1;
    *totalGain += fees[vehicleType - 1];

    // Display success message
    printf("Vehicle successfully entered!\n");
}

// Function to display current status
void showStatus(int vehicleCounts[], int totalVehicles, float totalGain)
{
    // Display individual vehicle counts
    for (int i = 0; i < 5; i++)
    {
        printf("%s count: %d\n", getVehicleName(i), vehicleCounts[i]);
    }

    // Display total vehicles and gain
    printf("Total vehicles: %d\n", totalVehicles);
    printf("Total gain: %.2f\n", totalGain);
}

// Function to reset all data to zero
void resetData(int vehicleCounts[], int *totalVehicles, float *totalGain)
{
    for (int i = 0; i < 5; i++)
    {
        vehicleCounts[i] = 0;
    }
    *totalVehicles = 0;
    *totalGain = 0.0;

    printf("Data successfully reset!\n");
}

// Function to return vehicle name based on type
char *getVehicleName(int type)
{
    switch (type)
    {
    case TRUCK:
        return "Truck";
    case BUS:
        return "Bus";
    case CAR:
        return "Car";
    case BIKE:
        return "Bike";
    case CYCLE:
        return "Cycle";
    }
    return 0;
}
