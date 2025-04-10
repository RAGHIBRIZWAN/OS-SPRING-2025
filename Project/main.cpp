#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
using namespace std;

class BookData
{
    string title;
    string author;
    string genre;
    bool isAvailable;
    int bookNumber;

public:
    BookData() {}
    BookData(string title, string author, string genre, int bookNumber, bool avail)
        : title(title), author(author), genre(genre), bookNumber(bookNumber), isAvailable(avail) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    bool getAvailability() const { return isAvailable; }
    int getBookNumber() const { return bookNumber; }
    void setAvailability(bool avail) { isAvailable = avail; }

    friend class Hashing;
    friend class Heap;
    friend class node;
    friend class BST;
    friend class Library;
    friend class User;
};

// Binary Search Tree Stores Data Of All Available Books
class node
{
    BookData *books;
    node *left;
    node *right;

public:
    node(BookData *d) : books(d), left(nullptr), right(nullptr) {}

    friend class BST;
    friend class User;
};

class BST
{
    node *head;

    node *insert(node *root, BookData *books)
    {
        if (root == nullptr)
        {
            return new node(books);
        }
        if (root->books->getBookNumber() == books->getBookNumber())
            return root;

        if (root->books->getBookNumber() > books->getBookNumber())
        {
            root->left = insert(root->left, books);
        }
        else
        {
            root->right = insert(root->right, books);
        }
        return root;
    }

    void inOrderTraversal(node *root)
    {
        if (root == nullptr)
            return;
        inOrderTraversal(root->left);
        cout << "Title: " << root->books->getTitle()
             << ", Author: " << root->books->getAuthor()
             << ", Genre: " << root->books->getGenre()
             << ", Book Number: " << root->books->getBookNumber()
             << ", Availability: " << (root->books->getAvailability() ? "Available" : "Issued") << endl;
        inOrderTraversal(root->right);
    }

public:
    BST() : head(nullptr) {}

    void display()
    {
        cout << "Books in BST (In-Order Traversal):" << endl;
        inOrderTraversal(head);
    }

    void insertion(BookData *books)
    {
        head = insert(head, books);
    }

    node *search(node *root, const string &val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->books->getTitle() == val)
        {
            return root;
        }
        if (root->books->getTitle() > val)
        {
            return search(root->left, val);
        }
        else
        {
            return search(root->right, val);
        }
    }

    void updateAvailability(node *root, const string &title, bool availability)
    {
        if (root == nullptr)
            return;

        if (root->books->getTitle() == title)
        {
            root->books->setAvailability(availability);
            return;
        }
        if (root->books->getTitle() > title)
        {
            updateAvailability(root->left, title, availability);
        }
        else
        {
            updateAvailability(root->right, title, availability);
        }
    }

    node *searching(string val)
    {
        return search(head, val);
    }

    node *Head()
    {
        return head;
    }

    friend class Library;
    friend class User;
};

// Data Stored Of All Books
class Heap
{
    vector<BookData> arr;

public:
    Heap()
    {
        arr.push_back(BookData("", "", "", 0, false));
    }

    void maxHeapInsertion(BookData book)
    {
        arr.push_back(book);
        int index = arr.size() - 1;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index].getBookNumber() > arr[parent].getBookNumber())
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void display()
    {
        cout << "Books in Heap (Level Order):" << endl;
        for (int i = 1; i < arr.size(); i++)
        {
            cout << "Title: " << arr[i].getTitle()
                 << ", Author: " << arr[i].getAuthor()
                 << ", Genre: " << arr[i].getGenre()
                 << ", Book Number: " << arr[i].getBookNumber()
                 << ", Availability: " << (arr[i].getAvailability() ? "Available" : "Issued") << endl;
        }
    }

    friend class Library;
    friend class User;
};

class WaitingList
{
    struct WaitEntry
    {
        string userName;
        string bookTitle;
    };

    queue<WaitEntry> waitQueue;

public:
    void addToQueue(const string &userName, const string &bookTitle)
    {
        waitQueue.push({userName, bookTitle});
        cout << userName << " has been added to the waiting list for " << bookTitle << "." << endl;
    }

    void notifyNext()
    {
        if (!waitQueue.empty())
        {
            WaitEntry nextUser = waitQueue.front();
            cout << "Notifying " << nextUser.userName << " that the book " << nextUser.bookTitle << " is now available!" << endl;
            waitQueue.pop();
        }
        else
        {
            cout << "No users are waiting for this book." << endl;
        }
    }

    bool isEmpty() const
    {
        return waitQueue.empty();
    }

    void displayQueue() const
    {
        if (waitQueue.empty())
        {
            cout << "No users are currently in the waiting list." << endl;
            return;
        }

        cout << "Users in the waiting list:" << endl;
        queue<WaitEntry> tempQueue = waitQueue; // Create a copy to display
        while (!tempQueue.empty())
        {
            WaitEntry entry = tempQueue.front();
            cout << ":User  " << entry.userName << ", Waiting for: " << entry.bookTitle << endl;
            tempQueue.pop();
        }
    }
};

class Library
{
    Heap heap;

public:
    BST bst;
    Library() {}

    void addBooksToHeap(string title, string author, string genre, int id, bool avail)
    {
        BookData books(title, author, genre, id, avail);
        heap.maxHeapInsertion(books);
        cout << "Book successfully added to heap!" << endl;
    }

    void addBooksToBST(string title, string author, string genre, int id, bool avail)
    {
        BookData *books = new BookData(title, author, genre, id, avail);
        if (books->getAvailability())
        {
            bst.insertion(books);
            cout << "Book successfully added to BST!" << endl;
        }
        else
        {
            cout << "Sorry, the book is not available, so it can't be added to BST!" << endl;
        }
    }

