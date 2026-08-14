#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// =============================
// 1. STRUCTURE DEFINITIONS
// =============================

typedef struct {
    int medicineID;
    char name[50];
    int currentStock;
    float unitPriceLKR;
    char expiryDate[15];
} Medicine;

typedef struct {
    int prescriptionID;
    char patientName[50];
    int targetMedicineID;
    int dailyDosage;
    int durationDays;
} Prescription;

typedef struct {
    int logID;
    int prescriptionID;
    int quantityDispensed;
    float measuredWeight;
    int status; // 1 - Success (Match), 0 - Error (Mismatch)
} DispenseLog;

typedef struct {
    int billID;
    char patientName[50];
    float subtotal;
    float finalBalance;
    int isPaid; // 1 - Paid, 0 - Unpaid
} Bill;

typedef struct {
    int supplierID;
    char companyName[50];
    int suppliedMedicineID;
    int leadTimeDays;
} Supplier;

// ==========================================
// 2. GLOBAL ARRAYS OF STRUCTURES
// ==========================================
Medicine inventory[MAX_ITEMS];
int medCount = 0;

Prescription prescriptions[MAX_ITEMS];
int rxCount = 0;

DispenseLog dispenses[MAX_ITEMS];
int dispCount = 0;

Bill bills[MAX_ITEMS];
int billCount = 0;

Supplier suppliers[MAX_ITEMS];
int supCount = 0;

// ==========================================
// 3. FUNCTION DECLARATIONS
// ==========================================
void clearBuffer();

// Member 1
void addMedicine();
void updateStockQuantity();
void searchMedicineByName();
void displayLowStockAlerts();
void removeExpiredStock();

// Member 2
void createNewPrescription();
void validatePrescriptionDetails();
void searchPrescriptionByID();
void viewPatientHistory();
void modifyPrescriptionDosage();

// Member 3
void processDispenseRequest();
void simulateWeightVerification();
void logDispenseTransaction();
void flagWeightMismatches();
void viewDispenseHistory();

// Member 4
void generatePatientBill();
void applyInsuranceDiscount();
void processBillPayment();
void viewUnpaidBalances();
void calculateDailyRevenue();

// Member 5
void registerNewSupplier();
void autoGeneratePurchaseOrders();
void viewSuppliersByItem();
void updateSupplierContact();
void calculateAverageLeadTime();

