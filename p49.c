#include <stdio.h>

#define DEFAULT_TAX_RATE 0.18f
#define MAX_ITEMS 10

typedef struct {
    float base_price;
    float discount_percent;
    float discount_amount;
    float taxable_amount;
    float tax_rate;
    float tax_amount;
    float final_price;
} Bill;

typedef struct {
    char name[50];
    float unit_price;
    int quantity;
    float discount_percent;
    Bill bill;
} Item;

void clear_input_buffer(void);
int read_positive_float(const char *prompt, float *out);
int read_non_negative_float(const char *prompt, float *out);
int read_positive_int(const char *prompt, int *out);
void init_bill(Bill *bill, float base_price, float discount_percent, float tax_rate);
void calculate_bill(Bill *bill);
void print_bill_details(const Bill *bill, const char *label);
void print_item_receipt(const Item *item);
void print_separator(void);
float get_tax_rate(void);

int main(void) {
    int choice;
    int item_count = 0;
    Item cart[MAX_ITEMS];
    float cart_subtotal = 0.0f;
    float cart_discount_total = 0.0f;
    float cart_tax_total = 0.0f;
    float cart_grand_total = 0.0f;
    float tax_rate;

    printf("=== Advanced Price Calculator ===\n");
    tax_rate = get_tax_rate();

    while (1) {
        printf("\n1. Add item\n");
        printf("2. View cart summary\n");
        printf("3. Checkout and exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (choice == 1) {
            Item item;

            if (item_count >= MAX_ITEMS) {
                printf("Cart is full. Maximum %d items allowed.\n", MAX_ITEMS);
                continue;
            }

            printf("Enter item name: ");
            if (fgets(item.name, sizeof(item.name), stdin) == NULL) {
                printf("Could not read item name.\n");
                continue;
            }

            if (item.name[0] == '\n') {
                printf("Item name cannot be empty.\n");
                continue;
            }

            if (!read_positive_float("Enter unit price: ", &item.unit_price)) {
                continue;
            }

            if (!read_positive_int("Enter quantity: ", &item.quantity)) {
                continue;
            }

            if (!read_non_negative_float("Enter discount percent (0 if none): ", &item.discount_percent)) {
                continue;
            }

            if (item.discount_percent > 100.0f) {
                printf("Discount cannot be more than 100%%.\n");
                continue;
            }

            init_bill(
                &item.bill,
                item.unit_price * item.quantity,
                item.discount_percent,
                tax_rate
            );
            calculate_bill(&item.bill);

            cart[item_count] = item;
            item_count++;

            cart_subtotal += item.bill.base_price;
            cart_discount_total += item.bill.discount_amount;
            cart_tax_total += item.bill.tax_amount;
            cart_grand_total += item.bill.final_price;

            printf("\nItem added successfully.\n");
            print_item_receipt(&item);
        } else if (choice == 2) {
            if (item_count == 0) {
                printf("Cart is empty.\n");
                continue;
            }

            print_separator();
            printf("CART SUMMARY\n");
            print_separator();

            for (int i = 0; i < item_count; i++) {
                printf("%d. %s", i + 1, cart[i].name);
                print_bill_details(&cart[i].bill, cart[i].name);
            }

            print_separator();
            printf("Subtotal       : %.2f\n", cart_subtotal);
            printf("Total Discount : %.2f\n", cart_discount_total);
            printf("Total Tax      : %.2f\n", cart_tax_total);
            printf("Grand Total    : %.2f\n", cart_grand_total);
            print_separator();
        } else if (choice == 3) {
            if (item_count == 0) {
                printf("No items to checkout.\n");
            } else {
                print_separator();
                printf("FINAL RECEIPT\n");
                print_separator();

                for (int i = 0; i < item_count; i++) {
                    print_item_receipt(&cart[i]);
                }

                print_separator();
                printf("Subtotal       : %.2f\n", cart_subtotal);
                printf("Total Discount : %.2f\n", cart_discount_total);
                printf("Total Tax (%.0f%%): %.2f\n", tax_rate * 100.0f, cart_tax_total);
                printf("Grand Total    : %.2f\n", cart_grand_total);
                print_separator();
                printf("Thank you for your purchase!\n");
            }
            break;
        } else {
            printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}

void clear_input_buffer(void) {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard invalid or leftover input */
    }
}

int read_positive_float(const char *prompt, float *out) {
    printf("%s", prompt);

    if (scanf("%f", out) != 1 || *out <= 0.0f) {
        printf("Please enter a valid positive number.\n");
        clear_input_buffer();
        return 0;
    }

    clear_input_buffer();
    return 1;
}

int read_non_negative_float(const char *prompt, float *out) {
    printf("%s", prompt);

    if (scanf("%f", out) != 1 || *out < 0.0f) {
        printf("Please enter zero or a positive number.\n");
        clear_input_buffer();
        return 0;
    }

    clear_input_buffer();
    return 1;
}

int read_positive_int(const char *prompt, int *out) {
    printf("%s", prompt);

    if (scanf("%d", out) != 1 || *out <= 0) {
        printf("Please enter a valid positive whole number.\n");
        clear_input_buffer();
        return 0;
    }

    clear_input_buffer();
    return 1;
}

void init_bill(Bill *bill, float base_price, float discount_percent, float tax_rate) {
    bill->base_price = base_price;
    bill->discount_percent = discount_percent;
    bill->tax_rate = tax_rate;
    bill->discount_amount = 0.0f;
    bill->taxable_amount = 0.0f;
    bill->tax_amount = 0.0f;
    bill->final_price = 0.0f;
}

void calculate_bill(Bill *bill) {
    bill->discount_amount = bill->base_price * (bill->discount_percent / 100.0f);
    bill->taxable_amount = bill->base_price - bill->discount_amount;

    if (bill->taxable_amount < 0.0f) {
        bill->taxable_amount = 0.0f;
    }

    bill->tax_amount = bill->taxable_amount * bill->tax_rate;
    bill->final_price = bill->taxable_amount + bill->tax_amount;
}

void print_separator(void) {
    printf("----------------------------------------\n");
}

void print_bill_details(const Bill *bill, const char *label) {
    (void)label;
    printf("Base Price     : %.2f\n", bill->base_price);
    printf("Discount (%.2f%%): %.2f\n", bill->discount_percent, bill->discount_amount);
    printf("Taxable Amount : %.2f\n", bill->taxable_amount);
    printf("Tax (%.0f%%)    : %.2f\n", bill->tax_rate * 100.0f, bill->tax_amount);
    printf("Final Price    : %.2f\n", bill->final_price);
}

void print_item_receipt(const Item *item) {
    print_separator();
    printf("Item           : %s", item->name);
    printf("Unit Price     : %.2f\n", item->unit_price);
    printf("Quantity       : %d\n", item->quantity);
    print_bill_details(&item->bill, item->name);
}

float get_tax_rate(void) {
    int use_default;
    float custom_rate;

    printf("Use default tax rate (18%%)? 1 = Yes, 0 = No: ");

    if (scanf("%d", &use_default) != 1) {
        printf("Invalid input. Using default tax rate.\n");
        clear_input_buffer();
        return DEFAULT_TAX_RATE;
    }
    clear_input_buffer();

    if (use_default == 1) {
        return DEFAULT_TAX_RATE;
    }

    if (!read_non_negative_float("Enter custom tax rate in percent: ", &custom_rate)) {
        printf("Using default tax rate.\n");
        return DEFAULT_TAX_RATE;
    }

    if (custom_rate > 100.0f) {
        printf("Tax rate too high. Using default tax rate.\n");
        return DEFAULT_TAX_RATE;
    }

    return custom_rate / 100.0f;
}