    void displayHeap()
    {
        heap.display();
    }

    void displayBST()
    {
        bst.display();
    }

    friend class User;
};

class User
{
    vector<pair<string, vector<BookData *>>> us;
    WaitingList waitingList;

public:
    void issueBook(string title, string user, BST &bst, WaitingList &waitingList)
    {
        node *a = bst.searching(title);

        if (a == nullptr)
        {
            cout << "Sorry, the book is not found!" << endl;
            return;
        }

        if (!a->books->getAvailability())
        {
            // If the book is unavailable, add the user to the waiting list
            waitingList.addToQueue(user, title);
            return;
        }

        // Existing logic for issuing the book
        bool userFound = false;

        for (int i = 0; i < us.size(); i++)
        {
            if (us[i].first == user)
            {
                us[i].second.push_back(a->books);
                userFound = true;
                break;
            }
        }

        if (!userFound)
        {
            us.push_back({user, {a->books}});
        }

        bst.updateAvailability(bst.Head(), title, false);
        cout << "Book successfully issued!" << endl;
    }

    void returnBook(string user, int bookNumber, BST &bst, WaitingList &waitingList)
    {
        for (int i = 0; i < us.size(); i++)
        {
            if (us[i].first == user)
            {
                auto &books = us[i].second;
                for (int j = 0; j < books.size(); j++)
                {
                    if (books[j]->getBookNumber() == bookNumber)
                    {
                        bst.updateAvailability(bst.Head(), books[j]->getTitle(), true);
                        books.erase(books.begin() + j);
                        cout << "Book successfully returned!" << endl;

                        // Notify the next user in the waiting list
                        waitingList.notifyNext();
                        return;
                    }
                }
                cout << "Book with the given number is not issued by this user." << endl;
                return;
            }
        }
        cout << "User  not found!" << endl;
    }

    void showAllBooksTaken()
    {
        if (us.empty())
        {
            cout << "No books have been issued yet." << endl;
            return;
        }

        cout << "Books issued by users:\n";

        for (int i = 0; i < us.size(); i++)
        {
            string userName = us[i].first;
            vector<BookData *> books = us[i].second;

            cout << ":User  " << userName << endl;

            if (books.empty())
            {
                cout << "  No books issued.\n";
                continue;
            }

            for (int j = 0; j < books.size(); j++)
            {
                cout << "  - Title: " << books[j]->getTitle()
                     << ", Author: " << books[j]->getAuthor()
                     << ", Book Number: " << books[j]->getBookNumber()
                     << ", Availability: "
                     << (books[j]->getAvailability() ? "Available" : "Issued") << endl;
            }
        }
    }
};

int main()
{
    int a = 0, b = 0;
    int code = 786;
    int cinCode, bId, id;
    string title, author, genre, bTitle, name;
    bool avail;
    Library lib;
    WaitingList waitingList;
    User use;

    while (true)
    {
        cout << "Choose Any One:" << endl;
        cout << "1.Librarian" << endl;
        cout << "2.User" << endl;
        cout << "3.Exit" << endl;
        cin >> a;

        switch (a)
        {
        case 1:
            cout << "Enter the code to access: ";
            cin >> cinCode;
            if (cinCode == code)
            {
                cout << "Access Granted!" << endl;
                while (true)
                {
                    cout << "Librarian Menu:" << endl;
                    cout << "1. Add Book To Shelf" << endl;
                    cout << "2. Display Heap" << endl;
                    cout << "3. Display BST" << endl;
                    cout << "4. Display Waiting List" << endl;
                    cout << "5. Exit Librarian Menu" << endl;
                    int librarianChoice;
                    cin >> librarianChoice;

                    if (librarianChoice == 1)
                    {
                        cout << "Add Book To shelf" << endl;
                        cout << "Enter the title of the book: ";
                        cin.ignore();
                        getline(cin, title);
                        cout << "Enter the author of the book: ";
                        getline(cin, author);
                        cout << "Enter the genre of the book: ";
                        getline(cin, genre);
                        cout << "Enter the Id of the book: ";
                        cin >> id;
                        cout << "Enter the availability of the book (1 for available, 0 for not available): ";
                        cin >> avail;
                        lib.addBooksToHeap(title, author, genre, id, avail);
                        lib.addBooksToBST(title, author, genre, id, avail);
                    }
                    else if (librarianChoice == 2)
                    {
                        lib.displayHeap();
                    }
                    else if (librarianChoice == 3)
                    {
                        lib.displayBST();
                    }
                    else if (librarianChoice == 4)
                    {
                        waitingList.displayQueue();
                    }
                    else if (librarianChoice == 5)
                    {
                        break; // Exit the librarian menu
                    }
                    else
                    {
                        cout << "Invalid option!" << endl;
                    }
                }
            }
            else
            {
                cout << "Sorry, wrong code!" << endl;
            }
            break;

        case 2:
            cout << "Choose Any One:" << endl;
            cout << "1.Issue Book" << endl;
            cout << "2.Return Book" << endl;
            cout << "3.Show All Books Taken" << endl;
            cin >> b;
            switch (b)
            {
            case 1:
                cout << "Title of Book: ";
                cin.ignore();
                getline(cin, bTitle);
                cout << "Your name: ";
                getline(cin, name);
                use.issueBook(bTitle, name, lib.bst, waitingList);
                break;

            case 2:
                cout << "Book id: ";
                cin >> bId;
                cout << "Your name: ";
                cin.ignore();
                getline(cin, name);
                use.returnBook(name, bId, lib.bst, waitingList);
                break;

            case 3:
                use.showAllBooksTaken();
                break;

            default:
                cout << "Invalid option!" << endl;
                break;
            }
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid option!" << endl;
            break;
        }
    }
}