// ==========================================
// MAIN FUNCTION & MENU INTERFACE
// ==========================================
int main() {
    int p = -1;
    while (p != 0) {
        printf("\n=== SMART MEDICAL INVENTORY & DISPENSING SYSTEM ===\n");
        printf("1. Inventory Management \n");
        printf("2. Prescription Management \n");
        printf("3. Automated Dispensing Simulator \n");
        printf("4. Billing & Revenue \n");
        printf("5. Supplier Logistics \n");
        printf("0. Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &p);
        clearBuffer();

        int subChoice;
        switch (p) {
            case 1:
                printf("\n--- INVENTORY MENU ---\n1. Add Medicine\n2. Update Stock\n3. Search Medicine\n4. Low Stock Alerts\n5. Remove Item\nChoice: ");
                scanf("%d", &subChoice); clearBuffer();
                if (subChoice == 1) addMedicine();
                else if (subChoice == 2) updateStockQuantity();
                else if (subChoice == 3) searchMedicineByName();
                else if (subChoice == 4) displayLowStockAlerts();
                else if (subChoice == 5) removeExpiredStock();
                break;
            case 2:
                printf("\n--- PRESCRIPTION MENU ---\n1. Create Prescription\n2. Validate Details\n3. Search by ID\n4. View Patient History\n5. Modify Dosage\nChoice: ");
                scanf("%d", &subChoice); clearBuffer();
                if (subChoice == 1) createNewPrescription();
                else if (subChoice == 2) validatePrescriptionDetails();
                else if (subChoice == 3) searchPrescriptionByID();
                else if (subChoice == 4) viewPatientHistory();
                else if (subChoice == 5) modifyPrescriptionDosage();
                break;
            case 3:
                printf("\n--- DISPENSING MENU ---\n1. Process Dispense Request\n2. Simulate Weight Verification\n3. Manual Log Entry\n4. Flag Mismatches\n5. View Dispense History\nChoice: ");
                scanf("%d", &subChoice); clearBuffer();
                if (subChoice == 1) processDispenseRequest();
                else if (subChoice == 2) simulateWeightVerification();
                else if (subChoice == 3) logDispenseTransaction();
                else if (subChoice == 4) flagWeightMismatches();
                else if (subChoice == 5) viewDispenseHistory();
                break;
            case 4:
                printf("\n--- BILLING MENU ---\n1. Generate Patient Bill\n2. Apply Discount\n3. Process Payment\n4. View Unpaid Balances\n5. Calculate Daily Revenue\nChoice: ");
                scanf("%d", &subChoice); clearBuffer();
                if (subChoice == 1) generatePatientBill();
                else if (subChoice == 2) applyInsuranceDiscount();
                else if (subChoice == 3) processBillPayment();
                else if (subChoice == 4) viewUnpaidBalances();
                else if (subChoice == 5) calculateDailyRevenue();
                break;
            case 5:
                printf("\n--- SUPPLIER MENU ---\n1. Register Supplier\n2. Auto-Generate POs\n3. View Suppliers by Item\n4. Update Contact Name\n5. Calc Average Lead Time\nChoice: ");
                scanf("%d", &subChoice); clearBuffer();
                if (subChoice == 1) registerNewSupplier();
                else if (subChoice == 2) autoGeneratePurchaseOrders();
                else if (subChoice == 3) viewSuppliersByItem();
                else if (subChoice == 4) updateSupplierContact();
                else if (subChoice == 5) calculateAverageLeadTime();
                break;
            case 0:
                printf("Exiting System...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}

// ==========================================
// FUNCTION IMPLEMENTATIONS
// ==========================================

void clearBuffer() {
    while (getchar() != '\n'); // To clear input buffer
}

// --- MODULE 1: INVENTORY ---
void addMedicine() {
    if (medCount >= MAX_ITEMS) return;
    printf("Enter ID: "); scanf("%d", &inventory[medCount].medicineID); clearBuffer();
    printf("Enter Name: "); fgets(inventory[medCount].name, 50, stdin); inventory[medCount].name[strcspn(inventory[medCount].name, "\n")] = 0;
    printf("Enter Stock: "); scanf("%d", &inventory[medCount].currentStock);
    printf("Enter Price (LKR): "); scanf("%f", &inventory[medCount].unitPriceLKR); clearBuffer();
    printf("Enter Expiry: "); fgets(inventory[medCount].expiryDate, 15, stdin); inventory[medCount].expiryDate[strcspn(inventory[medCount].expiryDate, "\n")] = 0;
    medCount++;
    printf("Medicine Added.\n");
}
void updateStockQuantity() {
    int id, amount;
    printf("Enter Medicine ID to update: "); scanf("%d", &id);
    for (int i = 0; i < medCount; i++) {
        if (inventory[i].medicineID == id) {
            printf("Current Stock: %d. Enter amount to add (use negative to subtract): ", inventory[i].currentStock);
            scanf("%d", &amount);
            inventory[i].currentStock += amount;
            printf("New Stock: %d\n", inventory[i].currentStock);
            return;
        }
    }
    printf("Medicine not found.\n");
}
void searchMedicineByName() {
    char search[50];
    printf("Enter name: "); fgets(search, 50, stdin); search[strcspn(search, "\n")] = 0;
    for (int i = 0; i < medCount; i++) {
        if (strcmp(inventory[i].name, search) == 0) {
            printf("Found: ID %d | Stock: %d | LKR %.2f\n", inventory[i].medicineID, inventory[i].currentStock, inventory[i].unitPriceLKR);
            return;
        }
    }
    printf("Not found.\n");
}
void displayLowStockAlerts() {
    printf("--- Low Stock (< 10 units) ---\n");
    for (int i = 0; i < medCount; i++) {
        if (inventory[i].currentStock < 10) {
            printf("ID: %d | Name: %s | Stock: %d\n", inventory[i].medicineID, inventory[i].name, inventory[i].currentStock);
        }
    }
}
void removeExpiredStock() {
    int id;
    printf("Enter ID to remove: "); scanf("%d", &id);
    for (int i = 0; i < medCount; i++) {
        if (inventory[i].medicineID == id) {
            for (int j = i; j < medCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift array elements
            }
            medCount--;
            printf("Item removed.\n");
            return;
        }
    }
    printf("Not found.\n");
}

// --- MODULE 2: PRESCRIPTION ---
void createNewPrescription() {
    if (rxCount >= MAX_ITEMS) return;
    printf("Enter Rx ID: "); scanf("%d", &prescriptions[rxCount].prescriptionID); clearBuffer();
    printf("Enter Patient Name: "); fgets(prescriptions[rxCount].patientName, 50, stdin); prescriptions[rxCount].patientName[strcspn(prescriptions[rxCount].patientName, "\n")] = 0;
    printf("Enter Target Med ID: "); scanf("%d", &prescriptions[rxCount].targetMedicineID);
    printf("Enter Daily Dosage: "); scanf("%d", &prescriptions[rxCount].dailyDosage);
    printf("Enter Duration (Days): "); scanf("%d", &prescriptions[rxCount].durationDays);
    rxCount++;
    printf("Prescription Created.\n");
}
void validatePrescriptionDetails() {
    int rxId;
    printf("Enter Rx ID to validate: "); scanf("%d", &rxId);
    for (int i = 0; i < rxCount; i++) {
        if (prescriptions[i].prescriptionID == rxId) {
            for (int j = 0; j < medCount; j++) {
                if (inventory[j].medicineID == prescriptions[i].targetMedicineID) {
                    printf("Valid: Medicine '%s' exists in inventory.\n", inventory[j].name);
                    return;
                }
            }
            printf("Invalid: Target Medicine ID %d does not exist.\n", prescriptions[i].targetMedicineID);
            return;
        }
    }
    printf("Rx Not Found.\n");
}
void searchPrescriptionByID() {
    int rxId;
    printf("Enter Rx ID: "); scanf("%d", &rxId);
    for (int i = 0; i < rxCount; i++) {
        if (prescriptions[i].prescriptionID == rxId) {
            printf("Patient: %s | Med ID: %d | Dosage: %d/day for %d days\n",
                   prescriptions[i].patientName, prescriptions[i].targetMedicineID, prescriptions[i].dailyDosage, prescriptions[i].durationDays);
            return;
        }
    }
    printf("Rx Not Found.\n");
}
void viewPatientHistory() {
    char searchName[50];
    int found = 0;
    printf("Enter Patient Name: "); fgets(searchName, 50, stdin); searchName[strcspn(searchName, "\n")] = 0;
    for (int i = 0; i < rxCount; i++) {
        if (strcmp(prescriptions[i].patientName, searchName) == 0) {
            printf("Rx ID: %d | Med ID: %d | Duration: %d days\n", prescriptions[i].prescriptionID, prescriptions[i].targetMedicineID, prescriptions[i].durationDays);
            found = 1;
        }
    }
    if (!found) printf("No history found.\n");
}
void modifyPrescriptionDosage() {
    int rxId, newDosage;
    printf("Enter Rx ID: "); scanf("%d", &rxId);
    for (int i = 0; i < rxCount; i++) {
        if (prescriptions[i].prescriptionID == rxId) {
            printf("Current Dosage: %d. Enter new dosage: ", prescriptions[i].dailyDosage);
            scanf("%d", &newDosage);
            prescriptions[i].dailyDosage = newDosage;
            printf("Dosage updated.\n");
            return;
        }
    }
}

// --- MODULE 3: DISPENSING ---
void processDispenseRequest() {
    int rxId;
    printf("Enter Rx ID to process: "); scanf("%d", &rxId);
    for (int i = 0; i < rxCount; i++) {
        if (prescriptions[i].prescriptionID == rxId) {
            int reqQty = prescriptions[i].dailyDosage * prescriptions[i].durationDays;
            for (int j = 0; j < medCount; j++) {
                if (inventory[j].medicineID == prescriptions[i].targetMedicineID) {
                    if (inventory[j].currentStock >= reqQty) {
                        inventory[j].currentStock -= reqQty;
                        dispenses[dispCount] = (DispenseLog){dispCount+1, rxId, reqQty, 0.0, 0}; // Pending weight verification
                        dispCount++;
                        printf("Dispensed %d units of %s. Logged as Log ID %d.\n", reqQty, inventory[j].name, dispCount);
                        return;
                    } else {
                        printf("Insufficient stock! Requires %d, have %d.\n", reqQty, inventory[j].currentStock);
                        return;
                    }
                }
            }
        }
    }
    printf("Request Failed.\n");
}
void simulateWeightVerification() {
    int logId;
    printf("Enter Dispense Log ID to verify weight: "); scanf("%d", &logId);
    for (int i = 0; i < dispCount; i++) {
        if (dispenses[i].logID == logId) {
            float expectedWeight = dispenses[i].quantityDispensed * 0.5; // Assume 0.5g per pill
            printf("Expected Weight: %.2fg. Enter Measured Weight from Scale: ", expectedWeight);
            scanf("%f", &dispenses[i].measuredWeight);

            // Check for 5% variance
            if (dispenses[i].measuredWeight >= expectedWeight * 0.95 && dispenses[i].measuredWeight <= expectedWeight * 1.05) {
                dispenses[i].status = 1;
                printf("Weight MATCH. Dispense verified.\n");
            } else {
                dispenses[i].status = 0;
                printf("Weight MISMATCH! Dispense flagged.\n");
            }
            return;
        }
    }
}
void logDispenseTransaction() {
    if (dispCount >= MAX_ITEMS) return;
    printf("Manual Log Entry. Rx ID: "); scanf("%d", &dispenses[dispCount].prescriptionID);
    printf("Qty Dispensed: "); scanf("%d", &dispenses[dispCount].quantityDispensed);
    dispenses[dispCount].logID = dispCount + 1;
    dispenses[dispCount].status = 1;
    dispCount++;
    printf("Manual Log Saved.\n");
}
void flagWeightMismatches() {
    printf("--- Flagged Dispenses (Weight Mismatch) ---\n");
    for (int i = 0; i < dispCount; i++) {
        if (dispenses[i].status == 0) {
            printf("Log ID: %d | Rx ID: %d | Qty: %d | Measured: %.2fg\n",
                   dispenses[i].logID, dispenses[i].prescriptionID, dispenses[i].quantityDispensed, dispenses[i].measuredWeight);
        }
    }
}
void viewDispenseHistory() {
    printf("--- Dispense History ---\n");
    for (int i = 0; i < dispCount; i++) {
        printf("Log ID: %d | Rx ID: %d | Qty: %d | Status: %s\n",
               dispenses[i].logID, dispenses[i].prescriptionID, dispenses[i].quantityDispensed, dispenses[i].status == 1 ? "Success" : "Error");
    }
}

// --- MODULE 4: BILLING ---
void generatePatientBill() {
    char patientName[50];
    float total = 0;
    printf("Enter Patient Name to generate bill: "); fgets(patientName, 50, stdin); patientName[strcspn(patientName, "\n")] = 0;

    for (int i = 0; i < rxCount; i++) {
        if (strcmp(prescriptions[i].patientName, patientName) == 0) {
            int qty = prescriptions[i].dailyDosage * prescriptions[i].durationDays;
            for (int j = 0; j < medCount; j++) {
                if (inventory[j].medicineID == prescriptions[i].targetMedicineID) {
                    total += (qty * inventory[j].unitPriceLKR);
                }
            }
        }
    }

    if (total > 0) {
        bills[billCount].billID = billCount + 1;
        strcpy(bills[billCount].patientName, patientName);
        bills[billCount].subtotal = total;
        bills[billCount].finalBalance = total;
        bills[billCount].isPaid = 0;
        printf("Bill Generated! ID: %d | Total: LKR %.2f\n", bills[billCount].billID, total);
        billCount++;
    } else {
        printf("No active prescriptions found for billing.\n");
    }
}
void applyInsuranceDiscount() {
    int bId;
    printf("Enter Bill ID: "); scanf("%d", &bId);
    for (int i = 0; i < billCount; i++) {
        if (bills[i].billID == bId && bills[i].isPaid == 0) {
            bills[i].finalBalance = bills[i].subtotal * 0.90; // 10% discount
            printf("10%% Insurance Discount Applied. New Balance: LKR %.2f\n", bills[i].finalBalance);
            return;
        }
    }
    printf("Bill not found or already paid.\n");
}
void processBillPayment() {
    int bId;
    printf("Enter Bill ID to Pay: "); scanf("%d", &bId);
    for (int i = 0; i < billCount; i++) {
        if (bills[i].billID == bId) {
            bills[i].isPaid = 1;
            bills[i].finalBalance = 0;
            printf("Payment successful. Bill closed.\n");
            return;
        }
    }
}
void viewUnpaidBalances() {
    printf("--- Unpaid Accounts ---\n");
    for (int i = 0; i < billCount; i++) {
        if (bills[i].isPaid == 0) {
            printf("Bill ID: %d | Patient: %s | Balance: LKR %.2f\n", bills[i].billID, bills[i].patientName, bills[i].finalBalance);
        }
    }
}
void calculateDailyRevenue() {
    float revenue = 0;
    for (int i = 0; i < billCount; i++) {
        if (bills[i].isPaid == 1) {
            revenue += bills[i].subtotal;
        }
    }
    printf("Total Collected Revenue: LKR %.2f\n", revenue);
}

// --- MODULE 5: SUPPLIER ---
void registerNewSupplier() {
    if (supCount >= MAX_ITEMS) return;
    printf("Enter Supplier ID: "); scanf("%d", &suppliers[supCount].supplierID); clearBuffer();
    printf("Enter Company Name: "); fgets(suppliers[supCount].companyName, 50, stdin); suppliers[supCount].companyName[strcspn(suppliers[supCount].companyName, "\n")] = 0;
    printf("Enter Supplied Med ID: "); scanf("%d", &suppliers[supCount].suppliedMedicineID);
    printf("Enter Lead Time (Days): "); scanf("%d", &suppliers[supCount].leadTimeDays);
    supCount++;
    printf("Supplier Registered.\n");
}
void autoGeneratePurchaseOrders() {
    printf("--- Auto-Generated Purchase Orders ---\n");
    int poCount = 0;
    for (int i = 0; i < medCount; i++) {
        if (inventory[i].currentStock < 10) {
            for (int j = 0; j < supCount; j++) {
                if (suppliers[j].suppliedMedicineID == inventory[i].medicineID) {
                    printf("PO Generated: Order %s from %s. Expected in %d days.\n", inventory[i].name, suppliers[j].companyName, suppliers[j].leadTimeDays);
                    poCount++;
                }
            }
        }
    }
    if (poCount == 0) printf("Inventory healthy. No POs needed.\n");
}
void viewSuppliersByItem() {
    int medId;
    printf("Enter Medicine ID to find suppliers: "); scanf("%d", &medId);
    for (int i = 0; i < supCount; i++) {
        if (suppliers[i].suppliedMedicineID == medId) {
            printf("Supplier ID: %d | Company: %s | Lead Time: %d days\n", suppliers[i].supplierID, suppliers[i].companyName, suppliers[i].leadTimeDays);
        }
    }
}
void updateSupplierContact() {
    int supId;
    printf("Enter Supplier ID to update: "); scanf("%d", &supId); clearBuffer();
    for (int i = 0; i < supCount; i++) {
        if (suppliers[i].supplierID == supId) {
            printf("Enter New Company Name: ");
            fgets(suppliers[i].companyName, 50, stdin);
            suppliers[i].companyName[strcspn(suppliers[i].companyName, "\n")] = 0;
            printf("Contact updated.\n");
            return;
        }
    }
}
void calculateAverageLeadTime() {
    if (supCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    int totalDays = 0;
    for (int i = 0; i < supCount; i++) {
        totalDays += suppliers[i].leadTimeDays;
    }
    float avg = (float)totalDays / supCount;
    printf("Average Fleet Logistics Lead Time: %.2f Days\n", avg);
}
