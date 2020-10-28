#include <iostream>
#include "console.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

struct eMailMsg {
    string to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};

// removes all elements whose subject begins with the string "SPAM"
void RemoveSpam(Vector<eMailMsg>& messageVector)
{
    for (int i = messageVector.size() - 1; i >= 0; i--)
        if (startsWith(messageVector[i].subject, "SPAM"))
            messageVector.remove(i);
}

void PrintEmail(eMailMsg& email)
{
    cout << "To: " << email.to << " | From: " << email.from
         << " | Message: " << email.message << " | Subject: " << email.subject
         << " | Date: " << email.date << " | Time: " << email.time << endl;
}

void PrintEmailVector(Vector<eMailMsg>& messageVector)
{
    for (int i = 0; i < messageVector.size(); i++)
        PrintEmail(messageVector[i]);
}

int main() {
    Vector<eMailMsg> vec;
    vec.add({"professor", "student", "The body",
             "CS106 rocks!", 30420, 2101});
    vec.add({"professor", "johndoe", "Buy this!",
            "SPAM Best Offers", 40420, 2102});
    vec.add({"professor", "anotherstudent", "Hello",
            "Read this!", 40420, 2107});
    vec.add({"professor", "student", "I'm testing this",
            "SPAM Important Information", 40420, 2108});
    vec.add({"james", "person", "Hi",
            "This is not spam", 40420, 2214});
    vec.add({"professor", "student", "The body",
            "SPAM", 40420, 2217});

    cout << "BEFORE REMOVING SPAM:" << endl;
    PrintEmailVector(vec);

    RemoveSpam(vec);

    cout << "\nAFTER REMOVING SPAM:" << endl;
    PrintEmailVector(vec);

    return 0;
}
