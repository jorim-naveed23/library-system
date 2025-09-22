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

// Sprint 1 storage (brainstorm ideas)
struct Book brainstormBooks[50];
int brainstormCount = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[bookCount].id);

    getchar(); // clear newline from buffer

    printf("Enter Book Title: ");
    fgets(library[bookCount].title, 50, stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0;

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

// ===== Sprint 1: Brainstorm + Sketch =====
void sprint1_brainstorm() {
    printf("\nEnter Idea Book ID: ");
    scanf("%d", &brainstormBooks[brainstormCount].id);

    getchar();

    printf("Enter Idea Book Title: ");
    fgets(brainstormBooks[brainstormCount].title, 50, stdin);
    brainstormBooks[brainstormCount].title[strcspn(brainstormBooks[brainstormCount].title, "\n")] = 0;

    printf("Enter Idea Author Name: ");
    fgets(brainstormBooks[brainstormCount].author, 50, stdin);
    brainstormBooks[brainstormCount].author[strcspn(brainstormBooks[brainstormCount].author, "\n")] = 0;

    brainstormBooks[brainstormCount].available = 1;
    brainstormCount++;

    printf("Brainstorm idea added! (Not final yet)\n");
}

// ===== Sprint 2: Refine with Feedback =====
void sprint2_refine() {
    int id;
    printf("\nEnter Idea Book ID to refine: ");
    scanf("%d", &id);
    for (int i = 0; i < brainstormCount; i++) {
        if (brainstormBooks[i].id == id) {
            getchar();
            printf("Enter Updated Book Title: ");
            fgets(brainstormBooks[i].title, 50, stdin);
            brainstormBooks[i].title[strcspn(brainstormBooks[i].title, "\n")] = 0;

            printf("Enter Updated Author Name: ");
            fgets(brainstormBooks[i].author, 50, stdin);
            brainstormBooks[i].author[strcspn(brainstormBooks[i].author, "\n")] = 0;

            // Move to main library after refinement
            library[bookCount++] = brainstormBooks[i];
            printf("Book refined & added to library successfully!\n");
            return;
        }
    }
    printf("Idea not found in brainstorm list.\n");
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
        printf("6. Sprint 1: Brainstorm + Sketch\n");
        printf("7. Sprint 2: Refine with Feedback\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: printf("Exiting program...\n"); break;
            case 6: sprint1_brainstorm(); break;
            case 7: sprint2_refine(); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}