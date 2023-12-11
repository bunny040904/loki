//Publishing Company for book and audio cassette versions . 

#include<iostream>
#include<string>
using namespace std;

class publication
{
public:
    string title;
    float price;

    void add()
    {
        cout << "\nEnter title of the publication : ";
        cin.ignore();
        getline(cin, title);
        cout << "\nEnter price of the publication : ";
        cin >> price;
    }

    void display()
    {
        cout << "\nTitle : " << title << endl;
        cout << "\nPrice : " << price << endl;
    }
};

class book : public publication
{
public:
    int page_count;
    void add_book()
    {
        try
        {
            add();
            cout << "\nEnter page count of book : " << endl;
            cin >> page_count;
            if (page_count <= 0)
            {
                throw page_count;
            }
        }
        catch (...)
        {
            cout << "Page count invalid " << endl;
            page_count = 0;
        }
    }

    void display_book()
    {
        display();
        cout << "\nPage count of book : " << page_count << endl;
    }
};

class tape : public publication
{
public:
    float dur;
    void add_tape()
    {
        try
        {
            add();
            cout << "Enter duration of tape in minutes : " << endl;
            cin >> dur;
            if (dur <= 0)
            {
                throw dur;
            }
        }
        catch (float)
        {
            dur = 0;
            cout << "Invalid time duration of tape " << endl;
        }
    }

    void display_tape()
    {
        display();
        cout << "Time duration : " << dur << endl;
    }
};

int main()
{
    book b[20];
    tape t[20];
    int ch, b_count = 0, t_count = 0, i;
    while (ch != 5)
    {
        cout << "\n\n-------------MENU--------------\n1. Add book\n2. Add tape\n3. Display book\n4. Display tape\n5. Exit\n\nEnter your choice (from 1 to 5) : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b[b_count].add_book();
            b_count++;
            break;
        case 2:
            t[t_count].add_tape();
            t_count++;
            break;
        case 3:
            i = 0;
            while (i < b_count)
            {
                b[i].display_book();
                i++;
            }
            break;
        case 4:
            i = 0;
            while (i < t_count)
            {
                t[i].display_tape();
                i++;
            }
            break;
        case 5:
            exit(0);
        }
    }
}

