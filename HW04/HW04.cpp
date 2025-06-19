#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
	string title;
	string author;
	Book(const string& title, const string& author)
		: title(title), author(author) {

	}
};

class BookManager {
private:
	vector<Book>books;

public:

	void addBook(const string& title, const string& author) {
		books.push_back(Book(title, author));
		cout << title << "by " << author << "을(를) 추가했습니다." << endl;
	}

	void displayAllBooks() {
		for (int i = 0; i < books.size(); i++) {
			cout << books[i].title << "by " << books[i].author << endl;
		}
	}

	void searchByTitle(const string& title) {
		for (Book& book : books) {
			if (title == book.title) {
				cout << title << "by " << book.author << "을(를) 찾았습니다." << endl;
				return;
			}		
		}
		cout << "해당하는 도서를 찾을 수 없습니다" << endl;		
	}

	void searchByAuthor(const string& author) {
		for (Book& book : books) {
			if (author == book.author) {
				cout << book.title << "by " << author << "을(를) 찾았습니다." << endl;
				return;
			}
		}
		cout << "해당하는 도서를 찾을 수 없습니다" << endl;
	}
};

int main() {
	BookManager manager;

	while (true) {
		
		cout << "도서관 관리 시스템" << endl;
		cout << "1. 도서 추가" << endl;
		cout << "2. 보관된 도서 확인" << endl;
		cout << "3. 도서 이름으로 도서 검색" << endl;
		cout << "4. 작가 이름으로 도서 검색" << endl;
		cout << "5. 시스템 종료" << endl;
		cout << "입력 : ";

		int choice;
		cin >> choice;
		cin.ignore();

		if (choice == 1) {

			string title, author;
			cout << "제목을 입력하세요 : " << endl;
			getline(cin, title);
			cout << "저자을 입력하세요 : " << endl;
			getline(cin, author);

			manager.addBook(title, author);
		}
		else if (choice == 2){
			manager.displayAllBooks();
		}
		else if (choice == 3) {
			string title;
			cout << "검색할 도서명을 적으세요" << endl;
			getline(cin, title);
			manager.searchByTitle(title);
		}
		else if (choice == 4) {
			string author;
			cout << "검색할 저자명을 적으세요" << endl;
			getline(cin, author);
			manager.searchByAuthor(author);
		}
		else {
			cout << "시스템을 종료합니다." << endl;
			break;
		}
	}

	return 0;
}