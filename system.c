#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;  // 1 = available, 0 = borrowed
};

struct Book library[100];
int bookCount = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[bookCount].id);

    getchar(); // clear newline from buffer

    printf("Enter Book Title: ");
    fgets(library[bookCount].title, 50, stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0; // remove newline

    printf("Enter Author Name: ");
    fgets(library[bookCount].author, 50, stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0;

    library[bookCount].available = 1;
    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    printf("\n--- Book Catalog ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | %s\n",
               library[i].id, library[i].title, library[i].author,
               library[i].available ? "Available" : "Borrowed");
    }
}

void borrowBook() {
    int id;
    printf("\nEnter Book ID to borrow: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].available) {
                library[i].available = 0;
                printf("You borrowed '%s'\n", library[i].title);
                return;
            } else {
                printf("Sorry, book is already borrowed.\n");
                return;
            }
        }
    }
    printf("Book not found!\n");
}

void returnBook() {
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (!library[i].available) {
                library[i].available = 1;
                printf("You returned '%s'\n", library[i].title);
                return;
            } else {
                printf("This book was not borrowed.\n");
                return;
            }
        }
    }
    printf("Book not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n===== Library Menu =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}