#include <stdio.h>

// Function to display the menu
void displayMenu()
{
    printf("\nVehicle Management System\n");
    printf("1. Enter Vehicle\n");
    printf("2. Show Status\n");
    printf("3. Delete Data\n");
    printf("4. Exit Program\n");
    printf("Enter your choice: ");
}

int main()
{
    int truckCount = 0, busCount = 0, carCount = 0, bikeCount = 0, cycleCount = 0;
    int totalVehicles = 0;
    float totalGainAmount = 0.0;

    int choice;
    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Enter Vehicle
            int vehicleType;
            printf("\nEnter Vehicle Type\n");
            printf("1. Truck\n2. Bus\n3. Car\n4. Bike\n5. Cycle\n");
            printf("Enter vehicle type (1-5): ");
            scanf("%d", &vehicleType);

            // Update counts and gain amount
            switch (vehicleType)
            {
            case 1:
                truckCount++;
                totalGainAmount += 10.0; // Assuming price for truck
                break;
            case 2:
                busCount++;
                totalGainAmount += 8.0; // Assuming price for bus
                break;
            case 3:
                carCount++;
                totalGainAmount += 5.0; // Assuming price for car
                break;
            case 4:
                bikeCount++;
                totalGainAmount += 2.0; // Assuming price for bike
                break;
            case 5:
                cycleCount++;
                totalGainAmount += 1.0; // Assuming price for cycle
                break;
            default:
                printf("Invalid choice\n");
            }
            totalVehicles++;
            printf("Vehicle entered successfully!\n");
            break;
        case 2:
            // Show Status
            printf("\n--- Vehicle Status ---\n");
            printf("Trucks: %d\n", truckCount);
            printf("Buses: %d\n", busCount);
            printf("Cars: %d\n", carCount);
            printf("Bikes: %d\n", bikeCount);
            printf("Cycles: %d\n", cycleCount);
            printf("Total Vehicles: %d\n", totalVehicles);
            printf("Total Gain Amount: $%.2f\n", totalGainAmount);
            break;
        case 3:
            // Delete Data
            truckCount = 0;
            busCount = 0;
            carCount = 0;
            bikeCount = 0;
            cycleCount = 0;
            totalVehicles = 0;
            totalGainAmount = 0.0;
            printf("\nAll data deleted!\n");
            break;
        case 4:
            // Exit Program
            printf("Exiting... Thank you!\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
