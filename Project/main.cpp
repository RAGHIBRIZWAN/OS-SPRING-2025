#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define SIZE 50

typedef struct {
    char name[30];
    char author[30];
    int id;
} bookData;

typedef struct {
    char uname[30];
    char name[30];
    char author[30];
    int id;
} issueData;

bookData booksArray[SIZE] = { {"", "", 0} };
issueData issueArray[SIZE] = { {"", "", "", 0} };
int count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // Chatgpt

void* authentication(void* arg) {
    int *code = (int *)arg;
    int *result = (int *)malloc(sizeof(int));
    if (*code == 786) {
        *result = 1;
    }
    return (void *)result;
}

void* addBook(void* arg) {
    bookData *data = (bookData *)arg;

    getchar();
    printf("Enter the name of the book: ");
    fgets(data->name, sizeof(data->name), stdin);
    data->name[strcspn(data->name, "\n")] = '\0';  // Remove newline

    printf("Enter the name of the author of the book: ");
    fgets(data->author, sizeof(data->author), stdin);
    data->author[strcspn(data->author, "\n")] = '\0';

    printf("Enter the ID of the book: ");
    scanf("%d", &data->id);
    getchar();

    pthread_mutex_lock(&lock);
    for (int i = 0; i < SIZE; i++) {
        if (booksArray[i].id == 0) break;
        if (strcmp(booksArray[i].name, data->name) == 0 &&
            strcmp(booksArray[i].author, data->author) == 0) {
            printf("Book already exists!\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (booksArray[i].id == 0) {
            booksArray[i] = *data;
            printf("Book added!\n");
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* deleteBook(void* arg) {
    char name[30], author[30];
    getchar();
    printf("Enter the name of the book to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the author of the book to delete: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    pthread_mutex_lock(&lock);
    for (int i = 0; i < SIZE; i++) {
        if (booksArray[i].id == 0) break;
        if (strcmp(booksArray[i].name, name) == 0 &&
            strcmp(booksArray[i].author, author) == 0) {
            strcpy(booksArray[i].name, "");
            strcpy(booksArray[i].author, "");
            booksArray[i].id = 0;
            printf("Book deleted!\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }
    printf("Book not found.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* updateBook(void* arg) {
    bookData *data = (bookData *)arg;
    getchar();
    printf("Enter the name of the book to update: ");
    fgets(data->name, sizeof(data->name), stdin);
    data->name[strcspn(data->name, "\n")] = '\0';

    printf("Enter the author of the book to update: ");
    fgets(data->author, sizeof(data->author), stdin);
    data->author[strcspn(data->author, "\n")] = '\0';

    pthread_mutex_lock(&lock);
    for (int i = 0; i < SIZE; i++) {
        if (booksArray[i].id == 0) break;
        if (strcmp(booksArray[i].name, data->name) == 0 && strcmp(booksArray[i].author, data->author) == 0) {

            printf("Enter new name: ");
            fgets(data->name, sizeof(data->name), stdin);
            data->name[strcspn(data->name, "\n")] = '\0';

            printf("Enter new author: ");
            fgets(data->author, sizeof(data->author), stdin);
            data->author[strcspn(data->author, "\n")] = '\0';

            printf("Enter new ID: ");
            scanf("%d", &data->id);
            getchar();

            booksArray[i] = *data;
            printf("Book updated!\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }
    printf("Book not found.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* searchBook(void* arg) {
    char name[30], author[30];
    getchar();
    printf("Enter the name of the book: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the author of the book: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    pthread_mutex_lock(&lock);
    for (int i = 0; i < SIZE; i++) {
        if (booksArray[i].id == 0) break;
        if (strcmp(booksArray[i].name, name) == 0 &&
            strcmp(booksArray[i].author, author) == 0) {
            printf("Book found!\nName: %s\nAuthor: %s\nID: %d\n",
                   booksArray[i].name, booksArray[i].author, booksArray[i].id);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }
    printf("Book not found.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* issueBook(void* arg) {
    issueData *data = (issueData *)arg;
    getchar();
    
    printf("Enter the name of the user: ");
    fgets(data->uname, sizeof(data->uname), stdin);
    data->uname[strcspn(data->uname, "\n")] = '\0';
    
    printf("Enter the name of the book: ");
    fgets(data->name, sizeof(data->name), stdin);
    data->name[strcspn(data->name, "\n")] = '\0';

    printf("Enter the author of the book: ");
    fgets(data->author, sizeof(data->author), stdin);
    data->author[strcspn(data->author, "\n")] = '\0';

    pthread_mutex_lock(&lock);
    for (int i = 0; i < SIZE; i++) {
        if (booksArray[i].id == 0) break;
        if (strcmp(booksArray[i].name, data->name) == 0 &&
            strcmp(booksArray[i].author, data->author) == 0) {
            issueArray[count] = *data;
            count++;
            printf("Book Issued Successfully!\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }
    printf("Book not found.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* returnBook(void* arg) {
    char name[30],author[30],uname[30];
    getchar();
    printf("Enter the name of the user: ");
    fgets(uname, sizeof(uname), stdin);
    uname[strcspn(uname, "\n")] = '\0';
    
    printf("Enter the name of the book: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the author of the book: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    pthread_mutex_lock(&lock);
    for (int i = 0; i <= count; i++) {
        if (booksArray[i].id == 0) break;
        if (strcmp(issueArray[i].name, name) == 0 && strcmp(issueArray[i].author, author) == 0 && strcmp(issueArray[i].uname, uname) == 0){
            strcpy(issueArray[i].uname, "");
            strcpy(issueArray[i].name, "");
            strcpy(issueArray[i].author, "");
            issueArray[i].id = 0;

            printf("Book Returned Successfully!\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }
    printf("Book not found.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* manager(void* arg){
  for (int i = 0; i <= count; i++){
    if(issueArray[i].id == 0){
      continue;
    }
    printf("User Name: %s\nBook Name: %s\nAuthor: %s\nID: %d\n", issueArray[i].uname, issueArray[i].name, issueArray[i].author, issueArray[i].id);
  }
  return NULL;
}

int main() {
    pthread_t threads[10];
    int code;
    int choice;
    int check = true;

    printf("Enter any one:\n 1) Library\n 2) User\n 3) Exit\n");
    scanf("%d", &choice);

    bookData data;
    issueData issue;
    
    void* authResult;
    
    while(check){
      printf("Enter any one:\n 1) Library\n 2) User\n 3) Exit\n");
      scanf("%d", &choice);
      switch(choice){
        case 1:
          printf("Enter the code to access library: ");
          scanf("%d", &code);
          pthread_create(&threads[0], NULL, authentication, &code);
          pthread_join(threads[0], &authResult);

          if (*(int*)authResult == 1) {
            int choice2;
            printf("Enter any one:\n 1) Add Book\n 2) Delete Book\n 3) Update Book\n 4) Search Book\n 5) Track Users\n");
            scanf("%d",&choice2);
            switch(choice2){
                case 1:
                    pthread_create(&threads[1], NULL, addBook, &data);
                    pthread_join(threads[1], NULL);
                    break;
                case 2:
                    pthread_create(&threads[2], NULL, deleteBook, NULL);
                    pthread_join(threads[2], NULL);
                    break;
                case 3:
                    pthread_create(&threads[3], NULL, updateBook, &data);
                    pthread_join(threads[3], NULL);
                    break;
                case 4:
                    pthread_create(&threads[4], NULL, searchBook, NULL);
                    pthread_join(threads[4], NULL);
                    break;
                case 5:
                    pthread_create(&threads[5], NULL, manager, NULL);
                    pthread_join(threads[5], NULL);
                    break;
                default:
                    printf("Wrong Input!\n");
                    break;
            }
        } else {
            printf("Wrong Password!\n");
        }
        break;
      case 2:
        int choice3;
        printf("Enter any one:\n 1) Issue Book\n 2) Return Book\n");
        scanf("%d",&choice3);
        switch(choice3){
          case 1:
            pthread_create(&threads[6], NULL, issueBook, (void *)&issue);
            pthread_join(threads[6], NULL);
            break;
          case 2:
            pthread_create(&threads[7], NULL, returnBook, NULL);
            pthread_join(threads[7], NULL);
            break;
          }
          break;
      case 3:
        check = false;
        break;
      default:
        printf("Wrong Input!");
        break;
    }
  }
    return 0;
}
