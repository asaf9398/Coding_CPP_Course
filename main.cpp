#include <iostream>
#include "Status.h"
#include "FanPage.h"
#include "User.h"

int main()
{


    Status s1("first status");
    Status s2("second status");


    FanPage f1("idos fans");
    f1.addStatus(&s1);
    f1.addStatus(&s2);

    User u1("ido",24,8,2000);
    User u2("ron",14,3,1999);

    u1.addStatus(&s1);

    u1.printStatuses();

    u1.addFriend(&u2);

    u1.printFriends();

    u1.removeFriend("ron");

    u1.printFriends();

    // f1.printStatuses();

    return 0;
}
